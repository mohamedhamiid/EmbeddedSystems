/********************************************************************************************/
/* Author  : Mohamed Abdel Hamid                                                            */
/* Date    : 22 / 7 / 2023                                                                  */
/* Version : V01                                                                            */
/********************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_priv.h"
#include "RCC_config.h"

u8 Global_u8CurrClkFreq = 0 ;

void RCC_voidInitSysClock(void){
	
	/* Choosing Clock Type */
	#if	RCC_CLOCK_TYPE == RCC_HSE_RC
		#if RCC_EXT_CLK_FREQ_MHZ <= RCC_CLK_EXT_RC_MAX_VALUE
			RCC_CR   = 0x00050000 ; 					  /* Enable HSE | Enable ByPass */
			RCC_CFGR = 0x00000001 ;					      /* Sys Clk switch = HSE */
			Global_u8CurrClkFreq = RCC_EXT_CLK_FREQ_MHZ ; /* Store the final freq */
		#else
			#error ("The RC Clock exceeds MAX value")
		#endif
		
	#elif RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		#if RCC_EXT_CLK_FREQ_MHZ <= RCC_CLK_EXT_CRYSTAL_MAX_VALUE
			RCC_CR   = 0x00010000 ; 					  /* Enable HSE */
			RCC_CFGR = 0x00000001 ; 					  /* Sys Clk switch = HSE */
			Global_u8CurrClkFreq = RCC_EXT_CLK_FREQ_MHZ ; /* Store the final freq */
		#else
			#error ("The Crystal Clock exceeds MAX value")
		#endif
		
	#elif	RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081 ; 						/* Enable HSI + Trimming = 0 */
		RCC_CFGR = 0x00000000 ;
		Global_u8CurrClkFreq = RCC_CLK_HSI_MAX_VALUE ;  /* Store the final freq */
		
	#elif	RCC_CLOCK_TYPE == RCC_PLL
			#if RCC_PLL_INPUT == RCC_PLL_INPUT_HSI_DIV_2
				#if ((RCC_CLK_HSI_MAX_VALUE/2) * RCC_PLL_MUL_VAL) <= RCC_CLK_SYS_MAX_VALUE 
					RCC_CFGR = ((RCC_PLL_MUL_VAL-2) << 18) ; /* Multiply Value */
					RCC_CR     = 0x01000081 ; 				 /* Enable HSI | Trimming = 0 | Enable PLL */
					RCC_CFGR  |= 0x00000002 ; 				 /* Sys switch = PLL */
					Global_u8CurrClkFreq = (RCC_CLK_HSI_MAX_VALUE/2) * RCC_PLL_MUL_VAL ; /* Store the final freq */
				#else
					#error ("The PLL Clock exceeds MAX value")
				#endif
			
			#elif RCC_PLL_INPUT == RCC_PLL_INPUT_HSE_RC_DIV_2
				#if ((RCC_EXT_CLK_FREQ_MHZ/2) * RCC_PLL_MUL_VAL) <= RCC_CLK_SYS_MAX_VALUE
					RCC_CFGR = ((RCC_PLL_MUL_VAL-2) << 18) ; 	/* Multiply Value */
					RCC_CR     = 0x01050000 ; 					/* Enable HSE | Enable ByPass | Enable PLL */
					RCC_CFGR  |= 0x00030002 ; 					/* Sys switch = PLL | Pll src = HSE | Pll input = HSE / 2 */
					Global_u8CurrClkFreq = (RCC_EXT_CLK_FREQ_MHZ/2) * RCC_PLL_MUL_VAL ; /* Store the final freq */
				#else
					#error ("The PLL Clock exceeds MAX value")
				#endif
				
			#elif RCC_PLL_INPUT == RCC_PLL_INPUT_HSE_RC
				#if (RCC_EXT_CLK_FREQ_MHZ * RCC_PLL_MUL_VAL) <= RCC_CLK_SYS_MAX_VALUE
					RCC_CFGR = ((RCC_PLL_MUL_VAL-2) << 18) ; /* Multiply Value */
					RCC_CR     = 0x01050000 ; 				 /* Enable HSE | Enable ByPass | Enable PLL */
					RCC_CFGR  |= 0x00010002 ; 				 /* Sys switch = PLL | Pll src = HSE | Pll input = HSE */
					Global_u8CurrClkFreq = RCC_EXT_CLK_FREQ_MHZ * RCC_PLL_MUL_VAL ; /* Store the final freq */
				#else
					#error ("The PLL Clock exceeds MAX value")
				#endif
			
			#elif RCC_PLL_INPUT == RCC_PLL_INPUT_HSE_CRYSTAL
				#if (RCC_EXT_CLK_FREQ_MHZ * RCC_PLL_MUL_VAL) <= RCC_CLK_SYS_MAX_VALUE
					RCC_CFGR = ((RCC_PLL_MUL_VAL-2) << 18) ; /* Multiply Value */
					RCC_CR     = 0x01010000 ; 				 /* Enable HSE | Enable PLL */
					RCC_CFGR  |= 0x00010002 ; 				 /* Sys switch = PLL | Pll src = HSE | Pll input = HSE */
					Global_u8CurrClkFreq = RCC_EXT_CLK_FREQ_MHZ * RCC_PLL_MUL_VAL ; /* Store the final freq */
				#else
					#error ("The PLL Clock exceeds MAX value")
				#endif
				
			#elif RCC_PLL_INPUT == RCC_PLL_INPUT_HSE_CRYSTAL_DIV_2
				#if ((RCC_EXT_CLK_FREQ_MHZ/2) * RCC_PLL_MUL_VAL) <= RCC_CLK_SYS_MAX_VALUE
					RCC_CFGR = ((RCC_PLL_MUL_VAL-2) << 18) ; /* Multiply Value */
					RCC_CR     = 0x01010000 ; 				 /* Enable HSE | Enable PLL */
					RCC_CFGR  |= 0x00030002 ; 				 /* Sys switch = PLL | Pll src = HSE | Pll input = HSE/2 */
					Global_u8CurrClkFreq = (RCC_EXT_CLK_FREQ_MHZ/2) * RCC_PLL_MUL_VAL ; /* Store the final freq */
				#else
					#error ("The PLL Clock exceeds MAX value")
				#endif
			#else   
				#error ("You Choose Invalid PLL Input")
			#endif
	#else
		#error ("You Choose Invalid Clock Type")
	#endif
	/* End of Choosing Clock Type */
	/***********************************************************************************************/
	
	/* Choose Buses Prescaling Factor */
	
			  /* AHB */
	#if RCC_AHB_DIV_FACTOR == RCC_AHB_DIV_FACTOR_1
		CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE);
		
	#elif RCC_AHB_DIV_FACTOR == RCC_AHB_DIV_FACTOR_2
		RCC_CFGR |= 0x00000080 ;
		
	#elif RCC_AHB_DIV_FACTOR == RCC_AHB_DIV_FACTOR_4
		RCC_CFGR |= 0x00000081 ;
		
	#elif RCC_AHB_DIV_FACTOR == RCC_AHB_DIV_FACTOR_8
		RCC_CFGR |= 0x00000082 ;
		
	#elif RCC_AHB_DIV_FACTOR == RCC_AHB_DIV_FACTOR_16
		RCC_CFGR |= 0x00000083 ;
		
	#elif RCC_AHB_DIV_FACTOR == RCC_AHB_DIV_FACTOR_64
		RCC_CFGR |= 0x00000084 ;
		
	#elif RCC_AHB_DIV_FACTOR == RCC_AHB_DIV_FACTOR_128
		RCC_CFGR |= 0x00000085 ;
		
	#elif RCC_AHB_DIV_FACTOR == RCC_AHB_DIV_FACTOR_256
		RCC_CFGR |= 0x00000086 ;
		
	#elif RCC_AHB_DIV_FACTOR == RCC_AHB_DIV_FACTOR_512
		RCC_CFGR |= 0x00000087 ;
	
	#else
		#error ("Invalid AHB division factor")
		
	#endif
	
			  /* APB2 */
	#if RCC_APB2_DIV_FACTOR == RCC_APB2_DIV_FACTOR_1
		CLR_BIT(RCC_CFGR,RCC_CFGR_PPRE2);
		
	#elif RCC_APB2_DIV_FACTOR == RCC_APB2_DIV_FACTOR_2
		RCC_CFGR |= 0x00002000 ;
	
	#elif RCC_APB2_DIV_FACTOR == RCC_APB2_DIV_FACTOR_4
		RCC_CFGR |= 0x00002001 ;
	
	#elif RCC_APB2_DIV_FACTOR == RCC_APB2_DIV_FACTOR_8
		RCC_CFGR |= 0x00002002 ;
	
	#elif RCC_APB2_DIV_FACTOR == RCC_APB2_DIV_FACTOR_16
		RCC_CFGR |= 0x00002003 ;
		
	#else
		#error ("Invalid APB2 division factor")
	
	#endif
	
			  /* APB1 */
		/* Freq mustn't exceed 36 MHZ */
	#if RCC_APB1_DIV_FACTOR == RCC_APB1_DIV_FACTOR_1
		#if (Global_u8CurrClkFreq / RCC_APB1_DIV_FACTOR_1) <= RCC_CLK_APB1_MAX_VALUE
			CLR_BIT(RCC_CFGR,RCC_CFGR_PPRE1);
		#else 
			#error ("APB1 Bus speed exceeds Max Value")
		#endif
	
	#elif RCC_APB1_DIV_FACTOR == RCC_APB1_DIV_FACTOR_2
		#if (Global_u8CurrClkFreq / RCC_APB1_DIV_FACTOR_2) <= RCC_CLK_APB1_MAX_VALUE
			RCC_CFGR |= 0x00000400 ;
		#else 
			#error ("APB1 Bus speed exceeds Max Value")
		#endif
	
	#elif RCC_APB1_DIV_FACTOR == RCC_APB1_DIV_FACTOR_4
		#if (Global_u8CurrClkFreq / RCC_APB1_DIV_FACTOR_4) <= RCC_CLK_APB1_MAX_VALUE
			RCC_CFGR |= 0x00000401 ;
		#else 
			#error ("APB1 Bus speed exceeds Max Value")
		#endif
		
	#elif RCC_APB1_DIV_FACTOR == RCC_APB1_DIV_FACTOR_8
		#if (Global_u8CurrClkFreq / RCC_APB1_DIV_FACTOR_8) <= RCC_CLK_APB1_MAX_VALUE
			RCC_CFGR |= 0x00000402 ;
		#else 
			#error ("APB1 Bus speed exceeds Max Value")
		#endif
	
	#elif RCC_APB1_DIV_FACTOR == RCC_APB1_DIV_FACTOR_16
		#if (Global_u8CurrClkFreq / RCC_APB1_DIV_FACTOR_16) <= RCC_CLK_APB1_MAX_VALUE
			RCC_CFGR |= 0x00000403 ;
		#else 
			#error ("APB1 Bus speed exceeds Max Value")
		#endif
	
	#else
		#error ("Invalid APB1 division factor")
	
	#endif
	/* End of Choose Buses Prescaling Factor */
	/***********************************************************************************************/
	
	/* Choose Clock Security System */
	#if	RCC_CLOCK_SECURITY_SYSTEM == RCC_CLOCK_SECURITY_SYSTEM_OFF
		CLR_BIT(RCC_CR,RCC_CR_CSS);
	#elif	RCC_CLOCK_SECURITY_SYSTEM == RCC_CLOCK_SECURITY_SYSTEM_ON
		SET_BIT(RCC_CR,RCC_CR_CSS)
	#endif
	/* End of Choosing Clock Security System */
	/***********************************************************************************************/
}

void RCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PeriphId){
	// Validate input
	if(Copy_u8PeriphId<32 && Copy_u8PeriphId >=0){
		switch(Copy_u8BusId){
			case RCC_AHB  : SET_BIT(RCC_AHBENR,Copy_u8PeriphId);  break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PeriphId); break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PeriphId); break;
		}
	}
	else{
		/* ERROR */
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PeriphId){
	if(Copy_u8PeriphId<32 && Copy_u8PeriphId >=0){
		switch(Copy_u8BusId){
			case RCC_AHB  : CLR_BIT(RCC_AHBENR,Copy_u8PeriphId);  break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PeriphId); break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PeriphId); break;
		}
	}
	else{
		/* ERROR */
	}
}

void RCC_voidTrimHSI(s8 Copy_s8NoOfTrimmingSteps){
	// Each Step will inc/dec 40 KHZ
	s8 Loc_u8FinalTrimVal = (((RCC_CR & 0xF8) >> 3) + Copy_s8NoOfTrimmingSteps) ; /* Trimming Current Value + Number of Steps
																				   0xF8 --> Mask to get bits[3:7] */																						
	if(Loc_u8FinalTrimVal>=0 && Loc_u8FinalTrimVal<32)
		RCC_CR |= (((u8)Loc_u8FinalTrimVal)<<3);
	else{}
		/* ERROR */
}

void RCC_voidSetAdcPrescale(u8 Copy_u8Prescale){
	switch(Copy_u8Prescale){
		
		case 2 : RCC_CFGR |= 0x00000000 ; break ;
		case 4 : RCC_CFGR |= 0x00004000 ; break ;
		case 6 : RCC_CFGR |= 0x00008000 ; break ;
		case 8 : RCC_CFGR |= 0x0000C000 ; break ;
		default : /* Error */           ; break ;
	} 
}

