#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_



#include "LIB/ERROR_STATE.h"
#include "EXTI_Config.h"




ErrorState EXTI_VidInit(u8 Local_U8IntChannel) ;

ErrorState EXTI_VidEnable(u8 Local_U8IntChannel);

ErrorState EXTI_VidDisable(u8 Local_U8IntChannel);



ErrorState EXTI_SetCallBackFun(u8 Copy_U8EXTINumber,void (* User_Fun)(void)) ;




#endif
