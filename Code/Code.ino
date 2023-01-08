// #include <ESP8266WiFi.h>
// #include <WiFiClient.h>
// #include <ESP8266WebServer.h>
// #include <FS.h>
// #include <LittleFS.h>

// #ifndef APSSID
// #define APSSID "Env. Module"
// #define APPSK "password"
// #endif

struct MyData {
    byte h;
    byte t;
};

// WIFI =======================
// bool apMode = true;
// String ssid = APSSID;
// String password = APPSK;
// ESP8266WebServer server(80);

void setup() {
    delay(1000);
    Serial.begin(115200);

    // if (!LittleFS.begin()) {
    //    Serial.println("Error while mounting LittleFS");
    //    return;
    // }

    // setupAP();
    setup_nrf();
    init_lcd();

    // server.on("/", handleRoot);
    // server.on("/connect", handleConnect);
    // Rajouter plus de liens ici
    // server.begin();
    // Serial.print("HTTP Server started");
}

void loop() {
    // server.handleClient();
    MyData data = getData();

    display_lcd(data);
    send_data(data);
    delay(250);
}
