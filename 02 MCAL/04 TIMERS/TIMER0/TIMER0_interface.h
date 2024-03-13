/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 25 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

/* Timer 0 Modes */
typedef enum{

	TIMER0_NORMAL_MODE=0x00,        /* Overfollow Mode */
	TIMER0_CTC_MODE =0x08,           /* Clear Timer On Compare Match */
	TIMER0_FASTPWM_MODE	=0x48,       /* Fast PWM Mode */
	TIMER0_PHASECORRECT_MODE=0x40,   /* Phase Correct PWM Mode */
}Timer0_Mode_t;


/* Timer0 PreScalers */
typedef enum{
	TIMER0_STOP,
	TIMER0_PS_1,			            /* 	 Timer0 Clock Prescales by 1 from MCU Clock		*/
	TIMER0_PS_8,		                /* 	 Timer0 Clock Prescales by 8 from MCU Clock		*/
	TIMER0_PS_64,			            /* 	 Timer0 Clock Prescales by 64 from MCU Clock    */
	TIMER0_PS_256,			            /* 	 Timer0 Clock Prescales by 256 from MCU Clock	*/
	TIMER0_PS_1024,			            /* 	 Timer0 Clock Prescales by 1024 from MCU Clock	*/
	TIMER0_EXTERNAL_FALLING,		   	/* 	 Timer0 Count from External Falling Edge		*/
	TIMER0_EXTERNAL_RISING			    /* 	 Timer0 Count from External Rising Edge		    */

}Timer0_Ps_t;

/* Timer0  OC0 Modes */
typedef enum{
	TIMER0_OC0_DISCONNECTED, 	
	TIMER0_OC0_TOGGLE  ,
	TIMER0_OC0_CLEAR,	
	TIMER0_OC0_SET,		
}Timer0_OC0_Mode_t;

typedef struct{

Timer0_Mode_t      TimerMode;
Timer0_Ps_t        TimerPrescaler;
Timer0_OC0_Mode_t  TimerOC0Mode;

}Timer0Config_t;

/****************************** TIMER 0 ********************************************/

void TIMER0_voidInit(Timer0Config_t TimerConfig);

void TIMER0_voidSetOCR0Value(uint8 OCR0_Value);
void TIMER0_voidSetPreloadValue(uint8 PreloadValue);

void TIMER0_voidOVFEnableInterrupt(void);
void TIMER0_voidOVFDisableInterrupt(void);
void TIMER0_voidOVFSetCallBack(void (*Copy_PF)(void));

void TIMER0_voidCTCSetCallBack(void (*Copy_PF)(void));
void TIMER0_voidCTCEnableInterrupt(void);
void TIMER0_voidCTCDisableInterrupt(void);

#endif