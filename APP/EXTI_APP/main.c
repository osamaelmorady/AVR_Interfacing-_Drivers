/*
 * main.c
 *
 *  Created on: Nov 4, 2020
 *      Author: Osama Elmorady
 */

#include "LIB/STD_TYPES.h"

#include "DIO/DIO_Interface.h"
#include "GIE/GIE_Interface.h"
#include "EXTI_Interface.h"

#include <util/delay.h>


void fun(void) ;

int main(void)
{
	DIO_EnuSetPinDir(PIN24,OUTPUT) ;
	DIO_EnuSetPinDir(PIN27,INPUT) ;
	DIO_EnuSetPinVal(PIN27,HIGH) ;

	EXTI_VidInit(INT2) ;

	EXTI_VidEnable(INT2);

	EXTI_SetCallBackFun(INT2,fun) ;



while(1)
{

}



return 0 ;
}



void fun(void)
{
	DIO_EnuTogglePin(PIN24) ;
	_delay_ms(1000) ;
}
