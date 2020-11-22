/**************************************************/
/********  Define AVR LCD_PROGRAM Header  *********/
/**************************************************/
/*  Author 	   :  Osama Mohamed Youssif Abdallah
	Date 	   : 19-10-2020
	Version 	   : V1
	Description : LCD Peripherals interfacing    */
/**************************************************/
/**************************************************/


/******************************************************/
/********  Include Headers Used With AVR DIO  *********/
/******************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/ERROR_STATE.h"

#include "DIO/DIO_Interface.h"

#include "LCD_Private.h"
#include "LCD_Config.h"

#include <util/delay.h>








/*********************************************/
/*********  Send a Character to LCD  *********/
/*********************************************/
ErrorState LCD_EnuSendData(u8 Copy_U8Data)
{
	ErrorState error = ES_NOK ;

	DIO_EnuSetPinVal(LCD_RS,HIGH) ;  	 // RS = 1  -> Send Data

	LCD_VidLatch(Copy_U8Data) ;

	error = ES_OK ;

	return error ;
}




/*********************************************/
/***********  Send a Command to LCD  *********/
/*********************************************/
ErrorState LCD_EnuSendCommand(u8 Copy_U8Command)
{
	ErrorState error = ES_NOK ;

	DIO_EnuSetPinVal(LCD_RS,LOW) ;   	// RS = 0  -> Send Command

	LCD_VidLatch(Copy_U8Command);

	error = ES_OK ;

	return error ;
}





/*********************************************************************************/
/***************  Latch Function for Sending data or command to LCD  *************/
/***********  Common Function for LCD_VidSendCommand and LCD_VidSendData *********/
/*********************************************************************************/
static void LCD_VidLatch(u8 Copy_U8Value)
{
	DIO_EnuSetPinVal(LCD_RW,LOW) ;	  	 // R/W =0  -> Write this data


	/*------------ LCD_8BIT_MODE ---------*/
	/*---------------------------------*/
#if LCD_MODE == LCD_8BIT_MODE


	DIO_EnuSetPinVal ( LCD_D0 , ( Copy_U8Value  >> BIT0 ) & 1  ) ;
	DIO_EnuSetPinVal ( LCD_D1 , ( Copy_U8Value  >> BIT1 ) & 1  ) ;
	DIO_EnuSetPinVal ( LCD_D2 , ( Copy_U8Value  >> BIT2 ) & 1  ) ;
	DIO_EnuSetPinVal ( LCD_D3 , ( Copy_U8Value  >> BIT3 ) & 1  ) ;
	DIO_EnuSetPinVal ( LCD_D4 , ( Copy_U8Value  >> BIT4 ) & 1  ) ;
	DIO_EnuSetPinVal ( LCD_D5 , ( Copy_U8Value  >> BIT5 ) & 1  ) ;
	DIO_EnuSetPinVal ( LCD_D6 , ( Copy_U8Value  >> BIT6 ) & 1  ) ;
	DIO_EnuSetPinVal ( LCD_D7 , ( Copy_U8Value  >> BIT7 ) & 1  ) ;

	DIO_EnuSetPinVal(LCD_EN,HIGH) ;   	 // EN = 1
	_delay_ms(1) ;

	DIO_EnuSetPinVal(LCD_EN,LOW) ;   	 // EN = 0
	_delay_ms(1) ;




	/*------------ LCD_4BIT_MODE ---------*/
	/*---------------------------------*/
#elif LCD_MODE == LCD_4BIT_MODE
	u8 n=0;
	if (Copy_U8Value==LCD_4BIT_MODE_SET_FUNCTION )
	{
		n=1 ;
	}

	for (u8 i=0;i<=n;i++)
	{
		DIO_EnuSetPinVal ( LCD_D4 , ( Copy_U8Value  >> BIT4 ) & 1  ) ;
		DIO_EnuSetPinVal ( LCD_D5 , ( Copy_U8Value  >> BIT5 ) & 1  ) ;
		DIO_EnuSetPinVal ( LCD_D6 , ( Copy_U8Value  >> BIT6 ) & 1  ) ;
		DIO_EnuSetPinVal ( LCD_D7 , ( Copy_U8Value  >> BIT7 ) & 1  ) ;  	 // MSB (Most significant 4 bits)

		DIO_EnuSetPinVal(LCD_EN,HIGH) ;   	 // EN = 1
		_delay_ms(1) ;
		DIO_EnuSetPinVal(LCD_EN,LOW) ;   	 // EN = 0
		_delay_ms(1) ;
	}

	DIO_EnuSetPinVal ( LCD_D4 , ( Copy_U8Value  >> BIT0 ) & 1  ) ;
	DIO_EnuSetPinVal ( LCD_D5 , ( Copy_U8Value  >> BIT1 ) & 1  ) ;
	DIO_EnuSetPinVal ( LCD_D6 , ( Copy_U8Value  >> BIT2 ) & 1  ) ;
	DIO_EnuSetPinVal ( LCD_D7 , ( Copy_U8Value  >> BIT3 ) & 1  ) ; 		// LSB Data  (Least significant 4 bits)

	DIO_EnuSetPinVal(LCD_EN,HIGH) ;   	 // EN = 1
	_delay_ms(1) ;

	DIO_EnuSetPinVal(LCD_EN,LOW) ;   	 // EN = 0
	_delay_ms(1) ;


#else
#error " Wrong LCD_Mode Input "


#endif

}





