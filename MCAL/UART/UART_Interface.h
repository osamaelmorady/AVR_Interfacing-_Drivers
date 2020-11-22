/*
 * UART_Interface.h
 *
 *  Created on: Nov 12, 2020
 *      Author: Osama Elmorady
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "LIB/ERROR_STATE.h"






/*******************************************************/
/*************** UART Initialization *******************/
/*******************************************************/
ErrorState UART_EnuInit(u16 Copy_U16BaudRate) ;








/******************************************************************/
/*************** Send Data From the Transmitter *******************/
/******************************************************************/
ErrorState UART_EnuSendData(u8 Copy_U8Data) ;








/******************************************************************/
/*************** Receive Data From the Receiver *******************/
/******************************************************************/
ErrorState UART_EnuReceiveData(u8 * Copy_PU8Data) ;







/******************************************************************/
/*************** Send a String to the Transmitter *****************/
/******************************************************************/
ErrorState UART_EnuWriteString(u8 Copy_PU8String[] )  ;









/*********************************************************************/
/***********  Write a Sentence ( INT Numbers ) on the Screen *********/
/*********************************************************************/
ErrorState UART_VidWriteIntNum(s32 Copy_S32IntData)  ;









/***********************************************************************/
/***********  Write a Sentense ( Float Numbers ) on the Screen *********/
/***********************************************************************/
ErrorState UART_VidWriteFloatNum(f32 Copy_F32IntData) ;













#endif /* UART_INTERFACE_H_ */
