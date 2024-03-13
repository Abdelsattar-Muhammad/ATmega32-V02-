/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 28 FEB 2024             */
/* Version : V02				   	 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"


/*****************Pointer to functions to be assigned to ISR******************************/

#define NULL ((void *)0)

static volatile uint8 *UART_TX_PTR=NULL;
static volatile uint16 UART_TX_SIZE;
static volatile uint16 UART_TX_COUNT=0;
static volatile uint8 *UART_RX_PTR=NULL;
static volatile uint16 UART_RX_SIZE;
static volatile uint16 UART_RX_COUNT=0;

/***************   Function definition   ******************/
/*********************************************************
* @fn UART_voidInit
* @brief The Function Set Configuration of UART.
* @param[in] huart :  Get Options @UART_HandleTypeDef struct
* @retval void
*/
/***************   Function definition    ******************/

void UART_voidInit(UART_HandleTypeDef* huart)
{
	
	 uint16 Local_u16UBRR;
	/* Setting Baud Rate Of uart */
	if (huart->UART_ModeOfSync == UART_ASYNCMODE)
	{
		switch(huart->UART_Sampling)
		{
			case UART_OVERSAMPLING_8:
			Local_u16UBRR=(F_CPU/(8 * huart->UART_Baudrate))-1;
			break;
			case UART_OVERSAMPLING_16:
			Local_u16UBRR=(F_CPU/(16 * huart->UART_Baudrate))-1;
			break;
		}
	}
	else
	{
		Local_u16UBRR=(F_CPU/(2 * huart->UART_Baudrate))-1;
	}
	
	UBRRH = (uint8)(Local_u16UBRR>>8);
	UBRRL = (uint8)(Local_u16UBRR);
	/* Setting Double Speed Transmision (OverSampling) */
	UCSRA |= (huart->UART_Sampling << U2X);
	/* Setting UART Mode as Tx or Rx Or Tx_Rx */
	UCSRB =	(huart->UART_Mode<<TXEN);
	/* Setting UART Mode of Synchronization and Data Size */
	UCSRC = ((1<<URSEL) | (huart->UART_ModeOfSync<<UMSEL) | (huart->UART_Parity<<UPM0) | (huart->UART_StopBits<<USBS) |(huart->UART_Wordlength<<UCSZ0));


}

/*********************************************************
* @fn UART_voidTransmit
* @brief Function to transmit data by UART.
* @param[in] Pdata :  Pointer to Data which want to transmit
* @param[in] Size  :  Size Of Data which want to transmit
* @retval void
*/

void UART_voidTransmit(uint8 *Pdata, uint16 Size)
{
	uint16 Count;
	for(Count=0;Count<Size;Count++)
	{
		while(GET_BIT(UCSRA,UDRE)==0);
		/* Put Data Into Data Register */
		UDR=Pdata[Count];
		/* Wait until Transmit Complete */
		while(GET_BIT(UCSRA,TXC)==0);
		
	}
}

/*********************************************************
* @fn UART_voidReceive
* @brief Function to Receive data by UART.
* @param[in] Pdata :  Pointer to Data which want to Receive
* @param[in] Size  :  Size Of Data which want to Receive
* @retval void
*/
void UART_voidReceive(uint8 Pdata[], uint16 Size)
{
	uint16 Count;
	for(Count=0;Count<Size;Count++)
	{
		/* Wait until Receiving Data Complete */
		while(GET_BIT(UCSRA,RXC)==0);
		Pdata[Count]=UDR;
		
	}
}

/*********************************************************
* @fn UART_voidTransmit_IT
* @brief Function to transmit data by UART using Interrupt.
* @param[in] Pdata :  Pointer to Data which want to transmit
* @param[in] Size  :  Size Of Data which want to transmit
* @retval void
*/

void UART_voidTransmit_IT(uint8 *Pdata, uint16 Size)
{
	UART_TX_PTR=Pdata;
	UART_TX_SIZE=Size;
	UART_TX_COUNT=0;
	UDR=Pdata[UART_TX_COUNT];
	/* Enable Global Interrupt */
	__asm__ __volatile__ ("sei" ::: "memory");
	/* Enable Transmision Interrupt */
	SET_BIT(UCSRB,TXCIE);
}

/*********************************************************
* @fn UART_voidReceive_IT
* @brief Function to Receive data by UART using Interrupt.
* @param[in] Pdata :  Pointer to Data which want to Receive
* @param[in] Size  :  Size Of Data which want to Receive
* @retval void
*/
void UART_voidReceive_IT(uint8 *Pdata, uint16 Size)
{
	UART_RX_PTR = Pdata;
	UART_RX_SIZE=Size;
	UART_RX_COUNT=0;
	/* Enable Global Interrupt */
	__asm__ __volatile__ ("sei" ::: "memory");
	/* Enable Receive Interrupt */
	SET_BIT(UCSRB,RXCIE);

}

/*********************** ISR ***********************************/
ISR(USART_TXC_vect)
{
	UART_TX_COUNT++;
	if (UART_TX_PTR != NULL && UART_TX_COUNT != UART_TX_SIZE )
	{
		UDR = UART_TX_PTR[UART_TX_COUNT];
	}
	else
	{
		/*Disable Interrupt*/
		CLR_BIT(UCSRB,TXCIE);
	}

}
ISR(USART_RXC_vect)
{
	
	if (UART_RX_PTR != NULL && UART_RX_COUNT != UART_RX_SIZE )
	{
		UART_RX_PTR[UART_RX_COUNT]=UDR ;
		UART_RX_COUNT++;
	}
	else
	{
		/*Disable Interrupt*/
		CLR_BIT(UCSRB,RXCIE);
	}
}