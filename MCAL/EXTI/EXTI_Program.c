
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "GIE/GIE_Interface.h"


#include "EXTI_Config.h"
#include "EXTI_Private.h"




ErrorState EXTI_VidInit(u8 Local_U8IntChannel)
{
	ErrorState error = ES_NOK ;

	/******** GIE Enable ***********/
	/*******************************/
	GIE_EnuEnable() ;

	switch (Local_U8IntChannel)
	{

/************** INT0 Configuration *******************/
/*****************************************************/

	case INT0 : 

	#if EXTI0_MODE==LOW_LEVEL
		CLR_BIT(MCUCR,ISC00) ;
		CLR_BIT(MCUCR,ISC01) ;

	#elif EXTI0_MODE==ON_CHANGE
		SET_BIT(MCUCR,ISC00) ;
		CLR_BIT(MCUCR,ISC01) ;

	#elif EXTI0_MODE==FALLING
		CLR_BIT(MCUCR,ISC00) ;
		CLR_BIT(MCUCR,ISC01) ;

	#elif EXTI0_MODE==RISING
		SET_BIT(MCUCR,ISC00) ;
		SET_BIT(MCUCR,ISC01) ;

	#else
	#error "Wrong INT0 Mode"
	#endif
		break ;


/************** INT0 Configuration *******************/
/*****************************************************/
	case INT1 :
	#if EXTI1_MODE==LOW_LEVEL
		CLR_BIT(MCUCR,ISC10) ;
		CLR_BIT(MCUCR,ISC11) ;

	#elif EXTI1_MODE==ON_CHANGE
		SET_BIT(MCUCR,ISC10) ;
		CLR_BIT(MCUCR,ISC11) ;

	#elif EXTI1_MODE==FALLING
		CLR_BIT(MCUCR,ISC10) ;
		CLR_BIT(MCUCR,ISC11) ;

	#elif EXTI1_MODE==RISING
		SET_BIT(MCUCR,ISC10) ;
		SET_BIT(MCUCR,ISC11) ;

	#else
	#error "Wrong INT1 Mode"
	#endif
		break ;


/************** INT0 Configuration *******************/
/*****************************************************/
	case INT2 :
	#if EXTI2_MODE==FALLING
		CLR_BIT(MCUCSR,ISC2) ;

	#elif EXTI2_MODE==RISING
		SET_BIT(MCUCSR,ISC2) ;
	#else
	#error "Wrong INT2 Mode"
	#endif
		break ;



	default :	
		break ;


	}

	 error = ES_OK ;

	 return error ;


}




ErrorState EXTI_VidEnable(u8 Local_U8IntChannel)
{
	ErrorState error = ES_NOK ;

	switch (Local_U8IntChannel)
	{
		case INT0 :		SET_BIT(GICR,EXTI_INT0) ;	break ;

		case INT1 :		SET_BIT(GICR,EXTI_INT1) ;	break ;

		case INT2 :

			/*****  Clear the INT2 Flag  *****/
			SET_BIT(GIFR,EXTI_INT2) ;

			SET_BIT(GICR,EXTI_INT2) ;	break ;

		default : 						break ;


	}
	
	error = ES_OK ;

	return error ;
	
}



ErrorState EXTI_VidDisable(u8 Local_U8IntChannel)
{
	ErrorState error = ES_NOK ;

	switch (Local_U8IntChannel)
	{
		case INT0 :		CLR_BIT(GICR,EXTI_INT0) ;	break ;

		case INT1 :		CLR_BIT(GICR,EXTI_INT1) ;	break ;

		case INT2 :		CLR_BIT(GICR,EXTI_INT2) ;	break ;

		default : 						break ;
		
	}
	
	error = ES_OK ;

	return error ;

}





/*************************************/
/****** Call Back Function  ******/
/*************************************/
void (* Copy_PFunEXTI0)(void) = NULL ;
void (* Copy_PFunEXTI1)(void) = NULL ;
void (* Copy_PFunEXTI2)(void) = NULL ;



ErrorState EXTI_SetCallBackFun(u8 Copy_U8EXTINumber,void (* Copy_PUserFun)(void))
{
	ErrorState error = ES_NOK ;

	switch(Copy_U8EXTINumber)
	{
	case INT0 :		Copy_PFunEXTI0 = Copy_PUserFun ; 	break ;

	case INT1 :		Copy_PFunEXTI1 = Copy_PUserFun ; 	break ;

	case INT2 :		Copy_PFunEXTI2 = Copy_PUserFun ; 	break ;

	default   : 							break ;

	}

	error = ES_OK ;

	return error ;

}



/*************************************/
/****** ISR Calling From System ******/
/*************************************/
void __vector_1(void)
{
	Copy_PFunEXTI0() ;
}



/*************************************/
/****** ISR Calling From System ******/
/*************************************/
void __vector_2(void)
{
	Copy_PFunEXTI1() ;
}



/*************************************/
/****** ISR Calling From System ******/
/*************************************/
void __vector_3(void)
{
	Copy_PFunEXTI2() ;
}









