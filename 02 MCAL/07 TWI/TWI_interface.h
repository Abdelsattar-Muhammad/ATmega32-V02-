/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 3 MAR 2024              */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/
 
#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

// Master as Transmitter

/* Frame OF I2C As Transmitter
(1-bit)S + (8-bit)ADDRESS+(R/W) + (1-bit) ACK + (8-bit) DATA + (1-bit) ACK +(1-bit) STOP
*/
/***************  TWI Mode  *******************
*@TWI_Mode_t enum
*
*/
typedef enum {		
		
        TWI_MASTER=1,
        TWI_SLAVE=2,		
}TWI_Mode_t;
/***************  TWI Prescalar  *******************
*@TWI_PS_t enum
*
*/
typedef enum {
	
	TWI_PS_1 ,     /* TWI Speed Is Fosc / 4   */
	TWI_PS_4 ,     /* TWI Speed Is Fosc / 8   */
	TWI_PS_16,     /* TWI Speed Is Fosc / 16  */	
	TWI_PS_64      /* TWI Speed Is Fosc / 64  */
	
}TWI_PS_t;

/***************   	TWI Configuration  	 *******************
* @TWI_HandleTypeDef struct
*
*/
typedef struct
{
    uint8               TWI_Adress;      /* Set in Master and Slave Mode */
    uint32              TWI_SCLFreq;     /* Set in Master Mode */
	TWI_Mode_t          TWI_Mode;          
    TWI_PS_t            TWI_Prescaler;   /* Set in Master Mode */
   
	
}TWI_HandleTypeDef;

/***************   Function definition   ******************/
/*********************************************************
* @fn TWI_voidInit
* @brief The Function Set Configuration of TWI.
* @param[in] hTWI :  Get Options @TWI_HandleTypeDef struct
* @retval void
*/
void TWI_voidInit(TWI_HandleTypeDef *hTWI);

/*********************************************************
* @fn TWI_voidMasterTransmit
* @brief Function to transmit data by TWI.
* @param[in] Address :  Address of Slave To transmit Data.
* @param[in] Pdata :  Pointer to Data which want to transmit
* @param[in] Size  :  Size Of Data which want to transmit
* @retval void
*/

void TWI_voidMasterTransmit(uint8 Address,uint8 *Pdata,uint16 Size);


/*********************************************************
* @fn TWI_voidMasterReceive
* @brief Function to Receive data by TWI.
* @param[in] Address :  Address of Slave To Receive Data.
* @param[in] Pdata :  Pointer to Data which want to Receive
* @retval void
*/
void TWI_voidMasterReceive(uint8 Address,uint8 *Pdata);

/*********************************************************
* @fn TWI_voidSlaveReceive
* @brief Function to Receive data by TWI.
* @param[in] Pdata :  Pointer to Data which want to Receive
* @retval void
*/
void TWI_voidSlaveReceive(uint8 *Pdata);


#endif