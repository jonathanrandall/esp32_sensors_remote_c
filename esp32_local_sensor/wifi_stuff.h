#ifndef WIFI_STUFF_
#define WIFI_STUFF_

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "time.h"
#include "ssid_stuff.h" //i have my wife details here. So I don't accidently put them on github :)
#include "sensor_stuff.h"
// I've put mine in ssid_stuff.h file
// const char *ssid = "";
// const char *password = "";
unsigned long cnt=0;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
void handleRequest(AsyncWebServerRequest *request);
// Json Variable to Hold Sensor Readings

// Timer variables
// unsigned long lastTime = 0;
// unsigned long timerDelay = 30000;
// NTP server to use for time synchronization
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 36000; // Adjust according to your timezone (e.g., 3600 for GMT+1)
const int   daylightOffset_sec = 3600; // Adjust for daylight savings time if applicable


//const char* ntpServer = "pool.ntp.org";

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");


void initWiFi()
{
  
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print('.');
        delay(1000);
        
    }
    Serial.println(WiFi.localIP());
    server.on("/get_readings", HTTP_GET, handleRequest);

    server.begin();
}

void initTime(){

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  // timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  // timeClient.setTimeOffset(gmtOffset_sec);
}

// Variable to save current epoch time
unsigned long epochTime; 

// Function that gets current epoch time
// unsigned long 
String getTime() {
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    //Serial.println("Failed to obtain time");
    return(String(cnt));
    cnt++;
  }
  time(&now);
  // Serial.println(now);
  // Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  char timeStringBuff[64]; // Buffer to hold the formatted time
  strftime(timeStringBuff, sizeof(timeStringBuff), "%A, %B %d %Y %H:%M:%S", &timeinfo);
  String formattedTime = String(timeStringBuff);
  Serial.println(formattedTime);
  // return now;
  return formattedTime;
}


String get_date_string(){
  timeClient.update();
  epochTime = timeClient.getEpochTime();
  struct tm *ptm = gmtime ((time_t *)&epochTime); 
  String mth_pad = "";
  String day_pad = "";
  int monthDay = ptm->tm_mday;
  int currentMonth = ptm->tm_mon+1;
  int currentYear = ptm->tm_year+1900;

  if(monthDay < 10){ day_pad = "0";}
  if (currentMonth <10){  mth_pad = "0"; }
  
  return (String(currentYear) +String(mth_pad) + String(currentMonth) + String(day_pad) + String(monthDay));
}


void handleRequest(AsyncWebServerRequest *request)
{    
    
    /// get_readings?var=variable&val=10

    // String variable = request->arg("var");
    // String valValue = request->arg("val");
    
    String resp;
    resp = getTime();
    get_data = false; //this is a mutex hack
    resp = resp+","+String(bmp.readTemperature())+","+String(bmp.readAltitude())+","+String(bmp.readPressure());
    get_data=true;
    request->send(200, "text/plain", resp);

    
}


#endif