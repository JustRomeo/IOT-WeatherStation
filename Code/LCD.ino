void init_lcd() {
    lcd.init();
    lcd.backlight();

    Serial.begin(9600);
    delay(1500);
}

void display_lcd(MyData data) {
    // print_serial();

    // Print Temperature on LCD
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    if ((int)data.t < 10)
        lcd.setCursor(7, 0);
    else
        lcd.setCursor(6, 0);
    lcd.print((int)data.t);
    lcd.setCursor(8, 0);
    lcd.print("*c");

    // Print Humidity on LCD
    lcd.setCursor(0, 1);
    lcd.print("Humi: ");
    if ((int)data.h < 10)
        lcd.setCursor(7, 1);
    else
        lcd.setCursor(6, 1);
    lcd.print((int)data.h);
    lcd.setCursor(8, 1);
    lcd.print("%");

    delay(2000);
}