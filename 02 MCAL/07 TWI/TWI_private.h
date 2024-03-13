/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 3 MAR 2024              */
/* Version : V02		  			 */
/* MCU 	   : ATMEGA32                */
/*************************************/

#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H

/* TWI stands for "Two Wire Interface"  */
#define TWBR    (*(volatile uint8*)0x20)
#define TWSR    (*(volatile uint8*)0x21)
#define TWAR    (*(volatile uint8*)0x22)
#define TWDR    (*(volatile uint8*)0x23)
#define TWCR    (*(volatile uint8*)0x56)


/* TWCR */
#define TWINT   7U
#define TWEA    6U
#define TWSTA   5U
#define TWSTO   4U
#define TWWC    3U
#define TWEN    2U
/* bit 1 reserved */
#define TWIE    0U

/* TWAR */
#define TWGCE   0U

/* TWSR */
#define TWS7    7U
#define TWS6    6U
#define TWS5    5U
#define TWS4    4U
#define TWS3    3U
/* bit 2 reserved */
#define TWPS1   1U
#define TWPS0   0U

#define START 		   	0x08
#define REPEATED_START  0x10
#define MT_SLA_ACK	    0x18
#define MT_DATA_ACK	    0x28

#define MR_SLA_ACK	    0x40
#define MR_DATA_NACK    0x58

#define SR_SLA_ACK    	0x60
#define SR_DATA_ACK    	0x80
static void TWI_voidStart(void);
static void TWI_voidSetAddress(uint8 Copy_u8Address );
static void TWI_voidWriteData(uint8 Copy_u8Data);
static void TWI_voidStop(void);
static uint8  TWI_ReadWithNACK(void);
static uint8  TWI_ReadWithACK(void);

#endif