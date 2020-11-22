/*
 * I2C_Program.h
 *
 *  Created on: Nov 22, 2020
 *      Author: Osama Elmorady
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_



/*************************************/
/****  Define AVR I2C  Addresses  ****/
/*************************************/
#define TWBR 	(*(u8 *) REG_TWBR )
#define TWSR	(*(u8 *) REG_TWSR )
#define TWAR	(*(u8 *) REG_TWAR )
#define TWDR	(*(u8 *) REG_TWDR )
#define TWCR	(*(u8 *) REG_TWCR )





/****  TWCR Register Bits  ****/
/******************************/
#define		TWIE		0

#define		TWEN		2
#define		TWWC		3
#define		TWSTO		4
#define		TWSTA		5
#define		TWEA		6
#define		TWINT		7


/****  TWSR Register Bits  ****/
/******************************/
#define		TWPS0		0
#define		TWPS1		1

#define		TWS3		3




/****  TWAR Register Bits  ****/
/******************************/
#define		TWGCE		0






/********************************/
/****  Define I2C PRESCALER  ****/
/********************************/
#define 	PRESCALER_1     	1
#define 	PRESCALER_4     	4
#define 	PRESCALER_16    	16
#define 	PRESCALER_64    	64





/**********************************/
/****  TWDR VALUE CALCULATION  ****/
/**********************************/
#define TWBR_VALUE		( (MCU_CLK/SENSOR_CLK)-16 ) / (2 * I2C_PRESCALER)








/*******************************/
/****  MCU CONFIGURATIONS   ****/
/*******************************/
#define MASTER_NODE		1
#define SLAVE_NODE		0

#define READING_MODE	1
#define WRITING_MODE	0

#define   ACK_ENABLE  	1
#define   ACK_DISABLE 	0

#define   GENERAL_CALL_ENABLE  		1
#define   GENERAL_CALL_DISABLE 		0






/**************************************/
/****  TWSR STATUS REGISTER CHECK  ****/
/**************************************/

#define TWSR_BITS_CHECK		(TWSR & 0xF8)


#define 	CORRECT_START_CONDITION			 0x08
#define 	CORRECT_RESTART_CONDITION		 0x10
#define 	CORRECT_ADDRESS_SENT_READING	 0x40
#define 	CORRECT_ADDRESS_SENT_WRITING	 0x18

#define 	CORRECT_MASTER_DATA_SENT		 0x28
#define 	CORRECT_MASTER_DATA_RECEIVED	 0x50

#define 	CORRECT_SLAVE_ADDRESS_RECEIVED_WRITING		 0x60
#define 	CORRECT_SLAVE_ADDRESS_RECEIVED_READING		 0xA8


#define 	CORRECT_SLAVE_DATA_SENT			 0xB8
#define 	CORRECT_SLAVE_DATA_RECEIVED		 0x80













#endif /* I2C_PRIVATE_H_ */
