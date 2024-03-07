/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 20 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
		
/***************   Pin Status   *******************
* @PinState_t
*
*/
typedef enum
{
 PIN_IS_LOW=0,
 PIN_IS_HIGH

}PinState_t;
/***************   Direction Status   *******************
* @Dir_t
*
*/
typedef enum
{
 INPUT=0,
 OUTPUT

}Dir_t;

/***************   Pin Number   *******************
* @Pin_t
*
*/
typedef enum
{
 PIN0=0,
 PIN1,
 PIN2,
 PIN3,
 PIN4,
 PIN5,
 PIN6,
 PIN7
}Pin_t;

/***************   Port Name   *******************
* @Port_t
*
*/
typedef enum
{
 PORTA=0,
 PORTB,
 PORTC,
 PORTD
}Port_t;

/**********************************************************************************************************
* @fn DIO_vSetPinDirection.
* @brief Set Pin Direction As Input or Output.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_PinNumber : Pin Number, Get Options @Pin_t enum.
* @param[in] Copy_Direction : Pin Direction , Get Options @Dir_t enum.
* @retval void.
*
*/
void DIO_vSetPinDirection(Port_t Copy_PortName,Pin_t Copy_PinNumber,Dir_t Copy_Direction );


/**********************************************************************************************************
* @fn DIO_vSetPinValue.
* @brief Set Pin Value As High or Low.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_PinNumber : Pin Number, Get Options @Pin_t enum.
* @param[in] PinState_t     : Pin State , Get Options @PinState_t enum.
* @retval void.
*
*/
void DIO_vSetPinValue(Port_t Copy_PortName,Pin_t Copy_PinNumber,PinState_t PinState);


/**********************************************************************************************************
* @fn DIO_u8GetPinValue.
* @brief Set Pin Value As High or Low.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_PinNumber : Pin Number, Get Options @Pin_t enum.
* @param[in] PinState_t     : Pin State , Get Options @PinState_t enum.
* @retval uint8.
*
*/
uint8 DIO_u8GetPinValue(Port_t Copy_PortName,Pin_t Copy_PinNumber);


/**********************************************************************************************************
* @fn DIO_vTogglePin.
* @brief Toggle Pin Value.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_PinNumber : Pin Number, Get Options @Pin_t enum.
* @retval void.
*
*/

void DIO_vTogglePin(Port_t Copy_PortName,Pin_t Copy_PinNumber);

/**********************************************************************************************************
* @fn DIO_vSetPullupPin.
* @brief Set Pin as Pull Up.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_PinNumber : Pin Number, Get Options @Pin_t enum.
* @retval void.
*
*/
void DIO_vSetPullupPin(Port_t Copy_PortName,Pin_t Copy_PinNumber);

/**********************************************************************************************************
* @fn DIO_vSetPortDirection.
* @brief Set Port Direction.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_uint8Direction : Set Pins Direction Of Port as input Value.
* @retval void.
*
*/

void DIO_vSetPortDirection(Port_t Copy_PortName, uint8 Copy_u8Direction );

/**********************************************************************************************************
* @fn DIO_vSetPortValue.
* @brief Set Port Value.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @param[in] Copy_uint8Value : Set Pins value Of Port as input Value.
* @retval void.
*
*/
void DIO_vSetPortValue(Port_t Copy_PortName , uint8 Copy_u8Value);
/**********************************************************************************************************
* @fn DIO_vGetPortValue.
* @brief Get Port Value.
* @param[in] Copy_PortName  : Port Name, Get Options @Port_t enum.
* @retval uint8.
*
*/
uint8 DIO_vGetPortValue(Port_t Copy_PortName);

#endif