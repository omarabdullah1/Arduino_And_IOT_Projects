
#include <Adafruit_GFX.h>    // Adafruit's core graphics library
#include <Adafruit_TFTLCD.h> // Adafruit's hardware-specific library
#include <TouchScreen.h>     //Touchscreen library
#include <Fonts/Org_01.h>    //Include a different font
//#include <Adafruit_Fingerprint.h>    //FingerPrint
//#include <SoftwareSerial.h>         // SoftSerial
#include <EEPROM.h>         //Include the EEPROM library to score the highscore
#include <SD.h>
#include "def.h"

//SoftwareSerial mySerial(22, 23);
//Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup() {
  Init();
}
void loop() {
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();     // Read touchscreen
  digitalWrite(13, LOW);

  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (currentpage == 1)
  {
    if (p.z > 5 && p.z < 1000)
    {
      if (p.x > 440 && p.x < 900 && p.y > 535 && p.y < 870 && p.z > MINPRESSURE && p.z < MAXPRESSURE)
      {
        byePage(1);
      }
      if (p.x > 440 && p.x < 900 && p.y > 120 && p.y < 470  && p.z > MINPRESSURE && p.z < MAXPRESSURE)
      {
        byePage(2);
      }
    }
  }
}
