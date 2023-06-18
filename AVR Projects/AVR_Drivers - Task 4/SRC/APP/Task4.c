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

/********************************Task 4*******************************/
/* - Counter with one 7 segment   0-->9                              */
/*********************************************************************/
int main(){
	u8 segment_7[10]={63,6,91,79,102,109,125,7,127,111};
	Seg_tCfg Seg2 = {
				.Port = DIO_u8_PORTA ,
				.Common_Type = Seg_CommCathode
			};
	Seg_vidSegInit(&Seg2);
while(1){

	for(u8 Seg2_Counter=0;Seg2_Counter<10;Seg2_Counter++){
		Seg_vidOn(&Seg2,segment_7[Seg2_Counter]);
		_delay_ms(1000);
		}
}
	return 0;
}
