/*
 * TIM_Program.c
 *
 *  Created on: Nov 8, 2020
 *      Author: Osama Elmorady
 */

#ifndef TIM1_PROGRAM_C_
#define TIM1_PROGRAM_C_

#include "LIB/AVR32_REG.h"
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "LIB/ERROR_STATE.h"

#include "GIE/GIE_Interface.h"
#include "DIO/DIO_Interface.h"
#include "TIM1_Config.h"
#include "TIM1_Private.h"



ErrorState TIM1A_VidInit(void)
{
	ErrorState error = ES_NOK ;

	/* Enable Global Interrupt */
	//GIE_EnuEnable() ;


	/* Reset all Configuration */
	TCCR1A=0x00 ;

	/* Timer Initial Value = 0 */
	TCNT1=0        ;

	/* Timer roof Value = 0 */
	ICR1=625    ;




	/*********************************************/
	/********* Timer 1 Mode Configuration **********/
	/*********************************************/
#if TIMER_MODE == NORMAL_TIMER
	/* Set a Normal Timer */
	CLR_BIT(TCCR1A,WGM10) ;
	CLR_BIT(TCCR1A,WGM11) ;

	CLR_BIT(TCCR1B,WGM12) ;
	CLR_BIT(TCCR1B,WGM13) ;

#elif TIMER_MODE == CTC_TIMER
	/* Set a CTC Timer */
	CLR_BIT(TCCR1A,WGM10) ;
	CLR_BIT(TCCR1A,WGM11) ;

	SET_BIT(TCCR1B,WGM12) ;
	CLR_BIT(TCCR1B,WGM13) ;

	OCR1B = 65535  ;

#elif TIMER_MODE == PWM_TIMER

	/* Set as PWM Timer */
	CLR_BIT(TCCR1A,WGM10) ;
	SET_BIT(TCCR1A,WGM11) ;

	SET_BIT(TCCR1B,WGM12) ;
	SET_BIT(TCCR1B,WGM13) ;

#else
#error "Wrong Timer Mode Input"
#endif




	/******************************************************/
	/********* Timer Compare Match Configuration **********/
	/******************************************************/
#if TIMER_COMPARE_MATCH == NORMAL_COMPARE

	/* Compare output mode , Non PWM */
		CLR_BIT(TCCR1A,COM1B0) ;
		CLR_BIT(TCCR1A,COM1B1) ;


#elif TIMER_COMPARE_MATCH == TOGGLE_ON_COMPARE

	/* Compare output mode , Non PWM */
		SET_BIT(TCCR1A,COM1B0) ;
		CLR_BIT(TCCR1A,COM1B1) ;


#elif TIMER_COMPARE_MATCH == CLEAR_ON_COMPARE

	/* Compare output mode , Fast PWM */
		CLR_BIT(TCCR1A,COM1B0) ;
		SET_BIT(TCCR1A,COM1B1) ;


#elif TIMER_COMPARE_MATCH == SET_ON_COMPARE
	/* Compare output mode , Fast PWM */
		SET_BIT(TCCR1A,COM1B0) ;
		SET_BIT(TCCR1A,COM1B1) ;

#else
#error "Wrong Compare Match Mode"
#endif




	/**************************************************/
	/********* Timer Prescaler Configuration **********/
	/**************************************************/
#if TIMER_PRESCALER == TIMER_NK_SOURCE
	/* Close the Clock   */
	CLR_BIT(TCCR1B,CS10) ;
	CLR_BIT(TCCR1B,CS11) ;
	CLR_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_1
	/* Set the Prescaler  1   */
	SET_BIT(TCCR1B,CS10) ;
	CLR_BIT(TCCR1B,CS11) ;
	CLR_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_8
	/* Set the Prescaler  8   */
	CLR_BIT(TCCR1B,CS10) ;
	SET_BIT(TCCR1B,CS11) ;
	CLR_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_64
	/* Set the Prescaler  64   */
	SET_BIT(TCCR1B,CS10) ;
	SET_BIT(TCCR1B,CS11) ;
	CLR_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_256

	CLR_BIT(TCCR1B,CS10) ;
	CLR_BIT(TCCR1B,CS11) ;
	SET_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_1024
	/* Set the Prescaler  1024   */
	SET_BIT(TCCR1B,CS10) ;
	CLR_BIT(TCCR1B,CS11) ;
	SET_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_CLK_ON_FALLING_EDGE
	/* External Clock Source on Falling Edge   */
	SET_BIT(TCCR1B,CS10) ;
	CLR_BIT(TCCR1B,CS11) ;
	SET_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_CLK_ON_RISING_EDGE
	/* External Clock Source on Rising Edge */
	SET_BIT(TCCR1B,CS10) ;
	CLR_BIT(TCCR1B,CS11) ;
	SET_BIT(TCCR1B,CS12) ;

#else
#error "Wrong Prescaler Input"
#endif


	/* Interrupt enable   */
	//SET_BIT(TIMSK,TOIE1) ;

	error =ES_OK ;

	return error ;

}





