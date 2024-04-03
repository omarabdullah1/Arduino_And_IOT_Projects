#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // The Address BUS in real 3C ,in simulation 3D.
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("ArduinoGlasses V1.0");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
  display.setCursor(0, 0);
  display.print("Glasses");
  display.setCursor(10, 15);
  display.print("Ready");
  display.display();
  delay(2000);
  // display.clear(ALL);
  display.clearDisplay();
}

void loop() {
//  while (!Serial.available() > 0) ;
String data=Serial.readString();
  Serial.println(data); // Reads the data from the serial port and store it in dataFromSlave variable
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("  Voltage");
  display.setCursor(0, 0);
  display.print("             ");
  display.print(data);
  display.print("V");
  display.display();
//  delay(1000);

}
