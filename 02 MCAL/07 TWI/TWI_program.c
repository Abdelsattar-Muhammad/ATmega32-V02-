/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 3 MAR 2024              */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

	
#include "DATA_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"

/***************   Function definition   ******************/
/*********************************************************
* @fn TWI_voidInit
* @brief The Function Set Configuration of TWI.
* @param[in] htwi :  Get Options @TWI_HandleTypeDef struct
* @retval void
*/
void TWI_voidInit(TWI_HandleTypeDef *htwi)
{
	
	if (htwi->TWI_Mode == TWI_MASTER)
	{
		uint8 PowOf4;
		switch (htwi->TWI_Prescaler)
		{	case TWI_PS_1 : PowOf4=1;	break;
			case TWI_PS_4 : PowOf4=4;	break;
			case TWI_PS_16: PowOf4=16;	break;
			case TWI_PS_64: PowOf4=64;	break;
		}
		/* Set Precaler of TWI */
		TWSR = htwi->TWI_Prescaler;
		/* Set Bit Rate of TWI */
		TWBR= (uint8)(((F_CPU/htwi->TWI_SCLFreq)-16) / (2.0*PowOf4));
			
	}
	/* Set Address Of The Node */
	TWAR= htwi->TWI_Adress;
	/* Enable TWI Priperal */
	TWCR=(1<<TWEN);
}

/* This Function Used To Send Start Bit */
static void TWI_voidStart(void)
{
	/* Clear TWINT by write 1 ,and Enable TWI, and Set Start Bit */
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA) ;
	/*wait until interrupt flag set*/
	while( GET_BIT( TWCR,TWINT)==0); 

	if((TWSR & 0xF8) != START )
	{
		/*	#error */
	}
}

/* This Function Used To Send Address of Node */
static void TWI_voidSetAddress(uint8 Copy_u8Address )
{
	/* Set Address In Data Register */
	TWDR= Copy_u8Address ;
	/* Clear TWINT by write 1 ,and Enable TWI */
	TWCR= (1 << TWINT) | (1 << TWEN);
	/*wait until interrupt flag set */
	while( GET_BIT( TWCR,TWINT)==0);

	if((TWSR & 0xF8)!=MT_SLA_ACK)
	{
		/*	#error */
	}
	
}
/* This Function Used To Send Data to Slave */
static void TWI_voidWriteData(uint8 Copy_u8Data)
{
	/* Set Data In Data Register */
	TWDR=Copy_u8Data;
	/* Clear TWINT by write 1 ,and Enable TWI */
	TWCR= (1 << TWINT) | (1 << TWEN) ;
	/* wait until interrupt flag set */
	while( GET_BIT( TWCR,TWINT)==0);
	if((TWSR & 0xF8)!=MT_DATA_ACK)
	{
		/*	#error */
	}
}
/* This Function Used To Send Stop Bit */
static void TWI_voidStop(void)
{
	/* Clear TWINT by write 1 ,and Enable TWI, and Set Stop Bit */
	TWCR= (1 << TWINT) | (1 << TWEN)| (1 << TWSTO) ;

}
/*********************************************************
* @fn TWI_voidMasterTransmit
* @brief Function to transmit data by TWI.
* @param[in] Address :  Address of Slave To transmit Data.
* @param[in] Pdata :  Pointer to Data which want to transmit
* @param[in] Size  :  Size Of Data which want to transmit
* @retval void
*/

void TWI_voidMasterTransmit(uint8 Address,uint8 *Pdata,uint16 Size)
{
	uint16 Count;
	TWI_voidStart();
	/* Set Bit 0 In Address As 0 To Write Data which will Transmitted */
	Address &= ~(1);
	TWI_voidSetAddress(Address);
	for(Count=0;Count<Size;Count++)
	{
		TWI_voidWriteData(Pdata[Count]);
	}
	TWI_voidStop();

}

static uint8  TWI_ReadWithNACK(void)
{
	/* Clear TWINT by write 1 ,and Enable TWI */
	TWCR= (1 << TWINT) | (1 << TWEN) ;
	/*wait until interrupt flag set*/
	while( GET_BIT( TWCR,TWINT)==0);
	return TWDR;
}
static uint8  TWI_ReadWithACK(void)
{	
	/* Clear TWINT by write 1 ,and Enable TWI ,and Enable ACK*/
	TWCR= (1 << TWINT) | (1 << TWEN) |  (1 << TWEA);
	/*wait until interrupt flag set*/
	while( GET_BIT( TWCR,TWINT)==0);
	return TWDR;
}


/*********************************************************
* @fn TWI_voidMasterReceive
* @brief Function to Receive data by TWI.
* @param[in] Address :  Address of Slave To Receive Data.
* @param[in] Pdata :  Pointer to Data which want to Receive
* @retval void
*/
void TWI_voidMasterReceive(uint8 Address,uint8 *Pdata)
{
	TWI_voidStart();
	/* Set Bit 0 In Address As 1 To Read Data which will Received*/
	Address |= (1);	
	TWI_voidSetAddress(Address);
	/*Read Received Data From Slave */
	*Pdata=TWI_ReadWithACK();
	TWI_voidStop();

}


/*********************************************************
* @fn TWI_voidSlaveReceive
* @brief Function to Receive data by TWI.
* @param[in] Pdata :  Pointer to Data which want to Receive
* @retval void
*/
void TWI_voidSlaveReceive(uint8 *Pdata)
{
	/* Verify The Address And Send Ack If Node it's Owner*/
		TWI_ReadWithACK();		
		*Pdata=TWI_ReadWithACK();

}
