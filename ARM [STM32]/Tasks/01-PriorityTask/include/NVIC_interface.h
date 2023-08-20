/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 14 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/* Prototypes */
void MNVIC_voidEnableInterrupt   (u8 Copy_u8IntNo);
void MNVIC_voidDisableInterrupt  (u8 Copy_u8IntNo);
void MNVIC_voidSetPendingFlag	 (u8 Copy_u8IntNo);
void MNVIC_voidClearPendingFlag  (u8 Copy_u8IntNo);
u8 	 MNVIC_u8GetActiveFlag       (u8 Copy_u8IntNo);


void MNVIC_voidSetPriority		 (s8 Copy_s8IntNo ,
								  u8 Copy_u8GroupPriority ,
								  u8 Copy_u8SubPriority);

void MNVIC_voidSetPendingFlagS(u32 Copy_u8Val);

/* Options for Copy_u8IntNo */

#define NVIC_EXT0                     6
#define NVIC_EXT1                     7
#define NVIC_EXT2                     8
#define NVIC_EXT3                     9
#define NVIC_EXT4                     10
#define NVIC_EXT5_EXT9                23
#define NVIC_EXT10_EXT15              40




#endif
