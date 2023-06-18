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
/********************************Task 2*******************************/
/* - Turn on all 8 led one after one in one direction and reverse it */
/*********************************************************************/
int main(){
Led_tCfg task2[8];
//Initialize all Leds
for(u8 Led_InitCount=0;Led_InitCount<8;Led_InitCount++){
		 task2[Led_InitCount].Led_NestStruct.Port = DIO_u8_PORTA ;
		 task2[Led_InitCount].Pin  = Led_InitCount ;
		 task2[Led_InitCount].Led_NestStruct.Active_Status = Led_Active_High ;
		 task2[Led_InitCount].Led_NestStruct.Current_Status= Led_Active_High_Low;
		 Led_vidLedInit(&task2[Led_InitCount]);
}
while(1){
for(u8 Led_ForwardCount=0;Led_ForwardCount<8;Led_ForwardCount++){
	Led_vidOn(&task2[Led_ForwardCount]);
	_delay_ms(200);
	Led_vidOff(&task2[Led_ForwardCount]);
	_delay_ms(200);
}
for(u8 Led_BackwardCount=6;Led_BackwardCount>=1;Led_BackwardCount--){
	Led_vidOn(&task1[Led_BackwardCount]);
	_delay_ms(200);
	Led_vidOff(&task1[Led_BackwardCount]);
	_delay_ms(200);
}

}
return 0;
}
