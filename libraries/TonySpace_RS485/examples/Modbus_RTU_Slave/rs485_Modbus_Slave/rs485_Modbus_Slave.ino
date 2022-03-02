#include "TonyS_X1.h"
#include "TonySpace_Modbus_Slave.h"

Tony_Modbus_Slave modbusSlave;
#define SLAVE_ID 0x01

 
#define COIL_ADDR 0x00
#define COIL_END_ADDR 0x10
uint16_t coil = 0b1010111101010011;

#define INPUT_ADDR 0x10
#define INPUT_END_ADDR 0x26
uint16_t inputStatus = 0b1100110011001100;

#define HOLDING_ADDR 100
#define HOLDING_END_ADDR 110
uint16_t holding[10] = {1000,2000,3000,4000,5000,6000,7000,8000,9000,10000};

#define INPUTREG_ADDR 200
#define INPUTREG_END_ADDR 210
uint16_t inputreg[10] = {2100,2200,2300,2400,2500,2600,2700,2800,2900,30000};


void setup()
{
  Serial.begin(115200);
  Serial.println("TonyS_X1 Example");
  Tony.begin();  //----  begin Library
  modbusSlave.setSlot(SLOT4);
  modbusSlave.setID(SLAVE_ID);
  modbusSlave.begin(9600);
  modbusSlave.callback = modbusCallback;
}
void loop()
{
 //Serial.println("Hello");
 
}
void modbusCallback(Modbus_Reuest request)
{ 
  switch(request.function)
  {
    case Read_Coil_Status: //Function 0x01
      Serial.println("Read Coil Status");
      Serial.print("Address: ");
      Serial.println(request.address);
      Serial.print("Number of coils requested: ");
      Serial.println(request.number);
      answerReadCoilStatus(request);
    break;
    case Read_Input_Status: //Function 0x02
      Serial.println("Read Input Status");
      Serial.print("Address: ");
      Serial.println(request.address);
      Serial.print("Number of Input requested: ");
      Serial.println(request.number);
      answerReadHoldingRegister(request);
    break;
    case Read_Holding_Register: //Function 0x03
      Serial.println("Read Holding Register");
      Serial.print("Address: ");
      Serial.println(request.address);
      Serial.print("Number of Holding Register requested: ");
      Serial.println(request.number);
      answerReadHoldingRegister(request);
    break;
    case Read_Input_Register: //Function 0x04
      Serial.println("Read Input Register");
      Serial.print("Address: ");
      Serial.println(request.address);
      Serial.print("Number of Input Register requested: ");
      Serial.println(request.number);
      answerReadInputRegister(request);
    break;
    case Force_Single_Coil: //Function 0x05
      Serial.println("Force Single Coil");
      Serial.print("Address: ");
      Serial.println(request.address);
      Serial.print("Set Input Register : ");
      Serial.println(request.number==0xFF00?"ON":"OFF");
      answerForceSingleCoil(request);
    break;
    case Preset_Single_Register: //Function 0x06
      Serial.println("Preset Single Register");
      Serial.print("Address: ");
      Serial.println(request.address);
      Serial.print("Set Register value : ");
      Serial.println(request.number);
      answerPresetSingleRegister(request);
    break;
    case Force_Multiple_Coils: //Function 0x0F
      Serial.println("Force Multiple Coils");
      Serial.print("Address: ");
      Serial.println(request.address);
      Serial.print("The number of registers to write bit: ");
      Serial.println(request.numberReg);
      Serial.print("The number of data bytes  : ");
      Serial.println(request.numberByte);
      answerForceMultipleCoils(request);
    break;
    case Preset_Multiple_Registers: //Function 0x10
      Serial.println("Preset Multiple Registers");
      Serial.print("Address: ");
      Serial.println(request.address);
      Serial.print("The number of registers to write : ");
      Serial.println(request.numberReg);
      Serial.print("The number of data bytes  : ");
      Serial.println(request.numberByte);
      answerPresetMultipleRegister(request);
    break;
  }
}

