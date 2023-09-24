/*
 * OS_program.c
 *
 *  Created on: Aug 23, 2023
 *      Author: mh_sm
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_config.h"
#include "OS_priv.h"

void SOS_voidCreateTask(void(*Copy_voidFuncPtr)(void) ,
						u8 Copy_u8TaskId ,
						u8 Copy_u8PeriodicityTime ,
						u8 Copy_u8FirstDelayTime  ,
						STK_enumUnit Copy_enuUnit)
{
	SOS_Tasks[Copy_u8TaskId].func = Copy_voidFuncPtr ;
	SOS_Tasks[Copy_u8TaskId].periodicity = MSTK_u32GetReloadValue(Copy_u8PeriodicityTime , Copy_enuUnit);
	SOS_Tasks[Copy_u8TaskId].firstDelay =  MSTK_u32GetReloadValue(Copy_u8FirstDelayTime  , Copy_enuUnit);
	SOS_Tasks[Copy_u8TaskId].state = STATE_READY ;
}


void SOS_voidStart(u32 Copy_u8TickTime , STK_enumUnit Copy_enuUnit){

	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(Copy_u8TickTime , Copy_enuUnit , SOS_voidScheduler);

}

void SOS_voidSuspendTask(Copy_u8TaskId){
	SOS_Tasks[Copy_u8TaskId].state = STATE_SUSPENDED ;
}

void SOS_voidResumeTask(Copy_u8TaskId){
	SOS_Tasks[Copy_u8TaskId].state = STATE_READY ;
}
void SOS_voidDeleteTask(Copy_u8TaskId){
	SOS_Tasks[Copy_u8TaskId].func = NULL ;
}


