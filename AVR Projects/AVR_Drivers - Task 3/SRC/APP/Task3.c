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
/***********************************Task 3**************************************/
/* - Turn on leds from inside to outside, then turn off from outside to inside */
/*******************************************************************************/
int main(){
Led_tCfg task3[8];
//Initialize all Leds
for(u8 Led_InitCount=0;Led_InitCount<8;Led_InitCount++){
		 task3[Led_InitCount].Led_NestStruct.Port = DIO_u8_PORTA ;
		 task3[Led_InitCount].Pin  = Led_InitCount ;
		 task3[Led_InitCount].Led_NestStruct.Active_Status = Led_Active_High ;
		 task3[Led_InitCount].Led_NestStruct.Current_Status= Led_Active_High_Low;
		 Led_vidLedInit(&task3[Led_InitCount]);
}
while(1){
for(u8 Led_OnCount=0;Led_OnCount<4;Led_OnCount++){
	Led_vidOn(&task3[(4+Led_OnCount)]);
	Led_vidOn(&task3[(3-Led_OnCount)]);
	_delay_ms(1000);
}
for(u8 Led_OffCount=3;Led_OffCount>=0;Led_OffCount--){
	Led_vidOff(&task3[3-Led_OffCount]);
	Led_vidOff(&task3[4+Led_OffCount]);
	_delay_ms(1000);
	if(Led_OffCount==0) break; // To avoid infinity loop because Counter is unsigned it will be 255(>=0)
}

}
return 0;
}
