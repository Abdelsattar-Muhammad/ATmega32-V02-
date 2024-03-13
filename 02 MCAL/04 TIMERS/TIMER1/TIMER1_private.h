/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 25 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef	TIMER1_PRIVATE_H
#define TIMER1_PRIVATE_H

/*Timer/Counter Control Register*/
#define ICR1    *((volatile uint16*)0x46)
#define TCNT1   *((volatile uint16*)0x4C)
#define OCR1A   *((volatile uint16*)0x4A)
#define OCR1B   *((volatile uint16*)0x48)
#define TCCR1B  *((volatile uint8* )0x4E)
#define TCCR1A  *((volatile uint8* )0x4F)

#define TIMSK   *((volatile uint8* )0x59)

#define ASSR    *((volatile uint8* )0x22)
#define AS2     3U

/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0


/* TIMSK */
#define	TOIE0	0
#define	OCIE0	1
#define	TOIE1	2
#define	OCIE1B  3
#define	OCIE1A	4
#define	TICIE1	5
#define	TOIE2	6
#define	OCIE2	7


/* Interrupt Service Routine */
#define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect		__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect		__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect		__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9


#endif


