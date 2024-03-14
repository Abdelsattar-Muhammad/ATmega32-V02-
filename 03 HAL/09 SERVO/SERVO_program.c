/*
 * SERVO_program.c
 *
 * Created: 01/07/2023 03:58:27 م
 *  Author: Abdelsattar
 */ 
#include "DATA_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "TIMER1_interface.h"
#include "SERVO_interface.h"


// Should adjust Timer 1 As phase Correct Mode OCR1A as Top 

void Servo_Angle(s8 Copy_Angle)
{
	u16 Local=0;
	TIMER1_Init();
	//Set OC1B As Output Pin
	DIO_vSetPinDirection(DPORT,Pin4,OUTPUT);
	//Set Top Value OF Timer
	TIMER1_Set_OCR1A_Value(9999);
	Local=750+((Copy_Angle*250.0)/90);
	//Set Compare Match Angle
	TIMER1_Set_OCR1B_Value(Local);
}