#ifndef CONFIG_H
#define CONFIG_H
#include <Arduino.h>         // brings in uint8_t, pinMode(), …

/*‑‑‑ LED pins — each tri‑colour block is driven by 2 bits ‑‑‑*/
constexpr uint8_t PIN_LED_BOARD = 48;   // on‑board header D13

/* Heater block (bit‑1 : bit‑0)  */
constexpr uint8_t PIN_HEAT_B1   = 6;    // MSB
constexpr uint8_t PIN_HEAT_B0   = 7;    // LSB

/* Cooler block */
constexpr uint8_t PIN_COOL_B1   = 8;
constexpr uint8_t PIN_COOL_B0   = 9;

/* Humidifier block */
constexpr uint8_t PIN_HUM_B1    = 10;
constexpr uint8_t PIN_HUM_B0    = 17;

/*── I²C wiring for DHT20 ────────────────────────────────────────────
   The sensor’s SDA is wired to the pin labelled “A2” on the board; we
   leave the dedicated SCL line alone.  Change here if you re‑wire.    */
constexpr uint8_t PIN_I2C_SDA = A2;   // sensor SDA
constexpr uint8_t PIN_I2C_SCL = SCL;  // board’s default SCL

/* Environmental thresholds */
constexpr float  T_LOW_WARN  = 20.0f;  // °C   heater RED (too cold)
constexpr float  T_LOW_SAFE  = 22.0f;  // °C   heater ORANGE warning
constexpr float  T_HIGH_SAFE = 26.0f;  // °C   cooler not needed below this
constexpr float  T_HIGH_WARN = 28.0f;  // °C   cooler RED pulse (too hot)
constexpr float  HUM_LOW     = 45.0f;  // %RH  humidifier starts
#endif