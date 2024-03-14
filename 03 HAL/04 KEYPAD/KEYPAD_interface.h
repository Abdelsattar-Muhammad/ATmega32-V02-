/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 22 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

#define NOT_PRESSED 0xFF
#define KEYPAD_PORT PORTA

void KEYPAD_vInit(void);
uint8 	 KEYPAD_u8Read(void);



#endif 