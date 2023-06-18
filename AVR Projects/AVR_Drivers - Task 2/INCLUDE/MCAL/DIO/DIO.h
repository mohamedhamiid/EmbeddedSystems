/*
 * DIO.h
 *
 *  Created on: Sep 2, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_MCAL_DIO_DIO_H_
#define INCLUDE_MCAL_DIO_DIO_H_

#include "../../../SERVICES/std_types.h"

/* enum for errors*/
typedef enum{
	Dio_enuOK,
	Dio_enuInvalidInput
}DIO_tenuErrorStatus;

/*Port Defines*/
#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

/* PIN Defines */
#define DIO_u8_PIN0 0
#define DIO_u8_PIN1 1
#define DIO_u8_PIN2 2
#define DIO_u8_PIN3 3
#define DIO_u8_PIN4 4
#define DIO_u8_PIN5 5
#define DIO_u8_PIN6 6
#define DIO_u8_PIN7 7

/* PIN Directions */
#define DIO_u8_INPUT 0
#define DIO_u8_OUTPUT 1

/* PIN Value Options */
// write (output) 1 or 0
#define DIO_u8_HIGH 1
#define DIO_u8_LOW 0

/* Port Direction */
#define DIO_u8_PORT_OUTPUT 255
#define DIO_u8_PORT_INPUT 0

/*IO Pins*/
DIO_tenuErrorStatus DIO_enuSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinVal);
/******************DIO_enuSetPinValue*********************/
/* USE : Set any Pin Value with 0 or 1                   */
/* PARAMETERS:                                           */
/* 1- Copy of Port ID: A-->0 , B-->1 , C--> 2 , D-->3    */
/* 2- Copy of Pin  ID: 0-->7                             */
/* 3- Copy of Pin  Value: High-->1 Low-->0               */
/* RETURN:                                               */
/* Error Status : 1 --> Error , 0--> No Error            */
/*********************************************************/
DIO_tenuErrorStatus DIO_u8GetPinValue (u8 Copy_u8PortId,u8 Copy_u8PinId, u8*Add_u8Result);
/******************DIO_u8GetPinValue**********************/
/* USE : Get any Pin Value -->  0 or 1                   */
/* PARAMETERS:                                           */
/* 1- Copy of Port ID: A-->0 , B-->1 , C--> 2 , D-->3    */
/* 2- Copy of Pin  ID: 0-->7                             */
/* 3- Address of Result Value to Put Value in it:        */
/* High-->1 Low-->0                                      */
/* RETURN:                                               */
/* Error Status : 1 --> Error , 0--> No Error            */
/* Note : I didn't use u8 Return Type to use Error Status*/
/*********************************************************/
DIO_tenuErrorStatus DIO_enuSetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDir); //determine input or output
/**************DIO_enuSetPinDirection*********************/
/* USE : Determine The Pin direction (Input or Output)   */
/* PARAMETERS:                                           */
/* 1- Copy of Port ID: A-->0 , B-->1 , C--> 2 , D-->3    */
/* 2- Copy of Pin  ID: 0-->7                             */
/* 3- Copy of Pin  Direction: Output-->1 Input-->0       */
/* RETURN:                                               */
/* Error Status : 1 --> Error , 0--> No Error            */
/*********************************************************/
DIO_tenuErrorStatus DIO_enuSetPortDirection(u8 Copy_u8PortId , u8 Copy_u8PortDir);
/**************DIO_enuSetPortDirection********************/
/* USE : Determine all Pins of a                         */
/* port direction (Input or Output)                      */
/* PARAMETERS:                                           */
/* 1- Copy of Port ID: A-->0 , B-->1 , C--> 2 , D-->3    */
/* 2- Copy of Port Direction: Output-->255 Input-->0     */
/* RETURN:                                               */
/* Error Status : 1 --> Error , 0--> No Error            */
/*********************************************************/
DIO_tenuErrorStatus DIO_enuSetPortValue(u8 Copy_u8PortId , u8 Copy_u8PortVal);
/**************DIO_enuSetPortValue************************/
/* USE : Determine The Value of the Port                 */
/* PARAMETERS:                                           */
/* 1- Copy of Port ID: A-->0 , B-->1 , C--> 2 , D-->3    */
/* 2- Copy of Port Value                                 */
/* RETURN:                                               */
/* Error Status : 1 --> Error , 0--> No Error            */
/*********************************************************/
#endif /* INCLUDE_MCAL_DIO_DIO_H_ */
