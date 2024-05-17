#ifndef OLED_STUFF_
#define OLED_STUFF_

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
#include "wifi_stuff.h"
// #include "sensor_stuff.h" included in wifi_stuff.h

#define SCREEN_WIDTH 128 //128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


//Adafruit_SSD1306 display(OLED_RESET);

String dataMessage;
String f_out;
unsigned long previousMillis = 0;
unsigned long interval_ = 3000;

void oled_setup_stuff(){
  if(!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  oled.setTextColor(WHITE);
  oled.setTextSize(2);
  oled.setCursor(0, 0);
  // oled.println(WiFi.localIP());
  delay(3000);
}



void displaydata() {
  if (get_data){
    temperature = String(bmp.readTemperature())+ " *C";
    altitude = String(bmp.readAltitude(1013.25)) + " m";
  }
  
  oled.clearDisplay();
  oled.setFont(&FreeSans9pt7b);
  oled.setTextColor(WHITE);
  oled.setTextSize(1);
  oled.setCursor(0, 17);

  oled.println(temperature);

  // oled.setCursor(35, 17);
  // oled.println(" *C");
  // oled.setCursor(50, 17);
  // // oled.println(current_mA);
  // oled.setCursor(95, 17);
  // oled.println("mA");
  oled.setCursor(0, 37);
  oled.println(altitude);
  // oled.setCursor(65, 37);
  // oled.println("mW");
  oled.setCursor(0, 57);
  oled.println(WiFi.localIP());
  // oled.setCursor(65, 57);
  // oled.println("mWh");
  oled.display();
}

#endif