
#ifndef TonySpace_4_20mA_Input_h
#define TonySpace_4_20mA_Input_h

#include "Arduino.h"
#include <movingAvg.h>

#define AVG_NUM 20
/*### 4-20mA input Test ###
	read Data	real Data (/100 = mA)
	5			0
	207			100
	408			200
	611			300
	813			400
	1015		500
	1217		600
	1419		700
	1622		800
	1824		900
	2026		1000
	2229		1100
	2431		1200
	2634		1300
	2837		1400
	3039		1500
	3242		1600
	3445		1700
	3648		1800
	3850		1900
	4053		2000

Polynomial 2'order
	y = -3E-07x2 + 0.4953x - 2.3869
*/
class TONY_4_20mA_IN
{
public:
	TONY_4_20mA_IN();
	void setSlot(uint8_t slot);
	int readADC(void);
	float read(void);
	
private:
	uint8_t apin;
	movingAvg *avg;
	
};

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SERIAL)
extern TONY_4_20mA_IN Input4_20mA;
#endif

#endif
















