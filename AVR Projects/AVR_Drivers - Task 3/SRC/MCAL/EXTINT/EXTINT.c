/*
 * EXTINT.c
 *
 *  Created on: Sep 20, 2022
 *      Author: mh_sm
 */
#include "../../../INCLUDE/MCAL/EXTINT/EXTINT_priv.h"
#include "../../../INCLUDE/MCAL/EXTINT/EXTINT.h"
#include "../../../INCLUDE/MCAL/DIO/DIO.h"
#include"../../../SERVICES/bit_utilies.h"
#include"../../../SERVICES/std_types.h"
#include "../../../INCLUDE/MCAL/GIE/GIE.h"
void EXTINT_voidEnable(EXTINT_structCfg*Add_ExtInt){

	GIE_voidGlobalInterruptEnable();

	///////////////////////// INPUT (EXTERNAL) \\\\\\\\\\\\\\\\\\\\\\\\\\\

	switch(Add_ExtInt->IntNo){
	case EXTINT_INT0: DIO_enuSetPinDirection(DIO_u8_PORTD ,DIO_u8_PIN2,DIO_u8_INPUT);break;
	case EXTINT_INT1: DIO_enuSetPinDirection(DIO_u8_PORTD ,DIO_u8_PIN3,DIO_u8_INPUT);break;
	case EXTINT_INT2: DIO_enuSetPinDirection(DIO_u8_PORTB ,DIO_u8_PIN2,DIO_u8_INPUT);break;
	}

	///////////////////////////// SETMODE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	switch(Add_ExtInt->IntNo){

	case EXTINT_INT0:
		switch(Add_ExtInt->IntMode){
	case EXTINT_RISING_EDGE     :SET_BIT(MCUCR,1);SET_BIT(MCUCR,0);break;
	case EXTINT_FALLING_EDGE    :SET_BIT(MCUCR,1);CLR_BIT(MCUCR,0);break;
	case EXTINT_LOGICAL_CHANGE  :CLR_BIT(MCUCR,1);SET_BIT(MCUCR,0);break;
	case EXTINT_LOW_LEVEL       :SET_BIT(MCUCR,1);SET_BIT(MCUCR,0);break;
		}
	break;

	case EXTINT_INT1:
		switch(Add_ExtInt->IntMode){
	case EXTINT_RISING_EDGE     :SET_BIT(MCUCR,3);SET_BIT(MCUCR,2);break;
	case EXTINT_FALLING_EDGE    :SET_BIT(MCUCR,3);CLR_BIT(MCUCR,2);break;
	case EXTINT_LOGICAL_CHANGE  :CLR_BIT(MCUCR,3);SET_BIT(MCUCR,2);break;
	case EXTINT_LOW_LEVEL       :SET_BIT(MCUCR,3);SET_BIT(MCUCR,2);break;
		}
	break;

	case EXTINT_INT2:
		switch(Add_ExtInt->IntMode){
	case EXTINT_RISING_EDGE     :SET_BIT(MCUCSR,6);break;
	case EXTINT_FALLING_EDGE    :CLR_BIT(MCUCSR,6);break;
		}
	break;
	}

	//////////////////// PIE ON \\\\\\\\\\\\\\\\\\\\\\\\\\\

	switch(Add_ExtInt->IntNo){
		case EXTINT_INT0: SET_BIT(GICR,6);break;
		case EXTINT_INT1: SET_BIT(GICR,7);break;
		case EXTINT_INT2: SET_BIT(GICR,5);break;
		}

	//

}
void EXTINT_voidDisable(EXTINT_structCfg*Add_ExtInt){

	//////////////////// PIE OFF \\\\\\\\\\\\\\\\\\\\\\\\\\\

	switch(Add_ExtInt->IntNo){
		case EXTINT_INT0: CLR_BIT(GICR,6);break;
		case EXTINT_INT1: CLR_BIT(GICR,7);break;
		case EXTINT_INT2: CLR_BIT(GICR,5);break;
		}

}

