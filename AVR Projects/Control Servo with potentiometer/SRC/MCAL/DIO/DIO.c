/*
 * DIO.c
 *
 *  Created on: Sep 2, 2022
 *      Author: mh_sm
 */
#include "../../../INCLUDE/MCAL/DIO/DIO_priv.h"
#include "../../../INCLUDE/MCAL/DIO/DIO.h"
#include "../../../SERVICES/bit_utilies.h"

// PORT REGISTER (OUTPUT)
DIO_tenuErrorStatus DIO_enuSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinVal){
	//Error flag
	DIO_tenuErrorStatus LOC_enuErrorStatus = Dio_enuOK;

	// Check if inputs are valid
	if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId<=DIO_u8_PIN7))
	{
		if(Copy_u8PinVal==DIO_u8_HIGH){
			switch(Copy_u8PortId){
			case DIO_u8_PORTA: SET_BIT(PORTA_Register,Copy_u8PinId);break;
			case DIO_u8_PORTB: SET_BIT(PORTB_Register,Copy_u8PinId);break;
			case DIO_u8_PORTC: SET_BIT(PORTC_Register,Copy_u8PinId);break;
			case DIO_u8_PORTD: SET_BIT(PORTD_Register,Copy_u8PinId);break;
			default:/* Wrong ID */ break;
			}
		}

		else if(Copy_u8PinVal==DIO_u8_LOW){
			switch(Copy_u8PortId){
			case DIO_u8_PORTA: CLR_BIT(PORTA_Register,Copy_u8PinId);break;
			case DIO_u8_PORTB: CLR_BIT(PORTB_Register,Copy_u8PinId);break;
			case DIO_u8_PORTC: CLR_BIT(PORTC_Register,Copy_u8PinId);break;
			case DIO_u8_PORTD: CLR_BIT(PORTD_Register,Copy_u8PinId);break;
			default:/* Wrong ID */ break;
			}
		}
	}
	//if there
	else {
		LOC_enuErrorStatus = Dio_enuInvalidInput;
	}
return LOC_enuErrorStatus;
}
//**************************************************************************************************
// DDR function (Direction)
DIO_tenuErrorStatus DIO_enuSetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDir){
	//Error flag
	DIO_tenuErrorStatus LOC_enuErrorStatus = Dio_enuOK;

	// Check if inputs are in valid range
	if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId<=DIO_u8_PIN7))
	{
		if(Copy_u8PinDir==DIO_u8_OUTPUT){
			switch(Copy_u8PortId){
			case DIO_u8_PORTA: SET_BIT(DDRA_Register,Copy_u8PinId);break;
			case DIO_u8_PORTB: SET_BIT(DDRB_Register,Copy_u8PinId);break;
			case DIO_u8_PORTC: SET_BIT(DDRC_Register,Copy_u8PinId);break;
			case DIO_u8_PORTD: SET_BIT(DDRD_Register,Copy_u8PinId);break;
			default:/* Wrong ID */ break;
			}
		}

		else if(Copy_u8PinDir==DIO_u8_INPUT){
			switch(Copy_u8PortId){
			case DIO_u8_PORTA: CLR_BIT(DDRA_Register,Copy_u8PinId);break;
			case DIO_u8_PORTB: CLR_BIT(DDRB_Register,Copy_u8PinId);break;
			case DIO_u8_PORTC: CLR_BIT(DDRC_Register,Copy_u8PinId);break;
			case DIO_u8_PORTD: CLR_BIT(DDRD_Register,Copy_u8PinId);break;
			default:/* Wrong ID */ break;
			}
		}
	}
	//if there
	else {
		LOC_enuErrorStatus = Dio_enuInvalidInput;
	}
return LOC_enuErrorStatus;
}

//**************************************************************************
// Func for PIN REGISTER (INPUT)
DIO_tenuErrorStatus DIO_u8GetPinValue (u8 Copy_u8PortId,u8 Copy_u8PinId, u8*Add_u8Result){
	// Define a LOC variable which store the value
	DIO_tenuErrorStatus LOC_enuErrorStatus = Dio_enuOK;
	// Valid Range
	if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId<=DIO_u8_PIN7))
	{
		switch(Copy_u8PortId){
		case DIO_u8_PORTA: *Add_u8Result=GET_BIT(PINA_Register,Copy_u8PinId);break;
		case DIO_u8_PORTB: *Add_u8Result=GET_BIT(PINB_Register,Copy_u8PinId);break;
		case DIO_u8_PORTC: *Add_u8Result=GET_BIT(PINC_Register,Copy_u8PinId);break;
		case DIO_u8_PORTD: *Add_u8Result=GET_BIT(PIND_Register,Copy_u8PinId);break;
		default:/* Wrong ID */ break;
		}
	}
	else
		LOC_enuErrorStatus = Dio_enuInvalidInput;
return LOC_enuErrorStatus;
}

//*************************************************************************************
// Determine the whole direction of a port
DIO_tenuErrorStatus DIO_enuSetPortDirection(u8 Copy_u8PortId , u8 Copy_u8PortDir){

	    //Error flag
		DIO_tenuErrorStatus LOC_enuErrorStatus = Dio_enuOK;

		// Check if inputs are in valid range
		if(Copy_u8PortId <= DIO_u8_PORTD)
		{
				switch(Copy_u8PortId)
				{
				case DIO_u8_PORTA: DDRA_Register=Copy_u8PortDir;break;
				case DIO_u8_PORTB: DDRB_Register=Copy_u8PortDir;break;
				case DIO_u8_PORTC: DDRC_Register=Copy_u8PortDir;break;
				case DIO_u8_PORTD: DDRD_Register=Copy_u8PortDir;break;
				default:/* Wrong ID */ break;
				}
		}
		//if there IS an error
		else
			LOC_enuErrorStatus = Dio_enuInvalidInput;

return LOC_enuErrorStatus;
}
//*************************************************************************************
// Determine the values of the PORT REG (OUTPUT ONLY)
DIO_tenuErrorStatus DIO_enuSetPortValue(u8 Copy_u8PortId , u8 Copy_u8PortVal){

	    //Error flag
		DIO_tenuErrorStatus LOC_enuErrorStatus = Dio_enuOK;

		// Check if inputs are in valid range
		if(Copy_u8PortId <= DIO_u8_PORTD)
		{
				switch(Copy_u8PortId)
				{
				case DIO_u8_PORTA: PORTA_Register=Copy_u8PortVal;break;
				case DIO_u8_PORTB: PORTB_Register=Copy_u8PortVal;break;
				case DIO_u8_PORTC: PORTC_Register=Copy_u8PortVal;break;
				case DIO_u8_PORTD: PORTD_Register=Copy_u8PortVal;break;
				default:/* Wrong ID */ break;
				}
		}
		//if there IS an error
		else
			LOC_enuErrorStatus = Dio_enuInvalidInput;

return LOC_enuErrorStatus;
}

