/*
 * UART.c
 *
 *  Created on: Oct 8, 2022
 *      Author: mh_sm
 */
#include "../../../INCLUDE/MCAL/UART/UART.h"
#include "../../../INCLUDE/MCAL/UART/UART_priv.h"
#include "../../../SERVICES/bit_utilies.h"
//#include "../../../INCLUDE/MCAL/GIE/GIE.h"
u8 Global_u8UBRRH_Value=0;
u8 Global_u8UCSRC_Value=0;
void UART_voidInit(UART_structCfg*Add_structUARTcfg){
	// SET BAUD RATE
	switch(Add_structUARTcfg->UART_u8BaudRate){
	case UART_BAUD_RATE_2400     :UBRRL|=UART_BAUD_RATE_2400     ;break;
	case UART_BAUD_RATE_4800     :UBRRL|=UART_BAUD_RATE_4800     ;break;
	case UART_BAUD_RATE_9600     :UBRRL|=UART_BAUD_RATE_9600     ;break;
	case UART_BAUD_RATE_14K      :UBRRL|=UART_BAUD_RATE_14K      ;break;
	case UART_BAUD_RATE_19K      :UBRRL|=UART_BAUD_RATE_19K      ;break;
	case UART_BAUD_RATE_28K      :UBRRL|=UART_BAUD_RATE_28K      ;break;
	case UART_BAUD_RATE_38K      :UBRRL|=UART_BAUD_RATE_38K      ;break;
	case UART_BAUD_RATE_57K      :UBRRL|=UART_BAUD_RATE_57K      ;break;
	case UART_BAUD_RATE_76K      :UBRRL|=UART_BAUD_RATE_76K      ;break;
	case UART_BAUD_RATE_115K     :UBRRL|=UART_BAUD_RATE_115K     ;break;
	case UART_BAUD_RATE_230K     :UBRRL|=UART_BAUD_RATE_230K     ;break;
	//case UART_BAUD_RATE_250K     :UBRRL|=UART_BAUD_RATE_250K     ;break;
	case UART_BAUD_RATE_HALF_MEGA:UBRRL|=UART_BAUD_RATE_HALF_MEGA;break;
	}
	// SET FRAME FORMAT
	// 1- SYNC OR ASYNC
	switch(Add_structUARTcfg->UART_u8Mode){
	case UART_MODE_SYNCHRONOUS:
		Global_u8UCSRC_Value|=UART_MODE_SYNCHRONOUS;
		// SET WHEN ACTION HAPPENS
		switch(Add_structUARTcfg->UART_u8ClockPolarity){
		case UART_CLOCK_POLARITY_TX_RISING_RX_FALLING: Global_u8UCSRC_Value|=UART_CLOCK_POLARITY_TX_RISING_RX_FALLING;break;
		case UART_CLOCK_POLARITY_TX_FALLING_RX_RISING: Global_u8UCSRC_Value|=UART_CLOCK_POLARITY_TX_FALLING_RX_RISING;break;
		}
	break;
	case UART_MODE_ASYNCHRONOUS: Global_u8UCSRC_Value|=UART_MODE_ASYNCHRONOUS;break;
	}

	// 2- PARITY
	switch(Add_structUARTcfg->UART_u8Parity){
	case UART_PARITY_DISABLED: Global_u8UCSRC_Value|=UART_PARITY_DISABLED;break;
	case UART_PARITY_EVEN: Global_u8UCSRC_Value|=UART_PARITY_EVEN;break;
	case UART_PARITY_ODD: Global_u8UCSRC_Value|=UART_PARITY_ODD;break;
	}

	// 3- CHARACTER SIZE
	switch(Add_structUARTcfg->UART_u8CharSize){
	case UART_CHARACTER_SIZE_5_BIT: Global_u8UCSRC_Value|=UART_CHARACTER_SIZE_5_BIT;break;
	case UART_CHARACTER_SIZE_6_BIT: Global_u8UCSRC_Value|=UART_CHARACTER_SIZE_6_BIT;break;
	case UART_CHARACTER_SIZE_7_BIT: Global_u8UCSRC_Value|=UART_CHARACTER_SIZE_7_BIT;break;
	case UART_CHARACTER_SIZE_8_BIT: Global_u8UCSRC_Value|=UART_CHARACTER_SIZE_8_BIT;break;
//	case UART_CHARACTER_SIZE_9_BIT:
//		Global_u8UCSRC_Value|=UART_CHARACTER_SIZE_9_BIT;
//		UCSRB|=UART_CHARACTER_SIZE_9_BIT_UCSRB_REG;
//	break;
	}

	// STOP BIT
	switch(Add_structUARTcfg->UART_u8StopBit){
	case UART_STOP_BIT_SELECT_1_BIT: Global_u8UCSRC_Value |= UART_STOP_BIT_SELECT_1_BIT;break;
	case UART_STOP_BIT_SELECT_2_BIT: Global_u8UCSRC_Value |= UART_STOP_BIT_SELECT_2_BIT;break;
	}
	UCSRC=Global_u8UCSRC_Value;
	//////////////////////////////////////////////////////////////////////////////////////////
	/***************************** ENABLE RX OR TX ******************************************/
	switch(Add_structUARTcfg->UART_u8EnableTXorRX){
	case UART_ENABLE_TX:UCSRB|=UART_ENABLE_TX;break;
	case UART_ENABLE_RX:UCSRB|=UART_ENABLE_RX;break;
	case UART_ENABLE_TX_RX:UCSRB|=UART_ENABLE_TX_RX;break;

	}
//	// SET BAUDRATE --> 9600/8 MHZ
//	UBRRL = 51;
//	UBRRH = 0;
//	// SET FRAME FORMAT --> 8 DATA , 1 STOP , NO PARITY
//	UCSRC = 0x86;
//	// ENABLE RX AND TX
//	UCSRB = 0x18;
}

void UART_voidSendChar(u8 Copy_u8Data){
	u8 Loc_u8UARTtimeOut=200;
	while(Loc_u8UARTtimeOut>0){
	if(GET_BIT(UCSRA,UART_DATA_REGISTER_EMPTY)==1)
		break;
	else
		#warning TimeOut DATA REGISTER NOT EMPTY
	Loc_u8UARTtimeOut--;
	}
	UDR_T=Copy_u8Data;
}

u8 UART_u8GetChar(void){
	u8 Loc_u8Res;
	u8 Loc_u8UARTtimeOut=200;
	while(Loc_u8UARTtimeOut>0){
		if(GET_BIT(UCSRA,UART_RECIEVE_COMPLETE)==1)
			break;
		else
			#warning TimeOut RECIEVE NOT COMPLETED
		Loc_u8UARTtimeOut--;
	}
	Loc_u8Res = UDR_R;
	return Loc_u8Res;
}

