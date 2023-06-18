/*
 * SPI.c
 *
 *  Created on: Oct 22, 2022
 *      Author: mh_sm
 */
#include "../../../INCLUDE/MCAL/SPI/SPI.h"
#include "../../../INCLUDE/MCAL/SPI/SPI_priv.h"
#include "../../../SERVICES/bit_utilies.h"
/******************SPI_voidInit*******************/
/* USE : Configure SPI settings                  */
/* PARAMETERS: Pointer that carries address of   */
/* configuration struct that user need           */                                       //
/* RETURN: No Return                             */
/*************************************************/

void SPI_voidInit(SPI_sructCfg*Add_sructSPIcfg){
	switch(Add_sructSPIcfg->SPI_u8SelectMasterSlave){
	case SPI_SELECT_MASTER:
		SPCR|= SPI_SELECT_MASTER;
		switch(Add_sructSPIcfg->SPI_u8ClockRate){
		case SPI_CLOCK_RATE_8   :  SPCR|= SPI_CLOCK_RATE_8   ;break;
		case SPI_CLOCK_RATE_16  :  SPCR|= SPI_CLOCK_RATE_16  ;break;
		case SPI_CLOCK_RATE_64  :  SPCR|= SPI_CLOCK_RATE_64  ;break;
		case SPI_CLOCK_RATE_128 :  SPCR|= SPI_CLOCK_RATE_128 ;break;
		}
	break;
	case SPI_SELECT_SLAVE:SPCR|= SPI_SELECT_SLAVE;
	}

	switch (Add_sructSPIcfg->SPI_u8ClockPhase){
	case SPI_CLOCK_PHASE_WRITE_FIRST : SPCR|=SPI_CLOCK_PHASE_WRITE_FIRST;break;
	case SPI_CLOCK_PHASE_READ_FIRST  : SPCR|=SPI_CLOCK_PHASE_READ_FIRST ;break;
	}

	switch(Add_sructSPIcfg->SPI_u8ClockPolarity){
	case SPI_CLOCK_POLARITY_RISING : SPCR|=SPI_CLOCK_POLARITY_RISING ;break;
	case SPI_CLOCK_POLARITY_FALLING: SPCR|=SPI_CLOCK_POLARITY_FALLING;break;
	}
	switch(Add_sructSPIcfg->SPI_u8DataOrder){
	case SPI_DATA_ORDER_LSB_FIRST : SPCR|=SPI_DATA_ORDER_LSB_FIRST;break;
	case SPI_DATA_ORDER_MSB_FIRST : SPCR|=SPI_DATA_ORDER_MSB_FIRST;break;
	}

	SPCR|=SPI_ENABLE;

}

/******************SPI_u8Tranceive*********************/
/* USE : Send and Recieve Data                        */
/* PARAMETERS: Copy of data to be Transmit or Recieve */
/* RETURN: Return the read data in case of reading    */
/* and un-needed data in case of writing              */
/******************************************************/
u8 SPI_u8Tranceive(u8 Copy_u8Data){
 SPDR = Copy_u8Data;
 u8 Loc_u8SPItimeOut=200;
 while(GET_BIT(SPSR,SPI_TRANSFER_FLAG)==SPI_TRANSFER_NOT_COMPLETED && Loc_u8SPItimeOut>0){
	 Loc_u8SPItimeOut--;
}
 if(Loc_u8SPItimeOut == SPI_TIMEOUT){
	 #warning SPI TIMEOUT
}
 else{
	 return SPDR;
}
}

