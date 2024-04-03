#include <Arduino.h>
#include <WiFiManager.h>
#include <WebSocketsServer.h>
#include <Wire.h>
#include "MPU6050_6Axis_MotionApps20.h"

#define ledpin 2
#define buzzer 18

WebSocketsServer webSocket = WebSocketsServer(81);
MPU6050 mpu;

const float alpha = 0.98; // Complementary filter constant
float roll, pitch, yaw;
uint8_t fifoBuffer[64];
Quaternion q;
VectorFloat gravity;
float ypr[3];

float accX, accY, accZ;
float gyroX, gyroY, gyroZ;
float dt = 0.050; // Adjust this value based on your loop time (in seconds)

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length) {
  String cmd = "";
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.println("WebSocket is disconnected");
      break;
    case WStype_CONNECTED:
      Serial.println("WebSocket is connected");
      Serial.println(num);
      Serial.println(webSocket.remoteIP(num).toString());
      webSocket.sendTXT(num, "connected");
      break;
    case WStype_TEXT:
      cmd = "";
      for (int i = 0; i < length; i++) {
        cmd = cmd + (char)payload[i];
      }
      Serial.println(cmd);

      if (cmd == "poweron") {
        digitalWrite(ledpin, HIGH);
      } else if (cmd == "poweroff") {
        digitalWrite(ledpin, LOW);
      } else if (cmd == "getroll") {
        webSocket.sendTXT(num, "roll:" + String(ypr[2] * 180 / M_PI));
      } else if (cmd == "getpitch") {
        webSocket.sendTXT(num, "pich:" + String(ypr[1] * 180 / M_PI));
      } else if (cmd == "getyaw") {
        webSocket.sendTXT(num, "yaw:" + String(ypr[0] * 180 / M_PI));
      }

      webSocket.sendTXT(num, cmd + ":success");
      break;
    default:
      break;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ledpin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Wire.begin();
  Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties

  mpu.dmpInitialize();

  // supply your own gyro offsets here, scaled for min sensitivity
  mpu.setXGyroOffset(220);
  mpu.setYGyroOffset(76);
  mpu.setZGyroOffset(-85);
  mpu.setZAccelOffset(1788); // 1688 factory default for my test chip

  // make sure it worked (returns 0 if so)

  // Calibration Time: generate offsets and calibrate our MPU6050
  mpu.CalibrateAccel(5);
  mpu.CalibrateGyro(5);
  mpu.PrintActiveOffsets();
  mpu.setDMPEnabled(true);
  //  mpu.dmpGetFIFOPacketSize();

  WiFiManager wifiManager;
  IPAddress staticIP(192, 168, 137, 16);
//  IPAddress staticIP(192, 168, 43, 16);
//  wifiManager.resetSettings();

  wifiManager.setSTAStaticIPConfig(staticIP, IPAddress(192, 168, 137, 1), IPAddress(255, 255, 255, 0));
//  wifiManager.setSTAStaticIPConfig(staticIP, IPAddress(192, 168, 43, 1), IPAddress(255, 255, 255, 0));

  if (!wifiManager.autoConnect("AutoConnectAP")) {
    Serial.println("Failed to connect and hit timeout");
    delay(3000);
    ESP.restart();
    delay(5000);
  }

  Serial.println("WiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  Serial.println("WebSocket is started");
}

void loop() {
  webSocket.loop();

  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

    Serial.print(ypr[1] * 180 / M_PI); // y
    Serial.print(",");
    Serial.print(ypr[2] * 180 / M_PI); // p
    Serial.print(",");
    Serial.println(ypr[0] * 180 / M_PI); // r
    
    // Check if the angles are out of range and trigger the buzzer
    if ((ypr[0] * 180 / M_PI < -45) ||
        (ypr[2] * 180 / M_PI < -77)) {
      digitalWrite(buzzer, HIGH); // Turn on the buzzer
    } else {
      digitalWrite(buzzer, LOW); // Turn off the buzzer
    }
  }

  webSocket.broadcastTXT("ypr:" + String(ypr[1] * 180 / M_PI) + " , " + String(ypr[2] * 180 / M_PI) + " , " + String(ypr[0] * 180 / M_PI));
}
