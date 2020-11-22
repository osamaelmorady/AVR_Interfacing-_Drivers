/*
 * I2C_Program.h
 *
 *  Created on: Nov 22, 2020
 *      Author: Osama Elmorady
 */


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/ERROR_STATE.h"
#include "LIB/AVR32_REG.h"

#include "I2C_Private.h"
#include "I2C_Config.h"







/*****************************************/
/****  Initialization I2C Peripheral  ****/
/*****************************************/
ErrorState I2C_EnuInit(void)
{

#if	I2C_PRESCALER == PRESCALER_1

	CLR_BIT (TWSR , TWPS0) ;
	CLR_BIT (TWSR , TWPS1) ;

#elif	I2C_PRESCALER == PRESCALER_4

	SET_BIT (TWSR , TWPS0) ;
	CLR_BIT (TWSR , TWPS1) ;

#elif	I2C_PRESCALER == PRESCALER_16

	CLR_BIT (TWSR , TWPS0) ;
	SET_BIT (TWSR , TWPS1) ;

#elif	I2C_PRESCALER == PRESCALER_64

	SET_BIT (TWSR , TWPS0) ;
	SET_BIT (TWSR , TWPS1) ;

#else
#error "Wrong I2C_PRESCALER !! "
#endif

	/************ Bit Rate Generator ***************/
	TWBR = (u8) TWBR_VALUE  ;

	/* Clear flag */
	SET_BIT (TWCR , TWINT);

#if ACK_MODE == ACK_ENABLE

	SET_BIT (TWCR , TWEA );		//	Enable ACK

#elif ACK_MODE == ACK_DISABLE

	CLR_BIT (TWCR , TWEA );		//	Disable ACK


#else
#error 	"Wrong ACK_MODE !! "
#endif

	/* Enable the I2C peripheral */
	SET_BIT (TWCR , TWEN );


#if GENERAL_CALL_MODE == GENERAL_CALL_ENABLE
	/* General call enable  */
	SET_BIT( TWAR , TWGCE );

#elif	GENERAL_CALL_MODE == GENERAL_CALL_DISABLE
	/* General call Disable  */
	CLR_BIT( TWAR , TWGCE );


#else
#error 	"Wrong GENERAL_CALL_MODE !! "
#endif


	TWAR |= (MCU_ADDRESS<<1)   ;


	return ES_OK ;

}














#if MCU_TYPE == MASTER_NODE



/********************************/
/****  MCU Master Functions  ****/
/********************************/

/****  First Step (Start Condition)  ****/
/****************************************/
ErrorState I2C_EnuStartCondition(void)
{

	/* Clear the flag & start the Condition */
	TWCR |= (1<<TWINT) | (1<<TWSTA)  ;

	/* Poll on the flag until condition ends */
	while (!GET_BIT(TWCR , TWINT)) ;

	/* if start condition occurs correctly , Reset manually */
	if (TWSR_BITS_CHECK == CORRECT_START_CONDITION)
	{
		return ES_OK ;
	}

	return ES_NOK ;

}







/****  Second Step (Send Address)   ****/
/***************************************/
ErrorState I2C_EnuMasterSendAddress(u8 Copy_U8Address,u8 Copy_U8Mode)
{

	/* Send address with Write */
	TWDR = ( Copy_U8Address << 1 )  | Copy_U8Mode   ;

	/* Clear the start condition	*/
	TWCR &=  ~(1<<TWSTA)  ;

	/* Clear the flag  */
	TWCR |= (1<<TWINT)   ;


	/* Poll on the flag until Sending address ends */
	while (!GET_BIT(TWCR,TWINT)) ;

	/* Slave address status Register in writing case with ACK  */
	if ( ( Copy_U8Mode==WRITING_MODE ) && (TWSR_BITS_CHECK == CORRECT_ADDRESS_SENT_WRITING )  )
	{
			return ES_OK ;
	}
	/* Slave address status Register in Reading case with ACK  */
	else if ( ( Copy_U8Mode==READING_MODE ) && (TWSR_BITS_CHECK == CORRECT_ADDRESS_SENT_READING )  )
	{
			return ES_OK ;
	}
	else
	{ 		return ES_OUT_OF_RANGE ;		}



}










