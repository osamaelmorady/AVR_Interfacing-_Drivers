/*
 * I2C_Config.h
 *
 *  Created on: Nov 22, 2020
 *      Author: Osama Elmorady
 */

#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_




/*************************************/
/****  Define MCU TYPE & ADDRESS  ****/
/*************************************/

#define MCU_TYPE		MASTER_NODE
//#define MCU_TYPE		SLAVE_NODE

#define MCU_ADDRESS		0X01






/********************************/
/****  Define I2C PRESCALER  ****/
/********************************/
#define 	I2C_PRESCALER	 PRESCALER_1
//#define 	I2C_PRESCALER	 PRESCALER_4
//#define 	I2C_PRESCALER	 PRESCALER_16
//#define 	I2C_PRESCALER	 PRESCALER_64





/*******************************************/
/****  Define MCU CLOCK & SENSOR CLOCK  ****/
/*******************************************/
#define MCU_CLK			8000000				//  8  MHz
#define SENSOR_CLK		400000				// 400 KHz





/*****************************/
/**** ACK RETURN CONTROL  ****/
/*****************************/
#define ACK_MODE		ACK_ENABLE
//#define ACK_MODE		ACK_DISABLE




/*******************************/
/**** GENERAL CALL CONTROL  ****/
/*******************************/
#define GENERAL_CALL_MODE		GENERAL_CALL_ENABLE
//#define GENERAL_CALL_MODE		GENERAL_CALL_DISABLE
















#endif /* I2C_CONFIG_H_ */
