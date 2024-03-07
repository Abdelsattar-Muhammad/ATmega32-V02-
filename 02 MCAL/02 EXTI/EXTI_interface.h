/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 21 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef	EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
/***************   Interrupt  Numbers   *******************
* @EXTI_t
*
*/
typedef enum {
				EXTI0=0, /* External interrupt 0	*/
				EXTI1, 	 /* External interrupt 1	*/
				EXTI2	 /* External interrupt 2	*/

			}EXTI_t;

/***************   Interrupt  Trigger    *******************
* @TrigEdge_t
*
*/			
typedef enum {
				LOW_LEVEL=0,
				ON_CHANGE,
				FALLING_EDGE,
				RISING_EDGE, 
				
			}TrigEdge_t;		


void EnablGlobalInterrupt(void);	


/**********************************************************************************************************
* @fn EXTI_vSetCallBack.
* @brief This Function Set CallBack Function to execute when interrupt Occures.
* @param[in] EXTI_Number  : External Interrupt Number, Get Options @EXTI_t enum.
* @param[in] (Copy_Ptr)() : Pointer To Function
* @retval void.
*
*/
void EXTI_vSetCallBack(EXTI_t EXTI_Number,void (*Copy_Ptr)(void) );
/**********************************************************************************************************
* @fn EXTI_vEnable.
* @brief This Function Enable External interrupt.
* @param[in] EXTI_Number  : External Interrupt Number, Get Options @EXTI_t enum.
* @retval void.
*
*/
void EXTI_vEnable(EXTI_t EXTI_Number);
/**********************************************************************************************************
* @fn EXTI_vDisable.
* @brief This Function Disable External interrupt.
* @param[in] EXTI_Number  : External Interrupt Number, Get Options @EXTI_t enum.
* @retval void.
*
*/
void EXTI_vDisable(EXTI_t EXTI_Number);
/**********************************************************************************************************
* @fn EXTI_vDisable.
* @brief This Function Set Trigger Level for External interrupt.
* @param[in] EXTI_Number  : External Interrupt Number, Get Options @EXTI_t enum.
* @param[in] EXTI_Mode 	  : Level or Edge Trigger, Get Options @TrigEdge_t enum.
* @retval void.
*
*/
void EXTI_vTriggerEdge(EXTI_t EXTI_Number,TrigEdge_t EXTI_Mode);
	   

#endif /* EXTERNAL INTERRUPT_H_ */