/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 25 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef TIMER2_INTERFACE_H
#define TIMER2_INTERFACE_H


/****************************** TIMER 2 ********************************************/

/* Timer2 Clock Source */
typedef enum{
	INTERNAL,
	EXTERNAL
}Timer2_ClkSrc_t;


/* Timer 2 Modes */
typedef enum{

	TIMER2_NORMAL_MODE=0x00,        /* Overfollow Mode */
	TIMER2_CTC_MODE =0x08,           /* Clear Timer On Compare Match */
	TIMER2_FASTPWM_MODE	=0x48,       /* Fast PWM Mode */
	TIMER2_PHASECORRECT_MODE=0x40,   /* Phase Correct PWM Mode */
}Timer2_Mode_t;


/* Timer2 PreScalers */
typedef enum{
	TIMER2_STOP,
	TIMER2_PS_1,			            /* 	 Timer2 Clock Prescales by 1 from MCU Clock		*/
	TIMER2_PS_8,		                /* 	 Timer2 Clock Prescales by 8 from MCU Clock		*/
	TIMER2_PS_32,		                /* 	 Timer2 Clock Prescales by 32 from MCU Clock		*/
    TIMER2_PS_64,			            /* 	 Timer2 Clock Prescales by 64 from MCU Clock    */
    TIMER2_PS_128,		                /* 	 Timer2 Clock Prescales by 128 from MCU Clock		*/
	TIMER2_PS_256,			            /* 	 Timer2 Clock Prescales by 256 from MCU Clock	*/
	TIMER2_PS_1024,			            /* 	 Timer2 Clock Prescales by 1024 from MCU Clock	*/

}Timer2_Ps_t;

/* Timer2  OC2 Modes */
typedef enum{
	TIMER2_OC2_DISCONNECTED, 	
	TIMER2_OC2_TOGGLE  ,
	TIMER2_OC2_CLEAR,	
	TIMER2_OC2_SET,		
}Timer2_OC2_Mode_t;

typedef struct{

	Timer2_Mode_t      Timer2Mode;
	Timer2_Ps_t        Timer2Prescaler;
	Timer2_OC2_Mode_t  Timer2OC2Mode;
	Timer2_ClkSrc_t    Timer2ClockSource;

}TIMER2Config_t;

/****************************** TIMER 2 ********************************************/
void TIMER2_voidInit(TIMER2Config_t TimerConfig);
void TIMER2_voidSetPreloadValue(uint8 PreloadValue);
void TIMER2_voidSetOCR2Value(uint8 OCR2_Value);
void TIMER2_voidOVFEnableInterrupt(void);
void TIMER2_voidOVFDisableInterrupt(void);
void TIMER2_voidOVFSetCallBack(void (*Copy_PF)(void));
void TIMER2_voidCTCSetCallBack(void (*Copy_PF)(void));
void TIMER2_voidCTCEnableInterrupt(void);
void TIMER2_voidCTCDisableInterrupt(void);

#endif