// smartdesk.ino
#include <WiFi.h>
#include <PubSubClient.h>
#include "DHTesp.h"

const char* ssid = "Wokwi-GUEST";
const char* mqtt_server = "test.mosquitto.org";

DHTesp dht;
WiFiClient espClient;
PubSubClient client(espClient);

// Pinos - ajuste se necessário conforme seu wiring no Wokwi
const int DHT_PIN = 15;
const int LDR_PIN = 34;
const int LED_GREEN = 25;
const int LED_YELLOW = 26;
const int LED_RED = 27;

void setup_wifi() {
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("SmartDeskESP32")) {
      // conectado
    } else {
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  dht.setup(DHT_PIN, DHTesp::DHT22);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  TempAndHumidity data = dht.getTempAndHumidity();
  int lightLevel = analogRead(LDR_PIN);

  bool temp_ok = (data.temperature >= 21 && data.temperature <= 26);
  bool hum_ok = (data.humidity >= 40 && data.humidity <= 60);
  bool light_ok = (lightLevel > 800); // ajustar conforme leitura no Wokwi

  if (temp_ok && hum_ok && light_ok) {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
  } else if (temp_ok || hum_ok || light_ok) {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, LOW);
  } else {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, HIGH);
    client.publish("smartdesk/alerts", "FAÇA UMA PAUSA: Condicoes ruins detectadas");
  }

  // Monta payload JSON simples
  char msg[120];
  snprintf(msg, sizeof(msg), "{\"temp\":%.1f,\"hum\":%.1f,\"light\":%d}", data.temperature, data.humidity, lightLevel);
  client.publish("smartdesk/data", msg);

  delay(5000); // espera 5s antes da próxima coleta
}

