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
void MEXTI_voidEnableEXTI(EXTI_tCfg * Add_EXTICfg){
	/*	Pin  */
	if(Add_EXTICfg->EXTI_u8Pin<=19){

		SET_BIT(EXTI->EXTI_IMR , Add_EXTICfg->EXTI_u8Pin);

	}

	else{
			/* Error : Invalid Pin  */
	}

}

void MEXTI_voidSetPendingFlagEXTI  	(EXTI_tCfg * Add_EXTICfg){
	if(Add_EXTICfg->EXTI_u8Pin <= EXTI_PIN15){
		EXTI->EXTI_PR = (1<<Add_EXTICfg->EXTI_u8Pin);
	}
}
void MEXTI_voidDoSwInterrupt  	 	(EXTI_tCfg * Add_EXTICfg){
	if(Add_EXTICfg->EXTI_u8Pin <= EXTI_PIN15){
			EXTI->EXTI_SWIER = (1<<Add_EXTICfg->EXTI_u8Pin);
	}
}
void MEXTI_voidResetInterruptFlag  	(u8 Copy_u8Pin){
	SET_BIT(EXTI->EXTI_PR,Copy_u8Pin);
}



