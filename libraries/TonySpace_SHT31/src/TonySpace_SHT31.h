
#ifndef TonySpace_SHT31_h
#define TonySpace_SHT31_h

#include "Arduino.h"
#include "Wire.h"
#include "Adafruit_SHT31.h"

#define SHT_ADDR 0x44

class TONY_SHT31
{
	public:
		TONY_SHT31();
		bool begin(uint8_t addr = SHT_ADDR);
		
		float readTemperature();
		float readHumidity();
	private:
		
};

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SERIAL)
	extern TONY_SHT31 TonySHT31;
#endif

#endif
















