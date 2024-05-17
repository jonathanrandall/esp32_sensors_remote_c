/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BMP280 Breakout
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

// #include "sensor_stuff.h"
#include "OLED_stuff.h"
// #include "wifi_stuff.h"

#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"



void setup() {
  
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector
  Serial.begin(115200);
  // Wire.begin();
  initWiFi();
  init_bmp280();
  oled_setup_stuff();
  initTime();
  
  
}

void loop() {
    displaydata();
    // Serial.print(F("Temperature = "));
    // Serial.print(bmp.readTemperature());
    // Serial.println(" *C");

    // Serial.print(F("Pressure = "));
    // Serial.print(bmp.readPressure());
    // Serial.println(" Pa");

    // Serial.print(F("Approx altitude = "));
    // Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    // Serial.println(" m");
    String tm = getTime();
    Serial.println(tm);
    // Serial.println();

    delay(1000);
}
