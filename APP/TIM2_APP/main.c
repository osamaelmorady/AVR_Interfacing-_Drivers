/*
 * main.c
 *
 *  Created on: Nov 8, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO/DIO_Interface.h"
#include <util/delay.h>
#include "TIM2_Interface.h"

void fun() ;


int main(void)
{

	DIO_EnuSetPinDir(PIN31,OUTPUT) ;

	TIM2_VidInit() ;



while (1)
{

	PWM2_SetDutyCycle(100) ;
		_delay_ms(1000) ;
	PWM2_SetDutyCycle(10) ;
		_delay_ms(1000) ;
	PWM2_SetDutyCycle(50) ;
		_delay_ms(80) ;
	PWM2_SetDutyCycle(80) ;
		_delay_ms(10) ;
}




return 0;
}





void fun()
{


	DIO_EnuTogglePin(PIN16) ;

}

