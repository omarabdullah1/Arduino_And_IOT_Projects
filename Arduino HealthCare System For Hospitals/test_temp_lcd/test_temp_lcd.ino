#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 7

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);
#define REPORTING_PERIOD_MS     500
//#define REPORTING_PERIOD_MS2     50
//#define REPORTING_PERIOD_MS3     10

//PulseOximeter pox;
uint32_t tsLastReport = 0;
//uint32_t tsLastReport2 = 0;
//uint32_t tsLastReport3 = 0;

const int GSR=A1;
float sensorValue=0;
float gsr_average=0;
float glucose=0;
int glucoselevel=0;
void onBeatDetected()
{
    Serial.println("Beat!");
}



void setup()
{
  pinMode(5, INPUT); // Setup for leads off detection LO +
  pinMode(6, INPUT); // Setup for leads off detection LO -

  Serial.begin(9600);
}


void loop()
{
//    if ((digitalRead(5) == 1) || (digitalRead(6) == 1)) {
//      String toSend1 = "add " ;
//      toSend1 += 1;
//      toSend1 += ",";
//      toSend1 += 0;
//      toSend1 += ",";
//      toSend1 += 1;
//      Serial.print(toSend1);
//      Serial.write(0xff);
//      Serial.write(0xff);
//      Serial.write(0xff);
//    }
//    else {
      int val = analogRead(0);
      String toSend = "add " ;
      toSend += 1;
      toSend += ",";
      toSend += 0;
      toSend += ",";
      toSend += val;
      Serial.print(toSend);
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
//    }
     float sum=0;
  for(int i=0;i<10;i++)           //Average the 10 measurements to remove the glitch
      {
      sensorValue=analogRead(GSR);
      sum += sensorValue;
      delay(10);
      }
   gsr_average = sum/1550;
   glucose=((-2.233*gsr_average)+10.83);
   glucoselevel=glucose*18.1348;
//   Serial.println(gsr_average);
//   Serial.println(glucose);
//   Serial.println(glucoselevel);
   int x = glucose;
   int y = (glucose-x)*10;
   Serial.print("n4.val=");
    Serial.print(x);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.print("n5.val=");
    Serial.print(y);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.print("n3.val=");
    Serial.print(glucoselevel);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
//   Serial.println(x);
//   Serial.println(y);
    sensors.requestTemperatures(); // Send the command to get temperatures
    int tempC = sensors.getTempCByIndex(0);
    Serial.print("n2.val=");
    Serial.print(tempC);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
//    pox.update();
//        if (millis() - tsLastReport > REPORTING_PERIOD_MS) {

//    Serial.print("n0.val=");
//    Serial.print(pox.getHeartRate());
//    Serial.write(0xff);
//    Serial.write(0xff);
//    Serial.write(0xff);
//    Serial.print("n1.val=");
//    Serial.print(pox.getSpO2());
//    Serial.write(0xff);
//    Serial.write(0xff);
//    Serial.write(0xff);
//  tsLastReport = millis();
//    }
}
