#include <Arduino.h>
#include "humidifier.h"
#include "config.h"
#include "led_codec.h"
#include "scheduler.h"

//  state machine helpers
static void phaseG();
static void phaseY();
static void phaseR();

static bool active = false;   // TRUE while we are cycling

void Humidifier_Init() {
  pinMode(PIN_HUM_B1, OUTPUT);
  pinMode(PIN_HUM_B0, OUTPUT);
  writeColour(PIN_HUM_B1, PIN_HUM_B0, 0b00);   // off
}

bool Humidifier_Active() { return active; }

void Humidifier_Start() {
  if (active) return;         // already running
  active = true;
  phaseG();                   // kick‑off first GREEN phase immediately
}

void Humidifier_Stop() {
  active = false;             // external request to stop
  writeColour(PIN_HUM_B1, PIN_HUM_B0, 0b00);   // ensure LEDs off
}

/*── Phase functions — they reschedule each other as long as `active` */
static void phaseG() {
  if (!active) return;
  writeColour(PIN_HUM_B1, PIN_HUM_B0, 0b10);   // GREEN
  SCH_Add_Task(phaseY, 5000, 0);               // next in 5 s
}

static void phaseY() {
  if (!active) return;
  writeColour(PIN_HUM_B1, PIN_HUM_B0, 0b01);   // YELLOW
  SCH_Add_Task(phaseR, 3000, 0);               // 3 s later
}

static void phaseR() {
  if (!active) return;
  writeColour(PIN_HUM_B1, PIN_HUM_B0, 0b11);   // RED
  SCH_Add_Task(phaseG, 2000, 0);               // loop after 2 s
}
