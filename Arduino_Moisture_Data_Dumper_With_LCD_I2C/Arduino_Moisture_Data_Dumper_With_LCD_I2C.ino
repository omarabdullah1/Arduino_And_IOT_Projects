#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

const int sensor_pin = 34;  /* Soil moisture sensor O/P pin */
const int relay_pin  = 32;  /* relay_pin O/P pin */
const int button_pin = 35;  /* button_pin sensor O/P pin */

void setup() {
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  Serial.begin(9600); /* Define baud rate for serial communication */
  pinMode(button_pin, INPUT);
  pinMode(relay_pin, OUTPUT);

}

void loop() {
  float moisture_percentage;
  int sensor_analog;
  int button_digital;
  sensor_analog = analogRead(sensor_pin);
  button_digital = digitalRead(button_pin);
  moisture_percentage = ( 100 - ( (sensor_analog / 4096.00) * 100 ) );
  lcd.setCursor(0, 0);
  lcd.print("Value(%)= ");
  Serial.print("Value(%)= ");
  lcd.print(moisture_percentage);
  Serial.print(moisture_percentage);
  Serial.print("%\n\n");
  Serial.print("btn data = ");
  Serial.print(button_digital);
  Serial.print("\n\n");
  if (button_digital) digitalWrite(relay_pin, HIGH);
  else digitalWrite(relay_pin, LOW);
  lcd.setCursor(0, 1);
  lcd.print("RELAY = ");
  button_digital ? lcd.print(" ON ") : lcd.print(" OFF ");
  delay(50);
}
