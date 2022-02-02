#ifndef TonySpace_LCDST7789_h
#define TonySpace_LCDST7789_h

#include "Arduino.h"
#include <SPI.h>

#define LCD_CLK 14000000 

#define TFT_240_240		0 
#define TFT_240_320		1

#define TFT_BLACK       0x0000      /*   0,   0,   0 */
#define TFT_NAVY        0x000F      /*   0,   0, 128 */
#define TFT_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define TFT_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define TFT_MAROON      0x7800      /* 128,   0,   0 */
#define TFT_PURPLE      0x780F      /* 128,   0, 128 */
#define TFT_OLIVE       0x7BE0      /* 128, 128,   0 */
#define TFT_LIGHTGREY   0xD69A      /* 211, 211, 211 */
#define TFT_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define TFT_BLUE        0x001F      /*   0,   0, 255 */
#define TFT_GREEN       0x07E0      /*   0, 255,   0 */
#define TFT_CYAN        0x07FF      /*   0, 255, 255 */
#define TFT_RED         0xF800      /* 255,   0,   0 */
#define TFT_MAGENTA     0xF81F      /* 255,   0, 255 */
#define TFT_YELLOW      0xFFE0      /* 255, 255,   0 */
#define TFT_WHITE       0xFFFF      /* 255, 255, 255 */
#define TFT_ORANGE      0xFDA0      /* 255, 180,   0 */
#define TFT_GREENYELLOW 0xB7E0      /* 180, 255,   0 */
#define TFT_PINK        0xFE19      /* 255, 192, 203 */ //Lighter pink, was 0xFC9F      
#define TFT_BROWN       0x9A60      /* 150,  75,   0 */
#define TFT_GOLD        0xFEA0      /* 255, 215,   0 */
#define TFT_SILVER      0xC618      /* 192, 192, 192 */
#define TFT_SKYBLUE     0x867D      /* 135, 206, 235 */
#define TFT_VIOLET      0x915C      /* 180,  46, 226 */


class TonySpace_LCDST7789
{
public:
	TonySpace_LCDST7789();
	void begin(uint8_t slot,uint8_t tfttype);
	void init();
	void writecommand(uint8_t c);
	void writedata(uint8_t d);
	void invert(bool en);
	void setWindow(size_t x0, size_t y0, size_t x1, size_t y1);
	void fillRec(size_t x,size_t y,size_t w,size_t h,uint16_t color);
	void rotation(uint8_t m);
	void backLight(bool en);
	size_t width(){return _width;};
	size_t height(){return _height;};
	void writeBuf(size_t x,size_t y,size_t w,size_t h,uint16_t *buf);
private:
	SPIClass *lcd_vSPI = NULL;
	uint8_t pin_DC,pin_BL,pin_CS_sel,pin_RST,pin_CS;
	uint8_t tft_type_;
	size_t lcd_w,lcd_h;
	size_t _width,_height;
	size_t colstart,rowstart;
	
  
};




#endif
