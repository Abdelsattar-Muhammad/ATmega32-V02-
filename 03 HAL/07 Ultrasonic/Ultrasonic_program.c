/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 26 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#include "BIT_MATH.h"
#include "DATA_TYPES.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_interface.h"
#include "TIMER1_interface.h"

#include "Ultrasonic_interface.h"

static volatile uint16 flag,counter,t1,t2;
static volatile uint8 NumberOfUltraSonic;

static void OVF_fun(void)
{
	counter++;
	if (counter==NumberOfUltraSonic)
	{
		counter=0;
	}
}
static void ICU_fun(void)
{
	if (flag==0)
	{
		counter=0;
		t1=TIMER1_u16GetICRValue();
		flag=1;
		TIMER1_voidSetICUEdge(FALLING);	
	} 
	else if(flag==1) 
	{
		t2=TIMER1_u16GetICRValue();
		flag=2;
		TIMER1_voidSetICUEdge(RISING);
		TIMER1_voidICUDisableInterrupt();
		TIMER1_voidOVFDisableInterrupt();
	}
}

void Ultrasonic_voidInit(USConfig_t TriggConfig)
{
	NumberOfUltraSonic++;
	Timer1Config_t Timer1Config ={.Timer1Mode=TIMER1_NORMAL_MODE,
								  .Timer1Prescaler=TIMER1_PS_1
								   };

	TIMER1_voidInit(Timer1Config);
	DIO_vSetPinDirection(TriggConfig.TriggerPort,TriggConfig.TriggerPin,OUTPUT);
	TIMER1_voidICUSetCallBack(ICU_fun);
	TIMER1_voidOVFSetCallBack(OVF_fun);
	
}
uint8 Ultrasonic_u8GetDistance(USConfig_t UltrasonicNumber)
{
		counter=0,flag=0;
		uint16 Time=0;
		uint16 Distance=0;
		/*Trigger 10us To Enable Ultrasonic*/
		DIO_vSetPinValue(UltrasonicNumber.TriggerPort,UltrasonicNumber.TriggerPin,PIN_IS_HIGH);
		_delay_us(10);
		DIO_vSetPinValue(UltrasonicNumber.TriggerPort,UltrasonicNumber.TriggerPin,PIN_IS_LOW);

		/* Set ICu To Didected Rising edge */ 
		TIMER1_voidSetICUEdge(RISING);
		TIMER1_voidICUEnableInterrupt();
		TIMER1_voidOVFEnableInterrupt();
		 /*wait utill flag equal 2*/
		while(flag<2);
		Time=t2-t1+((uint32)counter*65535);	 
		Distance=(Time/58.0);	
		return Distance;
}