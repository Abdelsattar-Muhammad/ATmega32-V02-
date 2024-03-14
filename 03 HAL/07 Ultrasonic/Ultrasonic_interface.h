/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 26 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/


#ifndef ULTRASONIC_INTERFACE_H
#define ULTRASONIC_INTERFACE_H

typedef  struct{
	Port_t TriggerPort;
	Pin_t  TriggerPin; 
}USConfig_t;
void Ultrasonic_voidInit(USConfig_t TriggConfig);
uint8 Ultrasonic_u8GetDistance(USConfig_t UltrasonicNumber);


#endif /* ULTRASONIC_INTERFACE_H_ */