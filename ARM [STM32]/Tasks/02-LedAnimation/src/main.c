/*
 * main.c
 *
 *  Created on: Jul 29, 2023
 *      Author: mh_sm
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "LED_interface.h"

#include "RCC_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"

HLED_structCfg Global_leds[8];

void ShiftLed(){
	for(u8 Loc_u8Counter=0 ; Loc_u8Counter < 8 ; Loc_u8Counter++){

		HLED_voidTurnOn(&Global_leds[Loc_u8Counter]);
		MSTK_voidSetBusyWait(100 , ms);

		HLED_voidTurnOff(&Global_leds[Loc_u8Counter]);
		MSTK_voidSetBusyWait(100 , ms);
	}
	for(u8 Loc_u8Counter=1 ; Loc_u8Counter < 8 ; Loc_u8Counter++){
		HLED_voidTurnOn(&Global_leds[7-Loc_u8Counter]);
		MSTK_voidSetBusyWait(100 , ms);

		HLED_voidTurnOff(&Global_leds[7-Loc_u8Counter]);
		MSTK_voidSetBusyWait(100 , ms);
	}
}

void InOutLed(){
	for(u8 Loc_u8Counter=4 , Loc_u8SecCounter=3 ; Loc_u8Counter < 8 ; Loc_u8Counter++,Loc_u8SecCounter--){

		HLED_voidTurnOn(&Global_leds[Loc_u8Counter]);
		HLED_voidTurnOn(&Global_leds[Loc_u8SecCounter]);
		MSTK_voidSetBusyWait(200 , ms);

	}
	for(u8 Loc_u8Counter=7 , Loc_u8SecCounter=0 ; Loc_u8Counter > Loc_u8SecCounter ; Loc_u8Counter--,Loc_u8SecCounter++){

		HLED_voidTurnOff(&Global_leds[Loc_u8Counter]);
		HLED_voidTurnOff(&Global_leds[Loc_u8SecCounter]);
		MSTK_voidSetBusyWait(200 , ms);

	}

}
void flashLed(){
	for(u8 Counter=0 ; Counter < 4 ; Counter++){
	for(u8 Loc_u8Counter=0 ; Loc_u8Counter < 8 ; Loc_u8Counter++){
			HLED_voidTurnOn(&Global_leds[Loc_u8Counter]);
	}

	MSTK_voidSetBusyWait(200 , ms);

	for(u8 Loc_u8Counter=0 ; Loc_u8Counter < 8 ; Loc_u8Counter++){
				HLED_voidTurnOff(&Global_leds[Loc_u8Counter]);
	}
	MSTK_voidSetBusyWait(200 , ms);
	}
}

void main(void){

	/* MCAL */
	/* 1- RCC */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 , RCC_GPIO_A);
	/* 2- SYSTICK */
	MSTK_voidInit();
	/* 3- NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(NVIC_EXT5_EXT9);
	/* 4- EXTI9 */
	EXTI_tCfg EXTI9={
			.EXTI_u8Pin  = EXTI_PIN9 ,
			.EXTI_u8Port = EXTI_PORTA ,
			.EXTI_u8Mode = EXTI_FALLING
	};
	MEXTI_voidInitEXTI (&EXTI9);
	MEXTI_voidEnableEXTI(&EXTI9 , flashLed);

	/* HAL */
	/* 01-Leds */
	for(u8 Loc_u8Counter=0 ; Loc_u8Counter < 8 ; Loc_u8Counter++){
		Global_leds[Loc_u8Counter].LED_u8Pin = Loc_u8Counter ;
		Global_leds[Loc_u8Counter].LED_2bitsPort = PORTA ;
		Global_leds[Loc_u8Counter].LED_2bitsOutFreq = LED_OUTPUT_2MHZ ;
		Global_leds[Loc_u8Counter].LED_1bitConnectionType = LED_ACTIVE_HIGH ;
		Global_leds[Loc_u8Counter].LED_1bitCurrentState = LED_ACTIVE_HIGH_OFF ;
		HLED_voidInitLed(&Global_leds[Loc_u8Counter]);
	}

	/* 02-Switch */
	SWITCH_structCfg sw1={
			.SWITCH_u8Pin     =  PIN9 ,
			.SWITCH_2bitsPort =  PORTA  ,
			.SWITCH_2bitsMode = SWITCH_PULL_UP
	};
	SWITCH_voidInitSwitch(&sw1);

	while(1){
		for(u8 Loc_u8Counter=0 ; Loc_u8Counter < 4 ; Loc_u8Counter++)
			ShiftLed();
		for(u8 Loc_u8Counter=0 ; Loc_u8Counter < 4 ; Loc_u8Counter++)
			InOutLed();
	}

}
