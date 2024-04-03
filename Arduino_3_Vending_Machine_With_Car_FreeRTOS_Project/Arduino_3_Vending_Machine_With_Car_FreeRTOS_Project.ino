#include <Arduino.h>

#include <Arduino_FreeRTOS.h>
#include "task.h"
#include "timers.h"

#include <Servo.h>
#include <Stepper.h>

Servo myservo;

int pos = 0;
#define Z_STEP_PIN 46
#define Z_DIR_PIN 48
#define Z_ENABLE_PIN 62

#define X_STEP_PIN 26
#define X_DIR_PIN 28
#define X_ENABLE_PIN 24

// #define E0_STEP_PIN        26
// #define E0_DIR_PIN         28
// #define E0_ENABLE_PIN      24

#define E1_STEP_PIN 36
#define E1_DIR_PIN 34
#define E1_ENABLE_PIN 30

// #define X_STEP_PIN 54
// #define X_DIR_PIN 55
// #define X_ENABLE_PIN 38

#define X_MIN_PIN 3
#define Y_MIN_PIN 14

#define Z_Axis_StepsPerRevolution 80  // for 1mm // 80
#define X_Axis_StepsPerRevolution 400 // for 1mm // 400
#define stepDelay 10                  // 10 microseconds

//////////////////////////////////////////////////////////
//              TINY STTEPER        //////////////////////
//////////////////////////////////////////////////////////

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 2

#define stepsPerRevolution 200
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

// #define HALFSTEPS 2038 // Number of half-steps for a full rotation
// int stepper_pins[4] = {4, 5, 6, 2};

enum Axis
{
  X_Axis, // فوق تحت
  Y_Axis, // للعربية
  Z_Axis  // يمين شمال
};
size_t counter = 0;
size_t counter2 = 0;

// void TaskHomeXAxis(void *pvParameters);
void TaskHomeYAxis(void *pvParameters);
void TaskMoveTinyStepper(void *pvParameters);
void TaskMoveServo(void *pvParameters);
void runMotor(Axis ax, int steps, int time, bool dir);
void step(bool forward, int times);
void halt();

