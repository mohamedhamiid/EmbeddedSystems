/*
 * main.c
 *
 *  Created on: Aug 18, 2023
 *      Author: Mohamed Hamid
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SEVENSEG_interface.h"

#include "NVIC_interface.h"


SEVENSEG_structCfg Global_structSeg1={
		.SEVENSEG_1bitCommonType =  SEVENSEG_COMMON_CATHODE ,
		.SEVENSEG_2bitPort       =  DIO_PORTA               ,
		.SEVENSEG_2bitsOutFreq   = 	DIO_OUTPUT_2MHZ         ,
		.SEVENSEG_u8StartPin     =  DIO_PIN0
};

void EXTI0_IRQHandler(){
	SEVENSEG_voidTurnOnSevenSeg(&Global_structSeg1 , 0);
	delay_ms(500);
}
void EXTI1_IRQHandler(){

	SEVENSEG_voidTurnOnSevenSeg(&Global_structSeg1 , 1);
	delay_ms(500);

	/********** For Case 2 ****************/
//	MNVIC_voidSetPendingFlag(NVIC_EXT0);
//
//	SEVENSEG_voidTurnOnSevenSeg(&Global_structSeg1 , 2);
//	delay_ms(500);
}



void main(void){

	/* MCAL */
	/* 1- RCC */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 , RCC_GPIO_A);

	/* 2- NVIC */
	MNVIC_voidInit();
	/******** CASE 1 : Two Interrupt at same time  **********/
	//*********** EXT0 higher group priority ***************//
	// EXTI0
	MNVIC_voidEnableInterrupt(NVIC_EXT0);
	MNVIC_voidSetPriority(NVIC_EXT0, 0,0);

	// EXTI1
	MNVIC_voidEnableInterrupt(NVIC_EXT1);
	MNVIC_voidSetPriority(NVIC_EXT1, 1,0);


	/* HAL */
	/* Seven Segment */
	SEVENSEG_voidInitSevenSeg(&Global_structSeg1);
	MNVIC_voidSetPendingFlagS(0b11000000);
	//******************************************************//
	//*********** EXT1 higher group priority ***************//
	// EXTI0
//	MNVIC_voidEnableInterrupt(NVIC_EXT0);
//	MNVIC_voidSetPriority(NVIC_EXT0, 1,0);
//
//	// EXTI1
//	MNVIC_voidEnableInterrupt(NVIC_EXT1);
//	MNVIC_voidSetPriority(NVIC_EXT1, 0,0);
//
//	/* HAL */
//	/* Seven Segment */
//	SEVENSEG_voidInitSevenSeg(&Global_structSeg1);
//	MNVIC_voidSetPendingFlagS(0b11000000);
	//******************************************************//
	//***********  EXT0 higher Sub Priority  ***************//
	// EXTI0
//	MNVIC_voidEnableInterrupt(NVIC_EXT0);
//	MNVIC_voidSetPriority(NVIC_EXT0, 0,0);
//
//	// EXTI1
//	MNVIC_voidEnableInterrupt(NVIC_EXT1);
//	MNVIC_voidSetPriority(NVIC_EXT1, 0,1);
//	MNVIC_voidSetPendingFlag (NVIC_EXT1);
//
//	/* HAL */
//	/* Seven Segment */
//	SEVENSEG_voidInitSevenSeg(&Global_structSeg1);
//	MNVIC_voidSetPendingFlagS(0b11000000);
	//******************************************************//
	//***********  EXT1 higher Sub Priority  ***************//
//	// EXTI0
//	MNVIC_voidEnableInterrupt(NVIC_EXT0);
//	MNVIC_voidSetPriority(NVIC_EXT0, 0,1);
//
//	// EXTI1
//	MNVIC_voidEnableInterrupt(NVIC_EXT1);
//	MNVIC_voidSetPriority(NVIC_EXT1, 0,0);
//	MNVIC_voidSetPendingFlag (NVIC_EXT1);

//	/* HAL */
//	/* Seven Segment */
//	SEVENSEG_voidInitSevenSeg(&Global_structSeg1);
//	MNVIC_voidSetPendingFlagS(0b11000000);
	//***********  Same Group and sub Priority  ***********//
//	// EXTI0
//	MNVIC_voidEnableInterrupt(NVIC_EXT0);
//	MNVIC_voidSetPriority(NVIC_EXT0, 0,0);
//
//	// EXTI1
//	MNVIC_voidEnableInterrupt(NVIC_EXT1);
//	MNVIC_voidSetPriority(NVIC_EXT1, 0,0);
//	MNVIC_voidSetPendingFlag (NVIC_EXT1);

//	/* HAL */
//	/* Seven Segment */
//	SEVENSEG_voidInitSevenSeg(&Global_structSeg1);
//	MNVIC_voidSetPendingFlagS(0b11000000);
	/************ CASE 2 : Nested Interrupt  ****************/
	//*********** EXT0 higher group priority ***************//
//	// EXTI0
//	MNVIC_voidEnableInterrupt(NVIC_EXT0);
//	MNVIC_voidSetPriority(NVIC_EXT0, 0,0);
//
//	// EXTI1
//	MNVIC_voidEnableInterrupt(NVIC_EXT1);
//	MNVIC_voidSetPriority(NVIC_EXT1, 1,0);

	//******************************************************//
	//*********** EXT1 higher group priority ***************//
//	// EXTI0
//	MNVIC_voidEnableInterrupt(NVIC_EXT0);
//	MNVIC_voidSetPriority(NVIC_EXT0, 1,0);
//
//	// EXTI1
//	MNVIC_voidEnableInterrupt(NVIC_EXT1);
//	MNVIC_voidSetPriority(NVIC_EXT1, 0,0);
	//******************************************************//

	while(1){}

}
