/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 15 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

void AFIO_voidSetEXTIPin(u8 Copy_u8Line , u8 Copy_u8Port);

/* Copy_u8Port Options: */
#define  AFIO_EXTI_PORTA   0b0000
#define  AFIO_EXTI_PORTB   0b0001
#define  AFIO_EXTI_PORTC   0b0010


#endif
