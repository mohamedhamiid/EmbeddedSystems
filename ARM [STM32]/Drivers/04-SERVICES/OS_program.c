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
						u8 Copy_u8Priority ,
						u16 Copy_Periodicity)
{
	SOS_Tasks[Copy_u8Priority].func = Copy_voidFuncPtr ;
	SOS_Tasks[Copy_u8Priority].periodicity = Copy_Periodicity ;
}


void SOS_voidStart(u32 Copy_u8TickTime , u8 Copy_u8Unit){

	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(Copy_u8TickTime , Copy_u8Unit , SOS_voidScheduler);

}


