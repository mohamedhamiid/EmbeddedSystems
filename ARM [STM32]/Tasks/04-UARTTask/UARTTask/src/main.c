/*
 * main.c
 *
 *  Created on: Aug 28, 2023
 *      Author: mh_sm
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "MUSART_interface.h"

#include "LED_interface.h"


int main(){
	/* Clock Init */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 , RCC_GPIO_A);
	RCC_voidEnableClock(RCC_APB2 , RCC_UART1);

	/* UART PINS */
	MDIO_voidSetPinDirection(PORTA,PIN9,MDIO_DIRECTION_OUTPUT_50MHZ,MDIO_MODE_OUTPUT_ALTER_FUNC_PUSH_PULL);
	MDIO_voidSetPinDirection(PORTA,PIN10,MDIO_DIRECTION_INPUT,MDIO_MODE_INPUT_FLOATING);

	MUART_tstructCfg UART1={
			.baudRate = 9600 ,
			.id       = MUART_ID_UART1 ,
			.direction = MUART_DIRECTION_TX_RX ,
			.wordLength = MUART_WORD_LENGTH_8_BITS ,
	};
	MUART_voidInit(&UART1);


	/* HAL */
	HLED_structCfg Global_leds[8];
	/* 01-Leds */
	for(u8 Loc_u8Counter=0 ; Loc_u8Counter < 8 ; Loc_u8Counter++){
		Global_leds[Loc_u8Counter].LED_u8Pin = Loc_u8Counter ;
		Global_leds[Loc_u8Counter].LED_2bitsPort = PORTA ;
		Global_leds[Loc_u8Counter].LED_2bitsOutFreq = LED_OUTPUT_2MHZ ;
		Global_leds[Loc_u8Counter].LED_1bitConnectionType = LED_ACTIVE_HIGH ;
		Global_leds[Loc_u8Counter].LED_1bitCurrentState = LED_ACTIVE_HIGH_OFF ;
		HLED_voidInitLed(&Global_leds[Loc_u8Counter]);
	}

	s8 Loc_u8LedCounter = 0 ;
		u8 Loc_u8RecChar = 0 ;
	while(1){

		if(Loc_u8LedCounter<0)
			Loc_u8LedCounter = 0 ;
		if(Loc_u8LedCounter>7)
			Loc_u8LedCounter = 7 ;


		Loc_u8RecChar= MUART_u8ReceiveChar(&UART1);
		HLED_voidTurnOn(&Global_leds[0]);

		if(Loc_u8RecChar=='1'){
			HLED_voidTurnOn(&Global_leds[Loc_u8LedCounter++]);
			MUART_voidSendString(&UART1 , "LED ");
			MUART_voidSendChar(&UART1 , (u8)(Loc_u8LedCounter +'0'));
			MUART_voidSendString(&UART1 , " ON");
			MUART_voidSendChar(&UART1 , '\n');

		}

		else if(Loc_u8RecChar=='2'){
			HLED_voidTurnOff(&Global_leds[Loc_u8LedCounter--]);
			MUART_voidSendString(&UART1 , "LED ");
			MUART_voidSendChar(&UART1 , (u8)(Loc_u8LedCounter+'2'));
			MUART_voidSendString(&UART1 , " OFF");
			MUART_voidSendChar(&UART1 , '\n');
		}

	}
}




