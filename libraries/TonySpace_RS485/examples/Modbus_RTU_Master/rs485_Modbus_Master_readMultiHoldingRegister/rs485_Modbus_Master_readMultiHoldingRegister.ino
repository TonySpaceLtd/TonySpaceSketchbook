#include "TonyS_X1.h"
#include "TonySpace_Modbus_Master.h"

#define SLAVE_ID 0x03
#define ADDRESS  0
#define NUMDATA  10
Tony_Modbus_Master modbus;

void setup() 
{
  Serial.begin(115200);
  Serial.println("TonyS_X1 Example");
  Tony.begin();  //----  begin Library
  modbus.setSlot(SLOT4);
  modbus.begin(9600);
}
void loop() 
{
 Serial.println("Read Multi Holding Register");
 uint16_t *dat;
 uint16_t len;
 if(modbus.readMultiHoldingRegister(SLAVE_ID,ADDRESS,NUMDATA,&dat,&len))
 {
    for(uint16_t i=0;i<len;i++)
    {
      Serial.print("Data "+String(i)+": ");
      Serial.println(dat[i]);
    }
 }
 delay(1000);
}
