/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 24 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

typedef enum{
	ADC_CHANNEL0,		/*ADC CHANNEL 0 - PortA  @ Pin0	*/
	ADC_CHANNEL1,		/*ADC CHANNEL 1 - PortA  @ Pin1	*/
	ADC_CHANNEL2,		/*ADC CHANNEL 2 - PortA  @ Pin2	*/
	ADC_CHANNEL3,		/*ADC CHANNEL 3 - PortA  @ Pin3	*/
	ADC_CHANNEL4,		/*ADC CHANNEL 4 - PortA  @ Pin4	*/
	ADC_CHANNEL5,		/*ADC CHANNEL 5 - PortA  @ Pin5	*/
	ADC_CHANNEL6,		/*ADC CHANNEL 6 - PortA  @ Pin6	*/
	ADC_CHANNEL7,		/*ADC CHANNEL 7 - PortA  @ Pin7	*/
}ADC_CHANNEL_t;

typedef enum{
	
	ADC_PS_2=0,			/* 	 ADC Clock Prescales by 2 from MCU Clock		*/
	ADC_PS_4 =2,		/* 	 ADC Clock Prescales by 4 from MCU Clock		*/
	ADC_PS_8,			/* 	 ADC Clock Prescales by 8 from MCU Clock		*/
	ADC_PS_16,			/* 	 ADC Clock Prescales by 16 from MCU Clock		*/
	ADC_PS_32,			/* 	 ADC Clock Prescales by 32 from MCU Clock		*/
	ADC_PS_64,			/* 	 ADC Clock Prescales by 64 from MCU Clock		*/
	ADC_PS_128			/* 	 ADC Clock Prescales by 128 from MCU Clock		*/

}ADC_PS_t;
typedef enum{
	/*These slectection of the voltage reference for the ADC */
	
	ADC_AREF=0,			/* AREF,  Internal Vref turned off */
	ADC_AVCC,			/* AVCC with external capacitor at AREF pin */ 
	ADC_AVCC_INTERNAL   /*Internal 2.56V Voltage Reference with external capacitor at AREF pin*/

}ADC_REF_t;


void   ADC_vInit(ADC_PS_t Prescaler ,ADC_REF_t VoltageRef );
uint16 ADC_u16Read(ADC_CHANNEL_t ADC_Channel);


#endif