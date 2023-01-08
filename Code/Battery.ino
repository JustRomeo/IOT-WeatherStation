/*float battery() {
    float TensionMin = 3.0;
    float TensionMax = 4.2;
    float b = analogRead(A2); //valeur analogique

    int minValue = (1023 * TensionMin) / 5;    // Arduino
    int maxValue = (1023 * TensionMax) / 5;    // Arduino
    // int minValue = (4095 * TensionMin) / 3; // ESP32
    // int maxValue = (4095 * TensionMax) / 3; // ESP32
  
    b = ((b - minValue) / (maxValue - minValue)) * 100; // mettre en pourcentage
    return b > 100 ? 100 : (b < 0 ? 0 : b);
}*/


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
    lcd.print("%");

    Print on console (or send to Processing)
    Serial.println((int)DHT.humidity);
*/