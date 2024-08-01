/*
Board ESP32S3 Dev Module
Flash size 8Mb
OPI PSRAM

board manager : esp32 by ESpressif 3.0.3
Libraries :
- lvgl by kisvegador 8.3.6
- LovyanGFX by lovyan03 1.1.16
*/

#include "displayStuff.h"



void setup() {
  Serial.begin(115200);

  tft.begin();

  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * 10);
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touch_read;
  lv_indev_drv_register(&indev_drv);

  ui_init();

  Serial.println("setup ok");
}




void loop() {
  lv_timer_handler();
  delay(5);
}

//SquareLine functions to add manually if "dont export function" checked


