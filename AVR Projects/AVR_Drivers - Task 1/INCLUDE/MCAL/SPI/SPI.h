/*
 * SPI.h
 *
 *  Created on: Oct 22, 2022
 *      Author: mh_sm
 */
#ifndef INCLUDE_MCAL_SPI_SPI_H_
#define INCLUDE_MCAL_SPI_SPI_H_

#include "../../../SERVICES/std_types.h"

#define SPI_INTERRUPT_ENABLE         0b10000000
///////////////////////////////////////////////
#define SPI_ENABLE                   0b01000000
///////////////////////////////////////////////
#define SPI_DATA_ORDER_LSB_FIRST     0b00100000
#define SPI_DATA_ORDER_MSB_FIRST     0b00000000
///////////////////////////////////////////////
#define SPI_SELECT_MASTER            0b00010000
#define SPI_SELECT_SLAVE             0b00000000
///////////////////////////////////////////////
#define SPI_CLOCK_POLARITY_RISING    0b00000000
#define SPI_CLOCK_POLARITY_FALLING   0b00001000
///////////////////////////////////////////////
#define SPI_CLOCK_PHASE_WRITE_FIRST  0b00000000
#define SPI_CLOCK_PHASE_READ_FIRST   0b00000100
///////////////////////////////////////////////
#define SPI_CLOCK_RATE_8             0b00000000
#define SPI_CLOCK_RATE_16            0b00000001
#define SPI_CLOCK_RATE_64            0b00000010
#define SPI_CLOCK_RATE_128           0b00000011
///////////////////////////////////////////////
#define SPI_DUOBLE_SPEED             0b00000001
///////////////////////////////////////////////
#define SPI_TRANSFER_FLAG            7
#define SPI_TRANSFER_NOT_COMPLETED   0
#define SPI_TIMEOUT                  0
///////////////////////////////////////////////
typedef struct {
	u8 SPI_u8SelectMasterSlave;
	u8 SPI_u8ClockPolarity;
	u8 SPI_u8ClockPhase;
	u8 SPI_u8ClockRate;
	u8 SPI_u8DoubleSpeed;
	u8 SPI_u8DataOrder;
}SPI_sructCfg;
////////////////////////////////////////////////
void SPI_voidInit(SPI_sructCfg*Add_sructSPIcfg);
/******************SPI_voidInit************************/
/* USE : Configure SPI settings                       */
/* PARAMETERS: Pointer that carries address of        */
/* configuration struct that user need                */
/* RETURN: No Return                                  */
/******************************************************/

u8   SPI_u8Tranceive(u8 Copy_u8Data);
/******************SPI_u8Tranceive*********************/
/* USE : Send and Receive Data                        */
/* PARAMETERS: Copy of data to be Transmit or Recieve */
/* RETURN: Return the read data in case of reading    */
/* and un-needed data in case of writing              */
/******************************************************/

#endif /* INCLUDE_MCAL_SPI_SPI_H_ */
