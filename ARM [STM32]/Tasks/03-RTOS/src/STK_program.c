/*
 * STK_program.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Mohamed Hamid
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_priv.h"
#include "STK_config.h"

u32 MSTK_u32GetReloadValue(u32 Copy_u32Value , u8 Copy_u8Unit){
	/* Determine Reload Value */
	u32 Local_u32LoadValue=0 ;
	switch(Copy_u8Unit){

		case us:
			 Local_u32LoadValue = (u32)(((double)Copy_u32Value/Global_u8STKClock) * 1);
		break;

		case ms:
			 Local_u32LoadValue = (u32)(((double)Copy_u32Value/Global_u8STKClock) * 1000);
		break;

		case s:
			 Local_u32LoadValue = (u32)(((double)Copy_u32Value/Global_u8STKClock) * 1000000);
		break;
	}
	/* End of Determine Reload Value */
	return Local_u32LoadValue ;
}

void MSTK_voidResetFlag(){
	u8 Loc_u8Temp;
	Loc_u8Temp = GET_BIT(STK->CTRL,16);
}

void MSTK_voidInit(){
	STK->CTRL = STK_CONFIG ;

	if(STK_CONFIG==STK_CLK_SOURCE_AHB_DIV_8)
		Global_u8STKClock = Global_u8CurrClkFreq / 8 ;
	else
		Global_u8STKClock = Global_u8CurrClkFreq     ;
}
void MSTK_voidSetBusyWait(u32 Copy_u32Value , u8 Copy_u8Unit){
	CLR_BIT(STK->CTRL,0);
	u32 Local_u32LoadValue = MSTK_u32GetReloadValue(Copy_u32Value,Copy_u8Unit);

	if(Local_u32LoadValue <= 0xFFFFFF &&  Copy_u8Unit<= s){

		STK->LOAD = Local_u32LoadValue ; /* Set Reload Value        */
		SET_BIT(STK->CTRL,0);            /* Enable STK              */
		while(GET_BIT(STK->CTRL,16)==0); /* Wait till count is done */
		MSTK_voidResetFlag();			 /* Clear Flag              */
	}

	else{
		/* Error : Invalid Values */
	}

}
void MSTK_voidSetIntervalSingle(u32 Copy_u32Value , u8 Copy_u8Unit , void(*func)(void)){

	u32 Local_u32LoadValue = MSTK_u32GetReloadValue(Copy_u32Value,Copy_u8Unit);

		if(Local_u32LoadValue <= 0xFFFFFF &&  Copy_u8Unit<= s){

		STK->LOAD = Local_u32LoadValue ; /* Set Reload Value      */
		SET_BIT(STK->CTRL,1);            /* Enable Interrupt      */
		MSTK_CallBack = func ;           /* Assign Call Back Func */
		SET_BIT(STK->CTRL,0);            /* Enable STK            */
		Global_u8SingleInterval = 1 ;
	}

	else{
		/* Error : Invalid Values */
	}

}
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Value , u8 Copy_u8Unit , void(*func)(void)){

	u32 Local_u32LoadValue = MSTK_u32GetReloadValue(Copy_u32Value,Copy_u8Unit);

		if(Local_u32LoadValue <= 0xFFFFFF &&  Copy_u8Unit<= s){
		STK->LOAD = Local_u32LoadValue - 1 ; /* Set Reload Value      */
		SET_BIT(STK->CTRL,1);            	 /* Enable Interrupt      */
		MSTK_CallBack = func ;           	 /* Assign Call Back Func */
		Global_u8SingleInterval = 0 ;
		SET_BIT(STK->CTRL,0);                /* Enable STK            */
	}

	else{
		/* Error : Invalid Values */
	}
}
void MSTK_voidStop(){
	CLR_BIT(STK->CTRL,0);  /* Disable STK */
}

u32 MSTK_u32GetElapsedTime(){
	return (STK->LOAD - STK->VALUE) ;
}

u32 MSTK_u32GetRemainingTime(){
	return STK->VALUE ;
}

void SysTick_Handler(void){


	if(Global_u8SingleInterval){
	    CLR_BIT(STK->CTRL,0);  /* Stop STK */
	    CLR_BIT(STK->CTRL,1);  /* Disable Interrupt */
		STK->LOAD = 0 ;        /* Reset Reload Value */
	}

	/* Func */
	MSTK_CallBack();


	MSTK_voidResetFlag();
}


