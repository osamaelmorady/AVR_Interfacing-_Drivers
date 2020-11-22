/*
 * SPI_Private.h
 *
 *  Created on: Nov 15, 2020
 *      Author: Osama Elmorady
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


#define NULL '\0'

/*************************************/
/****  Define AVR SPI  Addresses  ****/
/*************************************/
#define SPCR 	(*(u8 *)REG_SPCR)
#define SPSR	(*(u8 *)REG_SPSR)
#define SPDR	(*(u8 *)REG_SPDR)







/****  SPCR Register  ****/
/*************************/
#define		SPR0	0             /* SPI Clock Rate Select  */
#define		SPR1	1             /* SPI Clock Rate Select */
#define		CPHA	2             /* Clock Phase  */
#define		CPOL	3             /* Clock Polarity  */
#define		MSTR	4             /* Master/Slave Select   */
#define		DORD	5             /* Data Order (MSB),(LSB)   */
#define		SPE		6             /* SPI Enable */
#define		SPIE	7             /* SPI Interrupt Enable */




/****  SPSR Register  ****/
/*************************/
#define		SPI2X	0            /* Double SPI Speed Bit */

								 /*	(1-5) Reserved Bits	 */

#define		WCOL	6            /* Write COLlision Flag */
#define		SPIF	7            /* SPI Interrupt Flag   */




/****  SPDR Register  ****/
/*************************/

								/* Contain the Transmitted or Received data */








/******************************************/
/****  Define AVR SPI  Configurations  ****/
/******************************************/

/*  */
#define SPI_INTERRUPT_ENABLE		1
#define SPI_INTERRUPT_DISABLE		0




/*  */
#define SPI_DATA_ORDER_MSB			0
#define SPI_DATA_ORDER_LSB			1





/*  */
#define SPI_SAMPLE_RISING_SETUP_FALLING		0
#define SPI_SETUP_RISING_SAMPLE_FALLING		1
#define SPI_SAMPLE_FALLING_SETUP_RISING		2
#define SPI_SETUP_FALLING_SAMPLE_RISING		3




/*  */
#define SPI_FREQ_SELECT_NORMAL_4			0
#define SPI_FREQ_SELECT_NORMAL_16			1
#define SPI_FREQ_SELECT_NORMAL_64			2
#define SPI_FREQ_SELECT_NORMAL_128			3

#define SPI_FREQ_SELECT_DOUPLE_2			4
#define SPI_FREQ_SELECT_DOUPLE_8			5
#define SPI_FREQ_SELECT_DOUPLE_32			6
#define SPI_FREQ_SELECT_DOUPLE_64			7




/*  */
#define SPI_NORMAL_SPEED			0
#define SPI_DOUBLE_SPEED			1




/*  */
#define SPI_DISABLE_COLLISION			0
#define SPI_ENABLE_COLLISION			1







#endif /* SPI_PRIVATE_H_ */
