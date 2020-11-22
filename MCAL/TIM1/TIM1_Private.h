/*
 * TIM_Private.h
 *
 *  Created on: Nov 8, 2020
 *      Author: Osama Elmorady
 */

#ifndef TIM1_PRIVATE_H_
#define TIM1_PRIVATE_H_

#define NULL '\0'




/****************************************/
/****  Define AVR Timer 1 Addresses  ****/
/****************************************/
#define   TCCR1A		(*(u8 *)REG_TCCR1A)
#define   TCCR1B		(*(u8 *)REG_TCCR1B)

#define   TCNT1H		(*(u8 *)REG_TCNT1H)
#define   TCNT1L		(*(u8 *)REG_TCNT1L)
#define   TCNT1			(*(u16 *)REG_TCNT1L)


#define   OCR1AH		(*(u8 *)REG_OCR1AH)
#define   OCR1AL		(*(u8 *)REG_OCR1AL)
#define   OCR1A			(*(u16 *)REG_OCR1AL)

#define   OCR1BH		(*(u8 *)REG_OCR1BH)
#define   OCR1BL		(*(u8 *)REG_OCR1BL)
#define   OCR1B			(*(u16 *)REG_OCR1BL)




#define ICR1H			(*(u8 *)REG_ICR1H)
#define ICR1L			(*(u8 *)REG_ICR1L)
#define ICR1			(*(u16 *)REG_ICR1L)


/* Timer/Counter Mode Operation Bits */ /* Normal Timer , PWM (Correct Phase)  , CTC Timer  , PWM (Fast) */
#define WGM10		0
#define WGM11		1
#define WGM12		3
#define WGM13		4


/*  Compare Match For Output mode  */ /* Non PWM   ,   Fast PWM    , Phase Correct PWM */
#define COM1A0		6
#define COM1A1		7

#define COM1B0		4
#define COM1B1		5


/* Prescaler Bits */
#define CS10		0
#define CS11		1
#define CS12		2

/* Overflow interrupt enable bit */
#define TOIE1   	2			/* Interrupt Enable */
#define TICIE1		5
#define TOV1	  	2			/* Interrupt Flag */



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
#define    CTC_TIMER         1
#define	   PWM_TIMER		 2




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








/* Timer/Counter1 Overflow */
void __vector_9(void) __attribute__((signal)) ;


/* Timer/Counter1 Compare Match A*/
void __vector_7(void) __attribute__((signal)) ;


/* Timer/Counter1 Compare Match B */
void __vector_8(void) __attribute__((signal)) ;


/* Timer/Counter1 Capture Event */
void __vector_6(void) __attribute__((signal)) ;



#endif /* TIM1_PRIVATE_H_ */
