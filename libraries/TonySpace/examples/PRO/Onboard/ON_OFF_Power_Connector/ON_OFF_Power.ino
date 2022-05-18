#include "TonyS_X1.h"

void setup() 
{
  Serial.begin(115200);
  Tony.begin();  //----  begin Library
  delay(10);
  Serial.println("TonyS_X1 Example");
}

void loop() 
{
  Tony.onPower(); //---- Call function on power connector
  delay(5000); 
  Tony.offPower(); //---- Call function off power connector
  delay(5000); 
}
