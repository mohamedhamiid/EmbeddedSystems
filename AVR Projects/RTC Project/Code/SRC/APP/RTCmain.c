#include "util/delay.h"
#include "../../INCLUDE/MCAL/DIO/DIO.h"
#include "../../INCLUDE/MCAL/ADC/ADC.h"
#include "../../INCLUDE/MCAL/TIMER/TIMER.h"
#include "../../INCLUDE/MCAL/UART/UART.h"
#include "../../INCLUDE/MCAL/ADC/ADC_priv.h"
#include "../../INCLUDE/MCAL/UART/UART_priv.h"
#include "../../INCLUDE/MCAL/TIMER/TIMER_priv.h"
#include "../../INCLUDE/MCAL/ADC/ADC_cfg.h"
#include "../../INCLUDE/MCAL/DIO/DIO_priv.h"
#include "../../SERVICES/bit_utilies.h"
#include "../../SERVICES/std_types.h"
#include "../../INCLUDE/HAL/Led/Led.h"
#include "../../INCLUDE/HAL/seg_7/seg_7.h"
#include "../../INCLUDE/HAL/Button/Button.h"
#include "../../INCLUDE/HAL/Lcd/Lcd.h"
#include "../../INCLUDE/HAL/Keypad/Keypad.h"
#include "../../INCLUDE/MCAL/EXTINT/EXTINT.h"
#include "../../INCLUDE/MCAL/GIE/GIE.h"
#include "../../INCLUDE/HAL/STEPPER/STEPPER.h"
#include "avr/interrupt.h"
///////////////////////////////// RTC Project \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
/////////////////////////////// REAL TIME CLOCK \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
// - Has 2 Modes : 1) Clock Mode 2) Timer Mode                                    \\
// - 1) Clock Mode: You can set it using keypad                                   \\
// - 2) Timer Mode: It starts from 0 and increase every 1 seconds                 \\
////////////////////////////////////////////////////////////////////////////////////

// Switching Time Between 7 seg
#define RTC_MULTIPLEXING_TIME   0.5
// Display Time on 7 seg
void RTC_voidDisplay(void);
// To set Clock in Clock Mode
u8 RTC_u8SetClockTime(u8 *capy_u16PtrArray,u8 capy_SizeArray);
// Global varible to set time clock
volatile u8 Global_u8Seconds = 0 , Global_u8Hours=0 , Global_u8Minutes=0;

////////////// Struct to configure Keypad \\\\\\\\\\\\\\\

	Seg_tCfg segments = {
		 .Port = DIO_u8_PORTB ,
		 .Common_Type = Seg_CommCathode ,
	};

////////////////// Timer 0 ISR \\\\\\\\\\\\\\\\\\\\\\
// It performs Multiplexing switching              \\
// Every 5ms it turn off previous 7 seg , and      \\
// turn on next one + write value on it            \\
/////////////////////////////////////////////////////
u8 volatile Global_u8SegNo=0;
ISR(TIMER0_OVF_vect){
	if(Global_u8SegNo==6){
		Global_u8SegNo=0;
		DIO_enuSetPinValue(DIO_u8_PORTC,5,DIO_u8_HIGH);
	}
	DIO_enuSetPinValue(DIO_u8_PORTC,Global_u8SegNo-1,DIO_u8_HIGH);
	DIO_enuSetPinValue(DIO_u8_PORTC,Global_u8SegNo,DIO_u8_LOW);
	switch(Global_u8SegNo){
		case 0:
			// Display
		    Seg_vidOn(&segments,Global_u8Seconds%10);
			break;
		case 1:
			Seg_vidOn(&segments,Global_u8Seconds/10);
			break;
		case 2:
			Seg_vidOn(&segments,Global_u8Minutes%10);
			break;
		case 3:
			// Display
			Seg_vidOn(&segments,Global_u8Minutes/10);
			break;
		case 4:
			// Display
			Seg_vidOn(&segments,Global_u8Hours%10);
			break;
		case 5:
			// Display
			Seg_vidOn(&segments,Global_u8Hours/10);
			break;
	}
	Global_u8SegNo++;
}
////////////////// Timer 1 ISR \\\\\\\\\\\\\\\\\\\\\\
// Every 1 second it's Executed                    \\
// It Increases Seconds , Minutes and Hours        \\
/////////////////////////////////////////////////////
ISR(TIMER1_COMPA_vect){
	Global_u8Seconds++;
	if(Global_u8Seconds==60)
		{
			Global_u8Seconds=0;
			Global_u8Minutes++;
		}
		if(Global_u8Minutes==60)
		{
			Global_u8Minutes=0;
			Global_u8Hours++;
		}
		if(Global_u8Hours==24)
		{
			Global_u8Seconds=0;
			Global_u8Hours=0;
		}
}

///////////////// STRUCTS to configure \\\\\\\\\\\\\\\\
//////////////// Struct to configure LCD \\\\\\\\\\\\\\

