/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 27 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef MDMA_PRIV_H
#define MDMA_PRIV_H

typedef struct{
	volatile u32 CCR ;
	volatile u32 CNDTR ;
	volatile u32 CPAR ;
	volatile u32 CMAR ;
}MDMA_channel;

typedef struct{
	volatile u32 ISR ;
	volatile u32 IFCR ;
	MDMA_channel Channel[7] ;
}MDMA_tReg;

#define MDMA        ((volatile MDMA_tReg*)0x40020000)

#define RAM_START   0x08000000
#define RAM_END  	0x080003FF

static void (*MDMA_CallBack[7][3])(void)={NULL};
#endif
