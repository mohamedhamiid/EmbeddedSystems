/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 29 / 7 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_priv.h"
#include "DIO_config.h"


void DIO_voidSetPinDirection(u8 Copy_u8PortId ,u8 Copy_u8PinNo ,u8 Copy_u8Direction , u8 Copy_u8Mode){

	pu32 Loc_pu32CurrentCrReg=0;

	/* CHOOSE PIN AND PORT */
	switch(Copy_u8PortId){

		case DIO_PORTA:
			if(Copy_u8PinNo <= DIO_PIN7){

				Loc_pu32CurrentCrReg = GPIOA_CRL ;

				if(Copy_u8Direction == 0 && Copy_u8Mode==DIO_INPUT_PULL_UP)
					GPIOA_BSRR  = (1<<(Copy_u8PinNo)) ;
				else if(Copy_u8Direction == 0 && Copy_u8Mode==DIO_INPUT_PULL_DOWN)
					GPIOA_BRR   = (1<<(Copy_u8PinNo))  ;

				Copy_u8PinNo = (Copy_u8PinNo)  * 4 ;
			}
			else if(Copy_u8PinNo <= DIO_PIN15){

				Loc_pu32CurrentCrReg = GPIOA_CRH ;

				if(Copy_u8Direction == 0 && Copy_u8Mode==DIO_INPUT_PULL_UP)
					GPIOA_BSRR  = (1<<(Copy_u8PinNo)) ;
				else if(Copy_u8Direction == 0 && Copy_u8Mode==DIO_INPUT_PULL_DOWN)
					GPIOA_BRR  = (1<<(Copy_u8PinNo))  ;

				Copy_u8PinNo = (Copy_u8PinNo-8) * 4 ;
			}
			else{
				/* Error : Invalid Pin No */
			}
		break;

		case DIO_PORTB:
			if(Copy_u8PinNo <= DIO_PIN7){

				Loc_pu32CurrentCrReg = GPIOB_CRL ;

				if(Copy_u8Mode==DIO_INPUT_PULL_UP)
					GPIOB_BSRR  = (1<<(Copy_u8PinNo)) ;
				else if(Copy_u8Mode==DIO_INPUT_PULL_DOWN)
					GPIOB_BRR   = (1<<(Copy_u8PinNo))  ;

				Copy_u8PinNo = (Copy_u8PinNo)     * 4 ;
			}
			else if(Copy_u8PinNo <= DIO_PIN15){

				Loc_pu32CurrentCrReg = GPIOB_CRH ;

				if(Copy_u8Mode==DIO_INPUT_PULL_UP)
					GPIOB_BSRR  = (1<<(Copy_u8PinNo)) ;
				else if(Copy_u8Mode==DIO_INPUT_PULL_DOWN)
					GPIOB_BRR  = (1<<(Copy_u8PinNo))  ;

				Copy_u8PinNo = (Copy_u8PinNo-8)   * 4 ;
			}
			else{
				/* Error : Invalid Pin No */
			}
		break;

		case DIO_PORTC:

			if(Copy_u8PinNo <= DIO_PIN15 && Copy_u8PinNo>=DIO_PIN13){

				Loc_pu32CurrentCrReg = GPIOC_CRH ;

				if(Copy_u8Mode==DIO_INPUT_PULL_UP)
					GPIOC_BSRR  = (1<<(Copy_u8PinNo)) ;
				else if(Copy_u8Mode==DIO_INPUT_PULL_DOWN)
					GPIOC_BRR  = (1<<(Copy_u8PinNo))  ;

				Copy_u8PinNo = (Copy_u8PinNo-8)   * 4 ;
			}
			else{
				/* Error : Invalid Pin No */
			}
		break;

		default: /* Error : Invalid Port */
		break;
	}
	/* END OF CHOOSE PIN AND PORT */
	/******************************/

	*Loc_pu32CurrentCrReg &= ~(0xF<<Copy_u8PinNo); /* Reset Pin bits in the register */


	/* CHOOSE DIRECTION */
	if(Copy_u8Direction<=DIO_OUTPUT_50MHZ){
		*Loc_pu32CurrentCrReg |= Copy_u8Direction << (Copy_u8PinNo) ;
	}
	/* END OF CHOOSE DIRECTION */
	/***************************/


	/* Choose Mode */
	/* Output Modes :First condition check that it's output */
	if((Copy_u8Direction > 0) && (Copy_u8Mode <= DIO_OUTPUT_ALTER_FUNC_OPEN_DRAIN)){
		*Loc_pu32CurrentCrReg |= Copy_u8Mode << (Copy_u8PinNo + 2);
	}
	/* Input  Modes :First condition check that it's iutput */
	else if((Copy_u8Direction == 0) && (Copy_u8Mode <= DIO_INPUT_PULL_DOWN)){
		*Loc_pu32CurrentCrReg |= Copy_u8Mode << (Copy_u8PinNo + 2);
	}

} 
void DIO_voidSetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinNo , u8 Copy_u8PinVal){

	switch(Copy_u8PortId){

		case DIO_PORTA:
			if(Copy_u8PinNo<=DIO_PIN15){

				switch(Copy_u8PinVal){
					case DIO_PIN_LOW : GPIOA_BRR  = (1<<Copy_u8PinNo) ;break;
					case DIO_PIN_HIGH: GPIOA_BSRR = (1<<Copy_u8PinNo) ;break;
					default: /* Error Invalid Pin Value */;break;
				}
			}
			else{/* Error Invalid Pin No*/}
		break;
		case DIO_PORTB:
			if(Copy_u8PinNo<=DIO_PIN15){
				switch(Copy_u8PinVal){
					case DIO_PIN_LOW : GPIOB_BRR  = (1<<Copy_u8PinNo) ;break;
					case DIO_PIN_HIGH: GPIOB_BSRR = (1<<Copy_u8PinNo) ;break;
					default: /* Error Invalid Pin Value */;break;
				}
			}
			else{/* Error Invalid Pin No*/}
		break;
		case DIO_PORTC:
			if(Copy_u8PinNo>=DIO_PIN13 && Copy_u8PinNo<=DIO_PIN15){
				switch(Copy_u8PinVal){
					case DIO_PIN_LOW : GPIOC_BRR  = (1<<Copy_u8PinNo) ;break;
					case DIO_PIN_HIGH: GPIOC_BSRR = (1<<Copy_u8PinNo) ;break;
					default: /* Error Invalid Pin Value */;break;
				}
			}
			else{/* Error Invalid Pin No*/}
		break;
	}
}
void DIO_voidSet8BitsValue(u8 Copy_u8PortId ,u8 Copy_u8Start, u8 Copy_u8Val){

	switch(Copy_u8PortId){
		case DIO_PORTA:
			if(Copy_u8Start<=DIO_PIN15){
				if(Copy_u8Start<=8){ /* Make sure that the 8 bits don't exceed the port */
					GPIOA_ODR &= ~(0xFF<<Copy_u8Start); /* Reset the required 8 bits */
					GPIOA_ODR |= (Copy_u8Val<<Copy_u8Start);
				}
			}
			else{/* Error Invalid Pin No*/}
		break;
		case DIO_PORTB:
			if(Copy_u8Start<=DIO_PIN15){
				if(Copy_u8Start<=8){ /* Make sure that the 8 bits don't exceed the port */
					GPIOB_ODR &= ~(0xFF<<Copy_u8Start); /* Reset the required 8 bits */
					GPIOB_ODR |= (Copy_u8Val<<Copy_u8Start);
				}
			}
			else{/* Error Invalid Pin No*/}
		break;
		default: /* Invalid Port */ ;	break;
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinNo){
	switch(Copy_u8PortId){

		case DIO_PORTA:

			if(Copy_u8PinNo<=DIO_PIN15)
				return GET_BIT(GPIOA_IDR,Copy_u8PinNo);
			else{/* Error Invalid Pin No*/}

		break;

		case DIO_PORTB:

			if(Copy_u8PinNo<=DIO_PIN15)
				return GET_BIT(GPIOB_IDR,Copy_u8PinNo);
			else{/* Error Invalid Pin No*/}

		break;

		case DIO_PORTC:
			if(Copy_u8PinNo>=DIO_PIN13 && Copy_u8PinNo<=DIO_PIN15)
				return GET_BIT(GPIOC_IDR,Copy_u8PinNo);
			else{/* Error Invalid Pin No*/}
		break;
		}
	return 0;
}

void DIO_voidLockPin(u8 Copy_u8PortId ,u8 Copy_u8PinNo){
	switch(Copy_u8PortId){

			case DIO_PORTA:

				if(Copy_u8PinNo<=DIO_PIN15)
					SET_BIT(GPIOA_LCKR,Copy_u8PinNo);
				else{/* Error Invalid Pin No*/}

			break;

			case DIO_PORTB:

				if(Copy_u8PinNo<=DIO_PIN15)
					SET_BIT(GPIOB_LCKR,Copy_u8PinNo);
				else{/* Error Invalid Pin No*/}

			break;

			case DIO_PORTC:
				if(Copy_u8PinNo>=DIO_PIN13 && Copy_u8PinNo<=DIO_PIN15)
					SET_BIT(GPIOC_LCKR,Copy_u8PinNo);
				else{/* Error Invalid Pin No*/}
			break;

			}
	}

void DIO_voidUnlockPin(u8 Copy_u8PortId ,u8 Copy_u8PinNo){

	switch(Copy_u8PortId){

			case DIO_PORTA:
				if(Copy_u8PinNo<=DIO_PIN15)
					CLR_BIT(GPIOA_LCKR,Copy_u8PinNo);
				else{/* Error Invalid Pin No*/}
			break;

			case DIO_PORTB:
				if(Copy_u8PinNo<=DIO_PIN15)
					CLR_BIT(GPIOB_LCKR,Copy_u8PinNo);
				else{/* Error Invalid Pin No*/}
			break;

			case DIO_PORTC:
				if(Copy_u8PinNo>=DIO_PIN13 && Copy_u8PinNo<=DIO_PIN15)
					CLR_BIT(GPIOC_LCKR,Copy_u8PinNo);
				else{/* Error Invalid Pin No*/}
			break;

			}
	}

void DIO_voidLockLckReg(u8 Copy_u8PortId){
	switch(Copy_u8PortId){

			case DIO_PORTA:
					SET_BIT(GPIOA_LCKR,16);
					CLR_BIT(GPIOA_LCKR,16);
					SET_BIT(GPIOA_LCKR,16);
			break;

			case DIO_PORTB:
					SET_BIT(GPIOB_LCKR,16);
					CLR_BIT(GPIOB_LCKR,16);
					SET_BIT(GPIOB_LCKR,16);
			break;

			case DIO_PORTC:
					SET_BIT(GPIOC_LCKR,16);
					CLR_BIT(GPIOC_LCKR,16);
					SET_BIT(GPIOC_LCKR,16);
			break;


			}
	}



