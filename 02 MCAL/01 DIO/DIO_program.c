/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 20 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#include "DATA_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_interface.h"


/* Array of Pointers ,that Contain pointer to Ports */ 
volatile static	GPIO_RegDef_t *GPIO[NUMBER_OF_PORTS]={GPIOA,GPIOB,GPIOC,GPIOD};

/**********************************************************************************************************
* @fn DIO_vSetPinDirection.
* @brief Set Pin Direction As Input or Output.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_PinNumber : Pin Number, Get Options @Pin_t enum.
* @param[in] Copy_Direction : Pin Direction , Get Options @Dir_t enum.
* @retval void.
*
*/
void DIO_vSetPinDirection(Port_t Copy_PortName,Pin_t Copy_PinNumber,Dir_t Copy_Direction )
{
	if (OUTPUT==Copy_Direction)
	{
		SET_BIT((GPIO[Copy_PortName]->DDR),Copy_PinNumber);
	} //end if 
	else if(INPUT==Copy_Direction)
	{
		CLR_BIT((GPIO[Copy_PortName]->DDR),Copy_PinNumber);
	}//end else
	else
	{
		
	}
}

/**********************************************************************************************************
* @fn DIO_vSetPinValue.
* @brief Set Pin Value As High or Low.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_PinNumber : Pin Number, Get Options @Pin_t enum.
* @param[in] PinState_t     : Pin State , Get Options @PinState_t enum.
* @retval void.
*
*/
void DIO_vSetPinValue(Port_t Copy_PortName,Pin_t Copy_PinNumber,PinState_t PinState)
{
	if (PIN_IS_HIGH==PinState)
	{
		SET_BIT((GPIO[Copy_PortName]->PORT),Copy_PinNumber);
	} //end if 
	else if(PIN_IS_LOW==PinState)
	{
		CLR_BIT((GPIO[Copy_PortName]->PORT),Copy_PinNumber);
	}//end else
	else
	{
		
	}
}

/**********************************************************************************************************
* @fn DIO_u8GetPinValue.
* @brief Set Pin Value As High or Low.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_PinNumber : Pin Number, Get Options @Pin_t enum.
* @param[in] PinState_t     : Pin State , Get Options @PinState_t enum.
* @retval uint8.
*
*/
uint8 DIO_u8GetPinValue(Port_t Copy_PortName,Pin_t Copy_PinNumber)
{
	return GET_BIT((GPIO[Copy_PortName]->PIN),Copy_PinNumber);
}


/**********************************************************************************************************
* @fn DIO_vTogglePin.
* @brief Toggle Pin Value.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_PinNumber : Pin Number, Get Options @Pin_t enum.
* @retval void.
*
*/

void DIO_vTogglePin(Port_t Copy_PortName,Pin_t Copy_PinNumber)
{
	TOGGLE_BIT((GPIO[Copy_PortName]->PORT),Copy_PinNumber);
}
/**********************************************************************************************************
* @fn DIO_vSetPullupPin.
* @brief Set Pin as Pull Up.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_PinNumber : Pin Number, Get Options @Pin_t enum.
* @retval void.
*
*/
void DIO_vSetPullupPin(Port_t Copy_PortName,Pin_t Copy_PinNumber)
{
		CLR_BIT((GPIO[Copy_PortName]->DDR),Copy_PinNumber);
		SET_BIT((GPIO[Copy_PortName]->PORT),Copy_PinNumber);
}

/**********************************************************************************************************
* @fn DIO_vSetPortDirection.
* @brief Set Port Direction.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_uint8Direction : Set Pins Direction Of Port as input Value.
* @retval void.
*
*/

void DIO_vSetPortDirection(Port_t Copy_PortName ,uint8 Copy_u8Direction )
{
	GPIO[Copy_PortName]->DDR = Copy_u8Direction ;
}
/**********************************************************************************************************
* @fn DIO_vSetPortValue.
* @brief Set Port Value.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_uint8Value : Set Pins value Of Port as input Value.
* @retval void.
*
*/
void DIO_vSetPortValue(Port_t Copy_PortName,uint8 Copy_u8Value)
{
	GPIO[Copy_PortName]->PORT = Copy_u8Value;
}
/**********************************************************************************************************
* @fn DIO_u8GetPortValue.
* @brief Get Port Value.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @retval uint8.
*
*/
uint8 DIO_u8GetPortValue(Port_t Copy_PortName)
{
	uint8 ReturnValue=(GPIO[Copy_PortName]->PIN);
	return ReturnValue;
}



