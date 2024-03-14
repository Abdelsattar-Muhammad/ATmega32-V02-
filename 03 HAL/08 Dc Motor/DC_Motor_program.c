/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 June 2023            */
/* Version : V02					*/
/* MCU 	   : ATMEGA32               */
/************************************/

#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DC_Motor_interface.h"


void DcMotor_Init(void)
{
	/* Intialization Pins Of Motor 1 */
	DIO_vSetPinDirection(DC_MOTOR_PORT,	MOTOR_IN1, OUTPUT);
	DIO_vSetPinDirection(DC_MOTOR_PORT,	MOTOR_IN2, OUTPUT);
	DIO_vSetPinDirection(DC_MOTOR_PORT,	MOTOR_EN1, OUTPUT);
	/* Intialization Pins Of Motor 1 */
	DIO_vSetPinDirection(DC_MOTOR_PORT,	MOTOR_IN3, OUTPUT);
	DIO_vSetPinDirection(DC_MOTOR_PORT,	MOTOR_IN4, OUTPUT);
	DIO_vSetPinDirection(DC_MOTOR_PORT,	MOTOR_EN2, OUTPUT);
	/*
	DIO_vSetPullupPin(CONTROLS_PINS,FRONT_PIN);
	DIO_vSetPullupPin(CONTROLS_PINS,BACK_PIN);
	DIO_vSetPullupPin(CONTROLS_PINS,RIGHT_PIN);
	DIO_vSetPullupPin(CONTROLS_PINS,LEFT_PIN);
	*/
	
}



void DcMotor_TurnOn(Motor_Dir_t Copy_Direction)
{	
	/*  This Method Save 2 pins but it Take More Time 
	DIO_vSetPinValue(DC_MOTOR_PORT,MOTOR_IN1, GET_BIT(Copy_Direction,MOTOR_IN1) );
	DIO_vSetPinValue(DC_MOTOR_PORT,MOTOR_IN2, GET_BIT(Copy_Direction,MOTOR_IN2) );
	DIO_vSetPinValue(DC_MOTOR_PORT,MOTOR_EN1, GET_BIT(Copy_Direction,MOTOR_EN1) );
	DIO_vSetPinValue(DC_MOTOR_PORT,MOTOR_IN3, GET_BIT(Copy_Direction,MOTOR_IN3) );
	DIO_vSetPinValue(DC_MOTOR_PORT,MOTOR_IN4, GET_BIT(Copy_Direction,MOTOR_IN4) );
	DIO_vSetPinValue(DC_MOTOR_PORT,MOTOR_EN2, GET_BIT(Copy_Direction,MOTOR_EN2) );
	*/
	/* This Method Waste 2 Pins but Faster */
	DIO_vSetPortValue(DC_MOTOR_PORT,Copy_Direction);
}
void DcMotor_TurnOff(void)
{
	DIO_vSetPortValue(DC_MOTOR_PORT,0x00);
}