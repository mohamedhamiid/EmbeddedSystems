/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 15 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"

#include "AFIO_interface.h"
#include "NVIC_interface.h"

static void (*MEXT_CallBack[7])(void);

void MEXTI_voidInitEXTI(EXTI_tCfg * Add_EXTICfg){
	/*	Pin  */
	if(Add_EXTICfg->EXTI_u8Pin<=19){

		/*	Mode  */
		switch(Add_EXTICfg->EXTI_u8Mode){
			case EXTI_RISING  : EXTI->EXTI_RTSR = (1<<Add_EXTICfg->EXTI_u8Pin); break;
			case EXTI_FALLING :	EXTI->EXTI_FTSR = (1<<Add_EXTICfg->EXTI_u8Pin); break;
			case EXTI_ON_EDGE :	EXTI->EXTI_RTSR = (1<<Add_EXTICfg->EXTI_u8Pin);
								EXTI->EXTI_FTSR = (1<<Add_EXTICfg->EXTI_u8Pin);
								break;
//			default : /*  Error : Invalid Mode  */;break;
		}

		CLR_BIT(EXTI->EXTI_IMR , Add_EXTICfg->EXTI_u8Pin);

		/* Port */
		AFIO_voidSetEXTIPin(Add_EXTICfg->EXTI_u8Pin , Add_EXTICfg->EXTI_u8Port);
	}
	else{
		/* Error : Invalid Pin  */
	}
}


void MEXTI_voidDisableEXTI(EXTI_tCfg * Add_EXTICfg){
	/*	Pin  */
	if(Add_EXTICfg->EXTI_u8Pin<=19){

		CLR_BIT(EXTI->EXTI_IMR , Add_EXTICfg->EXTI_u8Pin);

	}

	else{
			/* Error : Invalid Pin  */
	}
}
void MEXTI_voidEnableEXTI(EXTI_tCfg * Add_EXTICfg , void(*Copy_ptr)(void)){
	/*	Pin  */
	if(Add_EXTICfg->EXTI_u8Pin<=19){
		if(Add_EXTICfg->EXTI_u8Pin<=4)
			MEXT_CallBack[Add_EXTICfg->EXTI_u8Pin] = Copy_ptr ;
		else if(Add_EXTICfg->EXTI_u8Pin<=9)
			MEXT_CallBack[5] = Copy_ptr ;
		else if(Add_EXTICfg->EXTI_u8Pin<=15)
			MEXT_CallBack[6] = Copy_ptr ;
		SET_BIT(EXTI->EXTI_IMR , Add_EXTICfg->EXTI_u8Pin);

	}

	else{
			/* Error : Invalid Pin  */
	}

}

void MEXTI_voidSetPendingFlagEXTI  	(EXTI_tCfg * Add_EXTICfg , void(*Copy_ptr)(void)){

	if(Add_EXTICfg->EXTI_u8Pin <= EXTI_PIN15){

		MEXT_CallBack[Add_EXTICfg->EXTI_u8Pin] = Copy_ptr ;
		EXTI->EXTI_PR = (1<<Add_EXTICfg->EXTI_u8Pin);

	}
}
void MEXTI_voidDoSwInterrupt  	 	(EXTI_tCfg * Add_EXTICfg , void(*Func)(void)){
	if(Add_EXTICfg->EXTI_u8Pin <= EXTI_PIN15){
			EXTI->EXTI_SWIER = (1<<Add_EXTICfg->EXTI_u8Pin);
	}
}
void MEXTI_voidResetInterruptFlag  	(u8 Copy_u8Pin){
	SET_BIT(EXTI->EXTI_PR,Copy_u8Pin);
}

/* ISRs */

void EXTI0_IRQHandler(void){

	/* Func */
	MEXT_CallBack[0]();

	/* Reset Flag */
	SET_BIT(EXTI->EXTI_PR,0);
}

void EXTI1_IRQHandler(void){

	/* Func */
	MEXT_CallBack[1]();

	/* Reset Flag */
	SET_BIT(EXTI->EXTI_PR,1);
}
void EXTI2_IRQHandler(void){

	/* Func */
	MEXT_CallBack[2]();

	/* Func */
	SET_BIT(EXTI->EXTI_PR,2);
}
void EXTI3_IRQHandler(void){

	/* Func */
	MEXT_CallBack[3]();

	/* Reset Flag */
	SET_BIT(EXTI->EXTI_PR,3);
}

void EXTI4_IRQHandler(void){

	/* Func */
	MEXT_CallBack[4]();

	/* Reset Flag */
	SET_BIT(EXTI->EXTI_PR,4);
}

void EXTI9_5_IRQHandler(void){
	/* Func */
	MEXT_CallBack[5]();

	/* Reset Flag */
	EXTI->EXTI_PR |= 0x3E0;
}
void EXTI15_10_IRQHandler(void){

	/* Func */
	MEXT_CallBack[6]();

	/* Reset Flag */
	EXTI->EXTI_PR |= 0xFC00;
}





