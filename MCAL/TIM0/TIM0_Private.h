/*
 * TIM_Private.h
 *
 *  Created on: Nov 8, 2020
 *      Author: Osama Elmorady
 */

#ifndef TIM0_PRIVATE_H_
#define TIM0_PRIVATE_H_

#define NULL '\0'

/****************************************/
/****  Define AVR Timer 0 Addresses  ****/
/****************************************/
#define   TCCR0		(*(u8 *)REG_TCCR0)
#define   TCNT0		(*(u8 *)REG_TCNT0)
#define   OCR0		(*(u8 *)REG_OCR0)

/* Timer/Counter Mode Operation Bits */ /* Normal Timer , PWM (Correct Phase)  , CTC Timer  , PWM (Fast) */
#define WGM00		6
#define WGM01		3

/*  Compare Match For Output mode  */ /* Non PWM   ,   Fast PWM    , Phase Correct PWM */
#define COM00		4
#define COM01		5

/* Prescaler Bits */
#define CS00		0
#define CS01		1
#define CS02		2

/* Overflow interrupt enable bit */
#define TOIE0   	0			/* Interrupt Enable */
#define TOV0  		0			/* Interrupt Flag */






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








void __vector_11(void) __attribute__((signal)) ;





#endif /* TIM0_PRIVATE_H_ */
