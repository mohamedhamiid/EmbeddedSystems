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


void MDIO_voidSetPinDirection(MDIO_enumPorts Copy_enumPortId ,
							 MDIO_enumPins Copy_enumPinNo ,
							 u8 Copy_u8Direction ,
							 u8 Copy_u8Mode){

	pu32 Loc_pu32CurrentCrReg=0;

	/* CHOOSE PIN AND PORT */
	switch(Copy_enumPortId){

		case PORTA:
			if(Copy_enumPinNo <= PIN7){

				Loc_pu32CurrentCrReg = GPIOA_CRL ;

				if(Copy_u8Direction == 0 && Copy_u8Mode==MDIO_MODE_INPUT_PULL_UP)
					GPIOA_BSRR  = (1<<(Copy_enumPinNo)) ;
				else if(Copy_u8Direction == 0 && Copy_u8Mode==MDIO_MODE_INPUT_PULL_DOWN)
					GPIOA_BRR   = (1<<(Copy_enumPinNo))  ;

				Copy_enumPinNo = (Copy_enumPinNo)  * 4 ;
			}
			else if(Copy_enumPinNo <= PIN15){

				Loc_pu32CurrentCrReg = GPIOA_CRH ;

				if(Copy_u8Direction == 0 && Copy_u8Mode==MDIO_MODE_INPUT_PULL_UP)
					GPIOA_BSRR  = (1<<(Copy_enumPinNo)) ;
				else if(Copy_u8Direction == 0 && Copy_u8Mode==MDIO_MODE_INPUT_PULL_DOWN)
					GPIOA_BRR  = (1<<(Copy_enumPinNo))  ;

				Copy_enumPinNo = (Copy_enumPinNo-8) * 4 ;
			}
			else{
				/* Error : Invalid Pin No */
			}
		break;

		case PORTB:
			if(Copy_enumPinNo <= PIN7){

				Loc_pu32CurrentCrReg = GPIOB_CRL ;

				if(Copy_u8Mode==MDIO_MODE_INPUT_PULL_UP)
					GPIOB_BSRR  = (1<<(Copy_enumPinNo)) ;
				else if(Copy_u8Mode==MDIO_MODE_INPUT_PULL_DOWN)
					GPIOB_BRR   = (1<<(Copy_enumPinNo))  ;

				Copy_enumPinNo = (Copy_enumPinNo)     * 4 ;
			}
			else if(Copy_enumPinNo <= PIN15){

				Loc_pu32CurrentCrReg = GPIOB_CRH ;

				if(Copy_u8Mode==MDIO_MODE_INPUT_PULL_UP)
					GPIOB_BSRR  = (1<<(Copy_enumPinNo)) ;
				else if(Copy_u8Mode==MDIO_MODE_INPUT_PULL_DOWN)
					GPIOB_BRR  = (1<<(Copy_enumPinNo))  ;

				Copy_enumPinNo = (Copy_enumPinNo-8)   * 4 ;
			}
			else{
				/* Error : Invalid Pin No */
			}
		break;

		case PORTC:

			if(Copy_enumPinNo <= PIN15 && Copy_enumPinNo>=PIN13){

				Loc_pu32CurrentCrReg = GPIOC_CRH ;

				if(Copy_u8Mode==MDIO_MODE_INPUT_PULL_UP)
					GPIOC_BSRR  = (1<<(Copy_enumPinNo)) ;
				else if(Copy_u8Mode==MDIO_MODE_INPUT_PULL_DOWN)
					GPIOC_BRR  = (1<<(Copy_enumPinNo))  ;

				Copy_enumPinNo = (Copy_enumPinNo-8)   * 4 ;
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

	*Loc_pu32CurrentCrReg &= ~(0xF<<Copy_enumPinNo); /* Reset Pin bits in the register */


	/* CHOOSE DIRECTION */
	if(Copy_u8Direction<=MDIO_DIRECTION_OUTPUT_50MHZ){
		*Loc_pu32CurrentCrReg |= Copy_u8Direction << (Copy_enumPinNo) ;
	}
	/* END OF CHOOSE DIRECTION */
	/***************************/


	/* Choose Mode */
	/* Output Modes :First condition check that it's output */
	if((Copy_u8Direction > 0) && (Copy_u8Mode <= MDIO_MODE_OUTPUT_ALTER_FUNC_OPEN_DRAIN)){
		*Loc_pu32CurrentCrReg |= Copy_u8Mode << (Copy_enumPinNo + 2);
	}
	/* Input  Modes :First condition check that it's iutput */
	else if((Copy_u8Direction == 0) && (Copy_u8Mode <= MDIO_MODE_INPUT_PULL_DOWN)){
		*Loc_pu32CurrentCrReg |= Copy_u8Mode << (Copy_enumPinNo + 2);
	}

} 
void DIO_voidSetPinValue(MDIO_enumPorts Copy_enumPortId ,MDIO_enumPins Copy_enumPinNo , u8 Copy_u8PinVal){

	switch(Copy_enumPortId){

		case PORTA:
			if(Copy_enumPinNo<=PIN15){

				switch(Copy_u8PinVal){
					case MDIO_PIN_LOW : GPIOA_BRR  = (1<<Copy_enumPinNo) ;break;
					case MDIO_PIN_HIGH: GPIOA_BSRR = (1<<Copy_enumPinNo) ;break;
					default: /* Error Invalid Pin Value */;break;
				}
			}
			else{/* Error Invalid Pin No*/}
		break;
		case PORTB:
			if(Copy_enumPinNo<=PIN15){
				switch(Copy_u8PinVal){
					case MDIO_PIN_LOW : GPIOB_BRR  = (1<<Copy_enumPinNo) ;break;
					case MDIO_PIN_HIGH: GPIOB_BSRR = (1<<Copy_enumPinNo) ;break;
					default: /* Error Invalid Pin Value */;break;
				}
			}
			else{/* Error Invalid Pin No*/}
		break;
		case PORTC:
			if(Copy_enumPinNo>=PIN13 && Copy_enumPinNo<=PIN15){
				switch(Copy_u8PinVal){
					case MDIO_PIN_LOW : GPIOC_BRR  = (1<<Copy_enumPinNo) ;break;
					case MDIO_PIN_HIGH: GPIOC_BSRR = (1<<Copy_enumPinNo) ;break;
					default: /* Error Invalid Pin Value */;break;
				}
			}
			else{/* Error Invalid Pin No*/}
		break;
	}
}
void DIO_voidSet8BitsValue(MDIO_enumPorts Copy_enumPortId ,MDIO_enumPins Copy_u8Start, u8 Copy_u8Val){

	switch(Copy_enumPortId){
		case PORTA:
			if(Copy_u8Start<=PIN15){
				if(Copy_u8Start<=8){ /* Make sure that the 8 bits don't exceed the port */
					GPIOA_ODR &= ~(0xFF<<Copy_u8Start); /* Reset the required 8 bits */
					GPIOA_ODR |= (Copy_u8Val<<Copy_u8Start);
				}
			}
			else{/* Error Invalid Pin No*/}
		break;
		case PORTB:
			if(Copy_u8Start<=PIN15){
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

u8 DIO_u8GetPinValue(MDIO_enumPorts Copy_enumPortId ,MDIO_enumPins Copy_enumPinNo){
	switch(Copy_enumPortId){

		case PORTA:

			if(Copy_enumPinNo<=PIN15)
				return GET_BIT(GPIOA_IDR,Copy_enumPinNo);
			else{/* Error Invalid Pin No*/}

		break;

		case PORTB:

			if(Copy_enumPinNo<=PIN15)
				return GET_BIT(GPIOB_IDR,Copy_enumPinNo);
			else{/* Error Invalid Pin No*/}

		break;

		case PORTC:
			if(Copy_enumPinNo>=PIN13 && Copy_enumPinNo<=PIN15)
				return GET_BIT(GPIOC_IDR,Copy_enumPinNo);
			else{/* Error Invalid Pin No*/}
		break;
		}
	return 0;
}

void DIO_voidLockPin(u8 Copy_enumPortId ,u8 Copy_enumPinNo){
	switch(Copy_enumPortId){

			case PORTA:

				if(Copy_enumPinNo<=PIN15)
					SET_BIT(GPIOA_LCKR,Copy_enumPinNo);
				else{/* Error Invalid Pin No*/}

			break;

			case PORTB:

				if(Copy_enumPinNo<=PIN15)
					SET_BIT(GPIOB_LCKR,Copy_enumPinNo);
				else{/* Error Invalid Pin No*/}

			break;

			case PORTC:
				if(Copy_enumPinNo>=PIN13 && Copy_enumPinNo<=PIN15)
					SET_BIT(GPIOC_LCKR,Copy_enumPinNo);
				else{/* Error Invalid Pin No*/}
			break;

			}
	}

void DIO_voidUnlockPin(u8 Copy_enumPortId ,u8 Copy_enumPinNo){

	switch(Copy_enumPortId){

			case PORTA:
				if(Copy_enumPinNo<=PIN15)
					CLR_BIT(GPIOA_LCKR,Copy_enumPinNo);
				else{/* Error Invalid Pin No*/}
			break;

			case PORTB:
				if(Copy_enumPinNo<=PIN15)
					CLR_BIT(GPIOB_LCKR,Copy_enumPinNo);
				else{/* Error Invalid Pin No*/}
			break;

			case PORTC:
				if(Copy_enumPinNo>=PIN13 && Copy_enumPinNo<=PIN15)
					CLR_BIT(GPIOC_LCKR,Copy_enumPinNo);
				else{/* Error Invalid Pin No*/}
			break;

			}
	}

void DIO_voidLockLckReg(u8 Copy_enumPortId){
	switch(Copy_enumPortId){

			case PORTA:
					SET_BIT(GPIOA_LCKR,16);
					CLR_BIT(GPIOA_LCKR,16);
					SET_BIT(GPIOA_LCKR,16);
			break;

			case PORTB:
					SET_BIT(GPIOB_LCKR,16);
					CLR_BIT(GPIOB_LCKR,16);
					SET_BIT(GPIOB_LCKR,16);
			break;

			case PORTC:
					SET_BIT(GPIOC_LCKR,16);
					CLR_BIT(GPIOC_LCKR,16);
					SET_BIT(GPIOC_LCKR,16);
			break;


			}
	}



