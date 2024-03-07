/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 21 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef	EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define NULL  (void*)0

/* Interrupt Service Routine */

#  define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)

/* Interrupt vectors */
/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3

/*General Interrupt Control Register- Used For Enable Interrupt*/
#define EXTI_GICR *((volatile uint8*)0x5B)

#define EXTI0_EN			 6      /*  Enable bit For EXTI0    */
#define EXTI1_EN			 7      /*  Enable bit For EXTI1    */
#define EXTI2_EN			 5      /*  Enable bit For EXTI2    */

/*General Interrupt Flag Register*/
#define EXTI_GIFR *((volatile uint8*)0x5A)

/* Flags Bits For External Interrupts */
#define EXTI0_FLAG			 6		/*  Flag bit For EXTI0    */
#define EXTI1_FLAG			 7		/*  Flag bit For EXTI1    */
#define EXTI2_FLAG			 5		/*  Flag bit For EXTI2    */

/*MCU Control Register*/
#define EXTI_MCUCR *((volatile uint8*)0x55)

#define ISC00_PIN 0
#define ISC01_PIN 1
#define ISC10_PIN 2
#define ISC11_PIN 3

/*MCU Control  and Status Register*/
#define EXTI_MCUCSR *((volatile uint8*)0x54) 

#define ISC2_PIN 6U

/* Status Register */
#define SREG *((volatile uint8*)0x5F)

/*where bit 7 for I Bit (Global interrupt bit)*/
#define I_BIT 7U






#endif


