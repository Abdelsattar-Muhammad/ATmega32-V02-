/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 21 FEB 2024            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#include "BIT_MATH.h"
#include "DATA_TYPES.h"
#include "DIO_interface.h"
#include "LED_interface.h"

/*initialization pin as output at given port*/
void LED_vInit	 ( Port_t Copy_PortName , Pin_t Copy_PinNumber )
{
	DIO_vSetPinDirection(Copy_PortName,Copy_PinNumber,OUTPUT);
}

void LED_vTurnOn ( Port_t Copy_PortName , Pin_t Copy_PinNumber )
{
	DIO_vSetPinValue(Copy_PortName,Copy_PinNumber,PIN_IS_HIGH);
}
void LED_vTurnOff( Port_t Copy_PortName , Pin_t Copy_PinNumber )
{
	DIO_vSetPinValue(Copy_PortName,Copy_PinNumber,PIN_IS_LOW);
}
void LED_vToggle ( Port_t Copy_PortName , Pin_t Copy_PinNumber )
{
	DIO_vTogglePin(Copy_PortName,Copy_PinNumber);
}