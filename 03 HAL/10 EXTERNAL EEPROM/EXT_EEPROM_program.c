/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 3 MAR 2024             */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/
 
#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "EXT_EEPROM_interface.h"

void EXT_EEPROM_Write(uint16 Address,uint8 Date)
{
	uint8 EEPROM_Frame[3]={0};
	EEPROM_Frame[0]=(uint8)((0b10100000)|((Address>>7U) & 0x0E));
	EEPROM_Frame[1]=(uint8)Address;
	EEPROM_Frame[2]= Data;
	void TWI_voidMasterTransmit(&EEPROM_Frame[0],&EEPROM_Frame[1],2);
}


uint8 EXT_EEPROM_Read(uint16 Address)
{	
	uint8 Date=0;
	uint8 EEPROM_Frame[3]={0};
	
	EEPROM_Frame[0]= (uint8)((0b10100000)|((Address>>7) & 0x0E));
	EEPROM_Frame[1]=(uint8)Address;
	TWI_voidMasterTransmit(&EEPROM_Frame[0],&EEPROM_Frame[1],2);
	TWI_voidMasterReceive(&EEPROM_Frame[0],&Data)
	return Date;
}