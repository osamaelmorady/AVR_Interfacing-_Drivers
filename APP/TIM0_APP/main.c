/*
 * main.c
 *
 *  Created on: Nov 8, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO/DIO_Interface.h"
#include "TIM0_Interface.h"


void fun() ;


int main(void)
{

	DIO_EnuSetPinDir(PIN16,OUTPUT) ;

	TIM0_VidInit() ;

	TIMER_VidSetCallBack(fun) ;


while (1)
{
}




return 0;
}



void fun()
{


	DIO_EnuTogglePin(PIN16) ;

}
