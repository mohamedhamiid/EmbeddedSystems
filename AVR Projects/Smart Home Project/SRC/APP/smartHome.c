#include "util/delay.h"
#include "../../INCLUDE/MCAL/DIO/DIO.h"
#include "../../INCLUDE/MCAL/UART/UART.h"
#include "../../INCLUDE/MCAL/UART/UART_priv.h"
#include "../../INCLUDE/MCAL/DIO/DIO_priv.h"
#include "../../SERVICES/bit_utilies.h"
#include "../../INCLUDE/HAL/Led/Led.h"
#include "../../INCLUDE/HAL/Button/Button.h"
#include "../../INCLUDE/HAL/Lcd/Lcd.h"
#include "../../INCLUDE/HAL/Keypad/Keypad.h"
#include "../../INCLUDE/MCAL/GIE/GIE.h"
#include "avr/interrupt.h"

/************************ Smart Home Project ***************************/

#define FAN  2           // PORTD
#define LEDS 0b11111111  // PORTC
#define LOCK 3           // PORTD
#define BUZZ 4           // PORTD

/*************************** LCD Messages ******************************/

u8 EnterMessageLine1[]="1) New User";
u8 EnterMessageLine2[]="2) Old User";

u8 NewUserNewPass[]="New Password";
u8 NewUserNewPassConfirm[]="Confirm Password";

u8 NewOldUserPass[]="Enter Password";

u8 NewIncorrectPass[]="Incorrect Password";
u8 NewcorrectPass[]="correct Password";

u8 openLed[]="1)Led";
u8 openFan[]="2)Fan";
u8 openLock[]="3)Lock";
u8 logout[]="4)Logout";

u8 NewPass[6];
u8 ConfPass[6];
u8 EnterPass[6];

u8 correct = 1;

