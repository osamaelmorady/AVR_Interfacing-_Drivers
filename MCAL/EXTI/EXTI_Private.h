#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_


#define NULL '\0'


/***************************************/
/**********   EXTI Registers   *********/
/***************************************/
#define SREG   (*(u8 *)0x5F)
#define MCUCR  (*(u8 *)0x55)
#define MCUCSR (*(u8 *)0x54)
#define GICR   (*(u8 *)0x5B)
#define GIFR   (*(u8 *)0x5A)




/**********  MCUCR ***********/
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3



/**********  MCUCSR ***********/
#define ISC2 6







/********************************************/
/**********   EXTI Mode Selection   *********/
/********************************************/
// Interrupt Sense Control
#define  LOW_LEVEL	 0
#define  ON_CHANGE	 1
#define  FALLING	 2
#define  RISING	 3






/*****************************************/
/**********   EXTI Pin Number    *********/
/*****************************************/
#define EXTI_INT0		6
#define EXTI_INT1		7
#define EXTI_INT2		5

/******* EXTI Flags ******/
#define EXTI_INTF0		6
#define EXTI_INTF1		7
#define EXTI_INTF2		5





void __vector_1(void) __attribute__((signal)) ;



void __vector_2(void) __attribute__((signal)) ;



void __vector_3(void) __attribute__((signal)) ;








#endif
