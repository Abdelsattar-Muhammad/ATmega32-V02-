/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 22 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/
#define F_CPU 8000000UL
#include <util/delay.h>

#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"



#define 	EIGHT_BIT_MODE		 0u	
#define 	FOUR_BIT_MODE 		 1u

#define 	ENABLE 				 1u
#define		DISABLE				 0u

typedef enum{

	CLEAR_SCREEN=0x01,
	RETURN_HOME	=0x02,
	ENTRY_MODE=0x06,
	DISPLAY_ON=0x0C,
	EIGHT_BIT=0x38, /* for 8-bit Mode*/
	FOUR_BIT=0x28,  /* for 4-bit Mode*/
}Command_t;


static void Enable(void)
{
	DIO_vSetPinValue(EN_PORT,EN_PIN,PIN_IS_HIGH);
	_delay_ms(2);
	DIO_vSetPinValue(EN_PORT,EN_PIN,PIN_IS_LOW);
	_delay_ms(2);
}

static void LCD_WriteCommand(Command_t Copy_Command)
{
	#if ( LCD_MODE == EIGHT_BIT_MODE )
	DIO_vSetPortValue(DATA_PORT,Copy_Command);
	DIO_vSetPinValue(RS_PORT,RS_PIN,PIN_IS_LOW);
	Enable();	
	_delay_ms(1);
	
	#elif ( LCD_MODE == FOUR_BIT_MODE )
	DIO_vSetPinValue( DATA_PORT , D4_PIN ,GET_BIT(Copy_Command,4) );
	DIO_vSetPinValue( DATA_PORT , D5_PIN , GET_BIT(Copy_Command,5) );
	DIO_vSetPinValue( DATA_PORT , D6_PIN , GET_BIT(Copy_Command,6) );
	DIO_vSetPinValue( DATA_PORT , D7_PIN , GET_BIT(Copy_Command,7) );

	DIO_vSetPinValue(RS_PORT,RS_PIN,PIN_IS_LOW);
	Enable();
	
	DIO_vSetPinValue(DATA_PORT,D4_PIN,GET_BIT(Copy_Command,0));
	DIO_vSetPinValue(DATA_PORT,D5_PIN,GET_BIT(Copy_Command,1));
	DIO_vSetPinValue(DATA_PORT,D6_PIN,GET_BIT(Copy_Command,2));
	DIO_vSetPinValue(DATA_PORT,D7_PIN,GET_BIT(Copy_Command,3));
	DIO_vSetPinValue(RS_PORT,RS_PIN,PIN_IS_LOW);
	Enable();
	_delay_ms(1);
	#endif
}

void LCD_vInit(void)
{
	
	#if (LCD_MODE == EIGHT_BIT_MODE)
	_delay_ms(100);
	DIO_vSetPortDirection(DATA_PORT,0xFF);
	DIO_vSetPinDirection(RS_PORT,RS_PIN,OUTPUT);
	DIO_vSetPinDirection(EN_PORT,EN_PIN,OUTPUT);
	LCD_WriteCommand(EIGHT_BIT);
	
	_delay_ms(1);
	
	LCD_WriteCommand( (DISPLAY_ON)| (CURSOR<<1) | (CURSOR_BLINKING) );
	
	_delay_ms(1);
	
	LCD_WriteCommand(CLEAR_SCREEN);
	
	_delay_ms(10);
	
	LCD_WriteCommand(ENTRY_MODE);
	
	_delay_ms(5);
	
	#elif LCD_MODE == FOUR_BIT_MODE
	_delay_ms(100);
	DIO_vSetPinDirection(DATA_PORT,D4_PIN,OUTPUT);
	DIO_vSetPinDirection(DATA_PORT,D5_PIN,OUTPUT);
	DIO_vSetPinDirection(DATA_PORT,D6_PIN,OUTPUT);
	DIO_vSetPinDirection(DATA_PORT,D7_PIN,OUTPUT);
	
	DIO_vSetPinDirection(RS_PORT,RS_PIN,OUTPUT);
	DIO_vSetPinDirection(EN_PORT,EN_PIN,OUTPUT);
	
	LCD_WriteCommand(RETURN_HOME);
	_delay_ms(5);
	LCD_WriteCommand(FOUR_BIT);
	_delay_ms(1);
	LCD_WriteCommand( (DISPLAY_ON) | (CURSOR<<1) | (CURSOR_BLINKING));
	_delay_ms(1);
	LCD_WriteCommand(CLEAR_SCREEN);
	_delay_ms(10);
	LCD_WriteCommand(ENTRY_MODE);
	_delay_ms(1);
	
	#endif
	
}

void LCD_vWriteChar(uint8 character)
{
	#if LCD_MODE == EIGHT_BIT_MODE
	DIO_vSetPortValue(DATA_PORT,character);
	DIO_vSetPinValue(RS_PORT,RS_PIN,PIN_IS_HIGH);
	Enable();
	_delay_ms(5);
	#elif LCD_MODE == FOUR_BIT_MODE
	DIO_vSetPinValue(DATA_PORT,D4_PIN,GET_BIT(character,4));
	DIO_vSetPinValue(DATA_PORT,D5_PIN,GET_BIT(character,5));
	DIO_vSetPinValue(DATA_PORT,D6_PIN,GET_BIT(character,6));
	DIO_vSetPinValue(DATA_PORT,D7_PIN,GET_BIT(character,7));
	
	DIO_vSetPinValue(RS_PORT,RS_PIN,PIN_IS_HIGH);
	
	Enable();
	
	DIO_vSetPinValue(DATA_PORT,D4_PIN,GET_BIT(character,0));
	DIO_vSetPinValue(DATA_PORT,D5_PIN,GET_BIT(character,1));
	DIO_vSetPinValue(DATA_PORT,D6_PIN,GET_BIT(character,2));
	DIO_vSetPinValue(DATA_PORT,D7_PIN,GET_BIT(character,3));
	
	DIO_vSetPinValue(RS_PORT,RS_PIN,PIN_IS_HIGH);
	Enable();
	_delay_ms(5);
	#endif
}
void LCD_vWriteSentence(uint8* ptrSentence)
{
	while(*ptrSentence!='\0')
	{
		LCD_vWriteChar(*ptrSentence);
		ptrSentence++;
		
	}
}

void LCD_vMoveCursor(uint8 row,uint8 colume)
{
	uint8 data=0;
	if (row<0 ||row> NUMBER_OF_ROW || colume<0|| colume> NUMBER_OF_COLUMS )
	{
		data=0x80;
	} 
	else
	{
		data=0x80 + ((row % 2) * 64) + colume +(16 * (row /2));
	}
	LCD_WriteCommand(data);
	_delay_ms(1);
	
}

void LCD_vClearScreen(void)
{
	LCD_WriteCommand(CLEAR_SCREEN);
	_delay_ms(10);
}

void LCD_vWriteNumber(uint64 Copy_Number)
{
	uint8 i=0,arr[10],j;
	
	if(Copy_Number==0)
	{
	LCD_vWriteChar('0');
	}
	else
	{
		while(Copy_Number)
		{
			arr[i]= (Copy_Number % 10 ) + '0' ;
			Copy_Number/=10;
			i++;
		}
		for(j = i ; j > 0 ; j--)
			{
			LCD_vWriteChar(arr[j-1]);
			}
	}//End else

}