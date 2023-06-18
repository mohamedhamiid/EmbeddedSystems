/*
 * SPI_priv.h
 *
 *  Created on: Oct 22, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_MCAL_SPI_SPI_PRIV_H_
#define INCLUDE_MCAL_SPI_SPI_PRIV_H_

#define SPCR *((volatile u8*)0x2D)
#define SPDR *((volatile u8*)0x2F)
#define SPSR *((volatile u8*)0x2E)

#endif /* INCLUDE_MCAL_SPI_SPI_PRIV_H_ */
