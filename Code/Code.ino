#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct MyData {
    byte h;
    byte t;
};

void setup() {
    delay(1000);
    Serial.begin(115200);

    setup_nrf();
    init_lcd();
}

void loop() {
    MyData data = getData();

    display_lcd(data);
    send_data(data);
    delay(250);
}
