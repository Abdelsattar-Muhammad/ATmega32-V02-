/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 21 FEB 2024            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

void Button_vInit(Port_t Copy_PortName,Pin_t Copy_PinNumber);

void Button_vPullupInit(Port_t Copy_PortName,Pin_t Copy_PinNumber);
uint8 	 Button_u8Read(Port_t Copy_PortName,Pin_t Copy_PinNumber);




#endif 