void answerReadCoilStatus(Modbus_Reuest request)
{
  if((request.address>= COIL_ADDR)&&(request.address < COIL_END_ADDR)) // Coil 16 bit start 0x00 - 0x0F
  {
    uint16_t mask=0xFFFF;
    mask = mask>>(16-request.number);
    uint16_t out = (coil>>(request.address-COIL_ADDR))&mask;
    Serial.println(out,BIN);
    uint8_t res[2];
    res[0] =  out&0x00FF;
    res[1] =  out>>8;
    modbusSlave.response(request,res,2);
  }
  else
    Serial.println("!!!invalid request address");
}
void answerReadInputStatus(Modbus_Reuest request)
{
  if((request.address>= INPUT_ADDR)&&(request.address < INPUT_END_ADDR)) // Input 16 bit start 0x10 - 0x26
  {
    uint16_t mask=0xFFFF;
    mask = mask>>(16-request.number);
    uint16_t out = (inputStatus>>(request.address-INPUT_ADDR))&mask;
    Serial.println(out,BIN);
    uint8_t res[2];
    res[0] =  out&0x00FF;
    res[1] =  out>>8;
    modbusSlave.response(request,res,2);
  }
  else
    Serial.println("!!!invalid request address");
}
void answerReadHoldingRegister(Modbus_Reuest request)
{
   if((request.address>= HOLDING_ADDR)&&(request.address < HOLDING_END_ADDR)) // HOLDING 10 reg  start 100 - 110 (1 reg = 2 byte)
   {
    if((request.address+request.number)<= HOLDING_END_ADDR)
    {
      uint16_t addr = (request.address-HOLDING_ADDR);
      for(uint8_t i=addr;i<(addr+request.number);i++)
      {
        Serial.print(holding[i]);
        Serial.print(" ");
      }
      Serial.println();
      modbusSlave.response(request,holding+addr,0);
    }
    else
      Serial.println("!!!invalid request number of data");
   }
   else
    Serial.println("!!!invalid request address");
}
void answerReadInputRegister(Modbus_Reuest request)
{
   if((request.address>= INPUTREG_ADDR)&&(request.address < INPUTREG_END_ADDR)) // INPUTREG 10 reg  start 200 - 210 (1 reg = 2 byte)
   {
    if((request.address+request.number)<= INPUTREG_END_ADDR)
    {
      uint16_t addr = (request.address-INPUTREG_ADDR);
      for(uint8_t i=addr;i<(addr+request.number);i++)
      {
        Serial.print(inputreg[i]);
        Serial.print(" ");
      }
      Serial.println();
      modbusSlave.response(request,inputreg+addr,0);
    }
    else
      Serial.println("!!!invalid request number of data");
   }
   else
    Serial.println("!!!invalid request address");
}
void answerForceSingleCoil(Modbus_Reuest request)
{
   if((request.address>= COIL_ADDR)&&(request.address < COIL_END_ADDR)) // Coil 16 bit start 0x00 - 0x0F
  {
      if(request.number == 0xFF00 )
      {
        coil |= 1<< request.address; 
      }
      else
      {
        coil &=~(1<< request.address);
      }
      Serial.println(coil,BIN);
       modbusSlave.response(request,0,0);    
  }
   else
    Serial.println("!!!invalid request address");
}
void answerPresetSingleRegister(Modbus_Reuest request)
{
  if((request.address>= HOLDING_ADDR)&&(request.address < HOLDING_END_ADDR)) // HOLDING 10 reg  start 100 - 110 (1 reg = 2 byte)
   {
      uint16_t addr = (request.address-HOLDING_ADDR);
      holding[addr] = request.number;
      for(uint8_t i=0;i<10;i++)
      {
        Serial.print(holding[i]);
        Serial.print(" ");
      }
      Serial.println();
      modbusSlave.response(request,0,0);
   }
   else
    Serial.println("!!!invalid request address");
}
void answerForceMultipleCoils(Modbus_Reuest request)
{
   if((request.address>= COIL_ADDR)&&(request.address < COIL_END_ADDR)) // Coil 16 bit start 0x00 - 0x0F
  {
    if(request.numberByte <= 2)
    {
      uint16_t dat=0;
      uint8_t i;
      if(request.numberByte==2)
        dat = request.data[1]<<8;
      dat |= request.data[0];
      
      uint16_t mask=0;
      for(i = request.address;i<(request.address+request.numberReg);i++)
          mask |= 1 << i;
      coil &= ~mask;
      coil |= dat << request.address;
      Serial.println(coil,BIN);
       modbusSlave.response(request,0,0);
    }
    else
      Serial.print("Out Of Range...");    
  }
   else
    Serial.println("!!!invalid request address");
}
void answerPresetMultipleRegister(Modbus_Reuest request)
{
  if((request.address>= HOLDING_ADDR)&&(request.address < HOLDING_END_ADDR)) // HOLDING 10 reg  start 100 - 110 (1 reg = 2 byte)
   {
    if((request.address+request.numberReg)<= HOLDING_END_ADDR)
    {
      uint16_t addr = (request.address-HOLDING_ADDR);
      uint16_t *dat = (uint16_t*) request.data;
      uint16_t i;
      Serial.print("New Data : ");
      for(i = 0;i<request.numberReg;i++)
      {
        Serial.print(dat[i]); Serial.print(" ");
        holding[addr+i] = dat[i];
      }
      Serial.println();
      Serial.print("All Data : ");
      for(i=0;i<10;i++)
      {
        Serial.print(holding[i]);
        Serial.print(" ");
      }
      Serial.println();
      modbusSlave.response(request,0,0);
    }
    else
     Serial.println("!!!invalid request number of data");
   }
   else
    Serial.println("!!!invalid request address");
}
