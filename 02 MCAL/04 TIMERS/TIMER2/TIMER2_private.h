/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 25 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef	TIMER2_PRIVATE_H
#define TIMER2_PRIVATE_H

/*Timer/Counter Control Register*/

#define TCCR2 *((volatile uint8*)0x45)
#define TCNT2 *((volatile uint8*)0x44)
#define OCR2  *((volatile uint8*)0x43)
#define ASSR  *((volatile uint8*)0x42)
#define AS2     3
#define TIMSK *((volatile uint8*)0x59)

/**** TIMSK *****/	
#define		TOIE2	6
#define		OCIE2	7       

/* TCCR2 */
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0


/* Interrupt Service Routine */

#  define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)

/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			__vector_5

#endif


