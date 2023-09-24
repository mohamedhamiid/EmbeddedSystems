/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 23 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H


void SOS_voidCreateTask(void(*Copy_voidFuncPtr)(void) ,
						u8 Copy_u8Priority 			  ,
						u16 Copy_Periodicity);

void SOS_voidStart(u32 Copy_u8TickTime , u8 Copy_u8Unit);


#endif
