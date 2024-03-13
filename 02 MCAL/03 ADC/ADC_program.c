/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 24 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

 #include "DATA_TYPES.h"
 #include "BIT_MATH.h"

 
 #include "ADC_interface.h"
 #include "ADC_private.h"
 
 #include "ADC_config.h"


/*****************Init functions**********/
void ADC_vInit(ADC_PS_t Prescaler ,ADC_REF_t VoltageRef )
{
	/* initialize the adc as user Config.	*/	
	ADMUX  = (VoltageRef<<6);
	/* Select prescaler and enable ADC 		*/
	ADCSRA = (Prescaler)|(1<<ADEN);
	
}

uint16 ADC_u16Read(ADC_CHANNEL_t ADC_Channel)
{
	/*Clear  ADC Multiplexer Selection Bits */
	ADMUX &= ~(0b11111);
	/*Select ADC Channel */
	ADMUX |= ADC_Channel; 
	uint16 Local_u16Value=0;
	/* Start Conversion */
	SET_BIT(ADCSRA,ADSC);
	/* Wait Until Conversion Finished */
	while((GET_BIT(ADCSRA,ADSC)) == 1);
	/* Read ADC Data Conversion */
	Local_u16Value  =(ADCL);
	Local_u16Value |= (ADCH<<8) ;
	return Local_u16Value;
	
}
 