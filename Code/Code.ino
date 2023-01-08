#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include <LittleFS.h>

#ifndef APSSID
#define APSSID "Env. Module"
#define APPSK "password"
#endif

bool apMode = true;
String ssid = APSSID;
String password = APPSK;

ESP8266WebServer server(80);

void setup() {
    delay(1000);
    Serial.begin(115200);

    if (!LittleFS.begin()) {
        Serial.println("Error while mounting LittleFS");
        return;
    }

    setupAP();
    init_lcd();

    server.on("/", handleRoot);
    server.on("/connect", handleConnect);
    // Rajout des liens pingables
    
    server.begin();

    Serial.print("HTTP Server started");
}

void loop() {
    server.handleClient();
    display_lcd();

    delay(250);
    // Execution du code Arduino
}