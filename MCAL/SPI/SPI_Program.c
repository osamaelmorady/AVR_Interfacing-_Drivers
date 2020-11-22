/*
 * SPI_Program.h
 *
 *  Created on: Nov 15, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "LIB/AVR32_REG.h"
#include "LIB/ERROR_STATE.h"

#include "GIE/GIE_Interface.h"
#include "DIO/DIO_Interface.h"

#include "SPI_Config.h"
#include "SPI_Private.h"







ErrorState SPI_VidInit(u8 Copy_U8MCUModeSelect)
{
	ErrorState error = ES_NOK ;

	/************ SPSR ************/
	#if SPI_SPEED == SPI_NORMAL_SPEED

		/* Normal Speed SPI */
		SPSR = (0<<SPI2X) ;

	#elif SPI_SPEED == SPI_DOUBLE_SPEED

		/* Double Speed SPI */
		SPSR = (1<<SPI2X) ;

	#else
	#error "Wrong SPI_SPEED Selection !! "

	#endif



	switch (Copy_U8MCUModeSelect)
	{
	case MASTER :

		/**** Set MCU as Master  *****/
		DIO_EnuSetPinDir(PIN12,OUTPUT)  ;			//	SS
		DIO_EnuSetPinDir(PIN13,OUTPUT)  ;			//	MOSI
		DIO_EnuSetPinDir(PIN14,INPUT)  ;			//	MISO
		DIO_EnuSetPinDir(PIN15,OUTPUT)  ;			//	SCK


		/************SPCR************/

		/* Disable Interrupt and Data transmission From LSB */
	#if (SPI_INTERRUPT == SPI_INTERRUPT_DISABLE) &&	(SPI_DATA_ORDER == SPI_DATA_ORDER_LSB)

		SPCR = (0<<SPIE) | (1<<SPE) | (1<<DORD) | (1<<MSTR) |  (0<<CPOL) |  (1<<CPHA) |  (1<<SPR1) |  (0<<SPR0)   ;

		/* Enable Interrupt and Data transmission From LSB */
	#elif SPI_INTERRUPT == SPI_INTERRUPT_ENABLE &&	(SPI_DATA_ORDER == SPI_DATA_ORDER_LSB)

		GIE_EnuEnable() ;

		SPCR = (1<<SPIE) | (1<<SPE) | (1<<DORD) | (1<<MSTR) |  (0<<CPOL) |  (1<<CPHA) |  (1<<SPR1) |  (0<<SPR0)   ;

		/* Disable Interrupt and Data transmission From MSB */
	#elif (SPI_INTERRUPT == SPI_INTERRUPT_DISABLE) &&	(SPI_DATA_ORDER == SPI_DATA_ORDER_MSB)

		SPCR = (0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) |  (0<<CPOL) |  (1<<CPHA) |  (1<<SPR1) |  (0<<SPR0)   ;

		/* Enable Interrupt and Data transmission From MSB */
	#elif (SPI_INTERRUPT == SPI_INTERRUPT_ENABLE) &&	(SPI_DATA_ORDER == SPI_DATA_ORDER_MSB)

		GIE_EnuEnable() ;

		SPCR = (1<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) |  (0<<CPOL) |  (1<<CPHA) |  (1<<SPR1) |  (0<<SPR0)   ;


	#else
		#error "Wrong SPI_INTERRUPT Selection, SPI_DATA_ORDER !! "
	#endif


		break ;



	case SLAVE :

		/**** Set MCU as Slave  *****/
		DIO_EnuSetPinDir(PIN12,INPUT)  ;			//	SS
		DIO_EnuSetPinDir(PIN13,INPUT)  ;			//	MOSI
		DIO_EnuSetPinDir(PIN14,OUTPUT)  ;			//	MISO
		DIO_EnuSetPinDir(PIN15,INPUT)  ;			//	SCK

		/************SPCR************/

		/* Disable Interrupt and Data transmission From LSB */
	#if (SPI_INTERRUPT == SPI_INTERRUPT_DISABLE) &&	(SPI_DATA_ORDER == SPI_DATA_ORDER_LSB)

		SPCR = (0<<SPIE) | (1<<SPE) | (1<<DORD) | (0<<MSTR) |  (0<<CPOL) |  (1<<CPHA) |  (1<<SPR1) |  (0<<SPR0)   ;

		/* Enable Interrupt and Data transmission From LSB */
	#elif SPI_INTERRUPT == SPI_INTERRUPT_ENABLE &&	(SPI_DATA_ORDER == SPI_DATA_ORDER_LSB)

		GIE_EnuEnable() ;

		SPCR = (1<<SPIE) | (1<<SPE) | (1<<DORD) | (0<<MSTR) |  (0<<CPOL) |  (1<<CPHA) |  (1<<SPR1) |  (0<<SPR0)   ;

		/* Disable Interrupt and Data transmission From MSB */
	#elif (SPI_INTERRUPT == SPI_INTERRUPT_DISABLE) &&	(SPI_DATA_ORDER == SPI_DATA_ORDER_MSB)

		SPCR = (0<<SPIE) | (1<<SPE) | (0<<DORD) | (0<<MSTR) |  (0<<CPOL) |  (1<<CPHA) |  (1<<SPR1) |  (0<<SPR0)   ;

		/* Enable Interrupt and Data transmission From MSB */
	#elif (SPI_INTERRUPT == SPI_INTERRUPT_ENABLE) &&	(SPI_DATA_ORDER == SPI_DATA_ORDER_MSB)

		GIE_EnuEnable() ;

		SPCR = (1<<SPIE) | (1<<SPE) | (0<<DORD) | (0<<MSTR) |  (0<<CPOL) |  (1<<CPHA) |  (1<<SPR1) |  (0<<SPR0)   ;


	#else
		#error "Wrong SPI_INTERRUPT Selection, SPI_DATA_ORDER !! "
	#endif


		break ;



	default : 		break ;

	}

	error = ES_OK ;

	return error ;

}









ErrorState SPI_VidSendData(u8 Copy_U8TransmittedValue)
{
	ErrorState error = ES_NOK ;

	/************ SPDR ************/
	SPDR = Copy_U8TransmittedValue ;

	/************ Poll on flag ************/
	while (!GET_BIT(SPSR,7)) ;

	error = ES_OK ;

	return error ;


}




ErrorState SPI_VidReceiveData(u8 * Copy_U8ReceivedValue)
{
	ErrorState error = ES_NOK ;

	/************Poll on flag ************/
	while (!GET_BIT(SPSR,7)) ;

	/************ SPDR ************/
	* Copy_U8ReceivedValue = SPDR  ;

	error = ES_OK ;

	return error ;

}








void (*SPI_PtrTransfer)(void)=NULL ;


ErrorState SPI_CallBackFun(void (*User_Fun)(void))
{
	ErrorState error = ES_NOK ;

	SPI_PtrTransfer = User_Fun ;

	error = ES_OK ;

	return error ;
}



/* SPI , Tx Complete Interrupt */
void __vector_12(void)
{
	SPI_PtrTransfer() ;
}

