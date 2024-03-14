/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 22 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/


#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


//void LCD_WriteCommand(Command_t Copy_Command);
void LCD_vInit(void);

void LCD_vWriteChar(uint8 character);
void LCD_vWriteSentence(uint8* ptrSentence);

void LCD_vMoveCursor(uint8 row,uint8 colume);
void LCD_vWriteNumber(uint64 Copy_Number);

void LCD_vClearScreen(void);



#endif 