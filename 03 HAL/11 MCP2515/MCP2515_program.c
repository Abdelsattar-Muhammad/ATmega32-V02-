/*****************************************/
/* Author      : Abdelsattar Muhammad    */
/* Date        : 10 MAR 2024             */
/* Version     : V01		  			 */
/* Controller  : MCP2515                 */
/*****************************************/
 
 #include "BIT_MATH.h"
 #include "DATA_TYPES.h"
 #include "SPI_interface.h"
 #include "MCP2515_interface.h"
 #include "MCP2515_config.h"
 #include "MCP2515_private.h"

 static uint8 MCP2515_u8ReadRegister(uint8 Address)
 {
    uint8 ReadValue=0;
    uint8 Buffer[2]={MCP2515_INS_READ,Address};
    SPI_voidTransmit(Buffer,2);
    SPI_voidReceive(&ReadValue,1);
    return ReadValue;
 }

static void MCP2515_voidWriteRegister(uint8 Address,uint8 Data)
 {
    uint8 Buffer[3]={MCP2515_INS_WRITE,Address,Data};
    SPI_voidTransmit(Buffer,3);
 }

void MCP2515_voidReset(void)
{
    uint8 ResetValue=MCP2515_INS_RESET;
    SPI_voidTransmit(&ResetValue,1);
}
void MCP2515_voidModify(uint8 Address,uint8 Mask,uint8 ValueOfMask)
{
    uint8 Buffer[4]={MCP2515_INS_MODIFY,Address,Mask,ValueOfMask};
    SPI_voidTransmit(Buffer,4);
}
void MCP2515_voidSetBitTiming(uint8 CNF1Value,uint8 CNF2Value,uint8 CNF3Value)
{
    MCP2515_voidWriteRegister(CNF1, CNF1Value);
    MCP2515_voidWriteRegister(CNF2, CNF2Value);
    MCP2515_voidWriteRegister(CNF3, CNF3Value);
}
void MCP2515_voidSetMode(uint8 Mode)
{

    MCP2515_voidModify(CANCTRL, 0xE0, (Mode<<5));

}