
#ifndef TonySpace_SHT31_h
#define TonySpace_SHT31_h

#include "Arduino.h"
#include "Wire.h"

#define SHT_ADDR 0x44

class TONY_SHT31
{
	public:
		TONY_SHT31();
		bool begin(uint8_t addr = SHT_ADDR);
		void write16(uint16_t data);
		void write(uint8_t data);
		uint8_t read(uint8_t data[], size_t size); 
		uint8_t checkCrc(uint8_t data[]);
		bool readTempHumi();
		float readTemperature();
		float readHumidity();
	private:
		uint8_t addr_;
		float humi;
		float temperature_C;
};

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SERIAL)
	extern TONY_SHT31 TonySHT31;
#endif

#endif
















