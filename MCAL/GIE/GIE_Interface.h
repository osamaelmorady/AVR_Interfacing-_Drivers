/*
 * GIE_Interface.h
 *
 *  Created on: Nov 5, 2020
 *      Author: Osama Elmorady
 */

#ifndef _GIE_INTERFACE_H_
#define _GIE_INTERFACE_H_

#include "LIB/ERROR_STATE.h"





/*******************************************/
/****** All Interrupt Enable Function ******/
/*******************************************/
ErrorState GIE_EnuEnable(void);






/********************************************/
/****** All Interrupt Disable Function ******/
/********************************************/
ErrorState GIE_EnuDisable(void);





#endif 
