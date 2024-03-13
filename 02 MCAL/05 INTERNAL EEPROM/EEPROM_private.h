/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 20 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef EEPROM_PRIVATE_H
#define EEPROM_PRIVATE_H
/* Register Definitions */
#define EEARL       *((volatile uint8* const)0x3E)
#define EEARH       *((volatile uint8* const)0x3F)
#define EEDR        *((volatile uint8* const)0x3D)
#define EECR        *((volatile uint8* const)0x3C)
#define SPMCR		*((volatile uint8* const)0x57)
/* Bits Definitions */
#define EERE	0u
#define EEWE	1u
#define EEMWE	2u
#define EERIE	3u
#define SPMEN	0u

#endif /* EEPROM_H_ */