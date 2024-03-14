/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 21 FEB 2024            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#include "DATA_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "Button_interface.h"

void Button_vInit(Port_t Copy_PortName,Pin_t Copy_PinNumber)
{
	DIO_vSetPinDirection(Copy_PortName,Copy_PinNumber,INPUT);
}
void Button_vPullupInit(Port_t Copy_PortName,Pin_t Copy_PinNumber)
{
	DIO_vSetPullupPin(Copy_PortName,Copy_PinNumber);
	
}
uint8 	 Button_u8Read(Port_t Copy_PortName,Pin_t Copy_PinNumber)
{
	uint8 Local_u8Value=0;
	Local_u8Value=DIO_u8GetPinValue(Copy_PortName,Copy_PinNumber);
	return Local_u8Value;
}
