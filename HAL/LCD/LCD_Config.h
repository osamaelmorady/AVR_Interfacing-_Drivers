/*
 * LCD_Config.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


/************************************************************/
/*************** LCD Connection Mode (4-8)Bits **************/
/************************************************************/
#define  LCD_MODE 	 LCD_8BIT_MODE
//#define  LCD_MODE  LCD_4BIT_MODE




/*******************************************************/
/*************** LCD Data CONNECTION PINS **************/
/*******************************************************/

#define LCD_D0		PIN8
#define LCD_D1		PIN9
#define LCD_D2		PIN10
#define LCD_D3		PIN11



/* This Pins For LCD 4Bit Mode */
/*******************************/
#define LCD_D4		PIN12
#define LCD_D5		PIN13
#define LCD_D6		PIN14
#define LCD_D7		PIN15



/*******************************************************/
/*************** LCD Data CONNECTION PINS **************/
/*******************************************************/
#define LCD_RS		PIN0
#define LCD_RW		PIN1
#define LCD_EN		PIN2






#endif /* LCD_CONFIG_H_ */
