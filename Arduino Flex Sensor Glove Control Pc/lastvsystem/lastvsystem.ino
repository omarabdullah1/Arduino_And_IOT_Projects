#include <Mouse.h>
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050_9Axis_MotionApps41.h"
MPU6050 mpu;

bool dmpReady = false;
uint8_t mpuIntStatus;
uint8_t devStatus;
uint16_t packetSize;
uint16_t fifoCount;
uint8_t fifoBuffer[64];

Quaternion q;
VectorFloat gravity;
float euler[3];
float ypr[3];
float yaw, pitch, roll;

int left_button_pin = 9;
int right_button_pin = 10;
int leftClickFlag = 0;
const int sensitivity = 30;
float vertZero, horzZero;
float vertValue, horzValue;

volatile bool mpuInterrupt = false;
void dmpDataReady() {
  mpuInterrupt = true;
}

const int finger1 = A0;
const int finger2 = A1;
const int finger3 = A2;
const int finger4 = A3;
const int finger5 = A4;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  while (!Serial);
  mpu.initialize();
  devStatus = mpu.dmpInitialize();
  if (devStatus == 0) {
    mpu.setDMPEnabled(true);
    attachInterrupt(0, dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();
    dmpReady = true;
    packetSize = mpu.dmpGetFIFOPacketSize();
  } else {
    Serial.print(F("DMP Initialization failed (code "));
    Serial.print(devStatus);
    Serial.println(F(")"));
  }
  yaw = 0.0;
  pitch = 0.0;
  roll = 0.0;
  vertZero = 0;
  horzZero = 0;
}

void loop() {
  int finger1Val = analogRead(finger1);
  int finger2Val = analogRead(finger2);
  int finger3Val = analogRead(finger3);
  int finger4Val = analogRead(finger4);
  int finger5Val = analogRead(finger5);

  if (!dmpReady) return;
  mpuInterrupt = true;
  fifoCount = mpu.getFIFOCount();
  if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
    mpu.resetFIFO();
    Serial.println(F("FIFO overflow!"));
  } else if (mpuIntStatus & 0x01) {
    while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
    mpu.getFIFOBytes(fifoBuffer, packetSize);
    fifoCount -= packetSize;

    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    yaw = ypr[1] / PI * 180;
    pitch = ypr[2] / PI * 180;
    roll = ypr[0] / PI * 180;

    vertValue = yaw - vertZero;
    horzValue = roll - horzZero;
    vertZero = yaw;
    horzZero = roll;

    if (abs(vertValue) > sensitivity) {
      if (vertValue > 0) {
        Serial.println( "Keyboard.write(KEY_UP_ARROW)"); // Move the mouse cursor up
      } else {
        Serial.println( " Keyboard.write(KEY_DOWN_ARROW)"); // Move the mouse cursor down
      }
    }

    if (abs(horzValue) > sensitivity) {
      if (horzValue > 0) {
        Serial.println( "Keyboard.write(KEY_RIGHT_ARROW)"); // Move the mouse cursor right
      } else {
        Serial.println( "Keyboard.write(KEY_LEFT_ARROW)"); // Move the mouse cursor left
      }
    }
    //    yaw pitch
    //    30+  , -40- right
    //    15< ,  10< left
    //    40>__>30 , 32>__>25 down
    //    20>__>10   , -20>__>-10 up
    yaw = map(yaw, -200, 200, -50, 50);
    pitch = map(pitch, -200, 200, -50, 50);
    roll = map(roll, -200, 200, -50, 50);

    //  if (abs(vertValue) > sensitivity || abs(horzValue) > sensitivity) {
    if (yaw > 30 && pitch < -40) {
      Serial.println("Right");
    } else if (yaw < 15 && pitch < 10) {
      Serial.println("Left");
    } else if (yaw > 30 && yaw < 40 && pitch > 25 && pitch < 32) {
      Serial.println("Down");
    } else if (yaw > 10 && yaw < 20 && pitch > -20 && pitch < -10) {
      Serial.println("Up");
    }

    if (yaw > 30 && pitch < -40) {
      Keyboard.press(KEY_RIGHT_ARROW);  // Press the right arrow key
      delay(50);  // Adjust delay as needed
      Keyboard.release(KEY_RIGHT_ARROW);  // Release the right arrow key
    } else if (yaw < 15 && pitch < 10) {
      Keyboard.press(KEY_LEFT_ARROW);   // Press the left arrow key
      delay(50);  // Adjust delay as needed
      Keyboard.release(KEY_LEFT_ARROW);   // Release the left arrow key
    } else if (yaw > 30 && yaw < 40 && pitch > 25 && pitch < 32) {
      Keyboard.press(KEY_DOWN_ARROW);   // Press the down arrow key
      delay(50);  // Adjust delay as needed
      Keyboard.release(KEY_DOWN_ARROW);   // Release the down arrow key
    } else if (yaw > 10 && yaw < 35 && pitch > -35 && pitch < -10) {
      Keyboard.press(KEY_UP_ARROW);     // Press the up arrow key
      delay(50);  // Adjust delay as needed
      Keyboard.release(KEY_UP_ARROW);     // Release the up arrow key
    }
    //  }
    Serial.print("ypr\t");
    Serial.print(yaw);
    Serial.print("\t");
    Serial.print(pitch);
    Serial.print("\t");
    Serial.print(roll);
    Serial.print("\t");
    Serial.print(horzValue);
    Serial.print("\t");
    Serial.print(vertValue);
    Serial.print("\t");
    Serial.print(horzValue * sensitivity);
    Serial.print("\t");
    Serial.print(vertValue * sensitivity);
    Serial.print("\t sensors Values: \t");
    Serial.print(finger1Val );
    Serial.print("\t");
    Serial.print(finger2Val );
    Serial.print("\t");
    Serial.print(finger3Val );
    Serial.print("\t");
    Serial.print(finger4Val );
    Serial.print("\t");
    Serial.println(finger5Val );
    if ((finger2Val < 175)) {
      Keyboard.press(KEY_LEFT_CTRL);  // Press CTRL
    } else {
      Keyboard.release(KEY_LEFT_CTRL);  // Release CTRL
    }

    if ((finger5Val < 150)) {
      Keyboard.press(KEY_LEFT_ALT);   // Press ALT
    } else {
      Keyboard.release(KEY_LEFT_ALT);   // Release ALT
    }

    if ((finger2Val < 175 ) && (finger3Val < 175 ) && (finger4Val < 175) && (finger5Val < 175 )) {
      Keyboard.press(' ');  // Press SPACE
    } else {
      Keyboard.release(' ');   // Release ALT
    }
  }
}
