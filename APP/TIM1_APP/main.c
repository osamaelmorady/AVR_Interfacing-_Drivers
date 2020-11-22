/*
 * main.c
 *
 *  Created on: Nov 8, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO/DIO_Interface.h"
#include "TIM1_Interface.h"

#include <util/delay.h>



int main(void)
{

DIO_EnuSetPinDir(PIN29,OUTPUT) ;
DIO_EnuSetPinDir(PIN28,OUTPUT) ;


TIM1_VidInit() ;










//TIMER_VidSetCallBack(DIO_VidTogglePinValue(PORTC,PIN0)) ;


while (1)
{


for(u8 i=0 ; i<100;i++)
{
	PWM_SetDutyCycle(i) ;
	_delay_ms(10) ;

}

_delay_ms(1000) ;

}


}
