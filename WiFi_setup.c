#include <WiFi.h>
const char* ssid = "MARS"
const char* pass = "12345678"
void setup() {
  Serial.begin(9600); 
  WiFi.begin(ssid, pass);
  while (WiFi.status != WL_CONNECTED) { // stopping }
  Serial.println(WiFi.localIP());
}
void loop() {
  // our logic
}