/***********************************************/
/***********  Initialization of a LCD  *********/
/***********  LCD Connection Selection *********/
/*********** _8BIT MODE  or _4BIT MODE *********/
/***********************************************/
ErrorState LCD_EnuInit(void)
{
	ErrorState error = ES_NOK ;

/*------------ _8BIT MODE ---------*/
/*---------------------------------*/
#if LCD_MODE==LCD_8BIT_MODE

	// Set Data Pins with Direction
	DIO_EnuSetPinDir ( LCD_D0 , OUTPUT  ) ;
	DIO_EnuSetPinDir ( LCD_D1 , OUTPUT  ) ;
	DIO_EnuSetPinDir ( LCD_D2 , OUTPUT  ) ;
	DIO_EnuSetPinDir ( LCD_D3 , OUTPUT  ) ;
	DIO_EnuSetPinDir ( LCD_D4 , OUTPUT  ) ;
	DIO_EnuSetPinDir ( LCD_D5 , OUTPUT  ) ;
	DIO_EnuSetPinDir ( LCD_D6 , OUTPUT  ) ;
	DIO_EnuSetPinDir ( LCD_D7 , OUTPUT  ) ;


	// Set Control Pins With Direction
	DIO_EnuSetPinDir( LCD_RS , OUTPUT );
	DIO_EnuSetPinDir( LCD_RW , OUTPUT );
	DIO_EnuSetPinDir( LCD_EN , OUTPUT );

	// Time Taken By LCD Rise VDD to 4.5v
	_delay_ms(50) ;

	// Function Set
	LCD_EnuSendCommand(LCD_8BIT_MODE_SET_FUNCTION) ;
	_delay_ms(1) ;

	// Display ON/OFF Control
	LCD_EnuSendCommand(LCD_ON_CONTROL_DISPLAY) ;
	_delay_ms(1) ;

	// Clear Display
	LCD_EnuSendCommand(LCD_CLEAR_DISPLAY) ;
	_delay_ms(2) ;

	error = ES_OK ;




/*------------ _4BIT MODE ---------*/
/*---------------------------------*/
#elif LCD_MODE==_4BIT

	// Set Control Pins With Direction
	DIO_EnuSetPinDir( LCD_RS , OUTPUT );
	DIO_EnuSetPinDir( LCD_RW , OUTPUT );
	DIO_EnuSetPinDir( LCD_EN , OUTPUT );

	// Set Data Pins with Direction
	DIO_EnuSetPinDir ( LCD_D4 , OUTPUT  ) ;
	DIO_EnuSetPinDir ( LCD_D5 , OUTPUT  ) ;
	DIO_EnuSetPinDir ( LCD_D6 , OUTPUT  ) ;
	DIO_EnuSetPinDir ( LCD_D7 , OUTPUT  ) ;

	// Time Taken By LCD Rise VDD to 4.5v
	_delay_ms(50) ;

	// Function Set 1
	LCD_EnuSendCommand(LCD_4BIT_MODE_SET_FUNCTION) ;
	_delay_ms(1) ;


	// Display ON/OFF Control
	LCD_EnuSendCommand(LCD_ON_CONTROL_DISPLAY) ;
	_delay_ms(1) ;


	// Clear Display
	LCD_EnuSendCommand(LCD_CLEAR_DISPLAY) ;
	_delay_ms(2) ;

	error = ES_OK ;


#else

#error " Wrong LCD_Mode Input "

#endif


	return error ;
}



