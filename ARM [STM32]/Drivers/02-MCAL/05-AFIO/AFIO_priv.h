/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 15 / 7 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef AFIO_PRIV_H
#define AFIO_PRIV_H

/* REGISTERS */
typedef struct{
	volatile u32 AFIO_EVCR ;
	volatile u32 AFIO_MAPR ;
	volatile u32 AFIO_EXTICR [4] ;
	volatile u32 AFIO_MAPR2 ;
}AFIO_tReg;

#define AFIO ((volatile AFIO_tReg*)0x40010000)

#endif
