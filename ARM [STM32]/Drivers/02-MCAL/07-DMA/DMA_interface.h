/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 27 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef MDMA_INTERFACE_H
#define MDMA_INTERFACE_H

typedef struct{
		 u32* SrcAddress                        ;
		 u32* DstAddress                        ;
		 u16  ElementSize                       ;
		 u8   ChannelNo                :  3     ;
		 u8   DstBlockLength           :  2     ;
		 u8   SrcBlockLength           :  2     ;
		 u8   TransferType             :  1     ;
		 u8   Priority                 :  2     ;
		 u8   Circular                 :  1     ;
		 u8   DstIncrement             :  1     ;
		 u8   SrcIncrement             :  1     ;
		 u8   InterruptTransfer 	   :  1     ;
		 u8   InterruptHalfTransfer    :  1     ;
		 u8   InterruptError    	   :  1     ;
//		 u8   TriggerSource           ;
}MDMA_structCfg;

/* Channel No */
#define MDMA_CHANNEL_1                    0
#define MDMA_CHANNEL_2                    1
#define MDMA_CHANNEL_3                    2
#define MDMA_CHANNEL_4                    3
#define MDMA_CHANNEL_5                    4
#define MDMA_CHANNEL_6                    5
#define MDMA_CHANNEL_7                    6

/* Transfer Type */
#define MDMA_TRANSFER_TYPE_MEM_PERIPH     0
#define MDMA_TRANSFER_TYPE_MEM_MEM        1

/* Priorities */
#define MDMA_PRIORITY_LOW                 0
#define MDMA_PRIORITY_MEDIUM              1
#define MDMA_PRIORITY_HIGH                2
#define MDMA_PRIORITY_VERY_HIGH           3

/* Block Length */
#define MDMA_BLOCK_LENGTH_8BITS           0
#define MDMA_BLOCK_LENGTH_16BITS          1
#define MDMA_BLOCK_LENGTH_32BITS          2

/* Increment */
#define MDMA_INCREMENT_DISABLE            0
#define MDMA_INCREMENT_ENABLE             1

/* Circular */
#define MDMA_CIRCULAR_DISABLE             0
#define MDMA_CIRCULAR_ENABLE              1

/* Interrupts */

#define MDMA_INTERRUPT_TRANSFER_DISABLE        0
#define MDMA_INTERRUPT_TRANSFER_ENBALE         1

#define MDMA_INTERRUPT_HALF_TRANSFER_DISABLE   0
#define MDMA_INTERRUPT_HALF_TRANSFER_ENBALE    1

#define MDMA_INTERRUPT_ERROR_DISABLE           0
#define MDMA_INTERRUPT_ERROR_ENBALE            1

#define MDMA_NO_FUNC                           0


void MDMA_voidInit(MDMA_structCfg * Add_structChannel);

void MDMA_voidStartNoInterrupt(MDMA_structCfg * Add_structChannel);

void MDMA_voidStartWithInterrupt(MDMA_structCfg * Add_structChannel,
							void(*Copy_TransferCompleteFunc)(void),
							void(*Copy_HalfTransferCompleteFunc)(void),
							void(*Copy_ErrorFunc)(void));

#endif
