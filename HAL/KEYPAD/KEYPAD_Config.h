/*
 * KEY_Config.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */


#ifndef 	KEY_CONFIG_H_
#define 	KEY_CONFIG_H_


/****************************************************/
/*************** KEYPAD CONNECTION PINS *************/
/****************************************************/
#define KEYPAD_U8DATA { {  '7'  , '8' , '9' , '-'}  ,  \
					    {  '4'  , '5' , '6' , '+'}  ,  \
					    {  '1'  , '2' , '3' , '/'}  ,  \
					    {  'E'  , '0' , 'C' , '*'}       }




/****************************************************/
/*************** KEYPAD CONNECTION PINS *************/
/****************************************************/
/** ROWS **/
#define KEY_R1    PIN24
#define KEY_R2    PIN25
#define KEY_R3    PIN26
#define KEY_R4    PIN27

/** COLUMNS **/
#define KEY_C1    PIN28
#define KEY_C2    PIN29
#define KEY_C3    PIN30
#define KEY_C4    PIN31





#endif 
