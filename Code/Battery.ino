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