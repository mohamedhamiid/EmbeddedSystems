/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 27 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MDMA_interface.h"
#include "MDMA_priv.h"
#include "MDMA_config.h"

void MDMA_voidInit(MDMA_structCfg * Add_structChannel){
	/* Check Channel No */
	if(Add_structChannel->ChannelNo < MDMA_CHANNEL_7){
		/* Check if mem to mem */

		MDMA->Channel[Add_structChannel->ChannelNo].CCR |= (Add_structChannel->Priority<<14);

		/* Config priority */
		if(Add_structChannel->Priority<=MDMA_PRIORITY_VERY_HIGH){
			MDMA->Channel[Add_structChannel->ChannelNo].CCR |= (Add_structChannel->Priority<<12);
		}
		else{
			/*Error: Invalid Priority*/
		}

		/* Config Dst Block Length */
		if(Add_structChannel->DstBlockLength<=MDMA_BLOCK_LENGTH_32BITS){
			MDMA->Channel[Add_structChannel->ChannelNo].CCR |= (Add_structChannel->DstBlockLength<<10);
		}
		else{
			/*Error: Invalid Dst Block Length*/
		}

		/* Config Src Block Length */
		if(Add_structChannel->DstBlockLength<=MDMA_BLOCK_LENGTH_32BITS){
			MDMA->Channel[Add_structChannel->ChannelNo].CCR |= (Add_structChannel->SrcBlockLength<<8);
		}
		else{
			/*Error: Invalid Src Block Length*/
		}

		/* Config Src Increment */
		if(Add_structChannel->DstIncrement<=MDMA_BLOCK_LENGTH_32BITS){
			MDMA->Channel[Add_structChannel->ChannelNo].CCR |= (Add_structChannel->SrcBlockLength<<6);
		}
		else{
			/*Error: Invalid Src Block Length*/
		}

		/* Config Circular */
		MDMA->Channel[Add_structChannel->ChannelNo].CCR |= (Add_structChannel->Circular<<5);

		/* Direction */
		SET_BIT(MDMA->Channel[Add_structChannel->ChannelNo].CCR,4);

		/* Config Interrupts */
		MDMA->Channel[Add_structChannel->ChannelNo].CCR |= (Add_structChannel->InterruptError<<3);
		MDMA->Channel[Add_structChannel->ChannelNo].CCR |= (Add_structChannel->InterruptHalfTransfer<<2);
		MDMA->Channel[Add_structChannel->ChannelNo].CCR |= (Add_structChannel->InterruptTransfer<<1);

		/* Config Element Size */
		if(Add_structChannel->ElementSize<=0xFFFF){
			MDMA->Channel[Add_structChannel->ChannelNo].CNDTR = Add_structChannel->ElementSize ;
		}
		else{
			/* Error : Invalid Element Size */
		}

	}
	else{
		/* Error: Invalid Channel No */
	}
}
void MDMA_voidStartNoInterrupt(MDMA_structCfg * Add_structChannel){

		/* Make Sure DMA disabled */
		CLR_BIT(MDMA->Channel[Add_structChannel->ChannelNo].CCR , 0);

		/* Config Dst Address */
		MDMA->Channel[Add_structChannel->ChannelNo].CPAR = (u32)Add_structChannel->DstAddress ;

		/* Config Src Address */
		MDMA->Channel[Add_structChannel->ChannelNo].CMAR = (u32)Add_structChannel->SrcAddress ;

		/* Start DMA */
		MDMA->Channel[Add_structChannel->ChannelNo].CCR |= 1 ;
}
void MDMA_voidStartWithInterrupt(MDMA_structCfg * Add_structChannel,
			  void(*Copy_TransferCompleteFunc)(void),
			  void(*Copy_HalfTransferCompleteFunc)(void),
			  void(*Copy_ErrorFunc)(void)){
	/* Make Sure DMA disabled */
	CLR_BIT(MDMA->Channel[Add_structChannel->ChannelNo].CCR , 0);

	/* Assign DMA ISR functions */
	MDMA_CallBack[Add_structChannel->ChannelNo][0] = Copy_TransferCompleteFunc ;
	MDMA_CallBack[Add_structChannel->ChannelNo][1] = Copy_HalfTransferCompleteFunc ;
	MDMA_CallBack[Add_structChannel->ChannelNo][2] = Copy_ErrorFunc ;

	MDMA_voidStartNoInterrupt(Add_structChannel);
}
void DMA1_Channel1_IRQHandler(void){

	/* Check that there is Function and flag of complete transfer is raised */
	if(MDMA_CallBack[0][0]!=NULL && (GET_BIT(MDMA->ISR,1)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[0][0]();
		/* Clears The Flag */
		MDMA->IFCR = 0x2 ;
	}
	/* Check that there is Function and flag of Half complete transfer is raised */
	if(MDMA_CallBack[0][1]!=NULL && (GET_BIT(MDMA->ISR,2)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[0][1]();
		/* Clears The Flag */
		MDMA->IFCR = 0x4 ;
	}
	/* Check that there is Function and flag of Error in transfer is raised */
	if(MDMA_CallBack[0][2]!=NULL && (GET_BIT(MDMA->ISR,3)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[0][2]();
		/* Clears The Flag */
		MDMA->IFCR = 0x8 ;
	}
	MDMA->IFCR = 0x1 ;
}
void DMA1_Channel2_IRQHandler(void){
	/* Check that there is Function and flag of complete transfer is raised */
	if(MDMA_CallBack[1][0]!=NULL && (GET_BIT(MDMA->ISR,5)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[1][0]();
		/* Clears The Flag */
		MDMA->IFCR = 0x20 ;
	}
	/* Check that there is Function and flag of Half complete transfer is raised */
	if(MDMA_CallBack[1][1]!=NULL && (GET_BIT(MDMA->ISR,6)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[1][1]();
		/* Clears The Flag */
		MDMA->IFCR = 0x40 ;
	}
	/* Check that there is Function and flag of Error in transfer is raised */
	if(MDMA_CallBack[1][2]!=NULL && (GET_BIT(MDMA->ISR,7)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[1][2]();
		/* Clears The Flag */
		MDMA->IFCR = 0x80 ;
	}
	MDMA->IFCR = 0x10 ;
}
void DMA1_Channel3_IRQHandler(void){
	/* Check that there is Function and flag of complete transfer is raised */
	if(MDMA_CallBack[2][0]!=NULL && (GET_BIT(MDMA->ISR,9)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[2][0]();
		/* Clears The Flag */
		MDMA->IFCR = 0x200 ;
	}
	/* Check that there is Function and flag of Half complete transfer is raised */
	if(MDMA_CallBack[2][1]!=NULL && (GET_BIT(MDMA->ISR,10)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[2][1]();
		/* Clears The Flag */
		MDMA->IFCR = 0x400 ;
	}
	/* Check that there is Function and flag of Error in transfer is raised */
	if(MDMA_CallBack[2][2]!=NULL && (GET_BIT(MDMA->ISR,11)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[2][2]();
		/* Clears The Flag */
		MDMA->IFCR = 0x800 ;
	}
	MDMA->IFCR = 0x100 ;
}
void DMA1_Channel4_IRQHandler(void){
	/* Check that there is Function and flag of complete transfer is raised */
	if(MDMA_CallBack[3][0]!=NULL && (GET_BIT(MDMA->ISR,13)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[3][0]();
		/* Clears The Flag */
		MDMA->IFCR = 0x2000 ;
	}
	/* Check that there is Function and flag of Half complete transfer is raised */
	if(MDMA_CallBack[3][1]!=NULL && (GET_BIT(MDMA->ISR,14)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[3][1]();
		/* Clears The Flag */
		MDMA->IFCR = 0x4000 ;
	}
	/* Check that there is Function and flag of Error in transfer is raised */
	if(MDMA_CallBack[3][2]!=NULL && (GET_BIT(MDMA->ISR,15)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[3][2]();
		/* Clears The Flag */
		MDMA->IFCR = 0x8000 ;
	}
	MDMA->IFCR = 0x1000 ;
}
void DMA1_Channel5_IRQHandler(void){
	/* Check that there is Function and flag of complete transfer is raised */
	if(MDMA_CallBack[4][0]!=NULL && (GET_BIT(MDMA->ISR,17)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[4][0]();
		/* Clears The Flag */
		MDMA->IFCR = 0x20000 ;
	}
	/* Check that there is Function and flag of Half complete transfer is raised */
	if(MDMA_CallBack[4][1]!=NULL && (GET_BIT(MDMA->ISR,18)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[4][1]();
		/* Clears The Flag */
		MDMA->IFCR = 0x40000 ;
	}
	/* Check that there is Function and flag of Error in transfer is raised */
	if(MDMA_CallBack[4][2]!=NULL && (GET_BIT(MDMA->ISR,19)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[4][2]();
		/* Clears The Flag */
		MDMA->IFCR = 0x80000 ;
	}
	MDMA->IFCR = 0x10000 ;

}
void DMA1_Channel6_IRQHandler(void){
	/* Check that there is Function and flag of complete transfer is raised */
	if(MDMA_CallBack[5][0]!=NULL && (GET_BIT(MDMA->ISR,21)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[5][0]();
		/* Clears The Flag */
		MDMA->IFCR = 0x200000 ;
	}
	/* Check that there is Function and flag of Half complete transfer is raised */
	if(MDMA_CallBack[5][1]!=NULL && (GET_BIT(MDMA->ISR,22)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[5][1]();
		/* Clears The Flag */
		MDMA->IFCR = 0x400000 ;
	}
	/* Check that there is Function and flag of Error in transfer is raised */
	if(MDMA_CallBack[5][2]!=NULL && (GET_BIT(MDMA->ISR,23)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[5][2]();
		/* Clears The Flag */
		MDMA->IFCR = 0x800000 ;
	}
	MDMA->IFCR = 0x100000 ;
}
void DMA1_Channel7_IRQHandler(void){
	/* Check that there is Function and flag of complete transfer is raised */
	if(MDMA_CallBack[6][0]!=NULL && (GET_BIT(MDMA->ISR,25)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[6][0]();
		/* Clears The Flag */
		MDMA->IFCR = 0x2000000 ;
	}
	/* Check that there is Function and flag of Half complete transfer is raised */
	if(MDMA_CallBack[6][1]!=NULL && (GET_BIT(MDMA->ISR,26)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[6][1]();
		/* Clears The Flag */
		MDMA->IFCR = 0x4000000 ;
	}
	/* Check that there is Function and flag of Error in transfer is raised */
	if(MDMA_CallBack[6][2]!=NULL && (GET_BIT(MDMA->ISR,27)== 1)){
		/* Execute the corresponding FUNCTION */
		MDMA_CallBack[6][2]();
		/* Clears The Flag */
		MDMA->IFCR = 0x8000000 ;
	}
	MDMA->IFCR = 0x1000000 ;

}


