#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define wifi_ssid "Ouifi"
#define wifi_password "ckepourmwa"

#define mqtt_server "192.168.32.241"

#define mqtt_user "toma"
#define mqtt_password "ckepourtwa"

char message_buff[100];

long lastMsg = 0;
long lastRecu = 0;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  pinMode(14, OUTPUT);
}

void setup_wifi() {
  delay(5000);
  Serial.println();
  Serial.print("Connexion a ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connexion WiFi etablie ");
  Serial.print("=> Addresse IP : ");
  Serial.print(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connexion au serveur MQTT...");
    if (client.connect("ESP8266Client", mqtt_user, mqtt_password)) {
      Serial.println("OK");
    } else {
      Serial.print("KO, erreur : ");
      Serial.print(client.state());
      Serial.println(" On attend 2 secondes avant de recommencer");
      delay(2000);
    }
  } client.subscribe("led");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 1000 * 60) {
    lastMsg = now;

    client.publish("testtopic", String("bonsoir").c_str(), true);
  }
}

bool isActive = false;

void callback(char* topic, byte* payload, unsigned int length) {

  int i = 0;
  // create character buffer with ending null terminator (string)
  for(i=0; i < length; i++) {
    message_buff[i] = payload[i];
  }
  message_buff[i] = '\0';
  
  String msgString = String(message_buff);

  Serial.println(msgString);
  if (isActive == false) {
    digitalWrite(14,HIGH);
  } else {
    digitalWrite(14,LOW);
  }
  isActive = !isActive;
}
