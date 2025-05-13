#include "timer_util.h"
#include "scheduler.h"
#include "config.h"
#include <Arduino.h>

void Timer_Init() {
  pinMode(PIN_LED_BOARD, OUTPUT);
}

void Timer_Tick() {
  SCH_Update();                          // advance cooperative scheduler (1 ms)

  static uint16_t msCnt = 0;
  if (++msCnt >= 1000) {                 // 1 s heartbeat
    static bool led = false;
    digitalWrite(PIN_LED_BOARD, (led = !led));
    msCnt = 0;
  }
}

void Timer_Run() {}