void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  myservo.attach(11); // attaches the servo on pin 9 to the servo object

  pinMode(Z_STEP_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  pinMode(X_MIN_PIN, INPUT_PULLUP);
  digitalWrite(Z_ENABLE_PIN, LOW);
  // xTaskCreate(
  //     TaskHomeXAxis, "TaskHomeXAxis", 128 // Stack size
  //     ,
  //     NULL, 1 // Priority
  //     ,
  //     NULL);
  xTaskCreate(
      TaskHomeYAxis, "TaskHomeYAxis", 128 // Stack size
      ,
      NULL, 1 // Priority
      ,
      NULL);

  // xTaskCreate(
  //     TaskMoveTinyStepper, "TaskMoveTinyStepper", 128 // Stack size
  //     ,
  //     NULL, 1 // Priority
  //     ,
  //     NULL);
  // xTaskCreate(
  //     TaskMoveServo, "TaskMoveServo", 128 // Stack size
  //     ,
  //     NULL, 1 // Priority
  //     ,
  //     NULL);
}
void loop()
{
  // xTaskResumeAll();
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void TaskHomeXAxis(void *pvParameters)
{
  (void)pvParameters;
  pinMode(Z_STEP_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  pinMode(X_MIN_PIN, INPUT_PULLUP);
  digitalWrite(Z_ENABLE_PIN, LOW);

  while (digitalRead(X_MIN_PIN))
  {
    runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 0);
    ++counter;
    if (!digitalRead(X_MIN_PIN))
      break;
  }
  for (size_t i = 0; i < counter; i++)
  {
    runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
  }

  while (digitalRead(Y_MIN_PIN))
  {
    runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 1);
    ++counter2;

    if (!digitalRead(Y_MIN_PIN))
      break;
  }

  for (size_t i = 0; i < counter2; i++)
  {
    runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
  }

  // Homing to zero
  for (;;)
  {

    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
}
void TaskHomeYAxis(void *pvParameters)
{
  (void)pvParameters;
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);
  pinMode(Y_MIN_PIN, INPUT_PULLUP);
  digitalWrite(X_ENABLE_PIN, LOW);
  pinMode(E1_DIR_PIN, OUTPUT);
  pinMode(E1_ENABLE_PIN, OUTPUT);
  pinMode(E1_STEP_PIN, OUTPUT);
  digitalWrite(E1_ENABLE_PIN, LOW);

  myStepper.setSpeed(120);

  for (;;)
  {
    char x = Serial.read();
    if (Serial.available())
    {
      Serial.println(x);

      // if (x == 'k')
      // {
      //   for (size_t i = 0; i < 670; i++)
      //   {
      //     runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
      //   }
      //   for (size_t i = 0; i < 10; i++)
      //   {
      //     runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
      //   }
      //   myservo.write(-80);
      //   vTaskDelay(500 / portTICK_PERIOD_MS);

      //   for (int i = 0; i < 20; i++)
      //     myStepper.step(-stepsPerRevolution);
      //   vTaskDelay(500 / portTICK_PERIOD_MS);

      //   myservo.write(80);
      //   vTaskDelay(500 / portTICK_PERIOD_MS);

      //   for (int i = 0; i < 20; i++)
      //     myStepper.step(stepsPerRevolution);
      //   vTaskDelay(500 / portTICK_PERIOD_MS);
      // }
      // if (x == 'K')
      // {
      //   for (size_t i = 0; i < 250; i++)
      //   {
      //     runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, true);
      //   }
      //   for (size_t i = 0; i < 190; i++)
      //   {
      //     runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, false);
      //   }
      //   for (int i = 0; i < 15; i++)
      //     myStepper.step(stepsPerRevolution);
      //   vTaskDelay(500 / portTICK_PERIOD_MS);
      //   myservo.write(-80);
      //   vTaskDelay(500 / portTICK_PERIOD_MS);
      //   for (int i = 0; i < 15; i++)
      //     myStepper.step(-stepsPerRevolution);
      //   vTaskDelay(500 / portTICK_PERIOD_MS);
      //   // myservo.write(-80);
      //   // vTaskDelay(500 / portTICK_PERIOD_MS);

      //   // for (int i = 0; i < 20; i++)
      //   //   myStepper.step(-stepsPerRevolution);
      //   // vTaskDelay(500 / portTICK_PERIOD_MS);

      //   // myservo.write(80);
      //   // vTaskDelay(500 / portTICK_PERIOD_MS);

      //   // for (int i = 0; i < 20; i++)
      //   //   myStepper.step(stepsPerRevolution);
      //   // vTaskDelay(500 / portTICK_PERIOD_MS);
      // }

      if (x == 'H') // chocolate
      {
        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
        while (digitalRead(X_MIN_PIN))
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 0);
          if (!digitalRead(X_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        while (digitalRead(Y_MIN_PIN))
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 1);
          if (!digitalRead(Y_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////

        for (size_t i = 0; i < 470; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }
        for (size_t i = 0; i < 10; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        myservo.write(-80);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        for (int i = 0; i < 20; i++)
          myStepper.step(stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        myservo.write(90);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        for (int i = 0; i < 20; i++)
          myStepper.step(-stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
        while (digitalRead(X_MIN_PIN))
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 0);
          if (!digitalRead(X_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        while (digitalRead(Y_MIN_PIN))
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 1);
          if (!digitalRead(Y_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////

        for (size_t i = 0; i < 250; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }
        for (size_t i = 0; i < 200; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        ////////////////////////////////////////////////////
        //             CAR MOTION
        ////////////////////////////////////////////////////

        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Y_Axis, Z_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }
        for (int i = 0; i < 15; i++)
          myStepper.step(stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        myservo.write(-80);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        for (int i = 0; i < 15; i++)
          myStepper.step(-stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        ////////////////////////////////////////////////////
        //             CAR MOTION
        ////////////////////////////////////////////////////
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Y_Axis, Z_Axis_StepsPerRevolution, stepDelay * 2, 1);
        }

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
        while (digitalRead(X_MIN_PIN))
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 0);
          if (!digitalRead(X_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        while (digitalRead(Y_MIN_PIN))
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 1);
          if (!digitalRead(Y_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
      }
      if (x == 'F') // chips
      {
        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
        while (digitalRead(X_MIN_PIN))
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 0);
          if (!digitalRead(X_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        while (digitalRead(Y_MIN_PIN))
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 1);
          if (!digitalRead(Y_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////

        for (size_t i = 0; i < 470; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }
        for (size_t i = 0; i < 200; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        myservo.write(-80);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        for (int i = 0; i < 20; i++)
          myStepper.step(stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        myservo.write(90);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        for (int i = 0; i < 20; i++)
          myStepper.step(-stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
        while (digitalRead(X_MIN_PIN))
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 0);
          if (!digitalRead(X_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        while (digitalRead(Y_MIN_PIN))
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 1);
          if (!digitalRead(Y_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////

        for (size_t i = 0; i < 250; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }
        for (size_t i = 0; i < 200; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        ////////////////////////////////////////////////////
        //             CAR MOTION
        ////////////////////////////////////////////////////
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Y_Axis, Z_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }
        for (int i = 0; i < 15; i++)
          myStepper.step(stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        myservo.write(-80);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        for (int i = 0; i < 15; i++)
          myStepper.step(-stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        ////////////////////////////////////////////////////
        //             CAR MOTION
        ////////////////////////////////////////////////////
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Y_Axis, Z_Axis_StepsPerRevolution, stepDelay * 2, 1);
        }

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
        while (digitalRead(X_MIN_PIN))
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 0);
          if (!digitalRead(X_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        while (digitalRead(Y_MIN_PIN))
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 1);
          if (!digitalRead(Y_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
      }

      if (x == 'L') // Pepsi
      {
        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
        while (digitalRead(X_MIN_PIN))
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 0);
          if (!digitalRead(X_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        while (digitalRead(Y_MIN_PIN))
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 1);
          if (!digitalRead(Y_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////

        for (size_t i = 0; i < 673; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }
        for (size_t i = 0; i < 10; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        myservo.write(-80);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        for (int i = 0; i < 20; i++)
          myStepper.step(stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        myservo.write(90);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        for (int i = 0; i < 20; i++)
          myStepper.step(-stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
        while (digitalRead(X_MIN_PIN))
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 0);
          if (!digitalRead(X_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        while (digitalRead(Y_MIN_PIN))
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 1);
          if (!digitalRead(Y_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////

        for (size_t i = 0; i < 250; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }
        for (size_t i = 0; i < 200; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }

        ////////////////////////////////////////////////////
        //             CAR MOTION
        ////////////////////////////////////////////////////

        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Y_Axis, Z_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }

        for (int i = 0; i < 15; i++)
          myStepper.step(stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        myservo.write(-80);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        for (int i = 0; i < 15; i++)
          myStepper.step(-stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        ////////////////////////////////////////////////////
        //             CAR MOTION
        ////////////////////////////////////////////////////

        for (size_t i = 0; i < 20; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 1);
        }

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
        while (digitalRead(X_MIN_PIN))
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 0);
          if (!digitalRead(X_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        while (digitalRead(Y_MIN_PIN))
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 1);
          if (!digitalRead(Y_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
      }
      if (x == 's') // servo open
      {
        myservo.write(90);
        delay(1000);
        vTaskDelay(50 / portTICK_PERIOD_MS);
      }
      if (x == 'S') // srevo close
      {
        myservo.write(-80);
        delay(1000);
        vTaskDelay(50 / portTICK_PERIOD_MS);
      }
      if (x == 'i') // srevo close
      {
        for (size_t i = 0; i < 80; i++)
        {
          runMotor(Y_Axis, Z_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
      }
      if (x == 'y') // srevo close
      {
        for (size_t i = 0; i < 80; i++)
        {
          runMotor(Y_Axis, Z_Axis_StepsPerRevolution, stepDelay * 2, 1);
        }
        vTaskDelay(50 / portTICK_PERIOD_MS);
      }
      if (x == 't') // z axis stepper mini
      {

        for (int i = 0; i < 20; i++)
          myStepper.step(stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        // step one revolution in the other direction:
        for (int i = 0; i < 20; i++)
          myStepper.step(-stepsPerRevolution);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        // step(0, 3000);
        //     vTaskDelay(500 / portTICK_PERIOD_MS);
        //     step(1, 3000);
        //     vTaskDelay(500 / portTICK_PERIOD_MS);
      }

      if (x == 'h') // homing
      {
        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
        while (digitalRead(X_MIN_PIN))
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 0);
          if (!digitalRead(X_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(Z_Axis, Z_Axis_StepsPerRevolution, stepDelay * 6, 1);
        }
        while (digitalRead(Y_MIN_PIN))
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 1);
          if (!digitalRead(Y_MIN_PIN))
            break;
        }
        for (size_t i = 0; i < 20; i++)
        {
          runMotor(X_Axis, X_Axis_StepsPerRevolution, stepDelay * 2, 0);
        }

        ///////////////////////////////////////////////////
        //                  HOMING
        ///////////////////////////////////////////////////
      }
    }
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
}
bool isDone = false;

void TaskMoveTinyStepper(void *pvParameters)
{
  (void)pvParameters;
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  for (;;)
  {
  }
}
void TaskMoveServo(void *pvParameters)
{
  (void)pvParameters;
  myservo.attach(11); // attaches the servo on pin 9 to the servo object

  // pinMode(X_STEP_PIN, OUTPUT);
  // digitalWrite(X_ENABLE_PIN, LOW);

  for (;;)
  {
  }
}

void runMotor(Axis ax, int steps, int time, bool dir)
{
  switch (ax)
  {
  case Z_Axis:
    digitalWrite(Z_DIR_PIN, dir ? HIGH : LOW);
    for (int i = 0; (i < steps); i++)
    {
      digitalWrite(Z_STEP_PIN, HIGH);
      delayMicroseconds(time);
      digitalWrite(Z_STEP_PIN, LOW);
      delayMicroseconds(time);
    }
    break;
  case X_Axis:
    digitalWrite(X_DIR_PIN, dir ? HIGH : LOW);
    for (int i = 0; (i < steps); i++)
    {
      digitalWrite(X_STEP_PIN, HIGH);
      delayMicroseconds(time);
      digitalWrite(X_STEP_PIN, LOW);
      delayMicroseconds(time);
    }
    break;
  case Y_Axis:
    digitalWrite(E1_DIR_PIN, dir ? HIGH : LOW);
    for (int i = 0; (i < steps); i++)
    {
      digitalWrite(E1_STEP_PIN, HIGH);
      delayMicroseconds(time);
      digitalWrite(E1_STEP_PIN, LOW);
      delayMicroseconds(time);
    }
    break;
  default:
    break;
  }
}

// void step(bool forward, int times)
// {
//   const uint8_t phase_pattern[][4] = {
//       {1, 0, 0, 0},
//       {1, 1, 0, 0},
//       {0, 1, 0, 0},
//       {0, 1, 1, 0},
//   };
//   const uint8_t phase_pattern2[][4] = {
//       {0, 0, 1, 0},
//       {0, 0, 1, 1},
//       {0, 0, 0, 1},
//       {1, 0, 0, 1},
//   };
//   for (int i = 0; i < times; i++)
//   {

//     static uint8_t current_step = 0;
//     if (forward)
//     {
//       current_step = (current_step + 1) % 8;
//     }
//     else
//     {
//       current_step = (current_step - 1) % 8;
//     }
//     for (uint8_t i = 0; i < 4; i++)
//     {
//       digitalWrite(stepper_pins[i], phase_pattern[current_step][i]);
//     }
//     for (uint8_t i = 0; i < 4; i++)
//     {
//       digitalWrite(stepper_pins[i], phase_pattern2[current_step][i]);
//     }
//     delay(2);
//   }
// }

// void halt()
// { // This writes all motor pins LOW, preventing the motor from drawing current when idle.
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, LOW);
// }
