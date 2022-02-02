
#include "TonySpace_LCDST7789.h"
#include "TonyS_X1.h"
#include "ST7789Define.h"
#include <stdlib.h>
#include <stdio.h>

uint8_t TFT_MAD_COLOR_ORDER;


TonySpace_LCDST7789::TonySpace_LCDST7789()
{
	colstart=0;
	rowstart=0;
}
void TonySpace_LCDST7789::begin(uint8_t slot,uint8_t tfttype)
{
	//uint8_t pin_DC,pin_CS,pin_RST;
	//pin_CS_sel
	//[slot][dc,rst,selCS,BL]
	//Serial.println(slot);
	bool invertFlag;
	
	static const uint8_t pin_240_240[13][4]={
		{0,0,0,0},\
		{IO0,AIO0,IO10,AIO10},\
		{IO1,AIO1,IO11,AIO11},\
		{IO2,AIO2,IO8,AIO8},\
		{IO3,AIO3,IO9,AIO9},\
		{IO4,AIO4,IO6,AIO6},\
		{IO5,AIO5,IO7,AIO7},\
		{IO6,AIO6,IO4,AIO4},\
		{IO7,AIO7,IO5,AIO5},\
		{IO8,AIO8,IO2,AIO2},\
		{IO9,AIO9,IO3,AIO3},\
		{IO10,AIO10,IO0,AIO0},\
		{IO11,AIO11,IO1,AIO1}
	};
	//[slot][dc,rst,selCS,BL]
	static const uint8_t pin_240_320[13][4]={
		{0,0,0,0},\
		{IO10,IO2,IO0,IO8},\
		{IO11,IO3,IO1,IO9},\
		{IO8,IO4,IO2,IO6},\
		{IO9,IO5,IO3,IO7},\
		{0,0,0,0},\
		{0,0,0,0},\
		{IO4,IO8,IO6,IO2},\
		{IO5,IO3,IO7,IO9},\
		{IO2,IO10,IO8,IO10},\
		{IO3,IO1,IO9,IO11},\
		{0,0,0,0},\
		{0,0,0,0}
	};
	
	pin_CS = IO_CS;
	Tony.pinMode(pin_CS, OUTPUT);
	Tony.digitalWrite(pin_CS, HIGH);
	
	tft_type_ = tfttype;
	if(tfttype==TFT_240_240)
	{
		pin_DC = pin_240_240[slot][0];
		pin_RST = pin_240_240[slot][1];
		pin_CS_sel = pin_240_240[slot][2];
		pin_BL = pin_240_240[slot][3];
		
		lcd_w = 240;
		lcd_h = 240;
		
		Tony.pinMode(pin_DC, OUTPUT);	
		Tony.digitalWrite(pin_DC, HIGH);
		
		Tony.pinMode(pin_RST, OUTPUT);	
		Tony.digitalWrite(pin_RST, HIGH);
		
		Tony.pinMode(pin_CS_sel, OUTPUT);	
		Tony.digitalWrite(pin_CS_sel, HIGH);
		Tony.pinMode(pin_BL, OUTPUT);
		Tony.digitalWrite(pin_BL, LOW);
		TFT_MAD_COLOR_ORDER= TFT_MAD_BGR;
		invertFlag = true;
		
	}
	
	if(tfttype==TFT_240_320)
	{
		pin_DC = pin_240_320[slot][0];
		pin_RST = pin_240_320[slot][1];
		pin_CS_sel = pin_240_320[slot][2];
		pin_BL = pin_240_320[slot][3];
		
		lcd_w = 240;
		lcd_h = 320;
		
		Tony.pinMode(pin_DC, OUTPUT);	
		Tony.digitalWrite(pin_DC, HIGH);
		
		Tony.pinMode(pin_RST, OUTPUT);	
		Tony.digitalWrite(pin_RST, HIGH);
		
		Tony.pinMode(pin_CS_sel, OUTPUT);	
		Tony.digitalWrite(pin_CS_sel, HIGH);
		Tony.pinMode(pin_BL, OUTPUT);
		Tony.digitalWrite(pin_BL, LOW);
		TFT_MAD_COLOR_ORDER = TFT_MAD_BGR;
		invertFlag = false;
	}
	
	//lcd_vSPI = new SPIClass(VSPI);
	//SCLK = 18, MISO = 19, MOSI = 23, SS = 5
	//lcd_vSPI->begin();
	//pinMode(lcd_vSPI->pinSS(), OUTPUT); //VSPI SS
	//pinMode(pin_CS, OUTPUT); //VSPI SS
	SPI.begin();
	init();
	invert(invertFlag);
	rotation(0);
	//setWindow(0, 0, 239, 239);
	fillRec(0,0,lcd_w,lcd_h,0xFFFF);
	backLight(true);
	
	
}
void TonySpace_LCDST7789::init()
{
	Tony.digitalWrite(pin_CS_sel, LOW);
	
	Tony.digitalWrite(pin_RST, LOW);
	delay(200);
	Tony.digitalWrite(pin_RST, HIGH);
	delay(200);
	
	
	writecommand(ST7789_SLPOUT);
	delay(120);
	writecommand(ST7789_NORON);  
	writecommand(ST7789_MADCTL);
	writedata(TFT_MAD_COLOR_ORDER); // RGB
	
	writecommand(0xB6);
	writedata(0x0A);
	writedata(0x82);
	
	writecommand(ST7789_RAMCTRL);
	writedata(0x00);
	writedata(0xE0);
	
	writecommand(ST7789_COLMOD);
	writedata(0x55);
	delay(10);
	
	writecommand(ST7789_PORCTRL);
	writedata(0x0c);
	writedata(0x0c);
	writedata(0x00);
	writedata(0x33);
	writedata(0x33);

	writecommand(ST7789_GCTRL);     
	writedata(0x35);
	
	writecommand(ST7789_VCOMS);
	writedata(0x28);		

	writecommand(ST7789_LCMCTRL);
	writedata(0x0C);

	writecommand(ST7789_VDVVRHEN);
	writedata(0x01);
	writedata(0xFF);

	writecommand(ST7789_VRHS);      
	writedata(0x10);

	writecommand(ST7789_VDVSET);
	writedata(0x20);

	writecommand(ST7789_FRCTR2);
	writedata(0x0f);

	writecommand(ST7789_PWCTRL1);
	writedata(0xa4);
	writedata(0xa1);

  writecommand(ST7789_PVGAMCTRL);
  writedata(0xd0);
  writedata(0x00);
  writedata(0x02);
  writedata(0x07);
  writedata(0x0a);
  writedata(0x28);
  writedata(0x32);
  writedata(0x44);
  writedata(0x42);
  writedata(0x06);
  writedata(0x0e);
  writedata(0x12);
  writedata(0x14);
  writedata(0x17);

  writecommand(ST7789_NVGAMCTRL);
  writedata(0xd0);
  writedata(0x00);
  writedata(0x02);
  writedata(0x07);
  writedata(0x0a);
  writedata(0x28);
  writedata(0x31);
  writedata(0x54);
  writedata(0x47);
  writedata(0x0e);
  writedata(0x1c);
  writedata(0x17);
  writedata(0x1b);
  writedata(0x1e);

  writecommand(ST7789_INVON);
  //writecommand(ST7789_INVOFF);

  writecommand(ST7789_CASET);    
  writedata(0x00);
  writedata(0x00);
  writedata(0x00);
  writedata(0xE5);   

  writecommand(ST7789_RASET);    
  writedata(0x00);
  writedata(0x00);
  writedata(0x01);
  writedata(0x3F);   
 
  delay(120);
  writecommand(ST7789_DISPON);    //Display on
  delay(120);
  Tony.digitalWrite(pin_CS_sel, HIGH);
}
void TonySpace_LCDST7789::writecommand(uint8_t c)
{
	//Tony.digitalWrite(pin_CS_sel, LOW);
	//lcd_vSPI->beginTransaction(SPISettings(LCD_CLK, MSBFIRST, SPI_MODE3));
	SPI.beginTransaction(SPISettings(LCD_CLK, MSBFIRST, SPI_MODE3));
	Tony.digitalWrite(pin_DC,LOW);
	digitalWrite(pin_CS, LOW);
	SPI.transfer(c);
	digitalWrite(pin_CS, HIGH); 
	//lcd_vSPI->endTransaction();
	SPI.endTransaction();
	Tony.digitalWrite(pin_DC, HIGH);
	//Tony.digitalWrite(pin_CS_sel, HIGH);
}
void TonySpace_LCDST7789::writedata(uint8_t d)
{
	//Tony.digitalWrite(pin_CS_sel, LOW);
	SPI.beginTransaction(SPISettings(LCD_CLK, MSBFIRST, SPI_MODE3));
	Tony.digitalWrite(pin_DC,HIGH);
	digitalWrite(pin_CS, LOW);
	SPI.transfer(d);
	digitalWrite(pin_CS, HIGH); 
	SPI.endTransaction();
	//Tony.digitalWrite(pin_CS_sel, HIGH);
}
void TonySpace_LCDST7789::invert(bool en)
{
	Tony.digitalWrite(pin_CS_sel, LOW);
	writecommand(en?ST7789_INVON:ST7789_INVOFF);
	Tony.digitalWrite(pin_CS_sel, HIGH);
}
void TonySpace_LCDST7789::backLight(bool en)
{
	Tony.digitalWrite(pin_BL,en);
}
void TonySpace_LCDST7789::rotation(uint8_t m)
{
	Tony.digitalWrite(pin_CS_sel, LOW);
	writecommand(TFT_MADCTL);
	uint8_t rotation = m;
	
	
	if(tft_type_ == TFT_240_240)
	{
		rotation =  m+1;
		if(rotation==4)
			rotation=0;
	}
	
	 switch (rotation) 
	 {
		case 0:
			writedata(TFT_MAD_COLOR_ORDER);
			_width  = lcd_w;
			_height = lcd_h;
			colstart = 0;
			rowstart = 0;
		break;
		case 1:
			 writedata(TFT_MAD_MX | TFT_MAD_MV | TFT_MAD_COLOR_ORDER);
			_width  = lcd_h;
			_height = lcd_w;
			colstart = 0;
			rowstart = 0;

		break;
		case 2:
			writedata(TFT_MAD_MX | TFT_MAD_MY | TFT_MAD_COLOR_ORDER);
			_width  = lcd_w;
			_height = lcd_h;
			colstart = 0;
			rowstart = (tft_type_ == TFT_240_240)?80:0 ;

		break;
		case 3:
			writedata(TFT_MAD_MV | TFT_MAD_MY | TFT_MAD_COLOR_ORDER);
			_width  = lcd_h;
			_height = lcd_w;
			colstart = (tft_type_ == TFT_240_240)?80:0 ;
			rowstart = 0;

		break;
			
	 }
	 Tony.digitalWrite(pin_CS_sel, HIGH);
}
void TonySpace_LCDST7789::setWindow(size_t x0, size_t y0, size_t x1, size_t y1)
{
	if(tft_type_ == TFT_240_240)
	{
		x0+=colstart;
		x1+=colstart;
		y0+=rowstart;
		y1+=rowstart;
	}
	
	Tony.digitalWrite(pin_CS_sel, LOW);
	writecommand(ST7789_CASET);
	writedata(x0>>8);
	writedata(x0);
	writedata(x1>>8);
	writedata(x1);
	
	writecommand(ST7789_RASET);
	writedata(y0>>8);
	writedata(y0);
	writedata(y1>>8);
	writedata(y1);
	
	writecommand(ST7789_RAMWR);
	Tony.digitalWrite(pin_CS_sel, HIGH);
	
}
void TonySpace_LCDST7789::fillRec(size_t x,size_t y,size_t w,size_t h,uint16_t color)
{
	
	setWindow(x, y, x+w-1, y+h-1);
	Tony.digitalWrite(pin_CS_sel, LOW);	
	SPI.beginTransaction(SPISettings(LCD_CLK, MSBFIRST, SPI_MODE3));
	
	Tony.digitalWrite(pin_DC,HIGH);
	
	digitalWrite(pin_CS, LOW);
	
	for(size_t i = 0; i < w; i++)
	{
		for(size_t j = 0; j < h; j++)
		{
			SPI.transfer(( color >> 8) & 0xff);
			SPI.transfer(color);
		}
   }
    digitalWrite(pin_CS, HIGH); 
	SPI.endTransaction();
	Tony.digitalWrite(pin_CS_sel, HIGH);
}
void TonySpace_LCDST7789::writeBuf(size_t x,size_t y,size_t w,size_t h,uint16_t *buf)
{
	if((x >= _width) || (y >= _height)) return;
	if((x + w - 1) >= _width)  w = _width  - x;
	if((y + h - 1) >= _height) h = _height - y;
  
	setWindow(x, y, x+w-1, y+h-1);
	
	Tony.digitalWrite(pin_CS_sel, LOW);	
	
	
	SPI.beginTransaction(SPISettings(LCD_CLK, MSBFIRST, SPI_MODE3));
	
	
	Tony.digitalWrite(pin_DC,HIGH);
	digitalWrite(pin_CS, LOW);
	
	/*for(size_t i=0;i<(w*h);i++)
	{
		//lcd_vSPI->transfer(( buf[i] >> 8) & 0xff);
		//lcd_vSPI->transfer(buf[i]& 0xff);
		 lcd_vSPI->transfer16(buf[i]);
	}
	*/
	
	SPI.writePixels(buf,w*h*2);
	
	digitalWrite(pin_CS, HIGH); 
	
	SPI.endTransaction();
	Tony.digitalWrite(pin_CS_sel, HIGH);
}














