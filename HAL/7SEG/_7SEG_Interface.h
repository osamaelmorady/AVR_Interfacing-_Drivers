/*
 * _7SEG_Interface.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */

#ifndef _7SEG_INTERFACE_H_
#define _7SEG_INTERFACE_H_

#include "LIB/ERROR_STATE.h"

/****************************************************************/
/*************** Initialization of the 7 Segment ****************/
/****************************************************************/
ErrorState _7SEG_VidInit(void) ;





/*************************************************/
/*************** COUNT UP FORM 0-9 ***************/
/*************************************************/
ErrorState _7SEG_VidShowNumber(u8 Local_U8ShowedNumber) ;



#endif /* 7SEG_INTERFACE_H_ */
