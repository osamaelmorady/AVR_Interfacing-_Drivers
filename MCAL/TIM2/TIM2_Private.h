/*
 * TIM_Private.h
 *
 *  Created on: Nov 8, 2020
 *      Author: Osama Elmorady
 */

#ifndef TIM2_PRIVATE_H_
#define TIM2_PRIVATE_H_

#define NULL '\0'



/****************************************/
/****  Define AVR Timer 2 Addresses  ****/
/****************************************/
#define   TCCR2		 (*(u8 *)REG_TCCR2)
#define   TCNT2		 (*(u8 *)REG_TCNT2)
#define   OCR2		 (*(u8 *)REG_OCR2)
#define   ASSR		 (*(u8 *)REG_ASSR)

/* Timer/Counter Mode Operation Bits */ /* Normal Timer , PWM (Correct Phase)  , CTC Timer  , PWM (Fast) */
#define WGM20		6
#define WGM21		3

/*  Compare Match For Output mode  */ /* Non PWM   ,   Fast PWM    , Phase Correct PWM */
#define COM20		4
#define COM21		5

/* Prescaler Bits */
#define CS20		0
#define CS21		1
#define CS22		2

/* Overflow interrupt enable bit */
#define TOIE2   	6			/* Interrupt Enable */
#define TOV2  		6			/* Interrupt Flag */









/**********************************************/
/****  Define AVR Timers Common Addresses  ****/
/**********************************************/
#define   TIMSK			(*(u8 *)REG_TIMSK )
#define   TIFR			(*(u8 *)REG_TIFR )
#define   SFIOR			(*(u8 *)REG_SFIOR )






/***********************************************/
/****  Define AVR Status Register  Address  ****/
/***********************************************/
#define SREG			(*(u8 *)REG_SREG)
#define SREG_INTERRUPT_BIT 		7










/*********************************************/
/********* Timer Mode Configuration **********/
/*********************************************/
#define    NORMAL_TIMER      0
#define    PHASE_PWM_TIMER         1
#define    CTC_TIMER         2
#define    FAST_PWM_TIMER         3





/******************************************************/
/********* Timer Compare Match Configuration **********/
/******************************************************/
#define   NORMAL_COMPARE           0
#define   TOGGLE_ON_COMPARE        1
#define   CLEAR_ON_COMPARE         2
#define   SET_ON_COMPARE           3






/**************************************************/
/********* Timer Prescaler Configuration **********/
/**************************************************/
#define   TIMER_NK_SOURCE                 0
#define   TIMER_PRESCALER_1               1
#define   TIMER_PRESCALER_8               2
#define   TIMER_PRESCALER_64              3
#define   TIMER_PRESCALER_256             4
#define   TIMER_PRESCALER_1024            5
#define   TIMER_CLK_ON_FALLING_EDGE       6
#define   TIMER_CLK_ON_RISING_EDGE        7






void __vector_5(void) __attribute__((signal)) ;





#endif /* TIM2_PRIVATE_H_ */
