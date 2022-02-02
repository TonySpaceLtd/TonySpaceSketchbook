#include "TonyS_X1.h"
#include "TonySpace_LCDDisplay.h"
/*
 * ############### Convert Font ###############
 * -Open web site https://lvgl.io/tools/fontconverter
 * - Name : font name
 * - Size : set font size
 * - Bpp : 1,2,4 bit-per-pixel
 * - TTF/WOFF file : upload File Font  
 * - Range : 0x0020-0x007F,0x0E00-0x0E7F // 0x20-0x7F =  Unicode character Basic Latin(Eng) , 0x0E00-0x0E7F Unicode character Thai
 * - Click Convert
 * - copy fontxxx.c to your project folder 
 */

void setup() {
  Serial.begin(115200);
  Tony.begin();  //----  begin Library
  Tony_Display.begin(SLOT1, TFT_240_320, 1);
  
  LV_FONT_DECLARE(THSarabun24);
  static lv_style_t style;
  lv_style_init(&style);
  lv_style_set_text_font(&style, &THSarabun24); 
  lv_style_set_text_color(&style,lv_palette_main(LV_PALETTE_BLUE));

  lv_obj_t *label= lv_label_create(lv_scr_act());
  //lv_obj_set_pos(label, 20, 20);
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
  lv_obj_add_style(label, &style, 0);
  lv_label_set_text(label, "Hello สวัสดี");
}

void loop() {
  
  lv_timer_handler();
}
