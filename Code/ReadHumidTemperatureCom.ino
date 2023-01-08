#include <dht.h>
#include <LiquidCrystal_I2C.h>

#define dht_apin A0
 
dht DHT;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void print_serial() {
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C°");   
}

void init_lcd() {
    lcd.init();
    lcd.backlight();

    Serial.begin(9600);
    delay(1500);
}

void display_lcd() {
    DHT.read11(dht_apin);

    // print_serial();

    // Print Temperature on LCD
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    if ((int)DHT.temperature < 10)
        lcd.setCursor(7, 0);
    else
        lcd.setCursor(6, 0);
    lcd.print((int)DHT.temperature);
    lcd.setCursor(8, 0);
    lcd.print("*c");

    // Print Humidity on LCD
    lcd.setCursor(0, 1);
    lcd.print("Humi: ");
    if ((int)DHT.humidity < 10)
        lcd.setCursor(7, 1);
    else
        lcd.setCursor(6, 1);
    lcd.print((int)DHT.humidity);
    lcd.setCursor(8, 1);
    lcd.print("%");

    // Print Battery
    /* float percent = battery();

    if (percent < 10)
        lcd.setCursor(14, 1);
    else if (percent < 100)
        lcd.setCursor(13, 1);
    else
        lcd.setCursor(12, 1);
    // ATTENTION
    // lcd.setCursor(10, 1);
    // _________

    lcd.print(percent);
    lcd.setCursor(15, 1);
    lcd.print("%");*/

    // Print on console (or send to Processing)
    // Serial.println((int)DHT.humidity);
    delay(2000);
}
