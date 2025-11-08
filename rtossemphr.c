#include <Arduino.h> 
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#define led 2
SemaphoreHandle_t xSemaphore; 

void taskLED(void *param) {
  while (1) {
    if (xSemaphoreTake(xSemaphore, portMAX_DELAY) == pdTRUE) {
      digitalWrite(led, HIGH);
      Serial.println("taskLED: ON");
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      digitalWrite(led, LOW);
      Serial.println("taskLED: OFF");
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      xSemaphoreGive(xSemaphore);
      vTaskDelay(1);
    }
  }
}
void taskBLINK(void *param) {
  while (1) {
    if (xSemaphoreTake(xSemaphore, portMAX_DELAY) == pdTRUE) {
      digitalWrite(led, HIGH);
      Serial.println("taskBLINK: ON");
      vTaskDelay(500 / portTICK_PERIOD_MS);
      digitalWrite(led, LOW);
      Serial.println("taskBLINK: OFF");
      vTaskDelay(500 / portTICK_PERIOD_MS); 
      xSemaphoreGive(xSemaphore);
      vTaskDelay(1);
    }
  }
}

void setup() {
  Serial.begin(115200); 
  pinMode(led, OUTPUT);
  xSemaphore = xSemaphoreCreateBinary();
  xSemaphoreGive(xSemaphore);
  xTaskCreate(taskLED, "LED TASK", 1024, NULL, 1, NULL);
  xTaskCreate(taskBLINK, "BLINK TASK", 1024, NULL, 1, NULL);
}

void loop() {}
