/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 26 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/

#ifndef DAC_PRIV_H
#define DAC_PRIV_H
typedef struct {
	u32 CurrentDataSize ;
	u8* CurrentDataArr  ;
}DAC_tDataInfo;

void HDAC_voidConvertData();
#endif
