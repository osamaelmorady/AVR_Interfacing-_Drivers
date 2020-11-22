/*
 * UART_Program.c
 *
 *  Created on: Nov 12, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "LIB/ERROR_STATE.h"
#include "LIB/AVR32_REG.h"

#include "UART_Private.h"
#include "UART_Config.h"

#include "GIE/GIE_Interface.h"
#include "DIO/DIO_Interface.h"

#include <util/delay.h>


#define UART_NAME_SIZE 	25




/*****************************************************************/
/********************* UART Initialization ***********************/
/*****************************************************************/
ErrorState UART_EnuInit(u16 Copy_U16BaudRate)
{

	ErrorState error = ES_NOK ;

/************* TX,RX Pin Configuration *************/
/***************************************************/


	DIO_EnuSetPinDir(UART_RX_PIN,INPUT) ;
	DIO_EnuSetPinDir(UART_TX_PIN,OUTPUT) ;




/************* UCSRA Configuration ****************/
/**************************************************/

	/* MultiProcessor Communication Mode Disabled */
	CLR_BIT(UCSRA,MPCM) ;


/******************** UART Speed Selection ***************/
#if UART_TRANSMISSION_SPEED==NORMAL_TRANSMISSION_SPEED

	/* Normal UART Speed */
	CLR_BIT(UCSRA,U2X) ;

#elif UART_TRANSMISSION_SPEED==DOUPLE_TRANSMISSION_SPEED

	/* Doubled UART Speed */
	SET_BIT(UCSRA,U2X) ;

#else
#error  "Wrong UART_TRANSMISSION_SPEED"
#endif
/*********************************************************/

	/* Parity Error Disabled */
	CLR_BIT(UCSRA,PE) ;

	/* Data OverRun Disabled */
	CLR_BIT(UCSRA,DOR) ;

	/* Frame Error Disabled */
	CLR_BIT(UCSRA,FE) ;




/************* UCSRB Configuration ****************/
/**************************************************/

	/* Character Size : 5-8 Bits only */
	CLR_BIT(UCSRB,TXB8) ;

	/* Character Size : 5-8 Bits only */
	CLR_BIT(UCSRB,RXB8) ;

	/* Character Size : 5-8 Bits only */
	CLR_BIT(UCSRB,UCSZ2) ;

	/* Transmitter Enable */
	SET_BIT(UCSRB,TXEN) ;

	/* Receiver Enable */
	SET_BIT(UCSRB,RXEN) ;

	/* Empty Interrupt Enable */
	CLR_BIT(UCSRB,UDRIE) ;

	/* TX Complete Interrupt Enable */
	CLR_BIT(UCSRB,TXCIE) ;

	/* RX Complete Interrupt Enable */
	CLR_BIT(UCSRB,RXCIE) ;



	/* General I/O Interrupt */
	//GIE_EnuEnable() ;

/************* UCSRC Configuration ****************/
/**************************************************/

	UCSRC = (0<<UCPOL) | (1<<UCSZ0) | (1<<UCSZ1) | (0<<USBS) | (0<<UPM0) | (0<<UPM1) | (0<<UMSEL) | (1<<URSEL)     ;


								/* Clock Polarity (Rising) */
	                            /* Character Size (8 bits) */
	                            /* Character Size (8 bits) */
	                            /* Stop Bit Select (1) */
	                            /* Parity Mode Disabled */
                                /* Parity Mode Disabled */
                                /* USART Mode Select (Async) */
                                /* Register Select (UCSRC Not UBRRH) */



/************* UBRR Configuration ****************/
/************* (Baud) Configuration **************/
/*************************************************/

	switch (Copy_U16BaudRate)
	{

	case B_9600  : 	UBRRL = BAUD_8MHZ_9600 ;	 error = ES_OK ;				 break ;		/* Baud Rate= 9600  , and normal speed */

	case B_14400 : 	UBRRL = BAUD_8MHZ_14400 ; 	 error = ES_OK ;				 break ;		/* Baud Rate= 14400 , and normal speed */

	case B_19200 : 	UBRRL = BAUD_8MHZ_19200 ; 	 error = ES_OK ;				 break ;		/* Baud Rate= 19200 , and normal speed */

	case B_28800 : 	UBRRL = BAUD_8MHZ_28800 ;	 error = ES_OK ;				 break ;		/* Baud Rate= 28800 , and normal speed */

	case B_38400 : 	UBRRL = BAUD_8MHZ_38400 ; 	 error = ES_OK ;		 		 break ;		/* Baud Rate= 38400 , and normal speed */

	default : 									 error = ES_OUT_OF_RANGE ;		 break ;

	}


	return error ;
}









