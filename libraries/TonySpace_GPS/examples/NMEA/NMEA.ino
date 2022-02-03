#include "TonyS_X1.h"
#include "TonySpace_GPS.h"

void setup() {
  Serial.begin(115200);
  Serial.println("TonyS X1");
  Tony.begin();
  TonyGPS.setSlot(SLOT2);
  TonyGPS.begin();
}

void loop() {
  if(TonyGPS.available())
      Serial.write(TonyGPS.read());
}
