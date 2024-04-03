const int motor = 10;

#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include <SoftwareSerial.h>
SoftwareSerial SIM900(9,8);
String textMessage;
String message, motorState;


 void setup() {
  pinMode(motor ,OUTPUT);

  Serial.begin(19200);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("system is on");
  delay(1500);

  SIM900.begin(19200); 
  delay(3000);
 Serial.print("SIM900 is ready to send receive sms");   
  SIM900.print("AT+CMGF=1\r");     // AT command to set SIM900 to SMS mode
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");       // Set module to send SMS data to serial out upon receipt
  delay(100);
    
   SIM900.println("AT+CMGF=1"); // Replace x with mobile number
  delay(1000);
  SIM900.println("AT+CMGS= \"+2010*******7\"\r"); // Replace * with mobile number
  delay(1000);
  SIM900.println("System is On");// The SMS text you want to send
  delay(100);
  SIM900.println((char)26);// ASCII code of CTRL+Z 
  lcd.clear();
}

void loop() {

   if(SIM900.available()>0){
   textMessage = SIM900.readString();
   Serial.print(textMessage);    
   delay(10);   
   }
   if(textMessage.indexOf("motor on")>=0){
    lcd.clear();
   digitalWrite(motor, HIGH);
    motorState = "on";
    Serial.println("motor set to ON");  
    textMessage = "ON";
    lcd.setCursor(0, 1 );
    lcd.print("motor on");
    delay(1000);      
  }
  if(textMessage.indexOf("motor off")>=0){
    // Turn off relay and save current state
    digitalWrite(motor, LOW);
    motorState = "off";
    Serial.println("motor set to OFF");
    textMessage = "OFF";
  } 
    if(textMessage.indexOf("state motor")>=0){
    String message = "motor1 is " + motorState;
    sendSMS(message);
    Serial.println("motor1 state resquest");
    textMessage = "";
  }     
