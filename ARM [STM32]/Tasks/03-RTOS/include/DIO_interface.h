/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 29 / 7 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* PORTS */
#define DIO_PORTA           0
#define DIO_PORTB           1
#define DIO_PORTC           2

/* PINS */
#define DIO_PIN0            0
#define DIO_PIN1            1
#define DIO_PIN2            2
#define DIO_PIN3            3
#define DIO_PIN4            4
#define DIO_PIN5            5
#define DIO_PIN6            6
#define DIO_PIN7            7
#define DIO_PIN8            8
#define DIO_PIN9            9
#define DIO_PIN10           10
#define DIO_PIN11           11
#define DIO_PIN12           12
#define DIO_PIN13           13
#define DIO_PIN14           14
#define DIO_PIN15           15

/* DIRECTIONS */
#define DIO_INPUT           0b00
#define DIO_OUTPUT_2MHZ     0b10
#define DIO_OUTPUT_10MHZ    0b01
#define DIO_OUTPUT_50MHZ    0b11

/* MODES */

/* INPUT */
#define DIO_INPUT_ANALOG        0b00
#define DIO_INPUT_FLOATING      0b01
#define DIO_INPUT_PULL_UP       0b10
#define DIO_INPUT_PULL_DOWN     0b11

/* OUTPUT */
#define DIO_OUTPUT_PUSH_PULL     			0b00
#define DIO_OUTPUT_OPEN_DRAIN    			0b01
#define DIO_OUTPUT_ALTER_FUNC_PUSH_PULL     0b10
#define DIO_OUTPUT_ALTER_FUNC_OPEN_DRAIN    0b11

/* PIN VALUES */
#define DIO_PIN_LOW   0
#define DIO_PIN_HIGH  1

void DIO_voidSetPinDirection(u8 Copy_u8PortId ,u8 Copy_u8PinNo ,u8 Copy_u8Direction , u8 Copy_u8Mode);
void DIO_voidSetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinNo , u8 Copy_u8PinVal);
void DIO_voidSet8BitsValue(u8 Copy_u8PortId ,u8 Copy_u8Start, u8 Copy_u8Val);
u8 	 DIO_u8GetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinNo);
void DIO_voidUnlockPin(u8 Copy_u8PortId ,u8 Copy_u8PinNo);
void DIO_voidLockPin(u8 Copy_u8PortId ,u8 Copy_u8PinNo);

#endif
