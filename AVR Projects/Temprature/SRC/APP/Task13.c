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
/************************************Task 13*********************************/
/* - ADC                                                                    */
/* - Temp Sensor + LCD                                                      */
/* - Take The Temp Sensor read and display it on LCD                        */
/****************************************************************************/

int main(){
	ADC_voidInit();
	u16 Loc_u16AdcRead=0;
	Lcd_tstrucCfg lcd1={
			.CtrlPortId=DIO_u8_PORTB,
			.DataPortId=DIO_u8_PORTD,
			.EN_Pin=2,
			.RW_Pin=1,
			.RS_Pin=0
	};
	Lcd_vidInit(&lcd1);
	u8 Lcd_string[]="TEMP = ";
	u8 Lcd_string2[]="C";
	Lcd_WriteString(&lcd1,Lcd_string);
	Lcd_GotoPosition(&lcd1,LCD_LINE2,14);
	Lcd_WriteString(&lcd1,Lcd_string2);
	while(1){
	ADC_voidGetRead(&Loc_u16AdcRead);
	Loc_u16AdcRead*=(500.0/1024.0);
	if(Loc_u16AdcRead>10&&Loc_u16AdcRead<=45){
	Lcd_GotoPosition(&lcd1,LCD_LINE2,6);
	Lcd_WriteNumber(&lcd1,Loc_u16AdcRead);
	_delay_ms(2000);
	}
	}

return 0;
}


