/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/***************  SPI Modes  *******************
*@SPI_Mode_t enum
*
*/
typedef enum {
	
	SPI_SLAVE=0,
	SPI_MASTER=1
	
}SPI_Mode_t;

/***************  SPI Prescalar  *******************
*@SPI_PS_t enum
*
*/
typedef enum {
	
	SPI_PS_4 =0b000,     /* SPI Speed Is Fosc / 4   */
	SPI_PS_8 =0b101,     /* SPI Speed Is Fosc / 8   */
	SPI_PS_16=0b001,     /* SPI Speed Is Fosc / 16  */
	SPI_PS_32=0b110,     /* SPI Speed Is Fosc / 32  */
	SPI_PS_64=0b010,     /* SPI Speed Is Fosc / 64  */
	SPI_PS_128=0b011,    /* SPI Speed Is Fosc / 128 */

	
}SPI_SPEED_t;

/***************  SPI Clock Polarity  *******************
*@SPI_POL_t enum
*
*/
typedef enum {
	
	LEADING_RISING=0,
	LEADING_FALLING=1
	
}SPI_POL_t;
/***************  SPI Clock Phase  *******************
*@SPI_PHA_t enum
*
*/
typedef enum {
	
	LEADING_SAMPLE=0,
	LEADING_SETUP=1
	
}SPI_PHA_t;


/***************   	SPI Configuration  	 *******************
* @SPI_HandleTypeDef struct
*
*/
typedef struct
{
	SPI_Mode_t           SPI_Mode;
	SPI_SPEED_t          SPI_Speed;
	SPI_POL_t			SPI_ClockPolarity;
	SPI_PHA_t			SPI_ClockPhase;
	
}SPI_HandleTypeDef;

/***************   Function definition   ******************/
/*********************************************************
* @fn SPI_voidInit
* @brief The Function Set Configuration of SPI.
* @param[in] hspi :  Get Options @SPI_HandleTypeDef struct
* @retval void
*/
void SPI_voidInit(SPI_HandleTypeDef *hspi);


/*********************************************************
* @fn SPI_voidTransmit
* @brief Function to transmit data by SPI.
* @param[in] Pdata :  Pointer to Data which want to transmit
* @param[in] Size  :  Size Of Data which want to transmit
* @retval void
*/

void SPI_voidTransmit(uint8 *Pdata,uint8 Size);


/*********************************************************
* @fn SPI_voidReceive
* @brief Function to Receive data by SPI.
* @param[in] Pdata :  Pointer to Data which want to Receive
* @param[in] Size  :  Size Of Data which want to Receive
* @retval void
*/
void SPI_voidReceive(uint8 *Pdata,uint8 Size);

/*********************************************************
* @fn SPI_voidTransmit_IT
* @brief Function to transmit data by SPI using Interrupt.
* @param[in] Pdata :  Pointer to Data which want to transmit
* @param[in] Size  :  Size Of Data which want to transmit
* @retval void
*/

void SPI_voidTransmit_IT(uint8 *Pdata, uint16 Size);
/*********************************************************
* @fn SPI_voidReceive_IT
* @brief Function to Receive data by SPI using Interrupt.
* @param[in] Pdata :  Pointer to Data which want to Receive
* @param[in] Size  :  Size Of Data which want to Receive
* @retval void
*/
void SPI_voidReceive_IT(uint8 *Pdata, uint16 Size);


#endif