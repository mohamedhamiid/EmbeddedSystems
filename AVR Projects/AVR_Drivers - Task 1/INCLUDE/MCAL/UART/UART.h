/*
 * UART.h
 *
 *  Created on: Oct 8, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_MCAL_UART_UART_H_
#define INCLUDE_MCAL_UART_UART_H_
#include "../../../SERVICES/std_types.h"
//////////////////////////////////////////////////////////
// UCSRC BIT 7 =1
/************Modes Macros***************/
#define UART_MODE_SYNCHRONOUS  0b11000000
#define UART_MODE_ASYNCHRONOUS 0b10000000
/************Parity Macros***************/
#define UART_PARITY_DISABLED   0b10000000
#define UART_PARITY_RESERVED   0b10010000
#define UART_PARITY_EVEN       0b10100000
#define UART_PARITY_ODD        0b10110000
/************STOP BIT SELECT Macros***************/
#define UART_STOP_BIT_SELECT_1_BIT 0b10000000
#define UART_STOP_BIT_SELECT_2_BIT 0b10001000
/************Character Size Macros***************/
#define UART_CHARACTER_SIZE_5_BIT            0b10000000
#define UART_CHARACTER_SIZE_6_BIT            0b10000010
#define UART_CHARACTER_SIZE_7_BIT            0b10000100
#define UART_CHARACTER_SIZE_8_BIT            0b10000110
#define UART_CHARACTER_SIZE_9_BIT            0b10000110
#define UART_CHARACTER_SIZE_9_BIT_UCSRB_REG  0b00000100
/************Clock Polarity Macros***************/
// SYCHRONOUS MODE ONLY
#define UART_CLOCK_POLARITY_TX_RISING_RX_FALLING  0b10000000
#define UART_CLOCK_POLARITY_TX_FALLING_RX_RISING  0b10000001
////////////////////////////////////////////////////////////
// UBBRH BIT 7 = 0
/************BAUD RATE REG Macros***************/
#define UART_BAUD_RATE_2400         207
#define UART_BAUD_RATE_4800         103
#define UART_BAUD_RATE_9600         51
#define UART_BAUD_RATE_14K          34
#define UART_BAUD_RATE_19K          25
#define UART_BAUD_RATE_28K          16
#define UART_BAUD_RATE_38K          12
#define UART_BAUD_RATE_57K          8
#define UART_BAUD_RATE_76K          6
#define UART_BAUD_RATE_115K         3
#define UART_BAUD_RATE_230K         1
#define UART_BAUD_RATE_250K         1
#define UART_BAUD_RATE_HALF_MEGA    0
///////////////////////////////////////////////////////////
/******************** TX OR RX ***************************/
#define UART_ENABLE_TX              0b00001000
#define UART_ENABLE_RX              0b00010000
#define UART_ENABLE_TX_RX           0b00011000
//////////////////////////////////////////////////////////
typedef struct {
	u8 UART_u8Mode;
	u8 UART_u8Parity;
	u8 UART_u8StopBit;
	u8 UART_u8CharSize;
	u8 UART_u8ClockPolarity; // SYNC ONLY
	u8 UART_u8BaudRate;
	u8 UART_u8EnableTXorRX;
}UART_structCfg;
//////////////////////////////////////////////////////////
/*********************CHECK MACROS***********************/
#define  UART_DATA_REGISTER_EMPTY   5
#define  UART_RECIEVE_COMPLETE      7
/********************************************************/

void UART_voidInit(UART_structCfg*Add_structUARTcfg);
/******************UART_voidInit*******************/
/* USE : Configure UART settings                  */
/* PARAMETERS: Pointer that carries address of    */
/* configuration struct that user need            */
/* RETURN: No Return                              */
/**************************************************/
void UART_voidSendChar(u8 Copy_u8Data);
/***************UART_voidSendChar******************/
/* USE : Send Data                                */
/* PARAMETERS: Copy of Data                       */
/* RETURN: No Return                              */
/**************************************************/
u8 UART_u8GetChar(void);
/***************UART_voidGetChar*******************/
/* USE : Receive Data                             */
/* PARAMETERS: No Parameters                      */
/* RETURN: The Data received                      */
/**************************************************/
#endif /* INCLUDE_MCAL_UART_UART_H_ */
