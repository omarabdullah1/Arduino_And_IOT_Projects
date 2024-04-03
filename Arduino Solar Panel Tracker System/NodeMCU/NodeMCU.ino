#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#include "def.h"

void setup()
{
  Init();
}

void loop()
{
  getSensorData();
  int moisture =  moistureSensor;
  value = voltageSensor;
  vOUT = (value * 3.3) / 1024.0;
  vIN = vOUT / (R2 / (R1 + R2));
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V2, vIN);
  Blynk.virtualWrite(V3, moisture);

  Blynk.run();


}
