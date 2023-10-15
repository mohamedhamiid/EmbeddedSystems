/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 04 / 9 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef MUART_PRIV_H
#define MUART_PRIV_H

typedef struct{
	volatile u32 SR    ;
	volatile u32 DR    ;
	volatile u32 BRR   ;
	volatile u32 CR[3] ;
	volatile u32 GTPR  ;
}MUART_tReg;


#define MUART1 ((volatile MUART_tReg*)0x40013800)
#define MUART2 ((volatile MUART_tReg*)0x40004400)
#define MUART3 ((volatile MUART_tReg*)0x40004800)

#endif
