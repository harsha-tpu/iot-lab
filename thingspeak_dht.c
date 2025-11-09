#include <ESP8266WiFi.h>
#include <DHT.h> 
#include <ThingSpeak.h> 
#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;
const char* ssid = "SSID";
const char* pass = "PASS";
const char* apiKey = "YOUR_API_KEY";
unsigned long channelNumber = CHANNEL_NO;

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) { Serial.print("."); }
  Serial.println("\n WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() {
  float humi = dht.readHumidity(); 
  float tempC = dht.readTemperature(); 
  if (isnan(humi) || isnan(tempC)) {
    Serial.println("Failed to read from DHT11 Sensor!");
    delay(2000);
    return;
  }
  Serial.printf("Temp: %.2f C | Humidity: %.2f%%\n", tempC, humi);
  ThingSpeak.setField(1, tempC);
  ThingSpeak.setField(2, humi);
  int code = ThingSpeak.writeFields(channelNumber, apiKey);
  if (code == 200) {
    Serial.println("Data Sent!");
  } else {
    Serial.printf("Error sending data. HTTP error code: %d\n", code);
  }
  delay(20000);
}
