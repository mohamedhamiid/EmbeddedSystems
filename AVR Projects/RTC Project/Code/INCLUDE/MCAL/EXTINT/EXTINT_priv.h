/*
 * EXTINT_priv.h
 *
 *  Created on: Sep 20, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_MCAL_EXTINT_EXTINT_PRIV_H_
#define INCLUDE_MCAL_EXTINT_EXTINT_PRIV_H_
#define MCUCR *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR *((volatile u8*)0x5B)
#define GIFR *((volatile u8*)0x5A)


#endif /* INCLUDE_MCAL_EXTINT_EXTINT_PRIV_H_ */
