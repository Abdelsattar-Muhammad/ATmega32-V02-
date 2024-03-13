/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 25 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H

/* Timer 0 Modes */
typedef enum{

	TIMER1_NORMAL_MODE =0b0000,			/* Overfollow Mode */
	TIMER1_CTC_ICR1_TOP_MODE=0b1100 ,	/* Clear Timer On Compare Match, ICR TOP  */
	TIMER1_CTC_OCR1A_TOP_MODE=0b0100,/* Clear Timer On Compare Match, OCRA TOP  */
	TIMER1_FASTPWM_ICR1_TOP_MODE=0b1110 , /* Fast PWM Mode, ICR TOP */
	TIMER1_FASTPWM_OCRA1_TOP_MODE=0b1111,/* Fast PWM Mode, OCRA TOP */
	TIMER1_PHASECORRECT_OCR1A_TOP_MODE=0b1001,/* Phase Correct PWM Mode, OCRA TOP */
	TIMER1_PHASECORRECT_ICR1_TOP_MODE=0b1010,/* Phase Correct PWM Mode, ICR TOP */

}Timer1_Mode_t;


/* Timer1 PreScalers */
typedef enum{
	TIMER1_STOP,
	TIMER1_PS_1,			            /* 	 Timer1 Clock Prescales by 1 from MCU Clock		*/
	TIMER1_PS_8,		                /* 	 Timer1 Clock Prescales by 8 from MCU Clock		*/
	TIMER1_PS_64,			            /* 	 Timer1 Clock Prescales by 64 from MCU Clock    */
	TIMER1_PS_256,			            /* 	 Timer1 Clock Prescales by 256 from MCU Clock	*/
	TIMER1_PS_1024,			            /* 	 Timer1 Clock Prescales by 1024 from MCU Clock	*/
	TIMER1_EXTERNAL_FALLING,		   	/* 	 Timer1 Count from External Falling Edge		*/
	TIMER1_EXTERNAL_RISING			    /* 	 Timer1 Count from External Rising Edge		    */

}Timer1_Ps_t;


/* Timer1  OC1A Modes */
typedef enum{
	TIMER1_OC1A_DISCONNECTED, 	
	TIMER1_OC1A_TOGGLE  ,
	TIMER1_OC1A_CLEAR,	
	TIMER1_OC1A_SET,		
}Timer1_OC1A_Mode_t;

/* Timer1  OC1B Modes */
typedef enum{
	TIMER1_OC1B_DISCONNECTED, 	
	TIMER1_OC1B_TOGGLE  ,
	TIMER1_OC1B_CLEAR,	
	TIMER1_OC1B_SET,		
}Timer1_OC1B_Mode_t;

typedef struct{

Timer1_Mode_t       Timer1Mode;
Timer1_Ps_t         Timer1Prescaler;
Timer1_OC1A_Mode_t  Timer1OC1AMode;
Timer1_OC1B_Mode_t  Timer1OC1BMode;
}Timer1Config_t;


typedef enum{
	FALLING,
	RISING
	
}ICU_Edge_t;

void TIMER1_voidInit(Timer1Config_t TimerConfig);
void TIMER1_voidSetICUEdge(ICU_Edge_t Edge);

/* This Functions Used if We Choose One Mode Of Them : 
		1-CTC_ICR_TOP_MODE 
		2-FASTPWM_ICR_TOP_MODE
		3-PhaseCorrect_ICR_TOP_MODE		
*/
void TIMER1_voidSetICRValue(uint16 ICR1_TOP);

/* This Functions Used to Set OCR1A or OCR1B Values */
void TIMER1_voidSetOCR1AValue(uint16 OCR1A_Value);
void TIMER1_voidSetOCR1BValue(uint16 OCR1B_Value);

uint16 TIMER1_u16GetICRValue(void);
/*********************************** Iterrupts **************************************/

void TIMER1_voidOVFEnableInterrupt(void);
void TIMER1_voidOVFDisableInterrupt(void);

void TIMER1_voidOCAEnableInterrupt(void);
void TIMER1_voidOCADisableInterrupt(void);
 
void TIMER1_voidOCBEnableInterrupt(void);
void TIMER1_voidOCBDisableInterrupt(void);

void TIMER1_voidICUEnableInterrupt(void);
void TIMER1_voidICUDisableInterrupt(void);

void TIMER1_voidOVFSetCallBack(void (*Copy_PF)(void));
void TIMER1_voidOCASetCallBack(void (*Copy_PF)(void));
void TIMER1_voidOCBSetCallBack(void (*Copy_PF)(void));
void TIMER1_voidICUSetCallBack(void (*Copy_PF)(void));


#endif