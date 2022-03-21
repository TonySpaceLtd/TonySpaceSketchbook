#include "TonyS_X1.h"
#include "TonySpace_4_20mA_Input.h"

void setup() {
  Serial.begin(115200);
  Serial.println("TonyS_X1 Example");
  Tony.begin();  //----  begin Library
  delay(10);
  Input4_20mA.setSlot(SLOT1);
}

void loop() 
{
 Serial.print("Read 4-20mA: ");
 Serial.print(Input4_20mA.read(),2);
 Serial.println(" mA");
 delay(200);
}