ErrorState TIM1_VidEnable (void)
{
	ErrorState error = ES_NOK ;




	error =ES_OK ;

	return error ;


}



ErrorState TIM1_VidDisable (void)
{
	ErrorState error = ES_NOK ;




	error =ES_OK ;

	return error ;


}





ErrorState PWM1A_SetDutyCycle(u8 Copy_U8Percent)
{
	ErrorState error = ES_NOK ;

	u16 Local_U16Value=(Copy_U8Percent/100)*(ICR1-1) ;

	OCR1A = Local_U16Value  ;

	error =ES_OK ;

	return error ;

}
















ErrorState TIM1B_VidInit(void)
{
	ErrorState error = ES_NOK ;

	/* Enable Global Interrupt */
	//SET_BIT(SREG,SREG_INTERRUPT_BIT) ;


	/* Reset all Configuration */
	TCCR1B=0x00 ;

	/* Timer Initial Value = 0 */
	TCNT1=0        ;

	/* Timer roof Value = 0 */
	ICR1=625    ;



	/*********************************************/
	/********* Timer 1 Mode Configuration **********/
	/*********************************************/
#if TIMER_MODE == NORMAL_TIMER
	/* Set a Normal Timer */
	CLR_BIT(TCCR1A,WGM10) ;
	CLR_BIT(TCCR1A,WGM11) ;

	CLR_BIT(TCCR1B,WGM12) ;
	CLR_BIT(TCCR1B,WGM13) ;

#elif TIMER_MODE == CTC_TIMER
	/* Set a CTC Timer */
	CLR_BIT(TCCR1A,WGM10) ;
	CLR_BIT(TCCR1A,WGM11) ;

	SET_BIT(TCCR1B,WGM12) ;
	CLR_BIT(TCCR1B,WGM13) ;

	OCR1B = 65535  ;

#elif TIMER_MODE == PWM_TIMER

	/* Set as PWM Timer */
	CLR_BIT(TCCR1A,WGM10) ;
	SET_BIT(TCCR1A,WGM11) ;

	SET_BIT(TCCR1B,WGM12) ;
	SET_BIT(TCCR1B,WGM13) ;

#else
#error "Wrong Timer Mode Input"
#endif




	/******************************************************/
	/********* Timer Compare Match Configuration **********/
	/******************************************************/
#if TIMER_COMPARE_MATCH == NORMAL_COMPARE

	/* Compare output mode , Non PWM */
		CLR_BIT(TCCR1A,COM1B0) ;
		CLR_BIT(TCCR1A,COM1B1) ;


#elif TIMER_COMPARE_MATCH == TOGGLE_ON_COMPARE

	/* Compare output mode , Non PWM */
		SET_BIT(TCCR1A,COM1B0) ;
		CLR_BIT(TCCR1A,COM1B1) ;


#elif TIMER_COMPARE_MATCH == CLEAR_ON_COMPARE

	/* Compare output mode , Fast PWM */
		CLR_BIT(TCCR1A,COM1B0) ;
		SET_BIT(TCCR1A,COM1B1) ;


#elif TIMER_COMPARE_MATCH == SET_ON_COMPARE
	/* Compare output mode , Fast PWM */
		SET_BIT(TCCR1A,COM1B0) ;
		SET_BIT(TCCR1A,COM1B1) ;

#else
#error "Wrong Compare Match Mode"
#endif




	/**************************************************/
	/********* Timer Prescaler Configuration **********/
	/**************************************************/
#if TIMER_PRESCALER == TIMER_NK_SOURCE
	/* Close the Clock   */
	CLR_BIT(TCCR1B,CS10) ;
	CLR_BIT(TCCR1B,CS11) ;
	CLR_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_1
	/* Set the Prescaler  1   */
	SET_BIT(TCCR1B,CS10) ;
	CLR_BIT(TCCR1B,CS11) ;
	CLR_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_8
	/* Set the Prescaler  8   */
	CLR_BIT(TCCR1B,CS10) ;
	SET_BIT(TCCR1B,CS11) ;
	CLR_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_64
	/* Set the Prescaler  64   */
	SET_BIT(TCCR1B,CS10) ;
	SET_BIT(TCCR1B,CS11) ;
	CLR_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_256

	CLR_BIT(TCCR1B,CS10) ;
	CLR_BIT(TCCR1B,CS11) ;
	SET_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_PRESCALER_1024
	/* Set the Prescaler  1024   */
	SET_BIT(TCCR1B,CS10) ;
	CLR_BIT(TCCR1B,CS11) ;
	SET_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_CLK_ON_FALLING_EDGE
	/* External Clock Source on Falling Edge   */
	SET_BIT(TCCR1B,CS10) ;
	CLR_BIT(TCCR1B,CS11) ;
	SET_BIT(TCCR1B,CS12) ;

#elif TIMER_PRESCALER == TIMER_CLK_ON_RISING_EDGE
	/* External Clock Source on Rising Edge */
	SET_BIT(TCCR1B,CS10) ;
	CLR_BIT(TCCR1B,CS11) ;
	SET_BIT(TCCR1B,CS12) ;

#else
#error "Wrong Prescaler Input"
#endif


	/* Interrupt enable   */
	//SET_BIT(TIMSK,TOIE1) ;

	error =ES_OK ;

	return error ;


}





