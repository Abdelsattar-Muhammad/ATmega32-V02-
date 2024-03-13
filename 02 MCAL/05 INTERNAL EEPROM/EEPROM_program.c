/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 20 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#include "DATA_TYPES.h"
#include "BIT_MATH.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"

/**********************************************************************************************************
* @fn EEPROM_vReadByte.
* @brief  read one byte from the given  address.
* @param[in] Copy_u16Address  :  Address that while hold Data.
* @retval uint8 (Receive Data).
*
*/
uint8 EEPROM_vReadByte(uint16 Copy_u16Address)
{
	/*set up address register*/
	EEARL=(uint8)(Copy_u16Address);
	EEARH=(uint8)(Copy_u16Address>>8);
	/*start EEPROM read by setting EERE*/
	SET_BIT(EECR,EERE);
	/*return data from data register*/
	return EEDR;
}
/**********************************************************************************************************
* @fn EEPROM_vWriteByte.
* @brief write one byte to the given address.
* @param[in] Copy_u16Address  :  Address that while hold Data.
* @param[in] Copy_u8Data : Data Will Be Write.
* @retval void.
*
*/

void EEPROM_vWriteByte(uint16 Copy_u16Address, uint8 Copy_u8Data)
{
	/*set up address register*/
	EEARL=(uint8)(Copy_u16Address);
	EEARH=(uint8)(Copy_u16Address>>8);
	/*set up data register*/
	EEDR=Copy_u8Data;
	/*write logical one to EEMWE and start EEPROM write by setting EEWE*/

	EECR =(1<<EEMWE | 1<<EEWE);
	
	/* wait for completion of  write operation */
	while(GET_BIT(EECR,EEWE) == 1 );	
}
