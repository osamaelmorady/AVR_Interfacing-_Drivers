/*
 * main.c
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "7SEG/_7SEG_Interface.h"
#include "ADC_Interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{

_7SEG_VidInit() ;


ADC_EnuInit() ;
ADC_EnuEnable() ;
ADC_EnuAutoTriggering(HIGH) ;
ADC_EnuSelectChannel(PIN0) ;

u32 Reading ;

while(1)
{

	ADC_EnuStartConversion() ;
	ADC_EnuPolling() ;
	ADC_EnuRead(&Reading) ;

	Reading=Reading/100 ;

	_7SEG_VidShowNumber(Reading) ;

}


}
