#include "TonyS_X1.h"
#include "TonySpace_LCDDisplay.h"
/*
 * ############### Convert Font ###############
 * - Open web site https://lvgl.io/tools/imageconverter
 * - Image file : Browse Image File
 * - File name(s) : Set Output File Name
 * - Color format : True Color(normal Image) , True Color With Alpha(Transparent Image) 
 * - Output format : C array
 * - Click Convert
 * - copy Imagexxx.c to your project folder 
 */
unsigned long previousMillis = 0;
const long interval = 20;
lv_obj_t * img;
void setup() {
  Serial.begin(115200);
  Tony.begin();  //----  begin Library
  Tony_Display.begin(SLOT1, TFT_240_320, 1);
  
  LV_IMG_DECLARE(TonySpaceLogo);
  img = lv_img_create(lv_scr_act());
  lv_img_set_src(img, &TonySpaceLogo);
  //lv_img_set_pivot(img, 0, 0);
  lv_obj_center(img);
}
uint16_t zoom=256;
uint16_t  rotate=0;
void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) 
  {
    lv_img_set_zoom(img,zoom--); // normal Image =256 ,0-256 zoom out,256-512 zoom in 
    lv_img_set_angle(img, (rotate+=2)*10); // 0-36000 ;ex 45.8° set 458.
    if(zoom==20)
      zoom =256;
    if(rotate==360)
      rotate=0;
    previousMillis = millis();
  }
  lv_timer_handler();
}
