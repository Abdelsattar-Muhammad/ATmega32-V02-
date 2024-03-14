/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 24 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#include "BIT_MATH.h"
#include "DATA_TYPES.h"

#include "ADC_interface.h"

#include "LM35_interface.h"


 uint8 LM35_GetTemperature(uint8 ADC_Channal)
{

	uint8 Temp=(ADC_u16Read(ADC_Channal)*(ADC_STEP_SIZE*100.0) );
	return Temp;
}