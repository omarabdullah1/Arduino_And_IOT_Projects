#include <Mouse.h>

// Define flex sensor pins
const int indexPin = A0;
const int middlePin = A1;

// Define flex sensor threshold and sensitivity
int threshold = 800;

void setup() {
  Serial.begin(9600);
  delay(1000); // Delay to give you time to open the Serial Monitor

  // Initialize Mouse
  Mouse.begin();
}

void loop() {
  // Read flex sensor values
  int indexValue = analogRead(indexPin);
  int middleValue = analogRead(middlePin);

  // Move the mouse based on flex sensor values
  moveMouse(indexValue, 0);

  // Check for mouse clicks
  checkMouseClick(indexValue, middleValue);
}

void moveMouse(int indexValue, int middleValue) {
  // Map flex sensor values to mouse movement
  int xMovement = map(indexValue, 100, 350, -100, 100);
  int yMovement = map(middleValue, 0, 1023, -sensitivity, sensitivity);

  // Move the mouse
  Mouse.move(xMovement, 0);

  // Print values for debugging
  Serial.print("X: ");
  Serial.print(xMovement);
  Serial.print("\tY: ");
  Serial.println(0);

  delay(10); // Adjust delay as needed
}

void checkMouseClick(int indexValue, int middleValue) {
   //Check for left mouse click
  if (indexValue > threshold) {
    Mouse.press(MOUSE_LEFT);
  } else {
    Mouse.release(MOUSE_LEFT);
  }

  // Check for right mouse click
  if (middleValue > threshold) {
    Mouse.press(MOUSE_RIGHT);
  } else {
    Mouse.release(MOUSE_RIGHT);
  }
}
