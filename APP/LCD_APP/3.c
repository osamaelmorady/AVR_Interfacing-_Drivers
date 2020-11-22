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


u8 pattern[8][8]={{0x07,0x07,0x0D,0x0F,0x0F,0x0F,0x07,0x07} ,
				  {0x1C,0x1C,0x1E,0x1E,0x1E,0x1E,0x1C,0x1C} ,
				  {0x1C,0x1C,0x18,0x10,0x10,0x18,0x1C,0x1C} ,
				  {0x1C,0x1C,0x16,0x1E,0x1E,0x1E,0x1C,0x1C} ,
				  {0x07,0x07,0x07,0x0F,0x0F,0x0F,0x07,0x07} ,
				  {0x07,0x07,0x03,0x01,0x01,0x03,0x07,0x07} ,
				  {0x00,0x00,0x00,0x06,0x0E,0x1E,0x00,0x00} };



u8 rowpath[5]={5,6,8,9,10} ;
u8 colpath[5]={3,4,7,8,11} ;

for (u8 i=0;i<7;i++){
LCD_VidRecordSpecialChar(pattern[i],i) ;
}

_delay_ms(2000) ;








while(1)
{
// Map Creation
for (u8 i=0;i<5;i++){
	LCD_VidSetPosition(0,rowpath[i]) ;
	LCD_VidWriteSpecialChar(6) ;
	LCD_VidSetPosition(1,colpath[i]) ;
	LCD_VidWriteSpecialChar(6) ;
	}


// Move in the first Line from col 0
for (u8 i=0;i<14;i++){
LCD_VidSetPosition(0,i) ;
LCD_VidWriteSpecialChar(0) ;
LCD_VidSetPosition(0,i+1) ;
LCD_VidWriteSpecialChar(1) ;
_delay_ms(250) ;
LCD_VidSetPosition(0,i+1) ;
LCD_VidSendData(' ') ;
LCD_VidSetPosition(0,i+1) ;
LCD_VidWriteSpecialChar(2) ;
_delay_ms(250) ;

LCD_VidSetPosition(0,i) ;
LCD_VidSendData(' ') ;
LCD_VidSetPosition(0,i+1) ;
LCD_VidSendData(' ') ;
}



// Set the last Point on the Screen
LCD_VidSetPosition(0,14) ;
LCD_VidWriteSpecialChar(0) ;
LCD_VidSetPosition(0,15) ;
LCD_VidWriteSpecialChar(1) ;
_delay_ms(250) ;
LCD_VidSetPosition(0,14) ;
LCD_VidSendData(' ') ;
LCD_VidSetPosition(0,15) ;
LCD_VidSendData(' ') ;



// Move in the Second Line from col 15
for (u8 i=15;i>1;i--){
LCD_VidSetPosition(1,i) ;
LCD_VidWriteSpecialChar(3) ;
LCD_VidSetPosition(1,i-1) ;
LCD_VidWriteSpecialChar(4) ;
_delay_ms(250) ;
LCD_VidSetPosition(1,i-1) ;
LCD_VidSendData(' ') ;
LCD_VidSetPosition(1,i-1) ;
LCD_VidWriteSpecialChar(5) ;
_delay_ms(250) ;

LCD_VidSetPosition(1,i) ;
LCD_VidSendData(' ') ;
LCD_VidSetPosition(1,i-1) ;
LCD_VidSendData(' ') ;
}





LCD_VidSetPosition(0,6) ;
LCD_VidWriteString("Game") ;
LCD_VidSetPosition(1,5) ;
LCD_VidWriteString("Over !") ;

_delay_ms(2000) ;
LCD_VidSendCommand(0x01) ;


}
return 0 ;







}
