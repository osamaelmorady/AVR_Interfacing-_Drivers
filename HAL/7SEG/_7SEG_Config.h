/*
 * _7SEG_Config.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Osama Elmorady
 */

#ifndef _7SEG_CONFIG_H_
#define _7SEG_CONFIG_H_


/************************************************/
/*************** 7 Segment Type *****************/
/*********** A_TYPE for Common Anode ************/
/*********** K_TYPE for Common Cathode **********/
/************************************************/

/* A_TYPE - K_TYPE */
#define  _7SEG_TYPE  A_TYPE




/*******************************************************/
/*************** 7 Segment CONNECTION PINS *************/
/*******************************************************/
#define _7SEG_PORT  PORTC

#define _7SEG_A 	PIN24
#define _7SEG_B 	PIN25
#define _7SEG_C		PIN26
#define _7SEG_D 	PIN27
#define _7SEG_E 	PIN28
#define _7SEG_F 	PIN29
#define _7SEG_G 	PIN30
#define _7SEG_DOT 	PIN31



#endif /* 7SEG_CONFIG_H_ */
