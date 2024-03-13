/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 25 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h" 
#include "TIMER1_config.h"

/*****************Pointer to functions to be assigned to ISR******************************/
#define NULL ((void *)0)
static void (*TIMER1_OVF_CallBack) (void)=NULL;
static void (*TIMER1_OCA_CallBack) (void)=NULL;
static void (*TIMER1_OCB_CallBack) (void)=NULL;
static void (*TIMER1_ICU_CallBack) (void)=NULL;

/*****************Init functions*****************************/
void TIMER1_voidInit(Timer1Config_t TimerConfig)
{
	/* Clear WGM10 & WGM11 */
	TCCR1A &= ~(0b11);
	/*	Set WGM10 & WGM11 */
	TCCR1A |= (0b11 &TimerConfig.Timer1Mode);
	
	/* Clear WGM12 & WGM13 */
	TCCR1B &= ~(0b11<<WGM12);
	/*	Set WGM12 & WGM13  */
	TCCR1B |= (0b1100 &TimerConfig.Timer1Mode)<<1;

	/* Clear COM1A1 & COM1A0 & COM1B1 & COM1B0  */
	TCCR1A &= (0b00001111);
	/* Set COM1A1 & COM1A0 & COM1B1 & COM1B0  */
	TCCR1A |= (TimerConfig.Timer1OC1AMode)<<COM1A0 ;
	TCCR1A |= (TimerConfig.Timer1OC1BMode)<<COM1B0 ;
	
	/* Clear CS10 & CS11 & CS12  */
	TCCR1B &= (0b11111000);
	/* Set CS10 & CS11 & CS12  */
	TCCR1B|= (TimerConfig.Timer1Prescaler);	
	
}
void TIMER1_voidSetICUEdge(ICU_Edge_t Edge)
{
	/*	SET_BIT(TCCR1B, ICNC1); /* To Cancle Noise*/
	
	if(Edge==RISING)
	{
	SET_BIT(TCCR1B,ICES1);
	}
	else if(Edge==FALLING)
	{
	CLR_BIT(TCCR1B,ICES1);
	}
}

/* This Functions Used if We Choose One Mode Of Them : 
		1-CTC_ICR_TOP_MODE 
		2-FASTPWM_ICR_TOP_MODE
		3-PhaseCorrect_ICR_TOP_MODE		
*/
void TIMER1_voidSetICRValue(uint16 ICR1_TOP)
{
	ICR1=ICR1_TOP;
}

/* This Functions Used to Set OCR1A or OCR1B Values */
void TIMER1_voidSetOCR1AValue(uint16 OCR1A_Value)
{
	OCR1A=OCR1A_Value;
}
void TIMER1_voidSetOCR1BValue(uint16 OCR1B_Value)
{
	OCR1B=OCR1B_Value;
}

uint16 TIMER1_u16GetICRValue(void)
{
	uint16 Local=0;
	Local=ICR1;
	return Local;
}
/*********************************** Iterrupts **************************************/


/****************************Timer 1 Interrupt functions**************************************/
void TIMER1_voidICUEnableInterrupt(void)
{
	/* Enable Global Interrupt */
	 __asm__ __volatile__ ("sei" ::: "memory");	
	SET_BIT(TIMSK,TICIE1);
}

void TIMER1_voidICUDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TICIE1);
}

void TIMER1_voidOVFEnableInterrupt(void)
{
	/* Enable Global Interrupt */
	 __asm__ __volatile__ ("sei" ::: "memory");	
	SET_BIT(TIMSK,TOIE1);
}
void TIMER1_voidOVFDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TOIE1);
}
void TIMER1_voidOCAEnableInterrupt(void)
{
	/* Enable Global Interrupt */
	 __asm__ __volatile__ ("sei" ::: "memory");	
	SET_BIT(TIMSK,OCIE1A);
}
void TIMER1_voidOCADisableInterrupt(void)
{
	CLR_BIT(TIMSK,OCIE1A);
}

void TIMER1_voidOCBEnableInterrupt(void)
{
	/* Enable Global Interrupt */
	 __asm__ __volatile__ ("sei" ::: "memory");	
	SET_BIT(TIMSK,OCIE1B);
}
void TIMER1_voidOCBDisableInterrupt(void)
{
	CLR_BIT(TIMSK,OCIE1B);
}


/*********************************Timer 1 Call Back functions*****************************************/

void TIMER1_voidOVFSetCallBack(void (*Copy_PF)(void))
{
	TIMER1_OVF_CallBack=Copy_PF;
}

void TIMER1_voidOCASetCallBack(void (*Copy_PF)(void))
{
	TIMER1_OCA_CallBack=Copy_PF;
}
void TIMER1_voidOCBSetCallBack(void (*Copy_PF)(void))
{
	TIMER1_OCB_CallBack=Copy_PF;
}
void TIMER1_voidICUSetCallBack(void (*Copy_PF)(void))
{
	TIMER1_ICU_CallBack=Copy_PF;
}

/*********************************Timer 1 ISR functions*********************************************/
ISR(TIMER1_OVF_vect)
{
	if( TIMER1_OVF_CallBack !=NULL)
	{
		TIMER1_OVF_CallBack();
	}
}
ISR(TIMER1_COMPA_vect)
{
	if(TIMER1_OCA_CallBack!=NULL)
	{
		TIMER1_OCA_CallBack();
	}
}
ISR(TIMER1_COMPB_vect)
{
	if(TIMER1_OCB_CallBack!=NULL)
	{
		TIMER1_OCB_CallBack();
	}
}
ISR(TIMER1_CAPT_vect)
{
	if(TIMER1_ICU_CallBack!=NULL)
	{
		TIMER1_ICU_CallBack();
	}
}