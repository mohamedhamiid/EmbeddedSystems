/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 04 / 9 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef MUART_INTERFACE_H
#define MUART_INTERFACE_H

typedef struct {
	u32 baudRate                ;
	u8 id                   : 3 ;
	u8 wordLength           : 1 ;
	u8 parity               : 2 ;
	u8 direction            : 2 ;

}MUART_tstructCfg;

void MUART_voidInit(MUART_tstructCfg* Add_structCfg);
void MUART_voidSendString(MUART_tstructCfg* Add_structCfg , u8 Copy_u8Arr[]);
u8   MUART_u8ReceiveChar(MUART_tstructCfg* Add_structCfg);
void MUART_voidSendChar(MUART_tstructCfg* Add_structCfg , u8 Copy_u8Char);

/* UART No Options */
#define MUART_ID_UART1            1
#define MUART_ID_UART2            2
#define MUART_ID_UART3            3
#define MUART_ID_UART4            4
#define MUART_ID_UART5            5

/* Word Length Options */
#define MUART_WORD_LENGTH_8_BITS  0    	/* Default value */
#define MUART_WORD_LENGTH_9_BITS  1

/* Parity Options */
#define MUART_PARITY_DISABLE      0b00 	/* Default value */
#define MUART_PARITY_EVEN         0b10
#define MUART_PARITY_ODD          0b11

/* direction */
#define MUART_DIRECTION_TX                  0b10
#define MUART_DIRECTION_RX                  0b01
#define MUART_DIRECTION_TX_RX               0b11


/* Interrupts Options */
#define MUART_INTERRUPT_DISABLE           0b00000 /* Default value */
#define MUART_INTERRUPT_PARITY            0b00001
#define MUART_INTERRUPT_TX_REG_EMPTY      0b00010
#define MUART_INTERRUPT_TX_COMPLETE   	  0b00100
#define MUART_INTERRUPT_RX_REG_NOT_EMPTY  0b01000
#define MUART_INTERRUPT_IDLE    		  0b10000
#endif
