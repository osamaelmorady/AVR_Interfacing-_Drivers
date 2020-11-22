/*
 * SPI_Interface.h
 *
 *  Created on: Nov 15, 2020
 *      Author: Osama Elmorady
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_



#include "LIB/ERROR_STATE.h"
#include "SPI_Config.h"





ErrorState SPI_VidInit(u8 Copy_U8MCUModeSelect) ;





ErrorState SPI_VidSendData(u8 Copy_U8TransmittedValue) ;





ErrorState SPI_VidReceiveData(u8 * Copy_U8ReceivedValue) ;



ErrorState SPI_CallBackFun(void (*Ptr)(void)) ;





#endif /* SPI_INTERFACE_H_ */
