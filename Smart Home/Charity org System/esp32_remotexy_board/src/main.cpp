// RemoteXY select connection mode and include library
#define REMOTEXY_MODE__ESP32CORE_WIFI_CLOUD
#include <WiFi.h>
#include <Pushbutton.h>
#include <RemoteXY.h>
 #include <IRremote.h>

// RemoteXY connection settings
#define REMOTEXY_WIFI_SSID "network 2"
#define REMOTEXY_WIFI_PASSWORD "ahmed@@@010"
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "3ca172960ce34b4c5ff6039f194426bb"
 #define SEND_PWM_BY_TIMER
 #define FLASHEND 0xFFFF

 #define STR_HELPER(x) #x
 #define STR(x) STR_HELPER(x)
 #define PIN_PUSHSWITCH_1 34
 #define IR_SEND_PIN PIN_PUSHSWITCH_1

// RemoteXY configurate
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =  379 bytes
    {255, 7, 0, 7, 0, 116, 1, 16, 229, 1, 2, 1, 5, 29, 17, 7, 2, 26, 31, 31,
     79, 78, 0, 79, 70, 70, 0, 2, 1, 5, 40, 17, 7, 2, 26, 31, 31, 79, 78, 0,
     79, 70, 70, 0, 2, 1, 5, 52, 17, 7, 2, 26, 31, 31, 79, 78, 0, 79, 70, 70,
     0, 2, 1, 41, 16, 17, 7, 2, 26, 31, 31, 79, 78, 0, 79, 70, 70, 0, 70, 16,
     10, 76, 9, 9, 26, 37, 0, 70, 16, 22, 76, 9, 9, 26, 37, 0, 70, 16, 33, 76,
     9, 9, 26, 37, 0, 70, 16, 45, 76, 9, 9, 26, 37, 0, 70, 16, 16, 89, 9, 9,
     26, 37, 0, 70, 16, 28, 89, 9, 9, 26, 37, 0, 70, 16, 39, 89, 9, 9, 26, 37,
     0, 2, 1, 41, 40, 17, 7, 2, 26, 31, 31, 79, 78, 0, 79, 70, 70, 0, 2, 1,
     41, 28, 17, 7, 2, 26, 31, 31, 79, 78, 0, 79, 70, 70, 0, 129, 0, 8, 13, 10,
     3, 17, 76, 73, 71, 72, 84, 49, 0, 129, 0, 8, 25, 10, 3, 17, 76, 73, 71, 72,
     84, 50, 0, 129, 0, 9, 37, 7, 3, 17, 70, 65, 78, 49, 0, 129, 0, 9, 49, 7,
     3, 17, 70, 65, 78, 50, 0, 129, 0, 46, 13, 5, 3, 17, 65, 47, 67, 0, 2, 1,
     5, 16, 17, 7, 2, 26, 31, 31, 79, 78, 0, 79, 70, 70, 0, 129, 0, 40, 37, 18,
     3, 17, 80, 82, 79, 74, 69, 67, 84, 79, 82, 0, 129, 0, 23, 2, 15, 6, 17, 76,
     65, 66, 50, 0, 129, 0, 9, 73, 10, 3, 17, 76, 73, 71, 72, 84, 49, 0, 129, 0,
     21, 73, 10, 3, 17, 76, 73, 71, 72, 84, 50, 0, 129, 0, 18, 86, 5, 3, 17, 65,
     47, 67, 0, 129, 0, 31, 86, 3, 3, 17, 84, 86, 0, 129, 0, 40, 86, 18, 3, 17,
     80, 82, 79, 74, 0, 129, 0, 47, 25, 3, 3, 17, 84, 86, 0, 129, 0, 34, 73, 7,
     3, 17, 70, 65, 78, 49, 0, 129, 0, 46, 73, 7, 3, 17, 70, 65, 78, 50, 0};

// this structure defines all the variables and events of your control interface
struct
{

   input variables
  uint8_t switch_2;      =1 if switch ON and =0 if OFF
  uint8_t switch_3;      =1 if switch ON and =0 if OFF
  uint8_t switch_4;      =1 if switch ON and =0 if OFF
  uint8_t switch_5;      =1 if switch ON and =0 if OFF
  uint8_t switch_7;      =1 if switch ON and =0 if OFF
  uint8_t switch_6;      =1 if switch ON and =0 if OFF
  uint8_t switch_1;      =1 if switch ON and =0 if OFF
  uint8_t pushSwitch_1;  =1 if state is ON, else =0

//   output variables
  uint8_t led_1;  led state 0 .. 1
  uint8_t led_2;  led state 0 .. 1
  uint8_t led_3;  led state 0 .. 1
  uint8_t led_4;  led state 0 .. 1
  uint8_t led_5;  led state 0 .. 1
  uint8_t led_6;  led state 0 .. 1
  uint8_t led_7;  led state 0 .. 1

//   other variable
  uint8_t connect_flag;  =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)

