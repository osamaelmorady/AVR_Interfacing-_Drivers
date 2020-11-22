/*
 * main.c
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO/DIO_Interface.h"
#include "_7SEG_Interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>




int main(void)
{

_7SEG_VidInit() ;



while(1)
{
	//DIO_EnuSetPortVal(PORTD,0XFF) ;



for (u8 i=0;i<=9;i++)
{
	_7SEG_VidShowNumber(i) ;
	_7SEG_VidShowNumber('.') ;
	_delay_ms(1000) ;
}



}

}
