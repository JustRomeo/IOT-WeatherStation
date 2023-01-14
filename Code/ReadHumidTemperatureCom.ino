#include <dht.h>

#define dht_apin A0
 
dht DHT;

// struct MyData {
//     byte h;
//     byte t;
// };

void print_serial() {
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C°");   
}

MyData getData() {
    DHT.read11(dht_apin);

    MyData data;

    data.h = DHT.humidity;
    data.t = DHT.temperature;
    return data;
}

