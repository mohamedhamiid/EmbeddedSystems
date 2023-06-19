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
#include "../../INCLUDE/HAL/Led/Led.h"
#include "../../INCLUDE/HAL/seg_7/seg_7.h"
#include "../../INCLUDE/HAL/Button/Button.h"
#include "../../INCLUDE/HAL/Lcd/Lcd.h"
#include "../../INCLUDE/HAL/Keypad/Keypad.h"
#include "../../INCLUDE/MCAL/EXTINT/EXTINT.h"
#include "../../INCLUDE/MCAL/GIE/GIE.h"
#include "../../INCLUDE/HAL/STEPPER/STEPPER.h"
/************************************Task 11*********************************/
/* - ADC                                                                    */
/* - Leds + Pot                                                             */
/* - Turn on Leds using Pot                                                 */
/****************************************************************************/

int main(){
	ADC_voidInit();
	u16 Loc_u16AdcRead=0;
	s8 Ledcounter=0;
	Lcd_tstrucCfg lcd1={
			.CtrlPortId=DIO_u8_PORTB,
			.DataPortId=DIO_u8_PORTD,
			.EN_Pin=2,
			.RW_Pin=1,
			.RS_Pin=0
	};
	Lcd_vidInit(&lcd1);
	DIO_enuSetPinDirection(DIO_u8_PORTA,DIO_u8_PIN5,1);
	DIO_enuSetPinValue(DIO_u8_PORTA,DIO_u8_PIN5,1);

	Led_tCfg Led_sys[8];
	for(Ledcounter=0;Ledcounter<8;Ledcounter++){
		Led_sys[Ledcounter].Pin = Ledcounter;
		Led_sys[Ledcounter].Led_NestStruct.Port=DIO_u8_PORTC;
		Led_sys[Ledcounter].Led_NestStruct.Current_Status=Led_Active_High_Low;
		Led_sys[Ledcounter].Led_NestStruct.Active_Status=Led_Active_High;
		Led_vidLedInit(&Led_sys[Ledcounter]);
	}
	Ledcounter=0;
	u16 Loc_previousRead=0;
	u16 Loc_u16AdcReadLcd=0;
	while(1){
	ADC_voidGetRead(&Loc_u16AdcRead);
	Loc_u16AdcReadLcd=(Loc_u16AdcReadLcd*(5.0/1024.0));
	Lcd_WriteNumber(&lcd1,&Loc_u16AdcReadLcd);
	if(Loc_u16AdcRead%256==0 && Loc_u16AdcRead>Loc_previousRead && Ledcounter<=7 && Ledcounter>=0){
		Led_vidOn(&Led_sys[Ledcounter]);
		Ledcounter++;
		Loc_previousRead=Loc_u16AdcRead;
	}
	else if(Loc_u16AdcRead%256==0 && Loc_u16AdcRead<Loc_previousRead && Ledcounter<=7 && Ledcounter>=0){

		Led_vidOff(&Led_sys[Ledcounter]);
		Ledcounter--;
		Loc_previousRead=Loc_u16AdcRead;
	}
	else if(Ledcounter>7||Ledcounter<0){
		if (Ledcounter>7)
			Ledcounter=7;
		else
			Ledcounter=0;
	}

	}
return 0;
}



