/*
   ESP32 Candle Flicker SImulation
   Description:
     A simple ESP32 to flicker and LED and simulate a flickering candle on the builtin LED.
   Notes:
   -Coming Soon!
   Contact Info:
   email - anthony.sleck@gmail.com
   web - anthony.sleck.us
   github - https://github.com/anthonysleck
   Changelog:
   0.1 - new code
   Contact Info:
   email - anthony.sleck@gmail.com
   web - anthony.sleck.us
   github - https://github.com/anthonysleck
*/

#ifndef config_h
#define config_h

// system versioning
#define VER "0.1"
#define VER_BUILD "060123"
#define email "anthony.sleck@gmail.com"
#define firmwareLink "https://github.com/anthonysleck/"

// common includes
#include <Arduino.h>
#include <AsyncElegantOTA.h>
//#include <AsyncTCP.h>
//#include <ESPAsyncWebServer.h>
//#include <HTTPClient.h>
//#include "webpages.h"
#include <WiFi.h>
#include <WiFiClient.h>

// debugging
#define DEBUG 1     // set to "0" to disable serial debugging

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif

// LED settings
const int ledPin = 2;
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
int rn;

// server configs
AsyncWebServer server(80);

// WiFi settings
const char *ssid = "********";        // enter your SSID here
const char *password = "********";    // enter password here

#endif