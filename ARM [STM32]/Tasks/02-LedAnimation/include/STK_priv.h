/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 20 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef STK_PRIV_H
#define STK_PRIV_H

/*		Register Definitions		*/
typedef struct {
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VALUE ;
	volatile u32 CALIB ;
}STK_tReg;

#define STK	   ((volatile STK_tReg*)0xE000E010)

/*		Options		*/
#define STK_CLK_SOURCE_AHB_DIV_8         0b000
#define STK_CLK_SOURCE_AHB       	   	 0b100

/* Call Back Func */
static void(*MSTK_CallBack)(void);

/* Externed Variable from RCC contain Clock freq in MHZ */
extern u8 Global_u8CurrClkFreq;

/* Variable to determine SysTick Clock freq in MHZ */
u8 Global_u8STKClock=1;

/* Variable for Interval Mode  */
static u8 Global_u8SingleInterval=0;


#endif
