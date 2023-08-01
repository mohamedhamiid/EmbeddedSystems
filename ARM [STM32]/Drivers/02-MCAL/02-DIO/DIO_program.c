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
	/* Choose Port */
	switch(Copy_u8PortId){
		case DIO_PORTA:
		
			/* Choose Pins */
			if(Copy_u8PinNo<=DIO_PIN7){
				GPIOA_CRL &= ~(0xF<<Copy_u8PinNo*4); /* Reset Pin bits in the register */
				/* Choose Direction */
				switch(Copy_u8Direction){
					case DIO_INPUT :
						GPIOA_CRL |= ((0b00)<<(Copy_u8PinNo*4));
					break;
						
					case DIO_OUTPUT_2MHZ :
						GPIOA_CRL |= (0b10<<Copy_u8PinNo*4);
					break;
					
					case DIO_OUTPUT_10MHZ :
						GPIOA_CRL |= ((0b01)<<(Copy_u8PinNo*4));
					break;
					
					case DIO_OUTPUT_50MHZ :
						GPIOA_CRL |= ((0b11)<<(Copy_u8PinNo*4));
					break;

					default: /* Error Invalid Direction*/ ; break; 
				}
				/* End of Choose Direction */
				/***************************/

				/* Choose Mode */
				if((GPIOA_CRL & (0x3<<Copy_u8PinNo*4))>0){ /* Check it's OUTPUT */
					switch(Copy_u8Mode){
						case DIO_OUTPUT_PUSH_PULL:
							GPIOA_CRL |= ((0b00)<<((Copy_u8PinNo*4)+2));
						break;
						case DIO_OUTPUT_OPEN_DRAIN:
							GPIOA_CRL |= ((0b01)<<((Copy_u8PinNo*4)+2));
						break;

						case DIO_OUTPUT_ALTER_FUNC_PUSH_PULL:
							GPIOA_CRL |= ((0b10)<<((Copy_u8PinNo*4)+2));
						break;
						case DIO_OUTPUT_ALTER_FUNC_OPEN_DRAIN:
							GPIOA_CRL |= ((0b11)<<((Copy_u8PinNo*4)+2));
						break;

						default:/* Error : Invalid Mode */ ; break;
					}
				}
				else{ /*It's INPUT */
					switch(Copy_u8Mode){
						case DIO_INPUT_ANALOG:
							GPIOA_CRL |= ((0b00)<<((Copy_u8PinNo*4)+2));
						break;
						case DIO_INPUT_FLOATING:
							GPIOA_CRL |= ((0b01)<<((Copy_u8PinNo*4)+2));
						break;
						case DIO_INPUT_PULL_UP:
							GPIOA_CRL |= ((0b10)<<((Copy_u8PinNo*4)+2));
							SET_BIT(GPIOA_ODR,Copy_u8PinNo);
						break;
						case DIO_INPUT_PULL_DOWN:
							GPIOA_CRL |= ((0b10)<<((Copy_u8PinNo*4)+2));
							CLR_BIT(GPIOA_ODR,Copy_u8PinNo);
						break;

						default:/* Error : Invalid Mode */ ; break;
					}
				}
				/* End of Choose Mode */
				/**********************/
			}
			else if(Copy_u8PinNo<=DIO_PIN15){
				GPIOA_CRH &= ~(0xF<<(Copy_u8PinNo-8)*4); /* Reset Pin bits in the register */
				/* Choose Direction */
				switch(Copy_u8Direction){

					case DIO_INPUT :
						GPIOA_CRH |= ((0b00)<<((Copy_u8PinNo-8)*4));
					break;
						
					case DIO_OUTPUT_2MHZ :
						GPIOA_CRH |= ((0b10)<<((Copy_u8PinNo-8)*4));
					break;
					
					case DIO_OUTPUT_10MHZ :
						GPIOA_CRH |= ((0b01)<<((Copy_u8PinNo-8)*4));
					break;
					
					case DIO_OUTPUT_50MHZ :
						GPIOA_CRH |= ((0b11)<<((Copy_u8PinNo-8)*4));
					break;

					default: /* Error Invalid Direction*/ ; break; 
				}
				/* End of Choose Direction */
				/***************************/

				/* Choose Mode */
				if((GPIOA_CRH & (0x3<<(Copy_u8PinNo-8)*4))>0){
				switch(Copy_u8Mode){

					case DIO_OUTPUT_PUSH_PULL:
						GPIOA_CRH |= ((0b00)<<(((Copy_u8PinNo-8)*4)+2));
					break;

					case DIO_OUTPUT_OPEN_DRAIN:
						GPIOA_CRH |= ((0b01)<<(((Copy_u8PinNo-8)*4)+2));
					break;

					case DIO_OUTPUT_ALTER_FUNC_PUSH_PULL:
						GPIOA_CRH |= ((0b10)<<(((Copy_u8PinNo-8)*4)+2));
					break;

					case DIO_OUTPUT_ALTER_FUNC_OPEN_DRAIN:
						GPIOA_CRH |= ((0b11)<<(((Copy_u8PinNo-8)*4)+2));
					break;

					default:/* Error : Invalid Mode */ ; break;
				}
			}
			else{

				switch(Copy_u8Mode){
					case DIO_INPUT_ANALOG:
						GPIOA_CRH |= ((0b00)<<(((Copy_u8PinNo-8)*4)+2));
					break;
					case DIO_INPUT_FLOATING:
						GPIOA_CRH |= ((0b01)<<(((Copy_u8PinNo-8)*4)+2));
					break;
					case DIO_INPUT_PULL_UP:
						GPIOA_CRH |= ((0b10)<<(((Copy_u8PinNo-8)*4)+2));
						SET_BIT(GPIOA_ODR,Copy_u8PinNo);
					break;
					case DIO_INPUT_PULL_DOWN:
						GPIOA_CRH |= ((0b10)<<(((Copy_u8PinNo-8)*4)+2));
						CLR_BIT(GPIOA_ODR,Copy_u8PinNo);
					break;

					default:/* Error : Invalid Mode */ ; break;
				}
			}
			/* End of Choose Mode */
			/**********************/

			}
			else{/* Error: Invalid Pin No */}
			/* End of Choose Pins */
			/**********************/
		break;
		
		case DIO_PORTB:

			/* Choose Pins */
			if(Copy_u8PinNo<=DIO_PIN7){
				GPIOB_CRL &= ~(0xF<<(Copy_u8PinNo*4)); /* Reset Pin bits in the register */

				/* Choose Direction */
				switch(Copy_u8Direction){

					case DIO_INPUT :
						GPIOB_CRL |= ((0b00)<<(Copy_u8PinNo*4));
					break;
						
					case DIO_OUTPUT_2MHZ :
						GPIOB_CRL |= ((0b10)<<(Copy_u8PinNo*4));
					break;
					
					case DIO_OUTPUT_10MHZ :
						GPIOB_CRL |= ((0b01)<<(Copy_u8PinNo*4));
					break;
					
					case DIO_OUTPUT_50MHZ :
						GPIOB_CRL |= ((0b11)<<(Copy_u8PinNo*4));
					break;

					default: /* Error Invalid Direction*/ ; break; 
				}
				/* End of Choose Direction */
				/***************************/

				/* Choose Mode */
				if((GPIOB_CRL & (0x3<<(Copy_u8PinNo*4)))>0){
					switch(Copy_u8Mode){
						case DIO_OUTPUT_PUSH_PULL:
							GPIOB_CRL |= ((0b00)<<((Copy_u8PinNo*4)+2));
						break;

						case DIO_OUTPUT_OPEN_DRAIN:
							GPIOB_CRL |= ((0b01)<<((Copy_u8PinNo*4)+2));
						break;

						case DIO_OUTPUT_ALTER_FUNC_PUSH_PULL:
							GPIOB_CRL |= ((0b10)<<((Copy_u8PinNo*4)+2));
						break;
						case DIO_OUTPUT_ALTER_FUNC_OPEN_DRAIN:
							GPIOB_CRL |= ((0b11)<<((Copy_u8PinNo*4)+2));
						break;

						default:/* Error : Invalid Mode */ ; break;
					}
				}
				else{
					switch(Copy_u8Mode){
						case DIO_INPUT_ANALOG:
							GPIOB_CRL |= ((0b00)<<((Copy_u8PinNo*4)+2));
						break;
						case DIO_INPUT_FLOATING:
							GPIOB_CRL |= ((0b01)<<((Copy_u8PinNo*4)+2));
						break;
						case DIO_INPUT_PULL_UP:
							GPIOB_CRL |= ((0b10)<<((Copy_u8PinNo*4)+2));
							SET_BIT(GPIOB_ODR,Copy_u8PinNo);
						break;
						case DIO_INPUT_PULL_DOWN:
							GPIOB_CRL |= ((0b10)<<((Copy_u8PinNo*4)+2));
							CLR_BIT(GPIOB_ODR,Copy_u8PinNo);

						break;

						default:/* Error : Invalid Mode */ ; break;
					}
				}
				/* End of Choose Mode */
				/**********************/
			}
			else if(Copy_u8PinNo<=DIO_PIN15){
				GPIOB_CRH &= ~(0xF<<(Copy_u8PinNo-8)*4); /* Reset Pin bits in the register */

				/* Choose Direction */
				switch(Copy_u8Direction){

					case DIO_INPUT :
						GPIOB_CRH |= ((0b00)<<((Copy_u8PinNo-8)*4));
					break;
						
					case DIO_OUTPUT_2MHZ :
						GPIOB_CRH |= ((0b10)<<((Copy_u8PinNo-8)*4));
					break;
					
					case DIO_OUTPUT_10MHZ :
						GPIOB_CRH |= ((0b01)<<((Copy_u8PinNo-8)*4));
					break;
					
					case DIO_OUTPUT_50MHZ :
						GPIOB_CRH |= ((0b11)<<((Copy_u8PinNo-8)*4));
					break;

					default: /* Error Invalid Direction*/ ; break; 
				}
				/* End of Choose Direction */
				/***************************/
				if((GPIOB_CRH & (0x3<<(Copy_u8PinNo-8)*4))>0){
					switch(Copy_u8Mode){

						case DIO_OUTPUT_PUSH_PULL:
							GPIOB_CRH |= ((0b00)<<(((Copy_u8PinNo-8)*4)+2));
						break;

						case DIO_OUTPUT_OPEN_DRAIN:
							GPIOB_CRH |= ((0b01)<<(((Copy_u8PinNo-8)*4)+2));
						break;

						case DIO_OUTPUT_ALTER_FUNC_PUSH_PULL:
							GPIOB_CRH |= ((0b10)<<(((Copy_u8PinNo-8)*4)+2));
						break;

						case DIO_OUTPUT_ALTER_FUNC_OPEN_DRAIN:
							GPIOB_CRH |= ((0b11)<<(((Copy_u8PinNo-8)*4)+2));
						break;

						default:/* Error : Invalid Mode */ ; break;
					}
				}

				else{

					switch(Copy_u8Mode){

						case DIO_INPUT_ANALOG:
							GPIOB_CRH |= ((0b00)<<(((Copy_u8PinNo-8)*4)+2));
						break;

						case DIO_INPUT_FLOATING:
							GPIOB_CRH |= ((0b01)<<(((Copy_u8PinNo-8)*4)+2));
						break;


						case DIO_INPUT_PULL_UP:
							GPIOB_CRH |= ((0b10)<<(((Copy_u8PinNo-8)*4)+2));
							SET_BIT(GPIOB_ODR,Copy_u8PinNo);
						break;

						case DIO_INPUT_PULL_DOWN:
							GPIOB_CRH |= ((0b10)<<(((Copy_u8PinNo-8)*4)+2));
							CLR_BIT(GPIOB_ODR,Copy_u8PinNo);
						break;

						default:/* Error : Invalid Mode */ ; break;
					}
				}
				/* End of Choose Mode */
				/**********************/
			}
			else{/* Error: Invalid Pin No */}
			/* End of Choose Pins */
			/**********************/
		break;
		
		case DIO_PORTC:
			GPIOC_CRL &= ~(0xF<<(Copy_u8PinNo-8)*4); /* Reset Pin bits in the register */

			/* Choose Pins */
			if(Copy_u8PinNo<=DIO_PIN15 && Copy_u8PinNo>=DIO_PIN13){
				GPIOC_CRH &= ~(0xF<<(Copy_u8PinNo-8)*4); /* Reset Pin bits in the register */
				/* Choose Direction */
				switch(Copy_u8Direction){
					case DIO_INPUT :
						GPIOC_CRH |= ((0b00)<<((Copy_u8PinNo-8)*4));
					break;

					case DIO_OUTPUT_2MHZ :
						GPIOC_CRH |= ((0b10)<<((Copy_u8PinNo-8)*4));
					break;
					
					case DIO_OUTPUT_10MHZ :
						GPIOC_CRH |= ((0b01)<<((Copy_u8PinNo-8)*4));
					break;
					
					case DIO_OUTPUT_50MHZ :
						GPIOC_CRH |= ((0b11)<<((Copy_u8PinNo-8)*4));
					break;

					default: /* Error Invalid Direction*/ ; break; 
				}
				/* End of Choose Direction */
				/***************************/

				/* Choose Mode */
				if((GPIOC_CRH & (0x3<<(Copy_u8PinNo-8)*4))>0){ /* Check it's OUTPUT */
					switch(Copy_u8Mode){
						case DIO_OUTPUT_PUSH_PULL:
							GPIOC_CRH |= ((0b00)<<(((Copy_u8PinNo-8)*4)+2));
						break;
						case DIO_OUTPUT_OPEN_DRAIN:
							GPIOC_CRH |= ((0b01)<<(((Copy_u8PinNo-8)*4)+2));
						break;

						case DIO_OUTPUT_ALTER_FUNC_PUSH_PULL:
							GPIOC_CRH |= ((0b10)<<(((Copy_u8PinNo-8)*4)+2));
						break;
						case DIO_OUTPUT_ALTER_FUNC_OPEN_DRAIN:
							GPIOC_CRH |= ((0b11)<<(((Copy_u8PinNo-8)*4)+2));
						break;
						default:/* Error : Invalid Mode */ ; break;
					}
				}

				else{ // It's Input

					switch(Copy_u8Mode){
						case DIO_INPUT_ANALOG:
							GPIOC_CRH |= ((0b00)<<(((Copy_u8PinNo-8)*4)+2));
						break;
						case DIO_INPUT_FLOATING:
							GPIOC_CRH |= ((0b01)<<(((Copy_u8PinNo-8)*4)+2));
						break;

						case DIO_INPUT_PULL_UP:
							GPIOC_CRH |= ((0b10)<<((Copy_u8PinNo*4)+2));
							SET_BIT(GPIOC_ODR,Copy_u8PinNo);
						break;
						case DIO_INPUT_PULL_DOWN:
							GPIOC_CRH |= ((0b10)<<((Copy_u8PinNo*4)+2));
							CLR_BIT(GPIOC_ODR,Copy_u8PinNo);
						break;

						default:/* Error : Invalid Mode */ ; break;
				}
					/* End of Choose Mode */
					/**********************/
				}
			}
			else{/* Error: Invalid Pin No */}
			/* End of Choose Pins */
			/**********************/
		break;
		
		default: /* Error Invalid Port */ ; break;
	}
	/* End of Choose Ports */
	/***********************/
} 
void DIO_voidSetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinNo , u8 Copy_u8PinVal){
	switch(Copy_u8PortId){
		case DIO_PORTA:
			if(Copy_u8PinNo>=DIO_PIN0 && Copy_u8PinNo<=DIO_PIN15){
				switch(Copy_u8PinVal){
					case DIO_PIN_LOW : CLR_BIT(GPIOA_ODR,Copy_u8PinNo);break;
					case DIO_PIN_HIGH: SET_BIT(GPIOA_ODR,Copy_u8PinNo);break;
					default: /* Error Invalid Pin Value */;break;
				}
			}
			else{/* Error Invalid Pin No*/}
		break;
		case DIO_PORTB:
			if(Copy_u8PinNo>=DIO_PIN0 && Copy_u8PinNo<=DIO_PIN15){
				switch(Copy_u8PinVal){
					case DIO_PIN_LOW : CLR_BIT(GPIOB_ODR,Copy_u8PinNo);break;
					case DIO_PIN_HIGH: SET_BIT(GPIOB_ODR,Copy_u8PinNo);break;
					default: /* Error Invalid Pin Value */;break;
				}
			}
			else{/* Error Invalid Pin No*/}
		break;
		case DIO_PORTC:
			if(Copy_u8PinNo>=DIO_PIN13 && Copy_u8PinNo<=DIO_PIN15){
				switch(Copy_u8PinVal){
					case DIO_PIN_LOW : CLR_BIT(GPIOC_ODR,Copy_u8PinNo);break;
					case DIO_PIN_HIGH: /* Error can't give source current */ ;break;
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
			if(Copy_u8Start>=DIO_PIN0 && Copy_u8Start<=DIO_PIN15){
				if(Copy_u8Start<=8){ /* Make sure that the 8 bits don't exceed the port */
					GPIOA_ODR &= ~(0xFF<<Copy_u8Start); /* Reset the required 8 bits */
					GPIOA_ODR |= (Copy_u8Val<<Copy_u8Start);
				}
			}
			else{/* Error Invalid Pin No*/}
		break;
		case DIO_PORTB:
			if(Copy_u8Start>=DIO_PIN0 && Copy_u8Start<=DIO_PIN15){
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

			if(Copy_u8PinNo>=DIO_PIN0 && Copy_u8PinNo<=DIO_PIN15)
				return GET_BIT(GPIOA_IDR,Copy_u8PinNo);
			else{/* Error Invalid Pin No*/}

		break;

		case DIO_PORTB:

			if(Copy_u8PinNo>=DIO_PIN0 && Copy_u8PinNo<=DIO_PIN15)
				return GET_BIT(GPIOB_IDR,Copy_u8PinNo);
			else{/* Error Invalid Pin No*/}

		break;

		case DIO_PORTC:
			if(Copy_u8PinNo>=DIO_PIN13 && Copy_u8PinNo<=DIO_PIN15)
				return GET_BIT(GPIOC_IDR,Copy_u8PinNo);
			else{/* Error Invalid Pin No*/}
		break;


		}
}
