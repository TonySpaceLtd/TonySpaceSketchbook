
#ifndef TonySpace_LCDDisplay_h
#define TonySpace_LCDDisplay_h

#include "Arduino.h"
#include "TonySpace_LCDST7789.h"
#include "lvgl/lvgl.h"

class TonySpace_LCDDisplay
{
public:
	TonySpace_LCDDisplay();
	void begin(uint8_t slot,uint8_t tfttype,uint8_t rotation=0);
	bool enableMouse(uint8_t slot,bool enable = true,bool beep = true);
	
	TonySpace_LCDST7789 lcd;
	void lvglInit();
	
	
private:
	
	
  
};

extern TonySpace_LCDDisplay Tony_Display;


#endif
















