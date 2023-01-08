#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipeOut = 0xE8E8F0F0E1LL;
#define DHTPIN 3
RF24 radio(9, 10); //  CN and CSN  pins of nrf

// struct MyData {
//     byte h;
//     byte t;
// };

MyData data;
void setup_nrf() {
    radio.begin();
    radio.setChannel(100);
    radio.setAutoAck(false);
    radio.setDataRate(RF24_250KBPS);
    radio.openWritingPipe(pipeOut);
}

void send_data(MyData data) {
    if (isnan(data.h) || isnan(data.t)){
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }
    Serial.println("Data Sent !");
    radio.write(&data, sizeof(MyData));

    delay(50);
}