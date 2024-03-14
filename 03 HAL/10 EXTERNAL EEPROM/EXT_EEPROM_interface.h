/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 3 MAR 2024             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
 

#ifndef EXT_EEPROM_INTERFACE_H
#define EXT_EEPROM_INTERFACE_H
void EXT_EEPROM_Write(uint16 Address,uint8 Date);

uint8	 EXT_EEPROM_Read(uint16 Address);

#endif