int main(){
		Lcd_tstrucCfg Lcd1={
				.DataPortId=DIO_u8_PORTA,
				.CtrlPortId=DIO_u8_PORTB,
				.RS_Pin=0,
				.RW_Pin=1,
				.EN_Pin=2
		};
		Lcd_vidInit(&Lcd1);

		UART_structCfg uart={
					.UART_u8BaudRate=UART_BAUD_RATE_9600,
					.UART_u8CharSize=UART_CHARACTER_SIZE_8_BIT,
					.UART_u8Parity=UART_PARITY_EVEN,
					.UART_u8Mode=UART_MODE_ASYNCHRONOUS,
					.UART_u8StopBit=UART_STOP_BIT_SELECT_1_BIT,
					.UART_u8EnableTXorRX=UART_ENABLE_RX,
			};
		UART_voidInit(&uart);
		DIO_enuSetPinDirection(DIO_u8_PORTD,FAN,DIO_u8_OUTPUT); // FAN
			DIO_enuSetPortDirection(DIO_u8_PORTC,DIO_u8_PORT_OUTPUT); // Leds
			DIO_enuSetPinDirection(DIO_u8_PORTD,LOCK,DIO_u8_OUTPUT); // lOCK
			DIO_enuSetPinDirection(DIO_u8_PORTD,BUZZ,DIO_u8_OUTPUT); // BUZZ
			DIO_enuSetPinValue(DIO_u8_PORTD,LOCK,DIO_u8_HIGH); // Disable Lock in start
			DIO_enuSetPinValue(DIO_u8_PORTD,BUZZ,DIO_u8_HIGH); // Disable BUZZ in start

			u8 star = '*';
///////////////////////////////////////////////////////
while (1){
	    Lcd_GotoPosition(&Lcd1,LCD_LINE1,0);
		Lcd_WriteString(&Lcd1,EnterMessageLine1);
		Lcd_GotoPosition(&Lcd1,LCD_LINE2,0);
		Lcd_WriteString(&Lcd1,EnterMessageLine2);
		UCSRB=0b00010000;
u8 newOrOld=0;
newOrOld = UART_u8GetChar();

if (newOrOld=='1'){
	Lcd_CLR(&Lcd1);
	Lcd_WriteString(&Lcd1,NewUserNewPass);
	Lcd_GotoPosition(&Lcd1,LCD_LINE2,0);


	for(u8 passCounter = 0 ; passCounter<6 ;passCounter++){
		u8 ch=0;
		UCSRB=0b00010000; //to activate the UART
		do{
			_delay_ms(200);
			ch=UART_u8GetChar();
			_delay_ms(100);
		}while(ch >= '9' || ch <= '0');
		UCSRB=0b00000000; // to disable UART
		NewPass[passCounter] = ch;
		Lcd_GotoPosition(&Lcd1,LCD_LINE2,passCounter);
		Lcd_WriteLetter(&Lcd1,&ch);
		_delay_ms(500);
		Lcd_GotoPosition(&Lcd1,LCD_LINE2,passCounter);
		Lcd_WriteLetter(&Lcd1,&star);
				_delay_ms(500);
	}

	Lcd_CLR(&Lcd1);
	Lcd_WriteString(&Lcd1,NewUserNewPassConfirm);
	Lcd_GotoPosition(&Lcd1,LCD_LINE2,0);

	for(u8 passCounter = 0 ; passCounter<6 ;passCounter++){
		u8 ch=0;
		UCSRB=0b00010000;
		do{
			_delay_ms(200);
			ch=UART_u8GetChar();
			_delay_ms(100);
		}while(ch >= '9' || ch <= '0');
		UCSRB=0b00000000;
		ConfPass[passCounter] = ch;
		Lcd_GotoPosition(&Lcd1,LCD_LINE2,passCounter);
		Lcd_WriteLetter(&Lcd1,&ch);
		_delay_ms(500);
		Lcd_GotoPosition(&Lcd1,LCD_LINE2,passCounter);
		Lcd_WriteLetter(&Lcd1,&star);
		_delay_ms(500);
	}

			correct = 1;
			Lcd_CLR(&Lcd1);
	for(u8 passCounter = 0 ; passCounter<6 ;passCounter++){
		if (NewPass[passCounter] != ConfPass[passCounter]){
			correct=0;
			break;
		}
	}

		if(correct){
			Lcd_WriteString(&Lcd1,NewcorrectPass);
			_delay_ms(1000);
		}
		else {
			Lcd_WriteString(&Lcd1,NewIncorrectPass);
						_delay_ms(1000);
		}
		UCSRB=0b00010000;
		Lcd_CLR(&Lcd1);
	}
else if(newOrOld=='2'){
	Lcd_CLR(&Lcd1);
	Lcd_WriteString(&Lcd1,NewOldUserPass);
	Lcd_GotoPosition(&Lcd1,LCD_LINE2,0);
	for(u8 passCounter = 0 ; passCounter<6 ;passCounter++){
		u8 ch;
		UCSRB=0b00010000;
				do{
					_delay_ms(200);
					ch=UART_u8GetChar();
					_delay_ms(100);
				}while(ch >= '9' || ch <= '0');
				UCSRB=0b00000000;
			EnterPass[passCounter] = ch;
			Lcd_WriteLetter(&Lcd1,&ch);
			_delay_ms(500);
			Lcd_GotoPosition(&Lcd1,LCD_LINE2,passCounter);
					Lcd_WriteLetter(&Lcd1,&star);
					_delay_ms(1000);
	}
	Lcd_CLR(&Lcd1);
	correct=1;
		for(u8 passCounter = 0 ; passCounter<6 ;passCounter++){

			if (EnterPass[passCounter] != NewPass[passCounter])
				correct=0;}

		   if(correct){

				Lcd_WriteString(&Lcd1,NewcorrectPass);
				TGL_BIT(PORTD_Register,LOCK);
				DIO_enuSetPinValue(DIO_u8_PORTD,BUZZ,DIO_u8_LOW);  // Buzz
				_delay_ms(250);
				DIO_enuSetPinValue(DIO_u8_PORTD,BUZZ,DIO_u8_HIGH); // Buzz
				_delay_ms(250);
				DIO_enuSetPinValue(DIO_u8_PORTD,BUZZ,DIO_u8_LOW);  // Buzz
			    _delay_ms(250);
				DIO_enuSetPinValue(DIO_u8_PORTD,BUZZ,DIO_u8_HIGH); // Buzz
				_delay_ms(250);
				TGL_BIT(PORTD_Register,LOCK);


				Lcd_CLR(&Lcd1);
			    Lcd_GotoPosition(&Lcd1,LCD_LINE1,0);
				Lcd_WriteString(&Lcd1,openLed);
				Lcd_GotoPosition(&Lcd1,LCD_LINE1,8);
				Lcd_WriteString(&Lcd1,openFan);
				Lcd_GotoPosition(&Lcd1,LCD_LINE2,0);
				Lcd_WriteString(&Lcd1,openLock);
				Lcd_GotoPosition(&Lcd1,LCD_LINE2,8);
				Lcd_WriteString(&Lcd1,logout);


				UCSRB=0b00010000;
				u8 options=0;
				do{
					UCSRB=0b00010000;
						options = UART_u8GetChar();

						if (options=='1'){

							TGL_BIT(PORTD_Register,FAN);
						}
						if (options=='2'){

							PORTC_Register^=LEDS;
						}
						if (options=='3'){

							TGL_BIT(PORTD_Register,LOCK);
						}

				}while(options != '4');
				Lcd_CLR(&Lcd1);
		   	}
			else {
				Lcd_WriteString(&Lcd1,NewIncorrectPass);
				_delay_ms(1000);
				Lcd_CLR(&Lcd1);
			}

		}
}
}

/*****************************End of project**************************/


