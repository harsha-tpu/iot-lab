#include <WiFi.h>
#include <PubSubClient.h>
/* This code is uploaded into ESP32 */
const char* ssid = "SSID";
const char* password = "PASSWORD";
const char* mqtt_server = "IP_ADDR";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println(WiFi.localIP());
  client.setServer(mqtt_server, 1883);
  client.connect("ESP32Client");
}

void loop() {
  if (!client.connected()) client.connect("ESP32Client");
  client.loop();
  client.publish("ESP32/Temperaturedataread", "500");
  delay(2000);
}

/* RASPBERRY PI */
/* Run ifconfig in terminal, and copy the IP Address under wlan0 */
/* sudo apt install mosquitto mosquitto-clients */
/* sudo systemctl status mosquitto */
/* sudo nano /etc/mosquitto/mosquitto.conf */
/* paste this one-by-one listener 1883, allow-anonymous true */

