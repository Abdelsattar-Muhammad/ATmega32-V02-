/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 22 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/


#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/* Number OF Rows at Character LCD */ 
#define NUMBER_OF_ROW				 2u

/* Number OF Colums at Character LCD */ 
#define NUMBER_OF_COLUMS			 16u


/* There Are 2 Modes 	(EIGHT_BIT_MODE and FOUR_BIT_MODE), Please Choose One Of Them. */

#define     LCD_MODE                 FOUR_BIT_MODE /* For Reduce Number Of PINs */

/* Register Sellection Pin Connection */
#define     RS_PIN                   PIN6
#define     RS_PORT                  PORTD
/* Enable Pin Connection */
#define     EN_PIN                   PIN7
#define     EN_PORT                  PORTD
/* Data  Pins Connection */ 
#define     DATA_PORT                PORTD
#define     D0_PIN                   /* Not Used in 4  Bit Mode */
#define     D1_PIN                   /* Not Used in 4  Bit Mode */
#define     D2_PIN                   /* Not Used in 4  Bit Mode */
#define     D3_PIN                   /* Not Used in 4  Bit Mode */
#define     D4_PIN                   PIN0
#define     D5_PIN                   PIN1
#define     D6_PIN                   PIN4
#define     D7_PIN                   PIN5

/* You Have 2 Choice To Enable or Disable Cursor (ENABLE & DISABLE) . */
#define		CURSOR                   ENABLE

/* You Have 2 Choice To Enable or Disable Blinking Cursor (ENABLE & DISABLE) . */
#define		CURSOR_BLINKING          DISABLE
#endif 