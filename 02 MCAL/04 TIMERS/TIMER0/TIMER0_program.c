/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 25 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

 
 #include "DATA_TYPES.h"
 #include "BIT_MATH.h"
 
 #include "TIMER0_interface.h"

 #include "TIMER0_private.h"
  #include "TIMER0_config.h"

 /***************************************************************************************/
 /********************************* TIMER 0 *********************************************/

#define  NULL ((void *)0) 


static void (*Timer0_OVF_CallBack)(void)=NULL;
static void (*Timer0_CTC_CallBack)(void)=NULL;

/*****************Init functions**********/

void TIMER0_voidInit(Timer0Config_t TimerConfig)
{
	/* Clear Bits of WGM00 & WGM01 */
	TCCR0 &= (0b10110111);
	/* Set Bits of WGM00 & WGM01 */
	TCCR0 |= TimerConfig.TimerMode;
	
	/* Clear Bits of COM01 & COM00 */
	TCCR0 &= ~(0b11<<COM00);
	/* Set Bits of COM01 & COM00 */
	TCCR0 |= (TimerConfig.TimerOC0Mode<<COM00);

	/* Clear Bits of CS11 & CS01 & CS00 */
	TCCR0 &= ~(0b111); 
	TCCR0 |= TimerConfig.TimerPrescaler;
}
void TIMER0_voidSetPreloadValue(uint8 PreloadValue)
{
	TCNT0 = PreloadValue;
}

void TIMER0_voidSetOCR0Value(uint8 OCR0_Value)
{
	OCR0=OCR0_Value;
}

void TIMER0_voidOVFEnableInterrupt(void)
{
	/* Enable Global Interrupt */
	 __asm__ __volatile__ ("sei" ::: "memory");		
	SET_BIT(TIMSK,TOIE0);
}
void TIMER0_voidOVFDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TOIE0);
}
void TIMER0_OVFSetCallBack(void (*Copy_PF)(void))
{
	Timer0_OVF_CallBack=Copy_PF;
}

void TIMER0_voidCTCSetCallBack(void (*Copy_PF)(void))
{
	Timer0_CTC_CallBack=Copy_PF;
}
void TIMER0_voidCTCEnableInterrupt(void)
{
	 __asm__ __volatile__ ("sei" ::: "memory");	
	SET_BIT(TIMSK,OCIE0);
}
void TIMER0_voidCTCDisableInterrupt(void)
{
	CLR_BIT(TIMSK,OCIE0);
}




ISR(TIMER0_OVF_vect)
{
	 if(Timer0_OVF_CallBack != NULL)
	 {
		 Timer0_OVF_CallBack();
	 }
	 
}
ISR(TIMER0_COMP_vect)
{
	 if(Timer0_CTC_CallBack != NULL)
	 {
		 Timer0_CTC_CallBack();
	 }
	 
}
 