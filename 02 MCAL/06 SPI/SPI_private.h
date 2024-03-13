/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef	SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* SPI I/O Pins */
#define SPI_PORT PORTB
#define SS		 4U
#define MOSI	 5U
#define MISO	 6U 
#define SCK		 7U

/*SPI I/O Data Register*/
#define SPDR *((volatile uint8*) 0x2F)

/*SPI Control Register*/
#define SPCR *((volatile uint8*) 0x2D)

#define SPR0 0U	/*SPI Clock Rate Select*/
#define SPR1 1U	/*SPI Clock Rate Select*/
#define CPHA 2U	/*Clock Phase*/
#define CPOL 3U  /*Clock Polarity*/
#define MSTR 4U  /*Master/Slave Select*/
#define DORD 5U  /*Data Order*/
#define SPE  6U	/*SPI Enable*/
#define SPIE 7U	/*SPI Interrupt Enable*/

/*SPI Status Register */
#define SPSR *((volatile uint8*) 0x2E)

#define SPI2X  0U /*SPI Double Speed Mode*/
/*Bit 5:1 These are reserved bits.*/
#define WCOL   6U /*Write Collision Flag*/
#define SPIF   7U /*SPI Interrupt Flag*/

/******************************************************************************/

/* Interrupt Service Routine */
#define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

/* Serial Transfer Complete */
#define SPI_STC_vect			__vector_12

#endif


