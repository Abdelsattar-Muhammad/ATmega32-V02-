/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 28 FEB 2024             */
/* Version : V02				   	 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/***************  UART Mode  *******************
*@UART_Mode_t enum
*
*/
typedef enum {		
		
        UART_TX=1,
        UART_RX=2,
        UART_RX_TX=3,		
}UART_Mode_t;

/***************  UART Synchronization Mode  *******************
*@UART_SyncMode_t enum
*
*/
typedef enum {		
		
        UART_ASYNCMODE=0,
        UART_SYNCMODE=1,
       		
}UART_SyncMode_t;
				
/***************   	UART Word Length	*******************
*@UART_WordLength_t enum
*
*/
typedef enum{
	UART_WORDLENGTH_5B=0,
    UART_WORDLENGTH_6B=1,
    UART_WORDLENGTH_7B=2,
    UART_WORDLENGTH_8B=3,

}UART_WordLength_t;

/***************   	UART Number of Stop Bits	*******************
*@UART_StopBits_t enum
*
*/
typedef enum{
	
    UART_STOPBITS_1=0,
    UART_STOPBITS_2=1,		

}UART_StopBits_t;

/***************   	UART Parity Bit	*******************
*@UART_Parity_t enum
*
*/
typedef enum{
	
    UART_PARITY_NONE=0,
    UART_PARITY_EVEN=2,
    UART_PARITY_ODD=3,   
}UART_Parity_t;

/***************   	UART Oversampling  	 *******************
*@UART_Oversampling_t enum
*
*/
typedef enum{
		UART_OVERSAMPLING_16=0,
        UART_OVERSAMPLING_8=1,

}UART_Oversampling_t;

/***************   	UART Configuration  	 *******************
* @UART_HandleTypeDef struct
*
*/		
typedef struct 
{
    uint32                  UART_Baudrate;
    UART_Mode_t             UART_Mode;
    UART_SyncMode_t         UART_ModeOfSync;
    UART_WordLength_t       UART_Wordlength;
    UART_StopBits_t         UART_StopBits;
    UART_Parity_t           UART_Parity;
    UART_Oversampling_t     UART_Sampling;

}UART_HandleTypeDef;
			
		

/***************   Function definition   ******************/
/*********************************************************
* @fn UART_voidInit
* @brief The Function Set Configuration of UART.
* @param[in] huart :  Get Options @UART_HandleTypeDef struct 
* @retval void
*/

void UART_voidInit(UART_HandleTypeDef* huart);

/*********************************************************
* @fn UART_voidTransmit
* @brief Function to transmit data by UART. 
* @param[in] Pdata :  Pointer to Data which want to transmit
* @param[in] Size  :  Size Of Data which want to transmit
* @retval void
*/

void UART_voidTransmit(uint8 *Pdata, uint16 Size);

/*********************************************************
* @fn UART_voidReceive
* @brief Function to Receive data by UART. 
* @param[in] Pdata :  Pointer to Data which want to Receive
* @param[in] Size  :  Size Of Data which want to Receive
* @retval void
*/
void UART_voidReceive(uint8 *Pdata, uint16 Size);

/*********************************************************
* @fn UART_voidTransmit_IT
* @brief Function to transmit data by UART using Interrupt.
* @param[in] Pdata :  Pointer to Data which want to transmit
* @param[in] Size  :  Size Of Data which want to transmit
* @retval void
*/

void UART_voidTransmit_IT(uint8 *Pdata, uint16 Size);
/*********************************************************
* @fn UART_voidReceive_IT
* @brief Function to Receive data by UART using Interrupt.
* @param[in] Pdata :  Pointer to Data which want to Receive
* @param[in] Size  :  Size Of Data which want to Receive
* @retval void
*/
void UART_voidReceive_IT(uint8 *Pdata, uint16 Size);



#endif