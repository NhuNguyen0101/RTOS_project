#ifndef HEATER_H
#define HEATER_H
#include <Arduino.h>

enum HeaterState { HEAT_GREEN, HEAT_ORANGE, HEAT_RED };
void Heater_Init();
void Heater_Set(HeaterState state);
void Heater_Run();
#endif