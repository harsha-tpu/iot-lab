#include <Arduino.h> 
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define led 2
TaskHandle_t task1handle, task2handle;

void task1(void *param) {
  while (1) {
    digitalWrite(led, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(led, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}


void task2(void *param) {
  while (1) {
    Serial.println("Task 2 running");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  xTaskCreate(task1, "LED TASK", 1024, NULL, 1, &task1handle);
  xTaskCreate(task2, "Print TASK", 1024, NULL, 1, &task2handle);
}

void loop() {}
