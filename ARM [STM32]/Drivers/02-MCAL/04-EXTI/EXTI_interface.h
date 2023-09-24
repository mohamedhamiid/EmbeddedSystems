/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 15 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/*Options:
 	 	  EXTI_u8Line 	EXTI_LINEn 	  : n = 0->15

 	 	  EXTI_u8Pin  	EXTI_PINn     : n = 0->15

 	 	  EXTI_u8Mode 	EXTI_RISING
 	 	  	  	  	  	EXTI_FALLING
 	 	  	  	  	  	EXTI_ON_EDGE                */
typedef struct{
	u8 EXTI_u8Pin;
	u8 EXTI_u8Port;
	u8 EXTI_u8Mode;
}EXTI_tCfg;

/* Prototypes */
void MEXTI_voidInitEXTI   		 	(EXTI_tCfg * Add_EXTICfg);
void MEXTI_voidEnableEXTI  	 	    (EXTI_tCfg * Add_EXTICfg , void(*Func)(void));
void MEXTI_voidDisableEXTI  	 	(EXTI_tCfg * Add_EXTICfg);
void MEXTI_voidSetPendingFlagEXTI  	(EXTI_tCfg * Add_EXTICfg , void(*Func)(void));
void MEXTI_voidDoSwInterrupt  	 	(EXTI_tCfg * Add_EXTICfg , void(*Func)(void));
void MEXTI_voidResetInterruptFlag  	(u8 Copy_u8Pin);


/* OPTIONS */
/* PINS */
#define EXTI_PIN0       0
#define EXTI_PIN1       1
#define EXTI_PIN2       2
#define EXTI_PIN3       3
#define EXTI_PIN4       4
#define EXTI_PIN5       5
#define EXTI_PIN6       6
#define EXTI_PIN7       7
#define EXTI_PIN8       8
#define EXTI_PIN9       9
#define EXTI_PIN10      10
#define EXTI_PIN11      11
#define EXTI_PIN12      12
#define EXTI_PIN13      13
#define EXTI_PIN14      14
#define EXTI_PIN15      15

/* PORT */
#define EXTI_PORTA      0
#define EXTI_PORTB      1
#define EXTI_PORTC      2

/* MODES */
#define EXTI_RISING     0
#define EXTI_FALLING	1
#define EXTI_ON_EDGE	2



#endif
