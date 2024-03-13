/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 25 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

 
 #include "DATA_TYPES.h"
 #include "BIT_MATH.h"
 #include "TIMER2_interface.h"
 #include "TIMER2_private.h"
 
 #include "TIMER2_config.h"
 /***************************************************************************************/
 /********************************* TIMER 2 *********************************************/
#define  NULL ((void *)0) 

static void (*TIMER2_OVF_CallBack)(void)=NULL;
static void (*TIMER2_CTC_CallBack)(void)=NULL;
/*****************Init functions**********/

void TIMER2_voidInit(TIMER2Config_t TimerConfig)
{
	if(TimerConfig.Timer2ClockSource == EXTERNAL)
	{
		SET_BIT(ASSR,AS2);
	}
	/* Clear Bits of WGM20 & WGM21 */
	TCCR2 &= (0b10110111);
	/* Set Bits of WGM20 & WGM21 */
	TCCR2 |= TimerConfig.Timer2Mode;
	
	/* Clear Bits of COM21 & COM20 */
	TCCR2 &= ~(0b11<<COM20);
	/* Set Bits of COM21 & COM20 */
	TCCR2 |= (TimerConfig.Timer2OC2Mode<<COM20);

	/* Clear Bits of CS22 & CS21 & CS20 */
	TCCR2 &= ~(0b111); 
	TCCR2 |= TimerConfig.Timer2Prescaler;
}
void TIMER2_voidSetPreloadValue(uint8 PreloadValue)
{
	TCNT2 = PreloadValue;
}

void TIMER2_voidSetOCR2Value(uint8 OCR2_Value)
{
	OCR2=OCR2_Value;
}

void TIMER2_voidOVFEnableInterrupt(void)
{
	 __asm__ __volatile__ ("sei" ::: "memory");	
	SET_BIT(TIMSK,TOIE2);
}
void TIMER2_voidOVFDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TOIE2);
}
void TIMER2_voidOVFSetCallBack(void (*Copy_PF)(void))
{
	TIMER2_OVF_CallBack=Copy_PF;
}

void TIMER2_voidCTCSetCallBack(void (*Copy_PF)(void))
{
	TIMER2_CTC_CallBack=Copy_PF;
}
void TIMER2_voidCTCEnableInterrupt(void)
{
	 __asm__ __volatile__ ("sei" ::: "memory");	
	SET_BIT(TIMSK,OCIE2);
}
void TIMER2_voidCTCDisableInterrupt(void)
{
	
	CLR_BIT(TIMSK,OCIE2);
}




ISR(TIMER2_OVF_vect)
{
	 if(TIMER2_OVF_CallBack != NULL)
	 {
		 TIMER2_OVF_CallBack();
	 }
	 
}
ISR(TIMER2_COMP_vect)
{
	 if(TIMER2_CTC_CallBack != NULL)
	 {
		 TIMER2_CTC_CallBack();
	 }
	 
}
 