///
    //       END RemoteXY include          
///

#define PIN_SWITCH_1 2
#define PIN_SWITCH_2 21
#define PIN_SWITCH_3 19
#define PIN_SWITCH_4 18
#define PIN_SWITCH_5 23
#define PIN_SWITCH_6 4
#define PIN_SWITCH_7 5

 #define Relay1 2   D1 lamp1
 #define Relay2 21  D3 lamp2
 #define Relay3 19  D3 fan1
 #define Relay4 18  D3 fan2
 #define Relay5 23   D3  AC
 #define Relay6 4   D2 tv
 #define Relay7 15  D0  projector
 #define Relay8 5  D3 

 #define Switch1 32  D5
 #define Switch2 33  D6
 #define Switch3 25  SD2
 #define Switch4 26  SD3
 #define Switch5 27  SD3
 #define Switch6 14  SD3
 #define Switch7 12  SD3
 #define Switch8 13  SD3

#define button1Pin 13  D5
#define button2Pin 12  D6
#define button3Pin 14  SD2
#define button4Pin 27  SD3
#define button5Pin 26  SD3
#define button6Pin 25  SD3
#define button7Pin 33  SD3

Pushbutton btn1(button1Pin, false, LOW);
Pushbutton btn2(button2Pin, false, LOW);
Pushbutton btn3(button3Pin, false, LOW);
Pushbutton btn4(button4Pin, false, LOW);
Pushbutton btn5(button5Pin, false, LOW);
Pushbutton btn6(button6Pin, false, LOW);
Pushbutton btn7(button7Pin, false, LOW);

bool currentState1 = false;
bool currentState2 = false;
bool currentState3 = false;
bool currentState4 = false;
bool currentState5 = false;
bool currentState6 = false;
bool currentState7 = false;
bool currentState8 = false;

void setup()
{
   IrSender.begin(PIN_PUSHSWITCH_1, ENABLE_LED_FEEDBACK);
   IrSender.enableIROut(38);

   RemoteXY_Init();
  

  pinMode(PIN_SWITCH_1, OUTPUT);
  pinMode(PIN_SWITCH_2, OUTPUT);
  pinMode(PIN_SWITCH_3, OUTPUT);
  pinMode(PIN_SWITCH_4, OUTPUT);
  pinMode(PIN_SWITCH_5, OUTPUT);
  pinMode(PIN_SWITCH_6, OUTPUT);
  pinMode(PIN_SWITCH_7, OUTPUT);
}

