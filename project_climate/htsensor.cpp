#include "htsensor.h"
#include <Wire.h>
#include <DHT20.h>
#include "config.h"

static DHT20 dht;  // default constructor uses &Wire

void HTSensor_Init() {
  /*  Initialise I²C using the pins defined in config.h  */
  Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL);
  dht.begin();
}

bool HTSensor_Read(float &t, float &h) {
  t = dht.getTemperature();
  h = dht.getHumidity();
  return !(isnan(t) || isnan(h));
}