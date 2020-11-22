/*
 * SPI_Config.h
 *
 *  Created on: Nov 15, 2020
 *      Author: Osama Elmorady
 */


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_



typedef	enum MCU_NETWORK_MODE
{
	SLAVE = 0 ,
	MASTER=1

}MCU_NETWORK_MODE ;




/******************************************/
/****  Define AVR SPI  Configurations  ****/
/******************************************/

/*  */

//#define SPI_INTERRUPT		SPI_INTERRUPT_ENABLE
#define SPI_INTERRUPT		SPI_INTERRUPT_DISABLE








/*  */

//#define SPI_DATA_ORDER			SPI_DATA_ORDER_MSB
#define SPI_DATA_ORDER			SPI_DATA_ORDER_LSB












/*  */

//#define SPI_CLOCK_POLARITY_SELECT         SPI_SAMPLE_RISING_SETUP_FALLING
#define SPI_CLOCK_POLARITY_SELECT         SPI_SETUP_RISING_SAMPLE_FALLING
//#define SPI_CLOCK_POLARITY_SELECT         SPI_SAMPLE_FALLING_SETUP_RISING
//#define SPI_CLOCK_POLARITY_SELECT         SPI_SETUP_FALLING_SAMPLE_RISING










/*  */

//#define SPI_SCK_FREQ_SELECT		SPI_FREQ_SELECT_NORMAL_4
//#define SPI_SCK_FREQ_SELECT		SPI_FREQ_SELECT_NORMAL_16
#define SPI_SCK_FREQ_SELECT		SPI_FREQ_SELECT_NORMAL_64
//#define SPI_SCK_FREQ_SELECT		SPI_FREQ_SELECT_NORMAL_128

//#define SPI_SCK_FREQ_SELECT		SPI_FREQ_SELECT_DOUPLE_2
//#define SPI_SCK_FREQ_SELECT		SPI_FREQ_SELECT_DOUPLE_8
//#define SPI_SCK_FREQ_SELECT		SPI_FREQ_SELECT_DOUPLE_32
//#define SPI_SCK_FREQ_SELECT		SPI_FREQ_SELECT_DOUPLE_64




/*  */

#define SPI_SPEED			SPI_NORMAL_SPEED
//#define SPI_SPEED			SPI_DOUBLE_SPEED









/*  */

#define SPI_COLLISION_MODE		SPI_DISABLE_COLLISION
//#define SPI_COLLISION_MODE		SPI_ENABLE_COLLISION









#endif /* SPI_CONFIG_H_ */
