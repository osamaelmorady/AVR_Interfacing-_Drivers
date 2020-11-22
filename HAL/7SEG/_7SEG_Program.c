
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO/DIO_Interface.h"


#include "_7SEG_Config.h"
#include "_7SEG_Private.h"



/****************************************************************/
/*************** Initialization of the 7 Segment ****************/
/****************************************************************/
ErrorState _7SEG_VidInit(void)
{
	ErrorState error = ES_NOK ;

	DIO_EnuSetPinDir( _7SEG_A   ,  OUTPUT  ) ;
	DIO_EnuSetPinDir( _7SEG_B   ,  OUTPUT  ) ;
	DIO_EnuSetPinDir( _7SEG_C   ,  OUTPUT  ) ;
	DIO_EnuSetPinDir( _7SEG_D   ,  OUTPUT  ) ;
	DIO_EnuSetPinDir( _7SEG_E   ,  OUTPUT  ) ;
	DIO_EnuSetPinDir( _7SEG_F   ,  OUTPUT  ) ;
	DIO_EnuSetPinDir( _7SEG_G   ,  OUTPUT  ) ;
	DIO_EnuSetPinDir( _7SEG_DOT ,  OUTPUT  ) ;

	error = ES_OK ;
	return error ;
}







/**************************************************************************/
/*************** Show A Number from 0-9 and '.' on 7Segment ***************/
/**************************************************************************/

u8 _7SEGMENT_U8Numbers[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

ErrorState _7SEG_VidShowNumber(u8 Local_U8ShowedNumber)
{
	ErrorState error = ES_NOK ;

#if _7SEG_TYPE == K_TYPE

	if ( Local_U8ShowedNumber>=0 && Local_U8ShowedNumber<=9 )
	{
		DIO_EnuSetPinVal ( _7SEG_A   , ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT0	)	) ;
		DIO_EnuSetPinVal ( _7SEG_B   , ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT1	)	) ;
		DIO_EnuSetPinVal ( _7SEG_C   , ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT2	)	) ;
		DIO_EnuSetPinVal ( _7SEG_D   , ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT3	)	) ;
		DIO_EnuSetPinVal ( _7SEG_E   , ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT4	)	) ;
		DIO_EnuSetPinVal ( _7SEG_F   , ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT5	)	) ;
		DIO_EnuSetPinVal ( _7SEG_G   , ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT6	)	) ;
		DIO_EnuSetPinVal ( _7SEG_DOT , LOW ) ;

		error = ES_OK ;
	}

	else if (Local_U8ShowedNumber=='.')
	{
		DIO_EnuSetPinVal ( _7SEG_DOT , HIGH ) ;

		error = ES_OK ;
	}
	else
	{
		error = ES_OUT_OF_RANGE ;
	}


#elif _7SEG_TYPE == A_TYPE

	if ( Local_U8ShowedNumber>=0 && Local_U8ShowedNumber<=9 )
		{
			DIO_EnuSetPinVal ( _7SEG_A   ,! ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT0	) ) ;
			DIO_EnuSetPinVal ( _7SEG_B   ,! ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT1	) ) ;
			DIO_EnuSetPinVal ( _7SEG_C   ,! ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT2	) ) ;
			DIO_EnuSetPinVal ( _7SEG_D   ,! ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT3	) ) ;
			DIO_EnuSetPinVal ( _7SEG_E   ,! ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT4	) ) ;
			DIO_EnuSetPinVal ( _7SEG_F   ,! ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT5	) ) ;
			DIO_EnuSetPinVal ( _7SEG_G   ,! ( _7SEGMENT_U8Numbers[Local_U8ShowedNumber]   &	_7SEG_BIT6	) ) ;

			DIO_EnuSetPinVal ( _7SEG_DOT , HIGH ) ;

			error = ES_OK ;
		}

		else if (Local_U8ShowedNumber=='.')
		{
			DIO_EnuSetPinVal ( _7SEG_DOT , LOW ) ;

			error = ES_OK ;
		}
		else
		{
			error = ES_OUT_OF_RANGE ;
		}

#else


#error "Wrong 7Segment Type Input"


#endif

	return error ;
}
