#include <Arduino_FreeRTOS.h>
#include "task.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BuzzerPin 10
#define SoundTone 250
#define TempSensorPin A0
#define FireSensorPin 9
#define MinDesigredTemp 27
#define MaxDesigredTemp 29
#define LcdAddress 0x20   // ---- 0x3f ---- 0x38 ---- 0x27 ---- 0x20 ----

LiquidCrystal_I2C lcd(LcdAddress, 16, 2);

void TaskDisplayTempAndFire( void *pvParameters );
void TaskOnFire( void *pvParameters );
void TaskGetTemp( void *pvParameters );
void TaskOnTempAndFire( void *pvParameters );


int tempReadValue = 0, fireReadValue = 0;
float millivolts, tempRealValue;

void setup() {

  xTaskCreate(
    TaskOnFire
    ,  "OnFire"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );
  xTaskCreate(
    TaskGetTemp
    ,  "GetTemp"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );
  xTaskCreate(
    TaskDisplayTempAndFire
    ,  "DisplayTempAndFire"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );
  xTaskCreate(
    TaskOnTempAndFire
    ,  "OnTempAndFire"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

}
void loop()
{
  //    vTaskDelete(NULL);
  xTaskResumeAll();
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/
void TaskDisplayTempAndFire( void *pvParameters ) {
  (void) pvParameters;
  lcd.begin();
  lcd.clear();
  for (;;) {
    lcd.setCursor(0, 0);
    lcd.print(tempRealValue);
    lcd.print(" C ");
    if (fireReadValue) {
      lcd.setCursor(0, 1);
      lcd.print("   Not  Flame   ");
    }
    else {
      lcd.setCursor(0, 1);
      lcd.print("Fire is Detected");
    }
    vTaskDelay( 1 );

  }
}

void TaskOnFire( void *pvParameters ) {
  (void) pvParameters;
  pinMode(FireSensorPin, INPUT);

  for (;;) {
    fireReadValue = digitalRead(FireSensorPin);
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability

  }
}
void TaskGetTemp( void *pvParameters )
{
  (void) pvParameters;
  for (;;) {
    tempReadValue = analogRead(TempSensorPin);
    millivolts = (tempReadValue / 1024.0) * 5000;
    tempRealValue = millivolts / 10;
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}
void TaskOnTempAndFire( void *pvParameters ) {
  (void) pvParameters;
  pinMode(BuzzerPin, OUTPUT);

  for (;;) {
    if (tempRealValue <= MinDesigredTemp)
    {
      noTone(BuzzerPin);
    }
    else if (tempRealValue >= MaxDesigredTemp)
    {
      if (!fireReadValue) {
        tone(BuzzerPin, SoundTone);
      }
      else {
        noTone(BuzzerPin);
      }
    }
    vTaskDelay(1);
  }
}
