/*****************************************************************************************/
/* Author  : Mohamed Abdel Hamid                             							 */
/* Date    : 20 / 8 / 2023                                  							 */
/* Version : V01                                           							 	 */
/*****************************************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

//u32  MSTK_u32GetReloadValue		 (u32 Copy_u32Value , u8 Copy_u8Unit);
//void MSTK_voidResetFlag			 ();

u32 MSTK_u32GetReloadValue(u32 Copy_u32Value , u8 Copy_u8Unit);

void MSTK_voidInit				 ();
void MSTK_voidSetBusyWait        (u32 Copy_u32Value , u8 Copy_u8Unit);
void MSTK_voidSetIntervalSingle  (u32 Copy_u32Value , u8 Copy_u8Unit , void(*func)(void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Value , u8 Copy_u8Unit , void(*func)(void));
void MSTK_voidStop               (void);
u32  MSTK_u32GetElapsedTime      (void);
u32  MSTK_u32GetRemainingTime 	 (void);

/* Options for Copy_u8Unit */
typedef enum{
	us ,
	ms ,
	s  ,

}STK_enumUnit;

#endif