/****************************************************************/
/*************** Send Data to the Transmitter *******************/
/****************************************************************/
ErrorState UART_EnuSendData(u8 Copy_U8Data)
{
	ErrorState error = ES_NOK ;

	/* check & Poll the Flag (UDRE) until UDR is Empty (ready to send new data) */
	while (!GET_BIT(UCSRA,UDRE)) ;

	/* Send the new data */
	UDR_TXB=Copy_U8Data ;

	/* check & Poll the Flag (TXC) to determine if the data has been Transmitted or not */
	while (!GET_BIT(UCSRA,TXC)) ;

	// Avoid data Collision
	_delay_us(500) ;

	error = ES_OK ;

	return error ;
}









/******************************************************************/
/*************** Receive Data From the Receiver *******************/
/******************************************************************/
ErrorState UART_EnuReceiveData(u8 * Copy_PU8Data)
{
	ErrorState error = ES_NOK ;

	/* check & Poll the Flag (RXC) to determine if the data has been received or not */
	while (!GET_BIT(UCSRA,RXC)) ;

	/* Store the received data */
	*Copy_PU8Data = UDR_RXB ;

	// Avoid data Collision
	_delay_us(500) ;

	error = ES_OK ;

	return error ;
}








/******************************************************************/
/*************** Send a String to the Transmitter *****************/
/******************************************************************/
ErrorState UART_EnuWriteString(u8 Copy_PU8String[UART_NAME_SIZE] )
{
	ErrorState error = ES_NOK ;

	u8 Local_U8Count = 0 ;

	while (  Copy_PU8String[ Local_U8Count ] !='\0'  )

		{
			UART_EnuSendData( Copy_PU8String[Local_U8Count] ) ;

			Local_U8Count++ ;
		}

	error = ES_OK ;

	return error ;
}







/*********************************************************************/
/***********  Write a Sentence ( INT Numbers ) on the Screen *********/
/*********************************************************************/
u8 Local_U8TempArray[16];

ErrorState UART_VidWriteIntNum(s32 Copy_S32IntData)
{
	ErrorState error = ES_NOK ;

	u8 Local_U8Flag =0 ;

	u32 Local_U32TempNum ;

	if (Copy_S32IntData>=0)
	{
		Local_U8Flag =0	;
	}
	else
	{
		Copy_S32IntData = - Copy_S32IntData ;

		Local_U8Flag = 1 ;
	}

	Local_U32TempNum=Copy_S32IntData	;

	u8 Local_U8Digits;

	for (Local_U8Digits=1 ; Local_U32TempNum/=10 ; Local_U8Digits++) ;


	Local_U32TempNum=Copy_S32IntData ;

	s32 Local_U8ReverseNum=0;

	for (u8 Local_U8Count=0 ; Local_U32TempNum ;Local_U8Count++ )
	{
		Local_U8ReverseNum=Local_U8ReverseNum+(Local_U32TempNum%10);

		Local_U8ReverseNum=Local_U8ReverseNum*10;

		Local_U32TempNum=Local_U32TempNum/10;
	}

	Local_U8ReverseNum=Local_U8ReverseNum/10;

	u8 Local_U8Count;

	for (Local_U8Count=0 ; Local_U8Count<Local_U8Digits ; Local_U8Count++ )
	{
		Local_U8TempArray[Local_U8Count]=(Local_U8ReverseNum%10)+'0';

		Local_U8ReverseNum=Local_U8ReverseNum/10;

	}
	if (Local_U8Flag)
	{
		UART_EnuSendData('-') ;

		UART_EnuWriteString(Local_U8TempArray) ;
	}
	else
	{
		UART_EnuWriteString(Local_U8TempArray) ;
	}

	error = ES_OK ;

	return error ;
}






