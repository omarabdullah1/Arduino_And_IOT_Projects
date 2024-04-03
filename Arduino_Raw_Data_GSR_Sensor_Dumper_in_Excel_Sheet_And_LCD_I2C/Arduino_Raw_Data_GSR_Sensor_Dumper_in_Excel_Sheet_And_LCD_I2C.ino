#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define GSR 0
#define BUTTON_PIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2);
//Pushbutton button(BUTTON_PIN,false,false);

int id = 0;
bool START = false;

void setup() {
  Serial.begin(9600);
  lcd.begin();

  lcd.backlight();

  Serial.println("CLEARDATA");

  Serial.println("LABEL,NOW_DATE,NOW_TIME,ID,GSR_ROW,GSR_V");

  Serial.println("RESETTIMER"); //resets timer to 0
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
//  if (!digitalRead(BUTTON_PIN))
//  {
//    START = !START;
//    while (!digitalRead(BUTTON_PIN));
//    START ? id++ : id;
//  }
//  while (START) {
    float conductivevoltage, y;
    float sensorValue = analogRead(GSR);
//    sensorValue=map(sensorValue,0,518,0,480);
    conductivevoltage = sensorValue * (5.0 / 1024.0);

    Serial.print("DATA,DATE,TIME,");
    
    Serial.print(id);
    Serial.print(" ,");
    Serial.print(sensorValue);
    Serial.print(" ,");
    Serial.print(conductivevoltage);
    Serial.println(" ,");

    lcd.clear();
    lcd.print("GSR = ");
    lcd.print(conductivevoltage);

//    if (!digitalRead(BUTTON_PIN)) {
//      break;
//      while (!digitalRead(BUTTON_PIN));
//
//    }
    delay(500);

  }
