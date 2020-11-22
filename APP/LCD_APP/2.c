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

LCD_EnuInit() ;


u8 pattern[8][8]={{0x0C,0x1E,0x1C,0x1C,0x1C,0x08,0x08,0x18} ,
				  {0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x0D} ,
				  {0x08,0x08,0x08,0x09,0x0C,0x0C,0x0A,0x0D} ,
				  {0x09,0x08,0x08,0x08,0x0C,0x0B,0x08,0x0C} ,
				  {0x00,0x18,0x1F,0x07,0x03,0x03,0x03,0x03} ,
				  {0x03,0x03,0x03,0x03,0x1F,0x1F,0x00,0x00} ,
				  {0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00}
				  } ;





for (u8 i=0;i<7;i++){
LCD_EnuRecordSpecialChar(pattern[i],i) ;
}

_delay_ms(2000) ;

LCD_EnuSetPosition(0,12) ;
LCD_EnuWriteSpecialChar(4) ;
LCD_EnuSetPosition(1,12) ;
LCD_EnuWriteSpecialChar(5) ;

while(1)
{

for (u8 i=0;i<6;i++){

LCD_EnuSetPosition(0,i) ;
LCD_EnuWriteSpecialChar(0) ;
LCD_EnuSetPosition(1,i) ;
LCD_EnuWriteSpecialChar(1) ;
_delay_ms(400) ;
LCD_EnuSetPosition(0,i) ;
LCD_EnuSendData(' ') ;
LCD_EnuSetPosition(1,i) ;
LCD_EnuSendData(' ') ;

LCD_EnuSetPosition(0,i) ;
LCD_EnuWriteSpecialChar(0) ;
LCD_EnuSetPosition(1,i) ;
LCD_EnuWriteSpecialChar(2) ;
_delay_ms(400) ;
LCD_EnuSetPosition(0,i) ;
LCD_EnuSendData(' ') ;
LCD_EnuSetPosition(1,i) ;
LCD_EnuSendData(' ') ;

LCD_EnuSetPosition(0,i) ;
LCD_EnuWriteSpecialChar(0) ;
LCD_EnuSetPosition(1,i) ;
LCD_EnuWriteSpecialChar(3) ;
_delay_ms(400) ;
LCD_EnuSetPosition(0,i) ;
LCD_EnuSendData(' ') ;
LCD_EnuSetPosition(1,i) ;
LCD_EnuSendData(' ') ;


}


//ball Throw

for (u8 i=6;i<12;i++)
{
LCD_EnuSetPosition(0,i) ;
LCD_EnuWriteSpecialChar(6) ;
_delay_ms(200) ;
LCD_EnuSetPosition(0,i) ;
LCD_EnuSendData(' ') ;


}







for (u8 i=6;i>0;i--){

LCD_EnuSetPosition(0,i) ;
LCD_EnuWriteSpecialChar(0) ;
LCD_EnuSetPosition(1,i) ;
LCD_EnuWriteSpecialChar(1) ;
_delay_ms(400) ;
LCD_EnuSetPosition(0,i) ;
LCD_EnuSendData(' ') ;
LCD_EnuSetPosition(1,i) ;
LCD_EnuSendData(' ') ;

LCD_EnuSetPosition(0,i) ;
LCD_EnuWriteSpecialChar(0) ;
LCD_EnuSetPosition(1,i) ;
LCD_EnuWriteSpecialChar(2) ;
_delay_ms(400) ;
LCD_EnuSetPosition(0,i) ;
LCD_EnuSendData(' ') ;
LCD_EnuSetPosition(1,i) ;
LCD_EnuSendData(' ') ;

LCD_EnuSetPosition(0,i) ;
LCD_EnuWriteSpecialChar(0) ;
LCD_EnuSetPosition(1,i) ;
LCD_EnuWriteSpecialChar(3) ;
_delay_ms(400) ;
LCD_EnuSetPosition(0,i) ;
LCD_EnuSendData(' ') ;
LCD_EnuSetPosition(1,i) ;
LCD_EnuSendData(' ') ;


}



}

return 0 ;

}
