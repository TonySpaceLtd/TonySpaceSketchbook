
#include "TonyS_X1.h"
#include "TonySpace_LCDDisplay.h"
#include "TonySpace_TactSwitch.h"

#include <stdlib.h>
#include <stdio.h>

#include <Ticker.h>
#define Mouse_TICK_PERIOD 10
Ticker tick; /* timer for interrupt handler */

#define LV_HOR_RES_MAX  320
static lv_disp_draw_buf_t disp_buf;
#define MUX_BUF 10
static lv_color_t buf_1[LV_HOR_RES_MAX * MUX_BUF];
//static lv_color_t buf_2[LV_HOR_RES_MAX * MUX_BUF];

TonySpace_LCDST7789 *lcd_;

static void mouse_tick_handler(void);


void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
void my_input_read(lv_indev_drv_t * drv, lv_indev_data_t *data);

static uint8_t buzz_cnt=0;
lv_obj_t * cursor_obj;

uint16_t mouseX , mouseY;
uint8_t swSlot;
uint8_t lcdRot_;
bool mouseEN;
bool beep_;
lv_indev_t * my_indev;	

TonySpace_LCDDisplay Tony_Display;

TonySpace_LCDDisplay::TonySpace_LCDDisplay()
{
	mouseEN = false;
	beep_ = false;
}
void TonySpace_LCDDisplay::begin(uint8_t slot,uint8_t tfttype,uint8_t rotation)
{
	lcd.begin(slot,tfttype);
	lcd_ = &lcd;
	lcdRot_ = rotation;
	lcd.rotation(rotation);
	lvglInit();
	
}
bool TonySpace_LCDDisplay::enableMouse(uint8_t slot,bool enable,bool beep)
{
	bool ret; 
	swSlot = slot;
	mouseX 	= 0;
	mouseY	= 0;
	ret = TonyTactSW.begin(slot);
	if(!ret)
	{
		Serial.println(F("TonySpace TactSwitch : Error!!!!"));
		return false;
	}
	
	
	mouseEN = enable;
	beep_ = beep;
	
	LV_IMG_DECLARE(mouse_cursor_icon);
	lv_obj_t * cursor_obj = lv_img_create(lv_scr_act()); 
	lv_img_set_src(cursor_obj, &mouse_cursor_icon); 
	lv_indev_set_cursor(my_indev, cursor_obj);
	tick.attach_ms(Mouse_TICK_PERIOD, mouse_tick_handler);
	
	return ret;
}
void TonySpace_LCDDisplay::lvglInit()
{
	lv_init();
	lv_disp_draw_buf_init(&disp_buf, buf_1,NULL, LV_HOR_RES_MAX * MUX_BUF);
	
	static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = lcd.width();
    disp_drv.ver_res = lcd.height();
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &disp_buf;
    lv_disp_drv_register(&disp_drv);
	
	
	static lv_indev_drv_t indev_drv;
	lv_indev_drv_init(&indev_drv);      
	indev_drv.type = LV_INDEV_TYPE_POINTER;                
	indev_drv.read_cb =  my_input_read;     
	//lv_indev_drv_register(&indev_drv);
	my_indev = lv_indev_drv_register(&indev_drv);
	
	
	

	
	

    //LV_IMG_DECLARE(mouse_cursor_icon);
	//cursor_obj = lv_img_create(lv_scr_act()); 
	//lv_img_set_src(cursor_obj, &mouse_cursor_icon); 
	
	
}
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
	
	lcd_->writeBuf(area->x1, area->y1,area->x2 - area->x1 + 1,area->y2 - area->y1 + 1, (uint16_t*)color_p);
	lv_disp_flush_ready(disp);
}
static void mouse_tick_handler(void)
{
	//3 down =0, 2 up, left 4 , rigth 0 center 1 
	if(!mouseEN)
		return;
	
	uint8_t data_all = ~TonyTactSW.readAll();
	
	bool up,down,left,right,enter;
	if(swSlot <=6)
	{
		const uint8_t tact_Slot_L[4][5]={{4,0,3,2,1},{2,3,4,0,1},{0,4,2,3,1},{3,2,0,4,1}};//[lcdRotate][up,down,left,right,enter]
		up 		= data_all & (1<<tact_Slot_L[lcdRot_][0]);
		down 	= data_all & (1<<tact_Slot_L[lcdRot_][1]);	
		left 	= data_all & (1<<tact_Slot_L[lcdRot_][2]);	
		right 	= data_all & (1<<tact_Slot_L[lcdRot_][3]);
		enter 	= data_all & (1<<tact_Slot_L[lcdRot_][4]);			
		
		
	}
	else
	{
		const uint8_t tact_Slot_R[4][5]={{0,4,2,3,1},{3,2,0,4,1},{4,0,3,2,1},{2,3,4,0,1}};//[lcdRotate][up,down,left,right,enter]
		up 		= data_all & (1<<tact_Slot_R[lcdRot_][0]);
		down 	= data_all & (1<<tact_Slot_R[lcdRot_][1]);	
		left 	= data_all & (1<<tact_Slot_R[lcdRot_][2]);	
		right 	= data_all & (1<<tact_Slot_R[lcdRot_][3]);
		enter 	= data_all & (1<<tact_Slot_R[lcdRot_][4]);	
	}
		
	
	
	/*mouseX += !TonyTactSW.read(0);
	mouseX -= !TonyTactSW.read(4);
	
	mouseY += !TonyTactSW.read(3);
	mouseY -= !TonyTactSW.read(2);
	*/
	mouseX += right;
	mouseX -= left;
	
	mouseY += down;
	mouseY -= up;
	
	if(mouseX>lcd_->width()){mouseX=0;}
	if(mouseX<=0){mouseX=0;}
	if(mouseX>=lcd_->width()){mouseX=lcd_->width()-1;}
	
	if(mouseY>lcd_->height()){mouseY=0;}
	if(mouseY<=0){mouseY=0;}
	if(mouseY>=lcd_->height()){mouseY=lcd_->height()-1;}
	
	if(TonyTactSW.read(1))
	{
		TonyTactSW.offBuzzer();
		buzz_cnt=0;
	}
	else
	{
		if(buzz_cnt<21)
			buzz_cnt++;
	}
	if(buzz_cnt==1)
		TonyTactSW.onBuzzer();
	if(buzz_cnt>=20)
		TonyTactSW.offBuzzer();
	
		 
	//Serial.printf("Mouse : %d,%d\r\n",mouseX,mouseY);
  //lv_obj_set_pos(cursor_obj, mouseX, mouseY);
  
  //lv_tick_inc(Mouse_TICK_PERIOD);
}
void my_input_read(lv_indev_drv_t * drv, lv_indev_data_t *data)
{
	if(!mouseEN)
	{
		data->state = LV_INDEV_STATE_PR;
		return;
	}
	if(!TonyTactSW.read(1)) 
	{
		data->state = LV_INDEV_STATE_PR;
		//TonyTactSW.onBuzzer();
		//buzz_cnt++;
		//if(buzz_cnt!=0)
		//buzz_cnt =0;
		//prev_x = data->point.x;
		//prev_y = data->point.y;
	}
	else 
	{
		//data->point.x = prev_x;
		//data->point.y = prev_y;
		data->state = LV_INDEV_STATE_REL; 
	}
		data->point.x = mouseX;
		data->point.y = mouseY;
	
	
    
}











