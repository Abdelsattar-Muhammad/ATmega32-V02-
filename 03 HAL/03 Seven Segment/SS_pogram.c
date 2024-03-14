/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 22 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#include "DATA_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "SS_interface.h"
	

void SS_vInit(Port_t Copy_PortName)
{
	DIO_vSetPortDirection(Copy_PortName,0xFF);
}


void SS_vWrite(Port_t Copy_PortName,uint8 Copy_u8Number)
{
	uint8 arr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
		
	#if defined COMMON_CATHOD
	DIO_vSetPortValue(Copy_PortName,arr[Copy_u8Number]);
	#elif defined COMMON_ANODE 
	DIO_vSetPortValue(Copy_PortName,~arr[Copy_u8Number]);
	#endif
}

void SS_BCD_Init(Port_t Copy_PortName)/*High nibble*/
{
	DIO_vSetPinDirection(Copy_PortName,PIN4,OUTPUT);
	DIO_vSetPinDirection(Copy_PortName,PIN5,OUTPUT);
	DIO_vSetPinDirection(Copy_PortName,PIN6,OUTPUT);
	DIO_vSetPinDirection(Copy_PortName,PIN7,OUTPUT);
}


void SS_BCD_Write(Port_t Copy_PortName,uint8 Copy_u8Number)
{
	DIO_vSetPinValue(Copy_PortName,PIN4,GET_BIT(Copy_u8Number,0));
	DIO_vSetPinValue(Copy_PortName,PIN5,GET_BIT(Copy_u8Number,1));
	DIO_vSetPinValue(Copy_PortName,PIN6,GET_BIT(Copy_u8Number,2));
	DIO_vSetPinValue(Copy_PortName,PIN7,GET_BIT(Copy_u8Number,3));
}


