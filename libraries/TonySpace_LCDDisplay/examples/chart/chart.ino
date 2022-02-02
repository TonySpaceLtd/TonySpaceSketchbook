#include "TonyS_X1.h"
#include "TonySpace_LCDDisplay.h"

unsigned long previousMillis = 0;
const long interval = 1000;
RTC_DS3231 rtc;
static lv_obj_t * chart1;
static lv_chart_series_t * ser1;

void setup() {
  Serial.begin(115200);
  Tony.begin();  //----  begin Library
  
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  Tony_Display.begin(SLOT1, TFT_240_320, 1);
  lv_example_chart();
}
void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) 
  {
    lv_chart_set_next_value(chart1, ser1, rtc.getTemperature());
    previousMillis = millis();
  }
  lv_timer_handler();
}
void lv_example_chart(void)
{
   chart1 = lv_chart_create(lv_scr_act());
    lv_obj_set_size(chart1, 200, 150);
    lv_obj_center(chart1);
    lv_chart_set_type(chart1, LV_CHART_TYPE_LINE);
    lv_chart_set_div_line_count(chart1, 5, 7);
    lv_chart_set_update_mode(chart1, LV_CHART_UPDATE_MODE_CIRCULAR);

    ser1 = lv_chart_add_series(chart1, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
}
