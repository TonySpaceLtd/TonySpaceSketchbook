/*
  Link Status
  This sketch prints the ethernet link status. When the
  ethernet cable is connected the link status should go to "ON".
  NOTE: Only WizNet W5200 and W5500 are capable of reporting
  the link status. W5100 will report "Unknown".
  Hardware:
   - Ethernet shield or equivalent board/shield with WizNet 5200/5500
  Written by Cristian Maglie
  This example is public domain.
*/

#include <SPI.h>
#include "TonyS_X1.h"
#include "TonySpace_Ethernet.h"

void setup() {
  Serial.begin(115200);
  Tony.begin();  //----  begin Library
  Ethernet.setSlot(SLOT1);
}

void loop() {
  auto link = Ethernet.linkStatus();
  Serial.print("Link status: ");
  switch (link) {
    case Unknown:
      Serial.println("Unknown");
      break;
    case LinkON:
      Serial.println("ON");
      break;
    case LinkOFF:
      Serial.println("OFF");
      break;
  }
  delay(1000);
}
