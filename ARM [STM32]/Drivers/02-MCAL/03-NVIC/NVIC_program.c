/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 14 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_priv.h"
#include "NVIC_config.h"


void MNVIC_voidInit(){
#define SCB_AIRCR *((volatile u32*)0xE000ED0C)
	SCB_AIRCR =  MNVIC_PRIORITY_BINARY_POINT ;
}

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNo){
	if(Copy_u8IntNo<=31){
		NVIC_ISER0 = (1<<Copy_u8IntNo);
	}
	else if(Copy_u8IntNo<=59){
		NVIC_ISER1 = (1<<(Copy_u8IntNo-32));
	}
	else{
		/* Error : Invalid Interrupt No */
	}
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNo){
	if(Copy_u8IntNo<=31){
		NVIC_ICER0 = (1<<Copy_u8IntNo);
	}
	else if(Copy_u8IntNo<=59){
		NVIC_ICER1 = (1<<(Copy_u8IntNo-32));
	}
	else{
		/* Error : Invalid Interrupt No */
	}
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNo){
	if(Copy_u8IntNo<=31){
		NVIC_ISPR0 = (1<<Copy_u8IntNo);
	}
	else if(Copy_u8IntNo<=59){
		NVIC_ISPR1 = (1<<(Copy_u8IntNo-32));
	}
	else{
		/* Error : Invalid Interrupt No */
	}
}
/**************** For Testing ******************/
void MNVIC_voidSetPendingFlagS(u32 Copy_u8Val){

		NVIC_ISPR0 = Copy_u8Val;
}
/************************************************/
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNo){
	if(Copy_u8IntNo<=31){
		NVIC_ICPR0 = (1<<Copy_u8IntNo);
	}
	else if(Copy_u8IntNo<=59){
		NVIC_ICPR1 = (1<<(Copy_u8IntNo-32));
	}
	else{
		/* Error : Invalid Interrupt No */
	}
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNo){
	u8 Loc_u8Temp=0;
	if(Copy_u8IntNo<=31){
		Loc_u8Temp = GET_BIT(NVIC_IABR0 , Copy_u8IntNo);
	}
	else if(Copy_u8IntNo<=59){
		Loc_u8Temp = GET_BIT(NVIC_IABR1 , (Copy_u8IntNo-32));
	}
	else{
		/* Error : Invalid Interrupt No */
	}
	return Loc_u8Temp ;
}

void MNVIC_voidSetPriority(s8 Copy_s8IntNo ,
						   u8 Copy_u8GroupPriority ,
						   u8 Copy_u8SubPriority){

	u8 Loc_u8BinaryPoint = Copy_u8SubPriority |
						   (Copy_u8GroupPriority<<
						   ((MNVIC_PRIORITY_BINARY_POINT - NVIC_GROUP_4_SUB_0)/0x100));

	if(Copy_s8IntNo < 0){
		/* Core Peripheral */
	}
	else if(Copy_s8IntNo >= 0 && Copy_s8IntNo <= 59){
		NVIC_IPR[Copy_s8IntNo] = Loc_u8BinaryPoint << 4 ;
	}
	else{
		/* Error : Invalid Int No */
	}

}


