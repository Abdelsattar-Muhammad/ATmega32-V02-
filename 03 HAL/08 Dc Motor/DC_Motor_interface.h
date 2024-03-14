/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#ifndef DC_MOTOR_INTERFACE_H
#define DC_MOTOR_INTERFACE_H

#define DC_MOTOR_PORT CPORT

/* Dc Motor Drive L293D */
typedef enum {
		/* Motor 1*/

		MOTOR_IN1=0,
		MOTOR_IN2=1,	
		MOTOR_EN1=2,	
		
		/* Motor 2*/
		
		MOTOR_IN3=3,	
		MOTOR_IN4=4,	
		MOTOR_EN2=5,		
		
	}	Motor_Pins;
	

typedef enum 
{
	FRONT_Direction =0b00110110,
	BACK_Direction  =0b00101101,
	RIGHT_Direction =0b00000110,
	LEFT_Direction  =0b00101000,
	
	
}Motor_Dir_t;
 
void DcMotor_Init(void);
void DcMotor_TurnOn(Motor_Dir_t Copy_Direction);
void DcMotor_TurnOff(void);

#endif 