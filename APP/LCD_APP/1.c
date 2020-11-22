/*
 * main.c
 *
 *  Created on: Oct 21, 2020
 *      Author: Osama Elmorady
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#define F_CPU 8000000L
#include <util/delay.h>


int main(void)
{

LCD_VidInit() ;


u8 pattern[8][8]={{0x06,0x04,0x0E,0x00,0x06,0x06,0x06,0x06} ,
				  {0x00,0x00,0x00,0x00,0x00,0x15,0xFF,0x0A} ,
				  {0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x00} ,
				  {0x06,0x06,0x06,0x06,0x06,0x07,0x03,0x00},
				  {0x00,0x00,0x00,0x02,0x07,0x1D,0x1F,0x02},
				  {0x00,0x06,0x0A,0x0E,0x02,0x03,0x01,0x00}} ;

u8 pattern2[8][8]={{0x00,0x00,0x00,0x02,0x07,0x1D,0x1F,0x02},
				   {0x00,0x00,0x1C,0x12,0x01,0x1F,0x1F,0x00},
				   {0x00,0x00,0x00,0x08,0x1C,0x17,0x1F,0x08},
				   {0x00,0x00,0x18,0x18,0x18,0x1F,0x1F,0x00},
				   {0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x00}} ;


_delay_ms(1000) ;




while(1)
{

for (u8 i=0;i<6;i++){
	LCD_EnuRecordSpecialChar(pattern[i],i) ;

	LCD_EnuSetPosition(0,14-i) ;

	LCD_EnuWriteSpecialChar(i) ;

	}
	_delay_ms(500) ;

LCD_EnuSendCommand(0x01) ;


for (u8 i=0;i<6;i++){
	LCD_EnuRecordSpecialChar(pattern2[i],i) ;

	LCD_EnuSetPosition(0,6-i) ;

	LCD_EnuWriteSpecialChar(i) ;

	}
	_delay_ms(500) ;

LCD_EnuSendCommand(0x01) ;



for (u8 i=0;i<6;i++){
	LCD_EnuRecordSpecialChar(pattern[i],i) ;

	LCD_EnuSetPosition(1,14-i) ;

	LCD_EnuWriteSpecialChar(i) ;

	}
	_delay_ms(500) ;

LCD_EnuSendCommand(0x01) ;



for (u8 i=0;i<6;i++){
	LCD_EnuRecordSpecialChar(pattern2[i],i) ;

	LCD_EnuSetPosition(1,6-i) ;

	LCD_EnuWriteSpecialChar(i) ;

	}
	_delay_ms(500) ;

LCD_EnuSendCommand(0x01) ;


	LCD_EnuSetPosition(0,0) ;
	LCD_EnuWriteString("Hello") ;
	LCD_EnuSetPosition(1,10) ;
	LCD_EnuWriteString("World") ;

	LCD_EnuSetPosition(0,17) ;
	LCD_EnuWriteString("Hello") ;
	LCD_EnuSetPosition(1,30) ;
	LCD_EnuWriteString("World") ;


for (u8 i=0;i<32;i++) {
LCD_EnuSendCommand(0x18) ;
_delay_ms(200) ;}

LCD_EnuSendCommand(0x01) ;
_delay_ms(200) ;




LCD_EnuSendCommand(0x01) ;
}

return 0 ;

}
