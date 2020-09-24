#include <Arduino.h>

#include <Arduino.h>
#include <U8g2lib.h>

#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  //M0/ESP32/ESP8266/mega2560/Uno/Leonardo

void setup(void) {
  u8g2.begin();    //init
  u8g2.enableUTF8Print();        // Enable UTF8 support for Arduino print（）function.
}

void loop(void) 
{
  /*
   *The font takes up a lot of memory, so please use it with caution. Get your own Chinese encode for displaying only several fixed words.
   *Display by drawXBM or use controller with larger memory
   *Chinese Font：require a controller with larger memory than Leonardo  
   *Japanese Font：require a controller with larger memory than UNO
   *Korean Font：Arduino INO files of the current version do not support for displaying Korean, but it can displayed properly on the Screen
  */
u8g2.setFont(u8g2_font_maniac_tf); 
  u8g2.setFontDirection(0);  
  u8g2.firstPage();
  do {
    u8g2.setCursor(/* x=*/0, /* y=*/15);    //Define the cursor of print function, any output of the print function will start at this position.
    u8g2.print("Hello World!");
  } while ( u8g2.nextPage() );
  delay(1000);
}