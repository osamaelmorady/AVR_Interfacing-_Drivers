/*
 * main.c
 *
 *  Created on: Nov 15, 2020
 *      Author: Osama Elmorady
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "DIO/DIO_Interface.h"

#include "I2C_Interface.h"

#include <util/delay.h>









int main (void)
{


I2C_EnuInit() ;

DIO_EnuSetPinDir(PIN0,OUTPUT) ;

DIO_EnuSetPinVal(PIN0,LOW) ;
_delay_ms(500) ;

while (1) {

	if (I2C_EnuStartCondition() )

	{
		DIO_EnuTogglePin(PIN0) ;
						_delay_ms(200) ;


		if (I2C_EnuMasterSendAddress(0x02,0))

		{
			DIO_EnuTogglePin(PIN0) ;
			_delay_ms(200) ;


			if (I2C_EnuMasterSendData('A'))
			{


				DIO_EnuTogglePin(PIN0) ;
				_delay_ms(200) ;

				I2C_EnuStopCondition() ;


				DIO_EnuTogglePin(PIN0) ;
								_delay_ms(200) ;


			}

		}
	}

_delay_ms(1000) ;
}



return 0 ;
}




