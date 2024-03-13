/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 24 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef	ADC_PRIVATE_H
#define ADC_PRIVATE_H


/*ADC Multiplexer Selection Register*/
#define ADMUX               *((volatile uint8*)0x27)

/*ADC Control and Status Register A*/

#define ADCSRA              *((volatile uint8*)0x26)

#define	 ADEN               7   /* ADC Enable BIT*/

#define	 ADSC               6	/* ADC Start Conversion BIT*/


/*ADC Data Registers*/
#define ADCH                *((volatile uint8*)0x25)
#define ADCL                *((volatile uint8*)0x24)




#endif