void loop()
{
   RemoteXY_Handler();
  
   digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1 == 0) ? LOW : HIGH);
   digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2 == 0) ? LOW : HIGH);
   digitalWrite(PIN_SWITCH_3, (RemoteXY.switch_3 == 0) ? LOW : HIGH);
   digitalWrite(PIN_SWITCH_4, (RemoteXY.switch_4 == 0) ? LOW : HIGH);
   digitalWrite(PIN_SWITCH_5, (RemoteXY.switch_5 == 0) ? LOW : HIGH);
   digitalWrite(PIN_SWITCH_6, (RemoteXY.switch_6 == 0) ? LOW : HIGH);
   digitalWrite(PIN_SWITCH_7, (RemoteXY.switch_7 == 0) ? LOW : HIGH);

  
   if (btn1.getSingleDebouncedPress())
   {
     currentState1 = !currentState1;
     digitalWrite(PIN_SWITCH_1, currentState1);
     RemoteXY.switch_1 = currentState1;
   }
   if (btn2.getSingleDebouncedPress())
   {
     currentState2 = !currentState2;
     digitalWrite(PIN_SWITCH_2, currentState2);
     RemoteXY.switch_2 = currentState2;
   }
   if (btn3.getSingleDebouncedPress())
   {
     currentState3 = !currentState3;
     digitalWrite(PIN_SWITCH_3, currentState3);
     RemoteXY.switch_3 = currentState3;
   }
   if (btn4.getSingleDebouncedPress())
   {
     currentState4 = !currentState4;
     digitalWrite(PIN_SWITCH_4, currentState4);
     RemoteXY.switch_4 = currentState4;
   }
   if (btn5.getSingleDebouncedPress())
   {
     currentState5 = !currentState5;
     digitalWrite(PIN_SWITCH_5, currentState5);
     RemoteXY.switch_5 = currentState5;
   }
   if (btn6.getSingleDebouncedPress())
   {
     currentState6 = !currentState6;
     digitalWrite(PIN_SWITCH_6, currentState6);
     RemoteXY.switch_6 = currentState6;
   }

   if (btn7.getSingleDebouncedPress())
   {
     currentState7 = !currentState8;
     digitalWrite(PIN_SWITCH_7, currentState7);
     RemoteXY.switch_7 = currentState7;
   }

    RemoteXY.switch_1 = digitalRead(PIN_SWITCH_1);
    RemoteXY.switch_2 = digitalRead(PIN_SWITCH_2);
    RemoteXY.switch_3 = digitalRead(PIN_SWITCH_3);
    RemoteXY.switch_4 = digitalRead(PIN_SWITCH_4);
    RemoteXY.switch_5 = digitalRead(PIN_SWITCH_5);
    RemoteXY.switch_6 = digitalRead(PIN_SWITCH_6);
    RemoteXY.switch_7 = digitalRead(PIN_SWITCH_7);

   RemoteXY.led_1 = digitalRead(PIN_SWITCH_1);
   RemoteXY.led_2 = digitalRead(PIN_SWITCH_2);
   RemoteXY.led_3 = digitalRead(PIN_SWITCH_3);
   RemoteXY.led_4 = digitalRead(PIN_SWITCH_4);
   RemoteXY.led_5 = digitalRead(PIN_SWITCH_5);
   RemoteXY.led_6 = digitalRead(PIN_SWITCH_6);
   RemoteXY.led_7 = digitalRead(PIN_SWITCH_7);


    if (RemoteXY.pushSwitch_1 == 1)
    {
      IrSender.sendSamsung(0x707, 0x2, 0);
    }
    else
    {
      IrSender.sendSamsung(0x707, 0x2, 0);
    }

     RemoteXY_Handler ();
   digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==0)?LOW:HIGH);
   digitalWrite(PIN_SWITCH_3, (RemoteXY.switch_3==0)?LOW:HIGH);
   digitalWrite(PIN_SWITCH_4, (RemoteXY.switch_4==0)?LOW:HIGH);
   digitalWrite(PIN_SWITCH_5, (RemoteXY.switch_5==0)?LOW:HIGH);
   digitalWrite(PIN_SWITCH_7, (RemoteXY.switch_7==0)?LOW:HIGH);
   digitalWrite(PIN_SWITCH_6, (RemoteXY.switch_6==0)?LOW:HIGH);
   digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  
  if (btn1.getSingleDebouncedPress()) {
    currentState1 = !currentState1;
    digitalWrite(PIN_SWITCH_1, currentState1);
  }
  if (btn2.getSingleDebouncedPress()) {
    currentState2 = !currentState2;
    digitalWrite(PIN_SWITCH_2, currentState2);
  }
  if (btn3.getSingleDebouncedPress()) {
    currentState3 = !currentState3;
    digitalWrite(PIN_SWITCH_3, currentState3);

  }
  if (btn4.getSingleDebouncedPress()) {
    currentState4 = !currentState4;
    digitalWrite(PIN_SWITCH_4, currentState4);
  }
  if (btn5.getSingleDebouncedPress()) {
    currentState5 = !currentState5;
    digitalWrite(PIN_SWITCH_5, currentState5);
  }
  if (btn6.getSingleDebouncedPress()) {
    currentState6 = !currentState6;
    digitalWrite(PIN_SWITCH_6, currentState6);
  }
  
  if (btn7.getSingleDebouncedPress()) {
     currentState7 = !currentState7;
    digitalWrite(PIN_SWITCH_7, currentState7);
  }
  

   RemoteXY.switch_1 = digitalRead(PIN_SWITCH_1);
   RemoteXY.led_1 = digitalRead(PIN_SWITCH_1);
    RemoteXY.switch_2 = digitalRead(PIN_SWITCH_2);
   RemoteXY.led_2 = digitalRead(PIN_SWITCH_2);
    RemoteXY.switch_3 = digitalRead(PIN_SWITCH_3);
   RemoteXY.led_3 = digitalRead(PIN_SWITCH_3);
    RemoteXY.switch_4 = digitalRead(PIN_SWITCH_4);
   RemoteXY.led_4 = digitalRead(PIN_SWITCH_4);
    RemoteXY.switch_5 = digitalRead(PIN_SWITCH_5);
   RemoteXY.led_5 = digitalRead(PIN_SWITCH_5);
    RemoteXY.switch_6 = digitalRead(PIN_SWITCH_6);
   RemoteXY.led_6 = digitalRead(PIN_SWITCH_6);
    RemoteXY.switch_7 = digitalRead(PIN_SWITCH_7);
   RemoteXY.led_7 = digitalRead(PIN_SWITCH_7);
  
}
