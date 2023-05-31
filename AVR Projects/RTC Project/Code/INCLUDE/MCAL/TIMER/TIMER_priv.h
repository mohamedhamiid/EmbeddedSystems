/*
 * TIMER_priv.h
 *
 *  Created on: Oct 1, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_PRIV_H_
#define INCLUDE_MCAL_TIMER_TIMER_PRIV_H_
// TIMER0
#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define TIMSK *((volatile u8*)0x59)
#define OCR0  *((volatile u8*)0x5C)
#define TIFR  *((volatile u8*)0x58)
// TIMER1
#define TCCR1 *((volatile u16*)0x4E)
#define TCNT1 *((volatile u16*)0x4C)
#define TIMSK *((volatile u8*)0x59)
#define OCR1A *((volatile u16*)0x4A)
#define OCR1B *((volatile u16*)0x48)
#define TIFR  *((volatile u8*)0x58)
#define ICR1  *((volatile u16*)0x46)
// TIMER2
#define TCCR2 *((volatile u8*)0x45)
#define TCNT2 *((volatile u8*)0x44)
#define TIMSK *((volatile u8*)0x59)
#define OCR2  *((volatile u8*)0x43)
#define TIFR  *((volatile u8*)0x58)
#define ASSR  *((volatile u8*)0x42)


#endif /* INCLUDE_MCAL_TIMER_TIMER_PRIV_H_ */
