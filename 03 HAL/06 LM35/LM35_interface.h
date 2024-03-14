/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 24 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H

#define ADC_STEP_SIZE       ((5.0/1023.0)) 

uint8 LM35_GetTemperature(uint8 ADC_Channal);


#endif /* LM35_INTERFACE_H */