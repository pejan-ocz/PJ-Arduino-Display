// OLED displej přes I2C řadič SSD1306
// připojení knihovny U8glib
#include "U8glib.h"

// Hello World - for use with Monochrome OLEDs
//**************************************************
// inicializace OLED displeje z knihovny U8glib
// Change this constructor to match your display!!!
//U8GLIB_SSD1306_128X64 mujOled(U8G_I2C_OPT_NONE);
U8GLIB_SSD1306_ADAFRUIT_128X64 mujOled(U8G_I2C_OPT_NONE);  //konečně funkční
//**************************************************

uint8_t pozice = 0;  //pro rolování textu

void setup() {
  // put your setup code here, to run once:
  mujOled.setFont(u8g_font_unifont);
  mujOled.setColorIndex(1); // Instructs the display to draw with a pixel on. 

}

void loop() {
  // put your main code here, to run repeatedly:
mujOled.firstPage();
  do {  
    draw();
  } while( mujOled.nextPage() );

  delay(500); 
}

void draw(){
  // nastavení písma, toto písmo umožní vypsat
  // přibližně 15x4 znaků
  mujOled.setFont(u8g_font_unifont);
  // nastavení pozice výpisu v pixelech
  // souřadnice jsou ve tvaru x, y
  // souřadnice 0, 0 je v levém horní rohu
  // OLED displeje, maximum je 128, 64
  mujOled.setPrintPos(5, 30);
  // výpis textu na zadanou souřadnici
  //mujOled.println("- Arduino test -");
  mujOled.print("2017");

  mujOled.drawStr( 5, 60, "Test");
  mujOled.drawCircle(60, 30, 10);
  mujOled.drawDisc(80, 30, 10);
  mujOled.drawLine(90, 20, 110, 40);
  mujOled.drawBox(50, 50, 20, 10);
  mujOled.drawFrame(1, 1, 127, 63);
      
}


