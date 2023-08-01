/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 22 / 7 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PeriphId);
void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PeriphId);
void RCC_voidTrimHSI(s8 Copy_s8NoOfTrimmingSteps);
void RCC_voidSetAdcPrescale(u8 Copy_u8Prescale);

/* BUSES */
#define RCC_AHB                           0
#define RCC_APB1                          1
#define RCC_APB2                          2

/* PERIPHIRALS BITS */
#define RCC_GPIO_A                        2
#define RCC_GPIO_B                        3
#define RCC_GPIO_C                        4

#endif
