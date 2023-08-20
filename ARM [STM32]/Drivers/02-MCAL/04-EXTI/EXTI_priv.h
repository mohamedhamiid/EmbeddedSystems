/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 15 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef EXTI_PRIV_H
#define EXTI_PRIV_H

/* REGISTERS */
typedef struct{
	volatile u32 EXTI_IMR ;
	volatile u32 EXTI_EMR ;
	volatile u32 EXTI_RTSR ;
	volatile u32 EXTI_FTSR ;
	volatile u32 EXTI_SWIER ;
	volatile u32 EXTI_PR ;

}EXTI_tReg;

#define EXTI ((volatile EXTI_tReg*)0x40010400)


#endif
