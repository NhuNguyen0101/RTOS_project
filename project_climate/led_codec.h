#ifndef LED_CODEC_H
#define LED_CODEC_H
#include <Arduino.h>

/*
   Helper to push a 2‑bit colour code to a tri‑colour LED block.
   bits  bit‑1  bit‑0   colour
   -----  -----  -----  -------
     00     0      0     off
     01     0      1     yellow
     10     1      0     green
     11     1      1     red
*/
inline void writeColour(uint8_t pinB1, uint8_t pinB0, uint8_t bits)
{
    digitalWrite(pinB1, (bits & 0b10) ? HIGH : LOW);   // MSB
    digitalWrite(pinB0, (bits & 0b01) ? HIGH : LOW);   // LSB
}
#endif