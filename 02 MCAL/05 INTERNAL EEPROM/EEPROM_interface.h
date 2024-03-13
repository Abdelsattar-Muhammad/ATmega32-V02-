/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 20 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

/**********************************************************************************************************
* @fn EEPROM_vReadByte.
* @brief  read one byte from the given  address.
* @param[in] Copy_u16Address  :  Address that while hold Data, Range Of Address (0:123).
* @retval uint8 (Receive Data).
*
*/
uint8 EEPROM_vReadByte(uint16 Copy_u16Address);
/**********************************************************************************************************
* @fn EEPROM_vWriteByte.
* @brief write one byte to the given address.
* @param[in] Copy_u16Address  :  Address that while hold Data, Range Of Address (0:123).
* @param[in] Copy_u8Data : Data Will Be Write.
* @retval void.
*
*/

void EEPROM_vWriteByte(uint16 Copy_u16Address, uint8 Copy_u8Data);

#endif 