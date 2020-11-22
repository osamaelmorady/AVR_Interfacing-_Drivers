/*
 * main.c
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO/DIO_Interface.h"
#include "LCD_Interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>




int main(void)
{

LCD_EnuInit() ;




while(1)
{

LCD_EnuSetPosition(0,2) ;
LCD_EnuSendData('1') ;


LCD_EnuSetPosition(1,2) ;
LCD_EnuWriteString("Hello World") ;
}



return 0 ;
}


