/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 22 / 7 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef RCC_PRIV_H
#define RCC_PRIV_H

/* Register Definition */
#define RCC_CR          *((u32*)0x40021000)
#define RCC_CFGR        *((u32*)0x40021004)
#define RCC_CIR         *((u32*)0x40021008)
#define RCC_APB2RSTR    *((u32*)0x4002100C)
#define RCC_APB1RSTR    *((u32*)0x40021010)
#define RCC_AHBENR      *((u32*)0x40021014)
#define RCC_APB2ENR     *((u32*)0x40021018)
#define RCC_APB1ENR     *((u32*)0x4002101C)
#define RCC_BDCR        *((u32*)0x40021020)
#define RCC_CSR         *((u32*)0x40021024)
#define RCC_AHBSTR      *((u32*)0x40021024)

/* Clock Types */
#define RCC_HSE_RC       	              0
#define RCC_HSE_CRYSTAL                   1
#define RCC_HSI                           2
#define RCC_PLL                           3

/* PLL Input */
#define RCC_PLL_INPUT_HSI_DIV_2           0
#define RCC_PLL_INPUT_HSE_CRYSTAL_DIV_2   1
#define RCC_PLL_INPUT_HSE_CRYSTAL		  2
#define RCC_PLL_INPUT_HSE_RC_DIV_2        3
#define RCC_PLL_INPUT_HSE_RC		      4

/* Clock Security System */
#define RCC_CLOCK_SECURITY_SYSTEM_OFF     0 
#define RCC_CLOCK_SECURITY_SYSTEM_ON      1 

/* Division Factors */
	/* AHB */
#define RCC_AHB_DIV_FACTOR_1              1
#define	RCC_AHB_DIV_FACTOR_2			  2			  
#define	RCC_AHB_DIV_FACTOR_4 			  4			   
#define	RCC_AHB_DIV_FACTOR_8 			  8				
#define	RCC_AHB_DIV_FACTOR_16			  16
#define	RCC_AHB_DIV_FACTOR_64			  64
#define	RCC_AHB_DIV_FACTOR_128			  128	
#define	RCC_AHB_DIV_FACTOR_256 			  256
#define	RCC_AHB_DIV_FACTOR_512			  512
	/* APB2 */ 
#define	RCC_APB2_DIV_FACTOR_1			  0			
#define RCC_APB2_DIV_FACTOR_2 			  1
#define RCC_APB2_DIV_FACTOR_4 			  2
#define RCC_APB2_DIV_FACTOR_8 			  3
#define RCC_APB2_DIV_FACTOR_16			  4
	/* APB1 */ 
#define	RCC_APB1_DIV_FACTOR_1			  1			
#define RCC_APB1_DIV_FACTOR_2 			  2
#define RCC_APB1_DIV_FACTOR_4 			  4
#define RCC_APB1_DIV_FACTOR_8 			  8
#define RCC_APB1_DIV_FACTOR_16			  16

/* REGISTER PINS */
// RCC_CR
#define RCC_CR_CSS                        19
// RCC_CFGR
#define RCC_CFGR_HPRE                     7
#define RCC_CFGR_PPRE2                    13
#define RCC_CFGR_PPRE1                    10

/* MAX VALUES */
#define RCC_CLK_SYS_MAX_VALUE             72      
#define RCC_CLK_EXT_RC_MAX_VALUE          25      
#define RCC_CLK_EXT_CRYSTAL_MAX_VALUE     16      
#define RCC_CLK_APB1_MAX_VALUE            36      
#define RCC_CLK_IO_MAX_VALUE              50 
#define RCC_CLK_HSI_MAX_VALUE             8


   

#endif 

