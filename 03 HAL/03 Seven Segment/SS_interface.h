/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 22 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef SS_INTERFACE_H
#define SS_INTERFACE_H

#define  COMMON_CATHOD

typedef enum {
	ZERO =0b00111111,
	ONE  =0b00000110,
	TWO  =0b01011011,
	THREE=0b01001111,
	FOUR =0b01100110,
	FIVE =0b01101101,
	SIX  =0b01111101,
	SEVEN=0b00000111,
	EIGHT=0b01111111,
	NINE =0b01101111,
	DOT  =0b10000000,
}Numbers_SS;

void SS_vInit(Port_t Copy_PortName);
void SS_vWrite(Port_t Copy_PortName,uint8 Copy_u8Number);
void SS_BCD_Init(Port_t Copy_PortName);
void SS_BCD_Write(Port_t Copy_PortName,uint8 Copy_u8Number);


#endif 