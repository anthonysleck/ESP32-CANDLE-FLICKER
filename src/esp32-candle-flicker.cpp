// includes
#include "config.h"

void rootServer()
{
    // start ElegantOTA
    AsyncElegantOTA.begin(&server);
    server.begin();
    debugln("HTTP server started");
}

void setup()
{
    // start serial
    Serial.begin(115200);
    delay(5000);

    // sketch information
    debugln("Created by Anthony Sleck");
    debugln("Email at anthony.sleck@gmail.com");
    debug("Version ");
    debugln(VER);
    debug("Build Code ");
    debugln(VER_BUILD);
    debug("Github: ");
    debugln(firmwareLink);

    // start WiFi
    debugln("Starting WIFI connection!");
    debugln();
    debug("Connecting to ");
    debugln(ssid);
    WiFi.begin(ssid, password);
    debugln("");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        debug(".");
    }

    debugln("");
    debug("Connected to ");
    debugln(ssid);
    debug("IP address: ");
    debugln(WiFi.localIP());

    // start server
    rootServer();

    ledcSetup(ledChannel, freq, resolution); // configure LED PWM functionalitites
    ledcAttachPin(ledPin, ledChannel);       // attach the channel to the GPIO to be controlled
}

void loop()
{
    rn = random(1, 255); // create a random number to be used as a PWM value
    Serial.println(rn);
    ledcWrite(ledChannel, rn);
    delay(100);
}