#include "TonySpace_SHT31.h"
#include "TonyS_X1.h"
#include <stdlib.h>
#include <stdio.h>

Adafruit_SHT31 sht31 = Adafruit_SHT31();

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SERIAL)
	TONY_SHT31 TonySHT31;
#endif

TONY_SHT31::TONY_SHT31()
{
	
}
bool TONY_SHT31::begin(uint8_t addr)
{
	if (! sht31.begin(SHT_ADDR)) 
	{   // Set to 0x45 for alternate i2c addr
    Serial.println("Couldn't find SHT31");
		return false;
	}
  return true;
}

float TONY_SHT31::readTemperature()
{
	return sht31.readTemperature();
}
float TONY_SHT31::readHumidity()
{
	return sht31.readHumidity();
}

