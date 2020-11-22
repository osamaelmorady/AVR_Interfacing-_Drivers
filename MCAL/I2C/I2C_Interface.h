/*
 * I2C_Interface.h
 *
 *  Created on: Nov 22, 2020
 *      Author: Osama Elmorady
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_


#include "LIB/ERROR_STATE.h"
#include "I2C_Config.h"





ErrorState I2C_EnuInit(void) ;







ErrorState I2C_EnuStartCondition(void) ;


ErrorState I2C_EnuMasterSendAddress(u8 Copy_U8Address,u8 Copy_U8Mode) ;


ErrorState I2C_EnuMasterSendData(u8 Copy_U8Data) ;

ErrorState I2C_EnuMasterReceiveData(u8 * Copy_PU8ReceivedData) ;


ErrorState I2C_EnuReStartCondition(void) ;


ErrorState I2C_EnuStopCondition(void) ;












ErrorState I2C_EnuSlaveCheckAddress(void) ;


ErrorState I2C_EnuSlaveSendData(u8 Copy_U8Data) ;


ErrorState I2C_EnuSlaveReceiveData(u8 * Copy_PU8ReceivedData) ;





























#endif /* I2C_INTERFACE_H_ */
