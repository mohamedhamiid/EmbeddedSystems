/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 26 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/

#ifndef DAC_INTERFACE_H
#define DAC_INTERFACE_H

typedef struct{
	MDIO_enumPorts port     ;
	MDIO_enumPins  startPin ;
	u8 samplingFreqInUs     ;

}HDAC_structCfg;

void DAC_voidStart(HDAC_structCfg* Add_structCfg);
void HDAC_voidSetConvertedData(u8*Add_u8DataArr,u32 Copy_u32ArrSize);

#endif
