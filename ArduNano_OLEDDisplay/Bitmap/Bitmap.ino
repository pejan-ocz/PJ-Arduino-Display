/*
  Bitmap.pde
  Show simple bitmap

*/

#include "U8glib.h"

// Hello World - for use with Monochrome OLEDs
//**************************************************
// inicializace OLED displeje z knihovny U8glib
// Change this constructor to match your display!!!
//U8GLIB_SSD1306_128X64 mujOled(U8G_I2C_OPT_NONE);
U8GLIB_SSD1306_ADAFRUIT_128X64 u8g(U8G_I2C_OPT_NONE);  //konečně funkční
//**************************************************


const uint8_t rook_bitmap[] PROGMEM = {
  0x00,         // 00000000 
  0x55,         // 01010101
  0x7f,          // 01111111
  0x3e,         // 00111110
  0x3e,         // 00111110 
  0x3e,         // 00111110
  0x3e,         // 00111110 
  0x7f           // 01111111
};

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.drawBitmapP( 0, 0, 1, 18, rook_bitmap);
}

void setup(void) {
}

void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(1000);
}

