/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 Feb 2024             */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#include "DATA_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h" 
#include "SPI_config.h"


/*****************Pointer to functions to be assigned to ISR******************************/

#define NULL ((void *)0)

volatile uint8 *SPI_TX_PTR 	=NULL;
volatile uint16 *SPI_TX_SIZE =NULL;
volatile uint8 *SPI_RX_PTR 	=NULL;
volatile uint16 *SPI_RX_SIZE =NULL;

/***************   Function definition   ******************/
/*********************************************************
* @fn SPI_voidInit
* @brief The Function Set Configuration of SPI.
* @param[in] hspi :  Get Options @SPI_HandleTypeDef struct 
* @retval void
*/
void SPI_voidInit(SPI_HandleTypeDef *hspi)
{

	if (hspi->SPI_Mode == SPI_MASTER)
	{
		/* Set Pins OF Spi Peripheral */
		DIO_vSetPinDirection(SPI_PORT, MOSI , OUTPUT );
		DIO_vSetPinDirection(SPI_PORT, MISO , INPUT  );
		DIO_vSetPinDirection(SPI_PORT, SCK  , OUTPUT );
		DIO_vSetPinDirection(SPI_PORT, SS   , OUTPUT );

	}
	else
	{
		/* Set Pins OF Spi Peripheral */
		DIO_vSetPinDirection(SPI_PORT,MOSI,INPUT);
		DIO_vSetPinDirection(SPI_PORT,MISO,OUTPUT);
		DIO_vSetPinDirection(SPI_PORT,SCK ,INPUT);
		DIO_vSetPinDirection(SPI_PORT,SS  ,INPUT);
	}
	/* Set Clock Polarity */
	SPCR |= (hspi->SPI_ClockPolarity)<<CPOL;
	/* Set Clock Phase */
	SPCR |= (hspi->SPI_ClockPhase)<<CPHA;
	/* Set Double Speed Mode IF User Select Speed Need it */
	SPSR |=	(hspi->SPI_Speed >> 2U);
	/* Set Prescaler and Mode  */
	SPCR = ((hspi->SPI_Mode<<MSTR) | (hspi->SPI_Speed & 0b11));
	/* Enable SPI */
	SET_BIT(SPCR,SPE);
}


/*********************************************************
* @fn SPI_voidTransmit
* @brief Function to transmit data by SPI. 
* @param[in] Pdata :  Pointer to Data which want to transmit
* @param[in] Size  :  Size Of Data which want to transmit
* @retval void
*/

void SPI_voidTransmit(uint8 *Pdata, uint8 Size)
{
	DIO_vSetPinValue(SPI_PORT, SS  ,PIN_IS_LOW);
	uint8 count;
	for (count=0; count<Size; count++)
	{
		SPDR = Pdata[count];
		while(GET_BIT(SPSR,SPIF)==0);
	}
	DIO_vSetPinValue(SPI_PORT, SS  ,PIN_IS_HIGH);
}


/*********************************************************
* @fn SPI_voidReceive
* @brief Function to Receive data by SPI. 
* @param[in] Pdata :  Pointer to Data which want to Receive
* @param[in] Size  :  Size Of Data which want to Receive
* @retval void
*/
void SPI_voidReceive(uint8 *Pdata,uint8 Size)
{
	
	uint8 count;	
	for (count=0; count<Size; count++)
	{
		/* Write Dummy Data */
		SPDR=0xff;
		/* Wait Untill Set Flag */
		while(GET_BIT(SPSR,SPIF)==0);
		/* Read Received Data */
		Pdata[count]= SPDR; 
	}
	
}

/*********************************************************
* @fn SPI_voidTransmit_IT
* @brief Function to transmit data by SPI using Interrupt.
* @param[in] Pdata :  Pointer to Data which want to transmit
* @param[in] Size  :  Size Of Data which want to transmit
* @retval void
*/

void SPI_voidTransmit_IT(uint8 *Pdata, uint16 Size)
{
	SPDR=Pdata[0];
	SPI_TX_PTR =Pdata;
	SPI_TX_SIZE=Size;
}
/*********************************************************
* @fn SPI_voidReceive_IT
* @brief Function to Receive data by SPI using Interrupt.
* @param[in] Pdata :  Pointer to Data which want to Receive
* @param[in] Size  :  Size Of Data which want to Receive
* @retval void
*/
void SPI_voidReceive_IT(uint8 *Pdata, uint16 Size)
{
	SPI_RX_PTR =Pdata;
	SPI_RX_SIZE=Size;

}

/*********************** ISR ***********************************/
ISR(SPI_STC_vect)
{
	static Tx_Count=1,Rx_Count;
	if (SPI_RX_PTR != NULL && Rx_Count != SPI_RX_SIZE )
	{
		SPDR=SPI_TX_PTR[Rx_Count];
		Rx_Count++;
		Rx_Count %= SPI_RX_SIZE;
	}
	if (SPI_TX_PTR != NULL && Tx_Count != SPI_TX_SIZE )
	{
		SPDR=SPI_TX_PTR[Tx_Count];
		Tx_Count++;
		Tx_Count %= SPI_TX_SIZE;
	}
	
}