/***********************************************************************/
/***********  Write a Sentense ( Float Numbers ) on the Screen *********/
/***********************************************************************/
u8 Local_U8FloatArray[10];

ErrorState UART_VidWriteFloatNum(f32 Copy_F32IntData)
{
	ErrorState error = ES_NOK ;

	u8 Local_U8Flag =0 ;

	if (Copy_F32IntData>=0)
	{
		Local_U8Flag =0	;
	}
	else
	{
		Copy_F32IntData = - Copy_F32IntData ;

		Local_U8Flag = 1 ;

	}


	u32 Local_U32TempNum = Copy_F32IntData ;

	u8 Local_U8IntDigits;

	for (Local_U8IntDigits=1 ; Local_U32TempNum/=10 ; Local_U8IntDigits++) ;


	Local_U32TempNum=Copy_F32IntData ;

	s32 Local_U8ReverseNum=0;

	for (u8 Local_U8Count=0 ; Local_U32TempNum ;Local_U8Count++ )
	{
		Local_U8ReverseNum=Local_U8ReverseNum+(Local_U32TempNum%10);

		Local_U8ReverseNum=Local_U8ReverseNum*10;

		Local_U32TempNum=Local_U32TempNum/10;
	}

	Local_U8ReverseNum=Local_U8ReverseNum/10;

	u8 Local_U8Count;

	for (Local_U8Count=0 ; Local_U8Count<Local_U8IntDigits ; Local_U8Count++ )
	{
		Local_U8FloatArray[Local_U8Count]=(Local_U8ReverseNum%10)+'0';

		Local_U8ReverseNum=Local_U8ReverseNum/10;

	}
	Local_U8FloatArray[Local_U8Count] = '.' ;





	Local_U32TempNum = Copy_F32IntData ;

	f32 Local_F32DecimalNum = Copy_F32IntData - Local_U32TempNum ;

	u32 Local_U32DecimalNum = Local_F32DecimalNum * 10000  ;

	Local_U32TempNum = Local_U32DecimalNum ;

	u8 Local_U8FloatDigits;

	for (Local_U8FloatDigits=1 ; Local_U32TempNum/=10 ; Local_U8FloatDigits++) ;


	Local_U32TempNum=Local_U32DecimalNum ;

	Local_U8ReverseNum=0;

	for (u8 Local_U8Count=0 ; Local_U32TempNum ;Local_U8Count++ )
	{
		Local_U8ReverseNum=Local_U8ReverseNum+(Local_U32TempNum%10);

		Local_U8ReverseNum=Local_U8ReverseNum*10;

		Local_U32TempNum=Local_U32TempNum/10;
	}

	Local_U8ReverseNum=Local_U8ReverseNum/10;

	for (Local_U8Count=Local_U8IntDigits+1 ; Local_U8Count<=(Local_U8IntDigits+4) ; Local_U8Count++ )
	{
		Local_U8FloatArray[Local_U8Count]=(Local_U8ReverseNum%10)+'0';

		Local_U8ReverseNum=Local_U8ReverseNum/10;

	}
	if (Local_U8Flag)
	{
		UART_EnuSendData('-') ;

		UART_EnuWriteString(Local_U8FloatArray) ;
	}
	else
	{
		UART_EnuWriteString(Local_U8FloatArray) ;
	}

	error = ES_OK ;

	return error ;

}






void (*UART_PtrTx)(void)=NULL ;
void (*UART_PtrRx)(void)=NULL ;
void (*UART_PtrData)(void)=NULL ;


void UART_TxCallBackFun(void (*User_Fun)(void))
{
	UART_PtrTx = User_Fun ;
}

void UART_RxCallBackFun(void (*User_Fun)(void))
{
	UART_PtrRx = User_Fun ;
}

void UART_DataCallBackFun(void (*User_Fun)(void))
{
	UART_PtrData = User_Fun ;
}




/* USART, Rx Complete Interrupt */
void __vector_13(void)
{
	UART_PtrTx() ;
}




/* USART Data Register Empty Interrupt */
void __vector_14(void)
{
	UART_PtrData() ;
}




/* USART, Tx Complete Interrupt */
void __vector_15(void)
{
	UART_PtrRx() ;
}



