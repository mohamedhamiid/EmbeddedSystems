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
/********************************Task 8*******************************/
/* - Using 4 Transistors to make to reverse Motor Direction          */
/* - Transistors are connected to pins 0 1 2  3                      */
/*********************************************************************/
int main(){
	DIO_enuSetPortDirection(DIO_u8_PORTA,255);
	while(1){
		DIO_enuSetPortValue(DIO_u8_PORTA ,0b00000011);
		_delay_ms(2000);
		DIO_enuSetPortValue(DIO_u8_PORTA ,0b00000000);
		_delay_ms(2000);
		DIO_enuSetPortValue(DIO_u8_PORTA ,0b00001100);
		_delay_ms(2000);
		DIO_enuSetPortValue(DIO_u8_PORTA ,0b00000000);
		_delay_ms(2000);
	}
return 0;
}

