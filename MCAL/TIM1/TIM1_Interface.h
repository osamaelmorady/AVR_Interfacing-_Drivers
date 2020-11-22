/*
 * TIM_Interface.h
 *
 *  Created on: Nov 8, 2020
 *      Author: Osama Elmorady
 */

#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_


#include "LIB/ERROR_STATE.h"
#include "TIM1_Config.h"




ErrorState TIM1A_VidInit(void) ;



ErrorState PWM1A_SetDutyCycle(u8 Copy_U8Percent) ;



ErrorState TIM1A_VidEnable (void) ;



ErrorState TIM1A_VidDisable (void) ;



ErrorState TIM1A_VidSetCallBack(void (*PF)(void)) ;











ErrorState TIM1B_VidInit(void) ;



ErrorState TIM1B_VidEnable (void) ;



ErrorState TIM1B_VidDisable (void) ;



ErrorState PWM1B_SetDutyCycle(u8 Copy_U8Percent) ;



ErrorState TIM1B_VidSetCallBack(void (*PF)(void)) ;

























#endif /* TIM1_INTERFACE_H_ */
