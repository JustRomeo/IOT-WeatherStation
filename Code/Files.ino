/*
char *readFile(const char *filepath) {
    int pos = 0;
    File file = LittleFS.open(filepath, "r");
    char *str = (char *)malloc(sizeof(char) * (file.size() + 1));

    if (!file) {
        Serial.print("Could not open file: ");
        Serial.println(filepath);
        return str;
    }
    while (file.available() && pos < file.size()) {
        str[pos] = file.read();
        pos ++;
    }
    str[pos] = '\0';
    file.close();
    return str;
}
*/
