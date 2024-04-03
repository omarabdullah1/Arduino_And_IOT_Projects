#include <Arduino_FreeRTOS.h>
#include "task.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define stepPin 2
#define dirPin 3
//#define enPin 5
#define swPin 4
#define xswPin 5
#define yswPin 6
#define zswPin 7

#define stepsPerRevolution 400 // for 1mm // 200
#define mDelay 2000 // 2000

#define LcdAddress 0x27   // ---- 0x3f ---- 0x38 ---- 0x27 ---- 0x20 ----

LiquidCrystal_I2C lcd(LcdAddress, 20, 4);

void TaskDisplay( void *pvParameters );
void TaskXButton( void *pvParameters );
void TaskYButton( void *pvParameters );
void TaskZButton( void *pvParameters );


int counter1 = 0, counter2 = 0, xvalue = 0, yvalue = 0, zvalue = 0;

void setup() {
  xTaskCreate(
    TaskDisplay
    ,  "Display"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );
  xTaskCreate(
    TaskXButton
    ,  "XButton"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );
  xTaskCreate(
    TaskYButton
    ,  "YButton"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );
  xTaskCreate(
    TaskZButton
    ,  "ZButton"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

}
void loop()
{
  xTaskResumeAll();
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/
void TaskDisplay( void *pvParameters ) {
  (void) pvParameters;
  lcd.begin();
  lcd.clear();
  
  for (;;) {
    lcd.setCursor(0, 0);
    lcd.print("x: ");
    lcd.print(xvalue);
    lcd.print("   cm  ");
    lcd.setCursor(0, 1);
    lcd.print("y: ");
    lcd.print(yvalue);
    lcd.print("   cm  ");
    lcd.setCursor(0, 2);
    lcd.print("z: ");
    lcd.print(zvalue);
    lcd.print("   cm  ");
    lcd.setCursor(0, 3);
    lcd.print("V: ");
    lcd.print(xvalue * yvalue * zvalue);
    lcd.print("   cm  ");
    vTaskDelay( 1 );
  }
}

void TaskXButton( void *pvParameters ) {
  (void) pvParameters;
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(swPin, INPUT_PULLUP);
  pinMode(xswPin, INPUT_PULLUP);

  for (;;) {
    if (!digitalRead(xswPin)) {
      counter1 = 0;
      counter2 = 0;
      while (digitalRead(swPin)) {
        digitalWrite(dirPin, LOW);
        for (int i = 0; (i < stepsPerRevolution) ; i++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(mDelay);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(mDelay);
          if (!digitalRead(swPin))break;
        }
      }// Homing to zero
      
      while (counter1 < 10) {
        digitalWrite(dirPin, HIGH);
        for (int i = 0; (i < stepsPerRevolution) ; i++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(mDelay);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(mDelay);
        }
        counter1++; // for how much cm have moved

        xvalue = counter1;
      }
      counter2 = counter1;

      vTaskDelay( 1000 / portTICK_PERIOD_MS );

      while (digitalRead(swPin) || counter2 == 0) {
        digitalWrite(dirPin, LOW);
        for (int i = 0; (i < stepsPerRevolution) ; i++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(mDelay);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(mDelay);
          if (!digitalRead(swPin))break;
        }
        counter2--;
        xvalue = counter2;
      }
      xvalue = counter1 - counter2;
    }
    vTaskDelay( 1 );
  }
}

void TaskYButton( void *pvParameters ) {
  (void) pvParameters;
  //  pinMode(swPin, INPUT_PULLUP);
  pinMode(yswPin, INPUT_PULLUP);

  for (;;) {
    if (!digitalRead(yswPin)) {
      counter1 = 0;
      counter2 = 0;
      while (digitalRead(swPin)) {
        digitalWrite(dirPin, LOW);
        for (int i = 0; (i < stepsPerRevolution)  ; i++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(mDelay);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(mDelay);
          if (!digitalRead(swPin))break;
        }
      }
      while (counter1 < 10) {
        digitalWrite(dirPin, HIGH);
        for (int i = 0; (i < stepsPerRevolution) ; i++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(mDelay);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(mDelay);
        }
        counter1++; // for how much cm have moved

        yvalue = counter1;
      }
      counter2 = counter1;

      vTaskDelay( 1000 / portTICK_PERIOD_MS );

      while (digitalRead(swPin) || counter2 == 0) {
        digitalWrite(dirPin, LOW);
        for (int i = 0; (i < stepsPerRevolution) ; i++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(mDelay);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(mDelay);
          if (!digitalRead(swPin))break;
        }
        counter2--;
        yvalue = counter2;
      }
      yvalue = counter1 - counter2;
    }
    vTaskDelay( 1 );
  }
}
void TaskZButton( void *pvParameters ) {
  (void) pvParameters;
  //  pinMode(stepPin, OUTPUT);
  //  pinMode(dirPin, OUTPUT);
  //  pinMode(swPin, INPUT_PULLUP);
  pinMode(zswPin, INPUT_PULLUP);

  for (;;) {
    if (!digitalRead(zswPin)) {
      counter1 = 0;
      counter2 = 0;
      while (digitalRead(swPin)) {
        digitalWrite(dirPin, LOW);
        for (int i = 0; (i < stepsPerRevolution)  ; i++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(mDelay);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(mDelay);
          if (!digitalRead(swPin))break;
        }
      }
      while (counter1 < 10) {
        digitalWrite(dirPin, HIGH);
        for (int i = 0; (i < stepsPerRevolution) ; i++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(mDelay);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(mDelay);
        }
        counter1++; // for how much cm have moved

        zvalue = counter1;
      }
      counter2 = counter1;

      vTaskDelay( 1000 / portTICK_PERIOD_MS );

      while (digitalRead(swPin) || counter2 == 0) {
        digitalWrite(dirPin, LOW);
        for (int i = 0; (i < stepsPerRevolution) ; i++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(mDelay);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(mDelay);
          if (!digitalRead(swPin))break;
        }
        counter2--;
        zvalue = counter2;
      }
      zvalue = counter1 - counter2;
    }
    //    zvalue = digitalRead(zswPin);
    vTaskDelay( 1 );
  }
}
