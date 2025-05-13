#ifndef HUMIDIFIER_H
#define HUMIDIFIER_H
#include <Arduino.h>

void Humidifier_Init();
void Humidifier_Start();      // begin perpetual GREEN→YELLOW→RED cycle
void Humidifier_Stop();       // abort cycle & turn LEDs off
bool Humidifier_Active();
#endif