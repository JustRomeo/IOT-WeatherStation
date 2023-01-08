void handleRoot() {
    // char *str = readFile("/index");

    String str = "<!DOCTYPE html>";
    str += "<html>";
    str += "<head>";
    str += "<title>Drinky Connection</title>";
    str += "<style>";
    str += "  * {";
    str += "    font-family: \"Montserrat\", sans-serif;";
    str += "    padding: 0;";
    str += "    margin: 0;";
    str += "  }";
    str += "  body {";
    str += "    display: flex;";
    str += "    justify-content: center;";
    str += "    align-items: center;";
    str += "    align-content: center;";
    str += "    height: 100vh;";
    str += "  }";
    str += "  h2 {";
    str += "    font-weight: bold;";
    str += "    margin-bottom: 16px;";
    str += "  }";
    str += "  input {";
    str += "    border: none;";
    str += "    background-color: #1b002d;";
    str += "    padding: 10px;";
    str += "    color: white;";
    str += "  }";
    str += "  input:focus {";
    str += "    background-color: #37005c;";
    str += "    outline: none;";
    str += "  }";
    str += "  span {";
    str += "    display: block;";
    str += "    margin-bottom: 4px;";
    str += "    margin-top: 4px;";
    str += "  }";
    str += "  button {";
    str += "    border: none;";
    str += "    display: block;";
    str += "    padding: 10px;";
    str += "    margin-top: 24px;";
    str += "    width: 100%;";
    str += "    background-color: #35012c;";
    str += "    color: white;";
    str += "  }";
    str += "  button:hover {";
    str += "    background-color: #550346;";
    str += "  }";
    str += "  button:active {";
    str += "    background-color: #73035f;";
    str += "  }";
    str += "  h1 {";
    str += "    margin-bottom: 32px;";
    str += "  }";
    str += "  .margin-bot {";
    str += "    margin-bottom: 8px;";
    str += "  }";
    str += "  .connection-container {";
    str += "    width: 45%;";
    str += "    display: flex;";
    str += "    justify-content: center;";
    str += "  }";
    str += "  .info-container {";
    str += "    flex: 1;";
    str += "    background-color: #11001c;";
    str += "    height: 100%;";
    str += "    display: flex;";
    str += "    align-items: center;";
    str += "    justify-content: center;";
    str += "    color: white;";
    str += "  }";
    str += "</style>";
    str += "<script>";
    str += "  function sendData() {";
    str += "    const ssid = document.getElementById(\"ssid\").value;";
    str += "    const password = document.getElementById(\"password\").value;";
    str += "    let xmlHttp = new XMLHttpRequest();";
    str += "    xmlHttp.open(\"POST\", \"http://192.168.4.1/connect\");";
    str += "    xmlHttp.setRequestHeader(\"Content-Type\", \"plain/text\");";
    str += "    xmlHttp.send(`${ssid};${password}`);";
    str += "  }";
    str += "</script>";
    str += "</head>";
    str += "<body>";
    str += "  <div class=\"connection-container\">";
    str += "    <div>";
    str += "      <h2>Connection</h2>";
    str += "      <span>SSID</span>";
    str += "      <input type=\"text\" id=\"ssid\" />";
    str += "      <span>Password</span>";
    str += "      <input type=\"password\" id=\"password\" />";
    str += "      <button type=\"submit\" onclick=\"sendData()\">Connect</button>";
    str += "    </div>";
    str += "  </div>";
    str += "  <div class=\"info-container\">";
    str += "    <div>";
    str += "      <h1>Welcome on the Drinky connection page</h1>";
    str += "      <p class=\"margin-bot\">Please set the WiFi information needed to connect to your WiFi router.</p>";
    str += "      <p>Drinky will then switch to connection mode and try to connect to the WiFi router</p>";
    str += "      <p>with the information you gave.</p>";
    str += "    </div>";
    str += "  </div>";
    str += "</body>";
    str += "</html>";
    server.send(200, "text/html", str);
    // free(str);
}

void handleConnect() {
    if (!server.hasArg("plain")) {
        server.send(400, "text/plain", "No body sent");
        return;
    }

    String message = server.arg("plain");
    const int delimPos = message.indexOf(';');
    const String newSSID = message.substring(0, delimPos);
    const String newPassword = message.substring(delimPos + 1, message.length() + 1);

    ssid = newSSID;
    password = newPassword;
    setupSTA();
}

void setupAP() {
    apMode = true;
    Serial.print("Configuring access point...");
    WiFi.softAP(ssid, password);
    IPAddress ip = WiFi.softAPIP();
    Serial.println("AP IP address: ");
    Serial.println(ip);
}

void setupSTA() {
    int tmout = 0;

    apMode = false;
    Serial.println("Configuring connection to WiFi...");
    WiFi.mode(WIFI_STA);
    Serial.print("SSID: ");
    Serial.println(ssid);
    Serial.print("Password: ");
    Serial.println(password);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED && tmout < 600) {
        delay(500);
        Serial.print(".");
        tmout += 1;
    }
    if (WiFi.status() != WL_CONNECTED)
        Serial.println("Timed out !");
    else {
        Serial.println("");
        Serial.println("Connected !");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    }
}