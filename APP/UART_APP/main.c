/*
 * main.c
 *
 *  Created on: Nov 12, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "DIO/DIO_Interface.h"
#include "LCD/LCD_Interface.h"

#include "UART_Interface.h"

#include <util/delay.h>


u8 Local_U8Data[100]={};


int main(void)
{

	LCD_VidInit() ;

	UART_EnuInit(9600) ;



while(1)
{


	UART_EnuReadString(Local_U8Data) ;

	LCD_VidWriteString(Local_U8Data) ;

	UART_EnuWriteString(Local_U8Data) ;

}


return 0 ;
}