/****************************************************************/
/***********  Set the LCD Cursor Position on the Screen *********/
/****************************************************************/
ErrorState LCD_EnuSetPosition ( u8 Copy_U8RowNumber,u8 Copy_U8ColumnNumber )
{
	ErrorState error = ES_NOK ;

	if ( ( Copy_U8ColumnNumber>=LCD_MIN_COL ) && ( Copy_U8ColumnNumber<=LCD_MAX_COL ) )
	{
		if (LCD_FIRSTROW==Copy_U8RowNumber)
		{
			LCD_EnuSendCommand(128+Copy_U8ColumnNumber) ;

			error = ES_OK ;
		}
		else if (LCD_SECONDROW==Copy_U8RowNumber)
		{
			LCD_EnuSendCommand(128+64+Copy_U8ColumnNumber);

			error = ES_OK ;
		}
		else
		{

			error = ES_OUT_OF_RANGE ;
		}
	}
	else
	{
		error = ES_OUT_OF_RANGE ;
	}

	return error ;
}




/****************************************************************/
/***********  Write a Sentence ( string ) on the Screen *********/
/****************************************************************/
ErrorState LCD_EnuWriteString(u8 * Copy_PU8Name)
{
	ErrorState error = ES_NOK ;

	for ( u8 Local_U8Count=0  ;  Copy_PU8Name[Local_U8Count]!='\0'  ;  Local_U8Count++ )
		{
			LCD_EnuSendData( Copy_PU8Name[Local_U8Count] );
		}

	error = ES_OK ;

	return error ;
}



/*********************************************************************/
/***********  Write a Sentence ( INT Numbers ) on the Screen *********/
/*********************************************************************/
u8 Local_U8TempArray[16];

ErrorState LCD_EnuWriteIntNum(s32 Copy_S32IntData)
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
		LCD_EnuSendData('-') ;

		LCD_EnuWriteString(Local_U8TempArray) ;
	}
	else
	{
		LCD_EnuWriteString(Local_U8TempArray) ;
	}

	error = ES_OK ;

	return error ;
}





/***********************************************************************/
/***********  Write a Sentense ( Float Numbers ) on the Screen *********/
/***********************************************************************/
u8 Local_U8FloatArray[10];

ErrorState LCD_EnuWriteFloatNum(f32 Copy_F32IntData)
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
		LCD_EnuSendData('-') ;

		LCD_EnuWriteString(Local_U8FloatArray) ;
	}
	else
	{
		LCD_EnuWriteString(Local_U8FloatArray) ;
	}

	error = ES_OK ;

	return error ;

}



/*******************************************************************/
/***********  Record a Special Character in the LCD CG-RAM *********/
/*******************************************************************/
ErrorState LCD_EnuRecordSpecialChar ( u8 Copy_U8PatternMatrix[8] ,u8 Copy_U8CGRAMPos)
{
	ErrorState error = ES_NOK ;

	if ( ( Copy_U8CGRAMPos>=0 ) && ( Copy_U8CGRAMPos<=7 ) )
	{
		/* Set Address Counter to the CG-RAM */
		LCD_EnuSendCommand(64+Copy_U8CGRAMPos*8) ;

		for ( u8 Local_U8Count=0 ; Local_U8Count<8 ; Local_U8Count++ )
		{
			LCD_EnuSendData(Copy_U8PatternMatrix[Local_U8Count]) ;
		}
		/* Return Address Counter to the DD-RAM*/
		LCD_EnuSendCommand(128) ;

		error = ES_OK ;
	}
	else
	{
		error = ES_OUT_OF_RANGE ;
	}
	return error ;

}



/**************************************************************************/
/***********  Write a Special Character on the Screen form CG-RAM *********/
/**************************************************************************/
ErrorState LCD_EnuWriteSpecialChar ( u8 Copy_U8CharPattern )
{
	ErrorState error = ES_NOK ;

	LCD_EnuSendData(Copy_U8CharPattern) ;

	error = ES_OK ;

	return error ;

}







