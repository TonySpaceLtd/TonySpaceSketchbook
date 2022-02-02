#include "TonySpace_SHT31.h"
#include "TonyS_X1.h"
#include <stdlib.h>
#include <stdio.h>



#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SERIAL)
	TONY_SHT31 TonySHT31;
#endif

TONY_SHT31::TONY_SHT31()
{
	
}
bool TONY_SHT31::begin(uint8_t addr)
{
	Wire.begin();
	addr_ = addr;
	
	write16(0x30A2);
    delay(10);
	
	
	write16(0x3780);
	delay(1);
    
	uint8_t data[6];
	read(data,6);
	
	uint8_t serialNumber1[3];
    uint8_t serialNumber2[3];
    memcpy(serialNumber1,data,3);
    memcpy(serialNumber2,data+3,3);
	uint32_t result = 0 ;
	 if((checkCrc(serialNumber1) == serialNumber1[2]) && (checkCrc(serialNumber2) == serialNumber2[2])){
    result = serialNumber1[0];
    result = (result << 8) | serialNumber1[1];
    result = (result << 8) | serialNumber2[0];
    result = (result << 8) | serialNumber2[1];
  }
  
  readTemperature();
  readHumidity();
  return true;
  //Serial.println(result);
	
}
bool TONY_SHT31::readTempHumi()
{
	byte error;
	Wire.beginTransmission(addr_);
    error = Wire.endTransmission();
	if(error!=0)
	{
		temperature_C = NAN;
		humi = NAN;
		return false;
	}
	uint8_t readbuffer[6];
	write16(0x2400);
	//delay(500);
	read(readbuffer,6);
	
    uint8_t Number1[3];
    uint8_t Number2[3];
    memcpy(Number1,readbuffer,3);
    memcpy(Number2,readbuffer+3,3);
	
  uint16_t ST, SRH;
  ST = readbuffer[0];
  ST <<= 8;
  ST |= readbuffer[1];

  if (readbuffer[2] != checkCrc(Number1)) return false;

  SRH = readbuffer[3];
  SRH <<= 8;
  SRH |= readbuffer[4];

  if (readbuffer[5] != checkCrc(Number2)) return false;

  double stemp = ST;
  stemp *= 175;
  stemp /= 0xffff;
  stemp = -45 + stemp;
  temperature_C = stemp;
  
  double shum = SRH;
  shum *= 100;
  shum /= 0xFFFF;
  humi = shum;
  return true;
}
float TONY_SHT31::readTemperature()
{
	readTempHumi();
	return temperature_C;
}
float TONY_SHT31::readHumidity()
{
	readTempHumi();
	return humi;
	
}
void TONY_SHT31::write16(uint16_t data)
{
	Wire.beginTransmission(addr_);
	Wire.write(data>>8);
	Wire.write(data&0xFF);
	Wire.endTransmission();
	
	
}
void TONY_SHT31::write(uint8_t data)
{
	Wire.beginTransmission(addr_);
	Wire.write(data);
	Wire.endTransmission();
}
uint8_t TONY_SHT31::read(uint8_t data[], size_t size) 
{
	uint8_t len = 0;
	Wire.requestFrom(addr_,size);
	if (Wire.available() != size) 
     return 0;
	for (uint8_t i = 0 ; i < size; i++) 
	{
		data[i] = Wire.read();
		//Serial.print(data[i],HEX);
		//Serial.print(" ");
    len++;
	}
  Wire.endTransmission();
  return len;
}
uint8_t TONY_SHT31::checkCrc(uint8_t data[])
{
    uint8_t bit;
    uint8_t crc = 0xFF;

    for (uint8_t dataCounter = 0; dataCounter < 2; dataCounter++)
    {
        crc ^= (data[dataCounter]);
        for (bit = 8; bit > 0; --bit)
        {
            if (crc & 0x80)
                crc = (crc << 1) ^ 0x31;
            else
                crc = (crc << 1);
        }
    }
    return crc;
}
