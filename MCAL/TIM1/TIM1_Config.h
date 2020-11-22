/*
 * TIM_Config.h
 *
 *  Created on: Nov 8, 2020
 *      Author: Osama Elmorady
 */

#ifndef TIM1_CONFIG_H_
#define TIM1_CONFIG_H_






/*********************************************/
/********* Timer Mode Configuration **********/
/*********************************************/
//#define TIMER_MODE 				 NORMAL_TIMER
//#define TIMER_MODE 				 CTC_TIMER
#define TIMER_MODE 				 	 PWM_TIMER





/******************************************************/
/********* Timer Compare Match Configuration **********/
/******************************************************/
//#define  TIMER_COMPARE_MATCH  		NORMAL_COMPARE
//#define  TIMER_COMPARE_MATCH  	TOGGLE_ON_COMPARE
#define  TIMER_COMPARE_MATCH  	CLEAR_ON_COMPARE
//#define  TIMER_COMPARE_MATCH  	SET_ON_COMPARE







/**************************************************/
/********* Timer Prescaler Configuration **********/
/**************************************************/
//#define  TIMER_PRESCALER		TIMER_NK_SOURCE
//#define  TIMER_PRESCALER		TIMER_PRESCALER_1
//#define  TIMER_PRESCALER		TIMER_PRESCALER_8
//#define  TIMER_PRESCALER		TIMER_PRESCALER_64
#define  TIMER_PRESCALER		TIMER_PRESCALER_256
//#define  TIMER_PRESCALER		TIMER_PRESCALER_1024
//#define  TIMER_PRESCALER		TIMER_CLK_ON_FALLING_EDGE
//#define  TIMER_PRESCALER		TIMER_CLK_ON_RISING_EDGE
















#endif /* TIM1_CONFIG_H_ */
