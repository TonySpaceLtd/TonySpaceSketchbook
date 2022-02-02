#include "TonyS_X1.h"
#include "TonySpace_7Segment.h"
uint32_t start, stop;

RTC_DS3231 rtc;
unsigned long previousMillis = 0;
const long interval = 500;

void setup()
{
  Serial.begin(115200);
  Tony.begin();  //----  begin Library
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  Tony7Seg.begin(); //----  begin 7-Segment 
  Tony7Seg.displayOn();
 
}

void loop()
{
   unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
     DateTime now = rtc.now();
     Tony7Seg.displayTime(now.hour(), now.minute());
     Tony7Seg.displayColon(now.second()&1);
     previousMillis = currentMillis;
  }
}