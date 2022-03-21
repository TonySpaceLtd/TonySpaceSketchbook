#include "TonySpace_4_20mA_Output.h"
#include "TonyS_X1.h"



#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SERIAL)
TONY_4_20mA_OUT Output4_20mA;
#endif

TONY_4_20mA_OUT::TONY_4_20mA_OUT()
{
	
}
void TONY_4_20mA_OUT::setSlot(uint8_t slot)
{
	apin = getPinAIO[slot];
}
void TONY_4_20mA_OUT::writeFloat(float value)
{
	float input = value;
	float cal = -0.0012*pow(input,3)+0.0491*pow(input,2)+62.717*input-219.68;
	int m = int(cal*10)%10;
	if(m>=5)
		cal +=1;
	Tony.analogWrite(apin, cal);
}
void TONY_4_20mA_OUT::write(uint8_t value)
{
	if((value>=0)&&(value<=100))
	{
		uint16_t cal = map(value,0,100,32,1045);
		Tony.analogWrite(apin, cal);
	}
}