Lcd_tstrucCfg Lcd1={
		.DataPortId=DIO_u8_PORTA,
		.CtrlPortId=DIO_u8_PORTC,
		.RS_Pin=6,
		.EN_Pin=7,
		.RW_Pin=8
	};

////////////// Struct to configure Keypad \\\\\\\\\\\\\\

Keypad_tstrucCfg Keypad1={
		.DataPortId=DIO_u8_PORTD
	};

///////////////////// Messages \\\\\\\\\\\\\\\\\\\\\\\\\\\
	// Intro Message
	u8 Intro_line1[]= "1) Clock Mode";
	u8 Intro_line2[]= "2) Timer Mode";
	// Clock Mode Messages
	u8 EnterHours[] = "Enter Hours= ";
	u8 EnterMin[]   = "Enter Min = ";
	u8 EnterSec[]   = "Enter Sec = ";
	u8 InClockMode [] = "Clock Mode";
	u8 ClockModeExit [] ="1)Set 2)Timer";
	u8 ThankYou[]   = "Done !";
    // Timer Mode Messages
	u8 InTimerMode [] = "Timer Mode";
	u8 TimerModeExit [] ="1)Clock 2)Reset";
	// Wrong Input
	u8 WrongChoice[]   = " Wrong Choice ";

int main(void) {

	// Initial Value of Keypad
	u8 Loc_u8pressedKey = Keypad_NotPressed;

	// Array to store each 7 seg value to display
	u8 Array[6]={'#','#','#','#','#','#'};

	// Enable Global Interrupt
	GIE_voidGlobalInterruptEnable();

	///////////////////////// Timer 0 \\\\\\\\\\\\\\\\\\\\\\\\\
	// Struct to cfg timer 0:                                \\
	// 1- Normal Mode                                        \\
	// 2- Prescalling 8                                      \\
	// 3- Setting start of counting from 193                 \\
	// 4- From 2 , 3 --> We get 5ms time between 7 seg       \\
	///////////////////////////////////////////////////////////
    Timer_structTimerCfg timer0={
			.Timer_u8TimerNo =TIMER_NO_TIMER0,
			.Timer_u8TimerForceOutputCompare=TIMER0_FOC_OFF,
			.Timer_u8WaveFormGenerationMode=TIMER0_MODE_NORMAL,
			.Timer_u8ClockSelect=TIMER0_CLOCK_PRESCALLING_8,
	};
  	TIMER_voidTimerInit(&timer0);
	TCNT0 = 193;
	///////////////////////// Timer 1 \\\\\\\\\\\\\\\\\\\\\\\\\
	// Struct to cfg timer 1:                                \\
	// 1- Channel A                                          \\
	// 2- CTC Mode                                           \\
	// 3- Prescalling 1024                                   \\
	///////////////////////////////////////////////////////////
	Timer_structTimerCfg timer1={
			.Timer_u8TimerNo =TIMER_NO_TIMER1,
			.Timer_u8TimerForceOutputCompare=TIMER1_FOC_OFF,
			.Timer_u8WaveFormGenerationMode=TIMER1_MODE_CTC,
			.Timer_u8ClockSelect=TIMER1_CLOCK_PRESCALLING_1024,
			.Timer1_u8Channel=TIMER1_CHANNEL_A,
			.Timer_Interrupt=TIMER_INTERRUPT_ON
	};

	// 1 second = (1024/10^6) * 955
	TIMER_voidCTCcfg(&timer1,955);

	// Init Timer 1
	TIMER_voidTimerInit(&timer1);

	////////////////////////// 7 SEG \\\\\\\\\\\\\\\\\\\\\\\\\\\

	// Set enables pins to output
	DIO_enuSetPortDirection(DIO_u8_PORTC,0b00111111); // 7SEG Power --> 0-5 Port C
	DIO_enuSetPortValue(DIO_u8_PORTC,0b00111111); // 7SEG Power --> 0-5 Port C


	// Init 7 Seg
	Seg_vidInit(&segments);

	/////////////////////////// Lcd \\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	// Init LCD
	Lcd_vidInit(&Lcd1);

	////////////////////////// KeyPad \\\\\\\\\\\\\\\\\\\\\\\\\\\

	// Init Keypad
	Keypad_vidInit(&Keypad1);

	//////////////////// Intro Message Display \\\\\\\\\\\\\\\\\\

	Lcd_WriteString(&Lcd1,Intro_line1);
	Lcd_GotoPosition(&Lcd1,LCD_LINE2,0);
	Lcd_WriteString(&Lcd1,Intro_line2);

	// Flag to distinguish First enter to loop
	u8 FirstTime=1;

	while (1) {
		// Get Keypad Read
		Loc_u8pressedKey=Keypad_u8GetPressedKey(&Keypad1);
		// 1 to Enter Clock Mode
		// 2 to Enter Timer Mode
		if (Loc_u8pressedKey != Keypad_NotPressed) {

			// Clock Mode
			if (Loc_u8pressedKey == '1') {

				FirstTime=0;
				Lcd_CLR(&Lcd1);

				// Set Clock Time
			    RTC_u8SetClockTime(Array,6);

			    // Update Time with set Time
			    RTC_voidUpdateClockTime(&Global_u8Seconds,&Global_u8Minutes,&Global_u8Hours,Array);

			    // Message displayed in Clock Mode
			    Lcd_CLR(&Lcd1);
			    Lcd_WriteString(&Lcd1,InClockMode);
			    Lcd_GotoPosition(&Lcd1,LCD_LINE2,0);
			    Lcd_WriteString(&Lcd1,ClockModeExit);

			}
			// Timer Mode
			else if(Loc_u8pressedKey == '2'){
				FirstTime=0;

				// Zero all 7 seg
				Global_u8Seconds=0;
				Global_u8Minutes=0;
				Global_u8Hours=0;

				// Message displayed in Timer Mode
				Lcd_CLR(&Lcd1);
				Lcd_WriteString(&Lcd1,InTimerMode);
				Lcd_GotoPosition(&Lcd1,LCD_LINE2,0);
				Lcd_WriteString(&Lcd1,TimerModeExit);
			}
			// Wrong input from Keypad
			else {

				// Wrong Message
				Lcd_CLR(&Lcd1);
				Lcd_GotoPosition(&Lcd1,LCD_LINE1,0);
				Lcd_WriteString(&Lcd1,WrongChoice);
				_delay_ms(100);

				// Intro Message Again
				Lcd_CLR(&Lcd1);
				Lcd_WriteString(&Lcd1,Intro_line1);
				Lcd_GotoPosition(&Lcd1,LCD_LINE2,0);
				Lcd_WriteString(&Lcd1,Intro_line2);
			}

		// Display Time in 7 seg
		}
		if(FirstTime==0)
		RTC_voidDisplay();
	}

	return 0;
}