ErrorState TIM1B_VidEnable (void)
{
	ErrorState error = ES_NOK ;



	error =ES_OK ;

	return error ;

}



ErrorState TIM1B_VidDisable (void)
{
	ErrorState error = ES_NOK ;





	error =ES_OK ;

	return error ;


}





ErrorState PWM1B_SetDutyCycle(u8 Copy_U8Percent)
{
	ErrorState error = ES_NOK ;

	u16 Local_U16Value=(Copy_U8Percent/100)*(ICR1-1) ;

	OCR1B = Local_U16Value  ;

	error =ES_OK ;

	return error ;
}
















static void (* PVid_SetCallBack)(void) = NULL ;
static void (* PVid1A_SetCallBack)(void) = NULL ;
static void (* PVid1B_SetCallBack)(void) = NULL ;





ErrorState TIMER1_VidSetCallBack(void (* PF)(void))
{
	ErrorState error = ES_NOK ;

	PVid_SetCallBack=PF ;

	error =ES_OK ;

	return error ;
}




ErrorState TIMER1A_VidSetCallBack(void (* PF)(void))
{
	ErrorState error = ES_NOK ;

	PVid1A_SetCallBack=PF ;

	error =ES_OK ;

	return error ;
}




ErrorState TIMER1B_VidSetCallBack(void (* PF)(void))
{
	ErrorState error = ES_NOK ;

	PVid1B_SetCallBack=PF ;

	error =ES_OK ;

	return error ;
}





/*************************************/
/****** ISR Calling From System ******/
/*************************************/
/* Timer/Counter1 Overflow */

u32 TIMER1_U32Counts=0 ;

void __vector_9(void)
{
	if 	(TIMER1_U32Counts == 488 )
	{
		TCNT1=184 ;

		TIMER1_U32Counts=0 ;

		PVid_SetCallBack() ;
	}
	else
	{
		TIMER1_U32Counts+=1 ;
	}


}





/*************************************/
/****** ISR Calling From System ******/
/*************************************/
/* Timer/Counter1 Compare Match A*/
u32 TIMER1A_U32Counts=0 ;

void __vector_7(void)
{
	if 	(TIMER1A_U32Counts == 488 )
	{
		TCNT1=184 ;

		TIMER1A_U32Counts=0 ;

		PVid1A_SetCallBack() ;
	}
	else
	{
		TIMER1A_U32Counts+=1 ;
	}


}




/*************************************/
/****** ISR Calling From System ******/
/*************************************/
/* Timer/Counter1 Compare Match B */
u32 TIMER1B_U32Counts=0 ;

void __vector_8(void)
{
	if 	(TIMER1B_U32Counts == 488 )
	{
		TCNT1=184 ;

		TIMER1B_U32Counts=0 ;

		PVid1B_SetCallBack() ;
	}
	else
	{
		TIMER1B_U32Counts+=1 ;
	}


}





/*************************************/
/****** ISR Calling From System ******/
/*************************************/
/* Timer/Counter1 Capture Event */

void __vector_6(void)
{


}










#endif /* TIM_PROGRAM_C_ */
