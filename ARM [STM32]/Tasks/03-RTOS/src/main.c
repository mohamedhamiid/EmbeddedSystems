/*
 * main.c
 *
 *  Created on: Jul 29, 2023
 *      Author: mh_sm
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "OS_interface.h"

#include "LED_interface.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"

HLED_structCfg Global_leds[3];

void Led1(){
	HLED_voidToggle(&Global_leds[1]);
}
void Led2(){
	HLED_voidToggle(&Global_leds[2]);
}
void Led3(){
	HLED_voidToggle(&Global_leds[3]);
}


void main(void){

	/* MCAL */
	/* 1- RCC */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 , RCC_GPIO_A);

	/* 2- RTOS */
	SOS_voidCreateTask(Led1 , 0 , 1 , 0 , ms);
	SOS_voidCreateTask(Led2 , 1 , 2 , 1 , ms);
	SOS_voidCreateTask(Led3 , 2 , 3 , 2 ,ms);

	SOS_voidStart(1 , ms);

	/* HAL */
	/* 01-Leds */
	for(u8 Loc_u8Counter=0 ; Loc_u8Counter < 3 ; Loc_u8Counter++){
		Global_leds[Loc_u8Counter].LED_u8Pin = Loc_u8Counter ;
		Global_leds[Loc_u8Counter].LED_2bitsPort = DIO_PORTA ;
		Global_leds[Loc_u8Counter].LED_2bitsOutFreq = LED_OUTPUT_2MHZ ;
		Global_leds[Loc_u8Counter].LED_1bitConnectionType = LED_ACTIVE_HIGH ;
		Global_leds[Loc_u8Counter].LED_1bitCurrentState = LED_ACTIVE_HIGH_OFF ;
		HLED_voidInitLed(&Global_leds[Loc_u8Counter]);
	}



	while(1){}

}
