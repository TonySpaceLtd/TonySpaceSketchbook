#include "TonyS_X1.h"
#include "TonySpace_4_20mA_Output.h"

void setup() {
  Serial.begin(115200);
  Serial.println("TonyS_X1 Example");
  Tony.begin();  //----  begin Library
  delay(10);
  Output4_20mA.setSlot(SLOT4);
}

void loop() 
{
  for(uint8_t i=0;i<101;i+=10)
  {
    Serial.printf("4-20mA Output: %d %%\r\n",i);
    Output4_20mA.write(i); // set 0-100 
    delay(2000);
  }
  for(uint8_t i=0;i<10;i++)
  {
    float ran = random(40,200)/10.0; 
    Serial.printf("4-20mA Output: %.2f mA\r\n",ran);
    Output4_20mA.writeFloat(ran); //  resolution 0.1 mA
    delay(2000);
  }
}