/****  Third Step (Send Data)   ****/
/***********************************/
ErrorState I2C_EnuMasterSendData(u8 Copy_U8Data)
{

	TWDR = Copy_U8Data ;

	/* Clear the flag */
	TWCR |= (1<<TWINT) ;

	/* Poll on the flag until Sending data ends */
	while (!GET_BIT(TWCR,TWINT)) ;

	/* Data has been transmitted With ACK Returned */
	if (TWSR_BITS_CHECK == CORRECT_MASTER_DATA_SENT)
		{
			return ES_OK ;
		}

	return ES_NOK ;


}




/****  Third Step (Receive Data)   ****/
/**************************************/
ErrorState I2C_EnuMasterReceiveData(u8 * Copy_PU8ReceivedData)
{

	/* Clear the flag */
	TWCR |= (1<<TWINT) ;

	/* Poll on the flag until Sending data ends */
	while (!GET_BIT(TWCR,TWINT)) ;

	/* Data has been Received With ACK Returned */
	if (TWSR_BITS_CHECK == CORRECT_MASTER_DATA_RECEIVED)
		{
			* Copy_PU8ReceivedData = TWDR ;

			return ES_OK ;
		}

	return ES_NOK ;


}




/****  Fourth Step (Repeated Start Condition) (Optional) ****/
/***********************************************************/
ErrorState I2C_EnuReStartCondition(void)
{

	/* Clear the flag & start the Condition */
		TWCR |= (1<<TWINT) | (1<<TWSTA)  ;

		/* Poll on the flag until condition ends */
		while (!GET_BIT(TWCR,TWINT)) ;

		/* if start condition occurs correctly , Reset manually */
		if (TWSR_BITS_CHECK == CORRECT_RESTART_CONDITION)
		{
			return ES_OK;
		}

		return ES_NOK ;

}



/****  Fifth Step (Stop Condition)  ****/
/***************************************/
ErrorState I2C_EnuStopCondition(void)
{

	/* Clear the flag  & Stop Condition */
	TWCR |= (1<<TWINT) | (1<<TWSTO) ;

	return ES_OK;

}







#elif MCU_TYPE == SLAVE_NODE


/********************************/
/****  MCU Slave Functions  ****/
/********************************/



/****  First Step (Check Address)  ****/
/**************************************/
ErrorState I2C_EnuSlaveCheckAddress(void)
{

	/* Clear the flag */
	TWCR |= (1<<TWINT) ;

	/* Slave address status Register in writing case with ACK  */
	if (TWSR_BITS_CHECK == CORRECT_SLAVE_ADDRESS_RECEIVED_WRITING)
		{
			return ES_OK ;
		}
	/* Slave address status Register in Reading case with ACK  */
	else if (TWSR_BITS_CHECK == CORRECT_SLAVE_ADDRESS_RECEIVED_READING)
		{
			return ES_OK ;
		}
	else
	{
			return ES_NOK ;
	}

}




/****  Second Step (Send Data)  ****/
/***********************************/
ErrorState I2C_EnuSlaveSendData(u8 Copy_U8Data)
{

	TWDR = Copy_U8Data ;

	/* Clear the flag */
	TWCR |= (1<<TWINT) ;

	/* Poll on the flag until Sending data ends */
	while (!GET_BIT(TWCR,TWINT)) ;

	/* Data has been Transmitted With ACK Returned */
	if (TWSR_BITS_CHECK == CORRECT_SLAVE_DATA_SENT)
		{
			return ES_OK ;
		}

	return ES_NOK ;



}




/****  Second Step (Receive Data)  ****/
/**************************************/
ErrorState I2C_EnuSlaveReceiveData(u8 * Copy_PU8ReceivedData)
{

	/* Clear the flag */
	TWCR |= (1<<TWINT) ;

	/* Poll on the flag until Receiving data ends */
	while (!GET_BIT(TWCR,TWINT)) ;

	/* Data has been Received With ACK Returned */
	if (TWSR_BITS_CHECK == CORRECT_SLAVE_DATA_RECEIVED)
		{
			* Copy_PU8ReceivedData = TWDR ;

			return ES_OK ;
		}

	return ES_NOK ;


}







#else
#error  "Wrong MCU_TYPE !! "
#endif


