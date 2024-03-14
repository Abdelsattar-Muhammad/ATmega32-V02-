#include "DIO_interface.h"
/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 21 FEB 2024            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

void LED_vInit	 ( Port_t Copy_PortName , Pin_t Copy_PinNumber );
void LED_vTurnOn ( Port_t Copy_PortName , Pin_t Copy_PinNumber );
void LED_vTurnOff( Port_t Copy_PortName , Pin_t Copy_PinNumber );
void LED_vToggle ( Port_t Copy_PortName , Pin_t Copy_PinNumber );

#endif /* LED_H_ */