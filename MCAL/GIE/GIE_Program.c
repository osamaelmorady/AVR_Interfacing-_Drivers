/*
 * GIE_Program.c
 *
 *  Created on: Nov 5, 2020
 *      Author: Osama Elmorady
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/ERROR_STATE.h"

#include "GIE_Private.h"
#include "GIE_Config.h"







/*******************************************/
/****** All Interrupt Enable Function ******/
/*******************************************/
ErrorState GIE_EnuEnable(void)
{
	ErrorState error = ES_NOK ;

	SET_BIT(SREG,SREG_INTBIT) ;	

	 error = ES_OK ;

	 return error ;
}



/********************************************/
/****** All Interrupt Disable Function ******/
/********************************************/
ErrorState GIE_EnuDisable(void)
{
	ErrorState error = ES_NOK ;

	CLR_BIT(SREG,SREG_INTBIT) ;

	 error = ES_OK ;

	 return error ;
}







