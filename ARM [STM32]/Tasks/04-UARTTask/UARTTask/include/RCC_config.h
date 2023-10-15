/******************************************************************************/
/* Author  : Mohamed Abdel Hamid                                              */
/* Date    : 22 / 7 / 2023                                                    */
/* Version : V01                                                              */
/******************************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Clock Type Configuration */

/* Options:	RCC_HSE_RC
			RCC_HSE_CRYSTAL
			RCC_HSI
			RCC_PLL */			
#define RCC_CLOCK_TYPE	            RCC_PLL


/* Note: Use these options only if you selected PLL Clock Type*/
#if		RCC_CLOCK_TYPE == RCC_PLL
/* Options:	RCC_PLL_INPUT_HSI_DIV_2
			RCC_PLL_INPUT_HSE_DIV_2
			RCC_PLL_INPUT_HSE */
#define RCC_PLL_INPUT               RCC_PLL_INPUT_HSE_CRYSTAL

/* Options:	2 -> 16 */
#define RCC_PLL_MUL_VAL             9
#endif

/* Note: Use these options only if you selected HSE Clock Type */
#if RCC_CLOCK_TYPE == RCC_HSE_RC || RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL || RCC_PLL_INPUT != RCC_PLL_INPUT_HSI_DIV_2
#define RCC_EXT_CLK_FREQ_MHZ        8
#endif

/* End of Clock Type Configuration */
/******************************************************************************/

/* Division Factor of Buses Configuration */

		/* AHB */
/* Options:	RCC_AHB_DIV_FACTOR_1 
			RCC_AHB_DIV_FACTOR_2 
			RCC_AHB_DIV_FACTOR_4 
			RCC_AHB_DIV_FACTOR_8 
			RCC_AHB_DIV_FACTOR_16 
			RCC_AHB_DIV_FACTOR_64 
			RCC_AHB_DIV_FACTOR_128 
			RCC_AHB_DIV_FACTOR_256 
			RCC_AHB_DIV_FACTOR_512 */
/* Note : Division Factor Here is from System Clock*/
#define RCC_AHB_DIV_FACTOR           RCC_AHB_DIV_FACTOR_1 

		/* APB2 */
/* Options:	RCC_APB2_DIV_FACTOR_1 
			RCC_APB2_DIV_FACTOR_2 
			RCC_APB2_DIV_FACTOR_4 
			RCC_APB2_DIV_FACTOR_8 
			RCC_APB2_DIV_FACTOR_16 */
/* Note : Division Factor Here is from AHB */
#define RCC_APB2_DIV_FACTOR          RCC_APB2_DIV_FACTOR_1 

		/* APB1 */
/* Options:	RCC_APB1_DIV_FACTOR_1 
			RCC_APB1_DIV_FACTOR_2 
			RCC_APB1_DIV_FACTOR_4 
			RCC_APB1_DIV_FACTOR_8 
			RCC_APB1_DIV_FACTOR_16 */
/* Note : - Division Factor Here is from AHB
		 - Mustn't exceed 36 MHZ */
#define RCC_APB1_DIV_FACTOR          RCC_APB1_DIV_FACTOR_2

/* End of Division Factor of Buses Configuration */
/******************************************************************************/
/* Options:	RCC_CLOCK_SECURITY_SYSTEM_OFF
			RCC_CLOCK_SECURITY_SYSTEM_ON */
#define RCC_CLOCK_SECURITY_SYSTEM    RCC_CLOCK_SECURITY_SYSTEM_OFF

#endif
