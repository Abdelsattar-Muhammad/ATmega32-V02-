/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 21 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

 #include "DATA_TYPES.h"
 #include "BIT_MATH.h"
 
 #include "DIO_interface.h"
 
 #include "EXTI_private.h"
 #include "EXTI_interface.h"
 #include "EXTI_config.h"

/*********Pointer to functions to be assigned to ISR************/

volatile static void (*EXTI0_CallBack)(void)=NULL;
volatile static void (*EXTI1_CallBack)(void)=NULL;
volatile static void (*EXTI2_CallBack)(void)=NULL;

void EnablGlobalInterrupt(void)
{
 __asm__ __volatile__ ("sei" ::: "memory");	
}
/**********************************************************************************************************
* @fn EXTI_vSetCallBack.
* @brief This Function Set CallBack Function to execute when interrupt Occures.
* @param[in] EXTI_Number  : External Interrupt Number, Get Options @EXTI_t enum.
* @param[in] (Copy_Ptr)() : Pointer To Function
* @retval void.
*
*/
void EXTI_vSetCallBack(EXTI_t EXTI_Number,void (*Copy_Ptr)(void) )
{
	switch(EXTI_Number)
	{
		case EXTI0 : EXTI0_CallBack=Copy_Ptr; break;
		case EXTI1 : EXTI1_CallBack=Copy_Ptr; break;
		case EXTI2 : EXTI2_CallBack=Copy_Ptr; break;
	}		
}

/**********************************************************************************************************
* @fn EXTI_vEnable.
* @brief This Function Enable External interrupt.
* @param[in] EXTI_Number  : External Interrupt Number, Get Options @EXTI_t enum.
* @retval void.
*
*/
void EXTI_vEnable(EXTI_t EXTI_Number)
{
	switch(EXTI_Number)
	{
		case EXTI0:
		SET_BIT(EXTI_GICR,EXTI0_EN);
		break;
		case EXTI1:
		SET_BIT(EXTI_GICR,EXTI1_EN);
		break;
		case EXTI2:
		SET_BIT(EXTI_GICR,EXTI2_EN);
		break;
	}	

}
/**********************************************************************************************************
* @fn EXTI_vDisable.
* @brief This Function Disable External interrupt.
* @param[in] EXTI_Number  : External Interrupt Number, Get Options @EXTI_t enum.
* @retval void.
*
*/
void EXTI_vDisable(EXTI_t EXTI_Number)
{
	switch(EXTI_Number)
	{
		case EXTI0:
		CLR_BIT(EXTI_GICR,EXTI0_EN);
		break;
		case EXTI1:
		CLR_BIT(EXTI_GICR,EXTI1_EN);
		break;
		case EXTI2:
		CLR_BIT(EXTI_GICR,EXTI2_EN);
		break;		
	}
	
}
/**********************************************************************************************************
* @fn EXTI_vTriggerEdge.
* @brief This Function Set Trigger Level for External interrupt.
* @param[in] EXTI_Number  : External Interrupt Number, Get Options @EXTI_t enum.
* @param[in] EXTI_Mode 	  : Level or Edge Trigger, Get Options @TrigEdge_t enum.
* @retval void.
*
*/
void EXTI_vTriggerEdge(EXTI_t EXTI_Number,TrigEdge_t EXTI_Mode)
{
	
	switch(EXTI_Number)
	{
		case EXTI0:
			/* Clear ISC01 & ISC00 */
			EXTI_MCUCR &= ~(0b11<<ISC00_PIN);
			/* Set Trigger Mode for EXTI0 */
			EXTI_MCUCR |= (EXTI_Mode<<ISC00_PIN);
		break;
		case EXTI1:
			/* Clear ISC11 & ISC10 */
			EXTI_MCUCR &= ~(0b11<<ISC10_PIN);
			/* Set Trigger Mode for EXTI0 */
			EXTI_MCUCR |= (EXTI_Mode<<ISC10_PIN);
		break;
		case EXTI2:
		switch(EXTI_Mode)
		{
			case RISING_EDGE : 
			SET_BIT(EXTI_MCUCR,ISC2_PIN);		
			break;
			case FALLING_EDGE :
			CLR_BIT(EXTI_MCUCSR,ISC2_PIN);
			break;
		}
		break;
		default: 
		/* Errorr*/
		break;
	}	
	
}



ISR(INT0_vect)
{
	if(EXTI0_CallBack != NULL)
	{
	EXTI0_CallBack();
	}
}
ISR(INT1_vect)
{
	if(EXTI1_CallBack != NULL)
	{
		EXTI1_CallBack();
	}
}

ISR(INT2_vect)
{
	if(EXTI2_CallBack != NULL)
	{
		/* Clear Flag Bit */
	SET_BIT(EXTI_GIFR,EXTI2_FLAG);
		EXTI2_CallBack();
	}
}