////////////////////// RTC_u8SetClockTime //////////////////////
// - Get Clock values from user by KeyPad                     //
////////////////////////////////////////////////////////////////
u8 RTC_u8SetClockTime(u8 *capy_u16PtrArray,u8 capy_SizeArray){

	u8 loc_counter=0;
	u8 loc_u8pressedKey=Keypad_NotPressed;
	Lcd_CLR(&Lcd1);
	// Enter Hours Message
	Lcd_WriteString(&Lcd1,EnterHours);
	_delay_ms(100);
	while(loc_counter <=capy_SizeArray){

		// Get Read form Keypad
		do{
			loc_u8pressedKey=Keypad_u8GetPressedKey(&Keypad1);
		}while (loc_u8pressedKey==Keypad_NotPressed);

		// Get hours from Keypad
		if((loc_u8pressedKey!=Keypad_NotPressed) && (loc_u8pressedKey!='c'))
		{
			capy_u16PtrArray[loc_counter]=loc_u8pressedKey-1;
			u8 letter = capy_u16PtrArray[loc_counter];
			Lcd_WriteLetter(&Lcd1,&letter);
			_delay_ms(100);
		}

		// Get Minutes
		if(loc_counter==1)
		{
			Lcd_CLR(&Lcd1);
			Lcd_WriteString(&Lcd1,EnterMin);
			_delay_ms(100);
		}

		// Get Seconds
		if(loc_counter==3)
		{
			Lcd_CLR(&Lcd1);
			Lcd_WriteString(&Lcd1,EnterSec);
			_delay_ms(100);
		}

		// End of getting Keypad
		if(loc_counter==5)
		{
			Lcd_CLR(&Lcd1);
			Lcd_WriteString(&Lcd1,ThankYou);
			_delay_ms(100);
			return 0 ;
		}
		if(loc_u8pressedKey=='c')
		{
			Lcd_CLR(&Lcd1);
			Lcd_WriteString(&Lcd1,Intro_line1);
			Lcd_GotoPosition(&Lcd1,LCD_LINE2,0);
			Lcd_WriteString(&Lcd1,Intro_line2);
			_delay_ms(100);
			break ;
		}
		loc_counter++;

	}
}

///////////////////////////// RTC_voidUpdateClockTime \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
// Update Clock in Array                                                                \\
//////////////////////////////////////////////////////////////////////////////////////////

void RTC_voidUpdateClockTime(u8 *ptrcount_Second,u8 *ptrcount_Minutes,u8 *ptrcount_Hours,u8 *capy_u16PtrArray)
{

   *ptrcount_Hours  = 10*(capy_u16PtrArray[0]-48)+(capy_u16PtrArray[1]-48);
   *ptrcount_Minutes= 10*(capy_u16PtrArray[2]-48)+(capy_u16PtrArray[3]-48);
   *ptrcount_Second = 10*(capy_u16PtrArray[4]-48)+(capy_u16PtrArray[5]-48);

}


