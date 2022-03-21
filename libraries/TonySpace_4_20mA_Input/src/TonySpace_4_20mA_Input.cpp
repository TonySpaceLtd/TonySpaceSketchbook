#include "TonySpace_4_20mA_Input.h"
#include "TonyS_X1.h"


#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SERIAL)
TONY_4_20mA_IN Input4_20mA;
#endif

TONY_4_20mA_IN::TONY_4_20mA_IN()
{
	
}
void TONY_4_20mA_IN::setSlot(uint8_t slot)
{
	avg = new movingAvg(AVG_NUM);
	apin = getPinAIO[slot];
	avg->begin();
	Tony.pinMode(apin, ADC2V5);  
}

int TONY_4_20mA_IN::readADC(void)
{
	long ret=0;
	for(uint8_t i=0;i<AVG_NUM;i++)
		ret += avg->reading(Tony.analogRead(apin));
	return ret/AVG_NUM;
} 
float TONY_4_20mA_IN::read(void)
{
	uint16_t x =  readADC();
	//y = -3E-07x2 + 0.4953x - 2.3869
	float y = -3*pow(10,-7)*pow(x,2)+0.4953*x-2.3869;
	return y/100.0;
}
