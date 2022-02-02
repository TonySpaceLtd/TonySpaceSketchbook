#include "TonyS_X1.h"
#include "TonySpace_SHT31.h"

void setup()
{
  Serial.begin(115200);
  Tony.begin();  //----  begin Library
  TonySHT31.begin();
}

void loop()
{
  float t = TonySHT31.readTemperature();
  float h = TonySHT31.readHumidity();

  if (! isnan(t)) {  // check if 'is not a number'
    Serial.print("Temp *C = "); Serial.println(t);
  } else { 
    Serial.println("Failed to read temperature");
  }
  
  if (! isnan(h)) {  // check if 'is not a number'
    Serial.print("Hum. % = "); Serial.println(h);
  } else { 
    Serial.println("Failed to read humidity");
  }
  Serial.println();
  delay(1000);
}
