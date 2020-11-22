/*
 * main.c
 *
 *  Created on: Nov 5, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/STD_TYPES.h"
#include "DIO_Interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
DIO_EnuSetPinDir(PIN25,OUTPUT) ;

DIO_EnuSetPinDir(PIN24,INPUT) ;
DIO_EnuSetPinVal(PIN24,HIGH) ;


DIO_EnuSetPinVal(PIN25,HIGH) ;
_delay_ms(2000) ;
DIO_EnuSetPinVal(PIN25,LOW) ;
_delay_ms(500) ;

DIO_EnuTogglePin(PIN25) ;
_delay_ms(1000) ;
DIO_EnuSetPinVal(PIN25,LOW) ;


u32 reading ;
while(1)
{

	DIO_EnuGetPinVal(PIN24,&reading) ;

	if (!reading)
	{
		DIO_EnuSetPinVal(PIN25,HIGH) ;
	}
	else
	{
		DIO_EnuSetPinVal(PIN25,LOW) ;
	}


}


return 0 ;
}
