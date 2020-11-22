/*
 * main.c
 *
 *  Created on: Oct 23, 2020
 *      Author: Osama Elmorady
 */

#include "LIB/STD_TYPES.h"
#include "DIO/DIO_Interface.h"
#define F_CPU 8000000L
#include <util/delay.h>




int main (void)
{

DIO_VidSetPinDir(DDRA,PIN0,OUTPUT) ;
DIO_VidSetPinDir(DDRB,PIN1,INPUT) ;
DIO_VidSetPinValue(PORTB,PIN1,HIGH);
u8 x;

while (1)
{

DIO_VidGetPinValue(PINB,PIN1,&x) ;

if (x==HIGH) {

DIO_VidSetPinValue(PORTA,PIN0,HIGH) ;
}

else if (x==LOW){
DIO_VidTogglePinValue(PORTA,PIN0) ;
_delay_ms(500) ;
}
}
return 0;

}
