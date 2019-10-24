/*
   ESP32 Flickering Candle
   Description:
   -Simulation of a flickering candle using an ESP32 and the builtin LED
   Notes:
   -N/A
   Components:
   -ESP32S
   Connections:
   -N/A
   Contact Info:
   email - anthony.sleck@gmail.com
   github - https://github.com/anthonysleck
   Changelog:
   0.0.1 - ars - new code
*/

//constants-variables
const int ledPin = 2;
const String ver = "esp32-candle-flicker - v0.0.1";
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
int rn;

void setup() {
  Serial.begin(115200);
  
  //print sketch information
  Serial.println("Created by Anthony Sleck");
  Serial.println("Email at anthony.sleck@gmail.com");
  Serial.println(ver);
  Serial.println("github - https://github.com/anthonysleck");


  ledcSetup(ledChannel, freq, resolution); //configure LED PWM functionalitites
  ledcAttachPin(ledPin, ledChannel); //attach the channel to the GPIO to be controlled
}

void loop() {
  rn = random(1, 255); //create a random number to be used as a PWM value
  Serial.println(rn);
  ledcWrite(ledChannel, rn);
  delay(100);
}
