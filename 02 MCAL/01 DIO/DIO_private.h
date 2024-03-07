/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 20 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H 

/*local defines*/
volatile typedef struct
{
	 volatile uint8 PIN;
	 volatile uint8 DDR;
	 volatile uint8 PORT;
     
}GPIO_RegDef_t;

#define NUMBER_OF_PORTS     4U

/* PORTA  Register*/
#define GPIOA  ((volatile GPIO_RegDef_t*)0x39)

#define GPIOB  ((volatile GPIO_RegDef_t*)0x36)
#define GPIOC  ((volatile GPIO_RegDef_t*)0x33)
#define GPIOD  ((volatile GPIO_RegDef_t*)0x30)

#endif