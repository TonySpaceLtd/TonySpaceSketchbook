
#ifndef TonySpace_4_20mA_Output_h
#define TonySpace_4_20mA_Output_h

#include "Arduino.h"

/*### 4-20mA output Test ###
Set data		raw Data
	4				32
	5				95
	6				158
	7				221
	8				285
	9				348
	10				411
	11				475
	12				538
	13				601
	14				665
	15				728
	16				792
	17				855
	18				918
	19				982
	20				1045
Polynomial 2'order
	y = -0.0012*(x^3)+0.0491*(x^2)+62.717*x-219.68
*/

class TONY_4_20mA_OUT
{
public:
	TONY_4_20mA_OUT();
	void setSlot(uint8_t slot);
	void write(uint8_t value);
	void writeFloat(float value);
private:
	uint8_t apin;
	
};

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SERIAL)
extern TONY_4_20mA_OUT Output4_20mA;
#endif

#endif
















