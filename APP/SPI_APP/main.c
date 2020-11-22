/*
 * main.c
 *
 *  Created on: Nov 15, 2020
 *      Author: Osama Elmorady
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "DIO/DIO_Interface.h"
#include "SPI_Interface.h"

#include <util/delay.h>






	u8 data_sent='A' ;



int main (void)
{


	SPI_VidInit(MASTER) ;

	DIO_EnuSetPinDir(PIN0,INPUT) ;
	DIO_EnuSetPinVal(PIN0,HIGH) ;




while (1) {

	SPI_VidSendData(data_sent)  ;

	_delay_ms(500) ;

}

return 0 ;
}






















