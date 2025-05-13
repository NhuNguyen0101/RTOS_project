#include <Arduino.h>
#include "scheduler.h"
#include "led_blinky.h"
#include "htsensor.h"
#include "light_control.h"
#include "timer_util.h"

/* FreeRTOS task: 1 ms software timer */
static void TIMER_ISR(void *pv) {
  (void)pv;
  const TickType_t period = 1 / portTICK_PERIOD_MS; // 1 ms
  while (true) {
    Timer_Tick();
    vTaskDelay(period);
  }
}

/* 5 s sensor sampling task (runs in cooperative scheduler) */
static void task_ReadSensors() {
  static uint32_t seq = 0;
  float temp, hum;
  if (HTSensor_Read(temp, hum)) {
    Serial.printf("[%lu]  T = %.1f °C,  H = %.1f %%RH\n", seq++, temp, hum);
    LightControl_Update(temp, hum);
  } else {
    Serial.println("[sensor] read error");
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Smart Climate Control – booting…\n");

  LED_Blinky_Init();    // configure on‑board LED
  Timer_Init();         // prepare timer utilities
  HTSensor_Init();
  LightControl_Init();

  SCH_Init();
  SCH_Add_Task(task_ReadSensors, 0, 5000);   // run every 5 s

  /* create the periodic FreeRTOS timer task */
  xTaskCreatePinnedToCore(TIMER_ISR, "TIMER_ISR", 2048, nullptr, 3, nullptr, 0);
}

void loop() {
  SCH_Dispatch_Tasks();  // cooperative tasks
  Timer_Run();           // currently empty
}
