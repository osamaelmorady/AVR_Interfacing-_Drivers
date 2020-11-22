/*
 * UART_Private.h
 *
 *  Created on: Nov 12, 2020
 *      Author: Osama Elmorady
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define NULL '\0'

/****************************************************************/
/*************** UART Registers CONFIGURATION *******************/
/****************************************************************/
#define UDR		(*(u8 *) REG_UDR )
#define UCSRA	(*(u8 *) REG_UCSRA )
#define UCSRB	(*(u8 *) REG_UCSRB )
#define UCSRC	(*(u8 *) REG_UCSRC )
#define UBRRH 	(*(u8 *) REG_UBRRH  )
#define UBRRL	(*(u8 *) REG_UBRRL )


/* UART I/O Register */
#define UDR_RXB		UDR
#define UDR_TXB		UDR




/*************** UART UCSRA Bits CONFIGURATION **************/
/************************************************************/
#define MPCM	0			/* Multi-Processor Communication Mode */
#define U2X		1			/* Double the USART Speed */
#define PE      2           /* Parity Error */
#define DOR     3           /* Data OverRun */
#define FE      4           /* Frame Error */
#define UDRE    5           /* USART Data Register Empty */
#define TXC     6           /* USART Transmit Complete */
#define RXC     7           /* USART Receive Complete */




/*************** UART UCSRB Bits CONFIGURATION **************/
/************************************************************/
#define TXB8	0			/* Transmit Data Bit 8 */
#define RXB8	1			/* Receive Data Bit 8 */
#define UCSZ2   2           /* Character Size (5:9) */
#define TXEN    3           /* Transmitter Enable */
#define RXEN    4           /* Receiver Enable */
#define UDRIE   5           /* USART Data Register Empty Interrupt Enable */
#define TXCIE   6           /* TX Complete Interrupt Enable */
#define RXCIE   7           /* RX Complete Interrupt Enable */





/*************** UART UCSRC Bits CONFIGURATION **************/
/************************************************************/
#define UCPOL	0			/* Clock Polarity (Rising - Falling) */
#define UCSZ0	1			/* Character Size (5:9) */
#define UCSZ1   2           /* Character Size (5:9) */
#define USBS    3           /* Stop Bit Select (1-2) */
#define UPM0    4           /* Parity Mode */
#define UPM1    5           /* Parity Mode */
#define UMSEL   6           /* USART Mode Select (Async - Sync) */
#define URSEL   7           /* Register Select */





/************* TX,RX Pin Configuration *************/
/***************************************************/
#define UART_RX_PIN		PIN24
#define UART_TX_PIN		PIN25







/********************************************************/
/*************** UART Speed Selection *******************/
/********************************************************/
#define NORMAL_TRANSMISSION_SPEED		0
#define DOUBLE_TRANSMISSION_SPEED		1






/********************************************************/
/*************** Baud Rate Selection *******************/
/********************************************************/
#define BAUD_8MHZ_9600		51			/* Baud Rate= 9600  , and normal speed */
#define BAUD_8MHZ_14400		34          /* Baud Rate= 14400 , and normal speed */
#define BAUD_8MHZ_19200		25          /* Baud Rate= 19200 , and normal speed */
#define BAUD_8MHZ_28800		16          /* Baud Rate= 28800 , and normal speed */
#define BAUD_8MHZ_38400		12          /* Baud Rate= 38400 , and normal speed */

#define B_9600		9600
#define B_14400     14400
#define B_19200     19200
#define B_28800     28800
#define B_38400     38400





/* USART, Rx Complete Interrupt */
void __vector_13(void)__attribute((signal)) ;




/* USART Data Register Empty Interrupt */
void __vector_14(void)__attribute((signal)) ;




/* USART, Tx Complete Interrupt */
void __vector_15(void)__attribute((signal)) ;






#endif /* UART_PRIVATE_H_ */
