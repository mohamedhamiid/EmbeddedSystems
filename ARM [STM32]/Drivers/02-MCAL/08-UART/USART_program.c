/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 04 / 9 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MUSART_interface.h"
#include "MUSART_priv.h"
#include "MUSART_config.h"

extern u8 Global_u8CurrClkFreq ;

void MUART_voidInit(MUART_tstructCfg* Add_structCfg){

	/* Pointer to Save the desired UART base address */
	volatile MUART_tReg* Loc_CurrUART;

	/* Determine which UART to init */
	switch(Add_structCfg->id){
		case MUART_ID_UART1 :Loc_CurrUART = MUART1 ;break;
		case MUART_ID_UART2 :Loc_CurrUART = MUART2 ;break;
		case MUART_ID_UART3 :Loc_CurrUART = MUART3 ;break;
	    default: /* Error Invalid Uart ID */; break;
	}

	/* 5- Determine baudrate */
	f64 Loc_f64DIV    = (f64)((Global_u8CurrClkFreq*1000000.0)/((Add_structCfg->baudRate)*16.0)) ;
	u16 Loc_u16IntBR  = (u16)Loc_f64DIV;
	u8  Loc_u8FloatBR = (u8)(((Loc_f64DIV-Loc_u16IntBR)*16)+0.5);

	if(Loc_u8FloatBR>15){
		Loc_u16IntBR++;
	}

	Loc_CurrUART->BRR = ((Loc_u8FloatBR)|(Loc_u16IntBR<<4));


	/* 1- Disable UART and reset Reg */
	Loc_CurrUART->CR[0] = 0x00000000 ;

	/* 2- Determine Word Length */
	if(Add_structCfg->wordLength <= MUART_WORD_LENGTH_9_BITS){

		if(Add_structCfg->wordLength == MUART_WORD_LENGTH_9_BITS)
			SET_BIT(Loc_CurrUART->CR[0],12);
	}
	else {/* Error : Invalid Word Length  */}

	/* 3- Determine Parity */
	if(Add_structCfg->parity <= MUART_PARITY_ODD){
		Loc_CurrUART->CR[0] |= (Add_structCfg->parity<<9);
	}
	else{/* Error : Invalid Parity */}

	/* 4- Determine Direction */
	if(Add_structCfg->direction <= MUART_DIRECTION_TX_RX){
		Loc_CurrUART->CR[0] |= (Add_structCfg->direction<<2);
	}
	else{/* Error : Invalid Parity */}


	/* Enable UART */
	SET_BIT(Loc_CurrUART->CR[0],13);

	/* Reset Status Register */
	Loc_CurrUART->SR  = 0;

}


void MUART_voidSendString(MUART_tstructCfg* Add_structCfg , u8 Copy_u8Arr[]){

	/* Pointer to Save the desired UART base address */
	volatile MUART_tReg* Loc_CurrUART;

	/* Determine which UART to send */
	switch(Add_structCfg->id){
		case MUART_ID_UART1 :Loc_CurrUART = MUART1 ;break;
		case MUART_ID_UART2 :Loc_CurrUART = MUART2 ;break;
		case MUART_ID_UART3 :Loc_CurrUART = MUART3 ;break;
	    default: /* Error Invalid UART ID */; break;
	}

	u8 Loc_u8Counter = 0 ;
	while(Copy_u8Arr[Loc_u8Counter] != '\0'){

//		u16 Loc_u16TimeOut = 200000 ;

//		/* Check That TX Data Reg is Empty  */
//		while(Loc_u16TimeOut>0){
//			if(GET_BIT(Loc_CurrUART->SR,7)==1)
//				break ;
//			Loc_u16TimeOut--;
//		}
//
//		/* Send data if not time out */
//		if(Loc_u16TimeOut>0)
			Loc_CurrUART->DR = Copy_u8Arr[Loc_u8Counter] ;
//		else
//			#warning "Timeout : TX Data register not empty"

		/* Check data is sent or not */
//		Loc_u16TimeOut = 200000 ;
//		while(Loc_u16TimeOut>0){
			while(GET_BIT(Loc_CurrUART->SR,6)==0);
//				 break ;
//			Loc_u16TimeOut--;
//		}
//		if(Loc_u16TimeOut==0)
//			#warning "Timeout : Data is not sent"

		Loc_u8Counter++;
	}
}
void MUART_voidSendChar(MUART_tstructCfg* Add_structCfg , u8 Copy_u8Char){

	/* Pointer to Save the desired UART base address */
	volatile MUART_tReg* Loc_CurrUART;

	/* Determine which UART to send */
	switch(Add_structCfg->id){
		case MUART_ID_UART1 :Loc_CurrUART = MUART1 ;break;
		case MUART_ID_UART2 :Loc_CurrUART = MUART2 ;break;
		case MUART_ID_UART3 :Loc_CurrUART = MUART3 ;break;
	    default: /* Error Invalid UART ID */; break;
	}

//		u16 Loc_u16TimeOut = 200000 ;

//		/* Check That TX Data Reg is Empty  */
//		while(Loc_u16TimeOut>0){
//			if(GET_BIT(Loc_CurrUART->SR,7)==1)
//				break ;
//			Loc_u16TimeOut--;
//		}
//
//		/* Send data if not time out */
//		if(Loc_u16TimeOut>0)
			Loc_CurrUART->DR = Copy_u8Char ;
//		else
//			#warning "Timeout : TX Data register not empty"

		/* Check data is sent or not */
//		Loc_u16TimeOut = 200000 ;
//		while(Loc_u16TimeOut>0){
			while(GET_BIT(Loc_CurrUART->SR,6)==0);
//				 break ;
//			Loc_u16TimeOut--;
//		}
//		if(Loc_u16TimeOut==0)
//			#warning "Timeout : Data is not sent"
}
u8  MUART_u8ReceiveChar(MUART_tstructCfg* Add_structCfg){
	/* Local Variable to store result */
	u8 Loc_u8RecievedChar = 0 ;
	/* Pointer to Save the desired UART base address */
	volatile MUART_tReg* Loc_CurrUART;

	/* Determine which UART to send */
	switch(Add_structCfg->id){
		case MUART_ID_UART1 :Loc_CurrUART = MUART1 ;break;
		case MUART_ID_UART2 :Loc_CurrUART = MUART2 ;break;
		case MUART_ID_UART3 :Loc_CurrUART = MUART3 ;break;
	    default: /* Error Invalid UART ID */; break;
	}


//	u16 Loc_u16TimeOut = 200000 ;

	/* Check That TX Data Reg is Empty  */
//	while(Loc_u16TimeOut>0){
		while(GET_BIT(Loc_CurrUART->SR,5)==0);
//			break ;
//		Loc_u16TimeOut--;
//	}

	/* Send data if not time out */
//	if(Loc_u16TimeOut>0)
		Loc_u8RecievedChar = Loc_CurrUART->DR ;
//	else
//		#warning "Timeout : RX Data register empty"

	return (Loc_u8RecievedChar) ;

}
