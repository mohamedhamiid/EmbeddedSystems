/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 29 / 7 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


/* PORTS */
typedef enum{
	PORTA ,
	PORTB ,
	PORTC
}MDIO_enumPorts;

/* PINS */
typedef enum{
	PIN0  ,
	PIN1  ,
	PIN2  ,
	PIN3  ,
	PIN4  ,
	PIN5  ,
	PIN6  ,
	PIN7  ,
	PIN8  ,
	PIN9  ,
	PIN10 ,
	PIN11 ,
	PIN12 ,
	PIN13 ,
	PIN14 ,
	PIN15
}MDIO_enumPins;


/* DIRECTIONS */
#define MDIO_DIRECTION_INPUT           0b00
#define MDIO_DIRECTION_OUTPUT_2MHZ     0b10
#define MDIO_DIRECTION_OUTPUT_10MHZ    0b01
#define MDIO_DIRECTION_OUTPUT_50MHZ    0b11

/* MODES */

/* INPUT */
#define MDIO_MODE_INPUT_ANALOG        0b00
#define MDIO_MODE_INPUT_FLOATING      0b01
#define MDIO_MODE_INPUT_PULL_UP       0b10
#define MDIO_MODE_INPUT_PULL_DOWN     0b11

/* OUTPUT */
#define MDIO_MODE_OUTPUT_PUSH_PULL     			0b00
#define MDIO_MODE_OUTPUT_OPEN_DRAIN    			0b01
#define MDIO_MODE_OUTPUT_ALTER_FUNC_PUSH_PULL     0b10
#define MDIO_MODE_OUTPUT_ALTER_FUNC_OPEN_DRAIN    0b11

/* PIN VALUES */
#define MDIO_PIN_LOW   0
#define MDIO_PIN_HIGH  1

void MDIO_voidSetPinDirection(MDIO_enumPorts Copy_enumPortId ,
							 MDIO_enumPins Copy_enumPinNo ,
							 u8 Copy_u8Direction ,
							 u8 Copy_u8Mode);

void MDIO_voidSetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinNo , u8 Copy_u8PinVal);
void MDIO_voidSet8BitsValue(u8 Copy_u8PortId ,u8 Copy_u8Start, u8 Copy_u8Val);
u8 	 MDIO_u8GetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinNo);
void MDIO_voidUnlockPin(u8 Copy_u8PortId ,u8 Copy_u8PinNo);
void MDIO_voidLockPin(u8 Copy_u8PortId ,u8 Copy_u8PinNo);
#endif
