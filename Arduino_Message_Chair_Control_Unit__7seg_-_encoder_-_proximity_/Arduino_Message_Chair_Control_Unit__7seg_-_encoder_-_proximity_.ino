// Pins to control each digit
#define DIGIT_ONE   A5
#define DIGIT_TWO   A3
#define DIGIT_THREE A4
#define stcp_Pin    A1
#define shcp_Pin    A2
#define ds_Pin      A0
#define outputA 6
#define outputB 5
#define btn 4
#define LED_MODE_1 7
#define LED_MODE_2 8
#define LED_MODE_3 9
#define LED_MODE_4 10
#define LED_MODE_5 11

#define EN_PIN_A   2
#define EN_PIN_B   3

#define RE_A   12
#define RE_B   13

// Array to store digits
const int digit[] = { DIGIT_ONE, DIGIT_TWO, DIGIT_THREE};
byte numberValue = 0;
int counter = 0, t, h, u; // counter , tens, hundreds, units
int mode = 0;
int aState;
int aLastState;
int btnRead;
int start_angle, end_angle, time, speed;
bool editMode = false, is_Start = false;
volatile long x;
void turnON_Digit(int number);
void turnOFF_Digit(int number);

void lights_off();  // turns off all 3 digits
void displayNum(int number);  // input integer between 0-9
void count2nine();  // counts from 0-9
void displayNum3(int one, int two, int three); // displays 3 numbers simultaneously
void showDisplay(int counterr);
void encoderRead();
void showLeds();
void A();
void B();
unsigned long previousMillis = 0;  // will store last time LED was updated
int ledState = LOW;  // ledState used to set the LED
const long interval = 1000;  // interval at which to blink (milliseconds)

void setup() {
  // put your setup code here, to run once:
  pinMode(DIGIT_ONE, OUTPUT);
  pinMode(DIGIT_TWO, OUTPUT);
  pinMode(DIGIT_THREE, OUTPUT);
  pinMode(stcp_Pin, OUTPUT);
  pinMode(shcp_Pin, OUTPUT);
  pinMode(ds_Pin, OUTPUT);
  pinMode(RE_A, OUTPUT);
  pinMode(RE_B, OUTPUT);
  for (int i = 7; i <= 12; i++)pinMode(i, OUTPUT);
  pinMode (outputA, INPUT);
  pinMode (outputB, INPUT);
  pinMode (btn, INPUT_PULLUP);
  pinMode(EN_PIN_A, INPUT_PULLUP);
  pinMode(EN_PIN_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(EN_PIN_A), A, RISING);

  attachInterrupt(digitalPinToInterrupt(EN_PIN_B), B, RISING);

  aLastState = digitalRead(outputA);
  Serial.begin (9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  encoderRead();
  switch (mode)
  {
    // first digit
    case 0:
      showDisplay(start_angle);
      break;
    // second digit
    case 1:
      showDisplay(end_angle);
      break;
    // third digit
    case 2:
      showDisplay(time);
      break;
    case 3:
      showDisplay(speed);
      break;
    case 4:
      showDisplay(is_Start ? 1 : 0);
      break;
  }
  showLeds();
  if (is_Start) {
    if ( counter != x ) {
      Serial.println (counter);
      x = counter;
    }
    unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= time*1000) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(RE_A, ledState);
    digitalWrite(RE_B, !ledState);
  }
    
//    delay(time*1000);
//    digitalWrite(RE_A, LOW);
//    digitalWrite(RE_B, HIGH);
//    delay(time*1000);
  }

}

void lights_off()
// Turns off all three digits
{
  for (int i = 5; i < 7; i++)
  {
    digitalWrite(digit[i], LOW);
  }
}


void turnON_Digit(int number)
{ // Turns on a single digit
  switch (number)
  {
    // first digit
    case DIGIT_ONE:
      digitalWrite(DIGIT_ONE, 1);
      break;
    // second digit
    case DIGIT_TWO:
      digitalWrite(DIGIT_TWO, 1);
      break;
    // third digit
    case DIGIT_THREE:
      digitalWrite(DIGIT_THREE, 1);
      break;
  }
}


void turnOFF_Digit(int number)
{ // Turns OFF a single digit
  switch (number)
  {
    // first digit
    case DIGIT_ONE:
      digitalWrite(DIGIT_ONE, LOW);
      break;
    // second digit
    case DIGIT_TWO:
      digitalWrite(DIGIT_TWO, LOW);
      break;
    // third digit
    case DIGIT_THREE:
      digitalWrite(DIGIT_THREE, LOW);
      break;
  }
}

void displayNum(int number)
{ // displays a number 0-9
  switch (number)
  {
    case 0:
      digitalWrite(stcp_Pin, LOW);
      shiftOut(ds_Pin, shcp_Pin, LSBFIRST, 0b00000101 );
      digitalWrite(stcp_Pin, HIGH);
      //      numberValue = 0b00000101;
      break;
    case 1:
      digitalWrite(stcp_Pin, LOW);
      shiftOut(ds_Pin, shcp_Pin, LSBFIRST, 0b11011101 );
      digitalWrite(stcp_Pin, HIGH);
      //      numberValue = 0b11011101;
      break;
    case 2:
      digitalWrite(stcp_Pin, LOW);
      shiftOut(ds_Pin, shcp_Pin, LSBFIRST, 0b01000110 );
      digitalWrite(stcp_Pin, HIGH);
      //      numberValue = 0b01000110;
      break;
    case 3:
      digitalWrite(stcp_Pin, LOW);
      shiftOut(ds_Pin, shcp_Pin, LSBFIRST, 0b01010100 );
      digitalWrite(stcp_Pin, HIGH);
      //      numberValue = 0b10010100;
      break;
    case 4:
      digitalWrite(stcp_Pin, LOW);
      shiftOut(ds_Pin, shcp_Pin, LSBFIRST, 0b10011100 );
      digitalWrite(stcp_Pin, HIGH);
      //      numberValue = 0b10011100;
      break;
    case 5:
      digitalWrite(stcp_Pin, LOW);
      shiftOut(ds_Pin, shcp_Pin, LSBFIRST, 0b00110100 );
      digitalWrite(stcp_Pin, HIGH);
      //      numberValue = 0b00110100;
      break;
    case 6:
      digitalWrite(stcp_Pin, LOW);
      shiftOut(ds_Pin, shcp_Pin, LSBFIRST, 0b00100100 );
      digitalWrite(stcp_Pin, HIGH);
      //      numberValue = 0b00100100;
      break;
    case 7:
      digitalWrite(stcp_Pin, LOW);
      shiftOut(ds_Pin, shcp_Pin, LSBFIRST, 0b01011101 );
      digitalWrite(stcp_Pin, HIGH);
      //      numberValue = 0b01011101;
      break;
    case 8:
      digitalWrite(stcp_Pin, LOW);
      shiftOut(ds_Pin, shcp_Pin, LSBFIRST, 0b00000100 );
      digitalWrite(stcp_Pin, HIGH);
      //      numberValue = 0b00000100;
      break;
    case 9:
      digitalWrite(stcp_Pin, LOW);
      shiftOut(ds_Pin, shcp_Pin, LSBFIRST, 0b00010100 );
      digitalWrite(stcp_Pin, HIGH);
      //      numberValue = 0b00010100;
      break;
  }
}

void count2nine()
// Counts from 0-9
{
  for (int i = 0; i < 10; i++)
  { displayNum(i);
    delay(500);
  }
}


void displayNum3(int one, int two, int three)
// Displays 3 different numbers simultaneously
{
  //display first number on digit 3
  turnON_Digit(DIGIT_THREE);
  turnOFF_Digit(DIGIT_TWO);
  turnOFF_Digit(DIGIT_ONE);
  displayNum(one);
  delay(5);
  //display second number on digit 2
  turnOFF_Digit(DIGIT_THREE);
  turnON_Digit(DIGIT_TWO);
  turnOFF_Digit(DIGIT_ONE);
  displayNum(two);
  delay(5);
  //display third number on digit 1
  turnOFF_Digit(DIGIT_THREE);
  turnOFF_Digit(DIGIT_TWO);
  turnON_Digit(DIGIT_ONE);
  displayNum(three);
  delay(5);
}
void showDisplay(int counterr)
{
  if (counterr <= 999) {
    if (counterr < 10) {
      u = counterr % 10;
      //display third number on digit 1
      turnOFF_Digit(DIGIT_THREE);
      turnOFF_Digit(DIGIT_TWO);
      turnON_Digit(DIGIT_ONE);
      displayNum(u);
      delay(5);
    }
    else if (counterr < 100) {
      u = counterr % 10;
      t = (counterr / 10) % 10;
      //display third number on digit 1
      turnOFF_Digit(DIGIT_THREE);
      turnOFF_Digit(DIGIT_TWO);
      turnON_Digit(DIGIT_ONE);
      displayNum(t);
      delay(5);        //display second number on digit 2
      turnOFF_Digit(DIGIT_THREE);
      turnON_Digit(DIGIT_TWO);
      turnOFF_Digit(DIGIT_ONE);
      displayNum(u);
      delay(5);
    }
    else if (counterr < 1000) {
      u = counterr % 10;
      t = (counterr / 10) % 10;
      h = (counterr / 100) % 10;
      //display first number on digit 3
      turnON_Digit(DIGIT_THREE);
      turnOFF_Digit(DIGIT_TWO);
      turnOFF_Digit(DIGIT_ONE);
      displayNum(u);
      delay(5);        //display second number on digit 2
      turnOFF_Digit(DIGIT_THREE);
      turnON_Digit(DIGIT_TWO);
      turnOFF_Digit(DIGIT_ONE);
      displayNum(t);
      delay(5);        //display third number on digit 1
      turnOFF_Digit(DIGIT_THREE);
      turnOFF_Digit(DIGIT_TWO);
      turnON_Digit(DIGIT_ONE);
      displayNum(h);
      delay(5);
    }
  }

}
void encoderRead() {
  btnRead = digitalRead(btn);
  aState = digitalRead(outputA);
  if (aState != aLastState) {
    if (digitalRead(outputB) != aState) {
      switch (mode)
      {
        // first digit
        case 0:
          start_angle++;
          break;
        // second digit
        case 1:
          end_angle++;
          break;
        // third digit
        case 2:
          time++;
          break;
        case 3:
          speed++;
          break;
        case 4:
          is_Start = !is_Start;
          break;
      }
    } else {
      switch (mode)
      {
        // first digit
        case 0:
          start_angle--;
          break;
        // second digit
        case 1:
          end_angle--;
          break;
        // third digit
        case 2:
          time--;
          break;
        case 3:
          speed--;
          break;
        case 4:
          is_Start = !is_Start;
          break;
      }
    }
    //    Serial.print("Position: ");
    //    Serial.println(counter);
    //    Serial.print("btn: ");
    //    Serial.println(btnRead);
  }
  aLastState = aState;
  //  }

  if (btnRead == 0) {
    delay(400);
    //    editMode = !editMode;
    mode ++;
    //    Serial.print("btn: ");
    //    Serial.println(btnRead);
  }
  //  if (counter >= 999)counter = 999;
  //  if (counter <= 0)counter = 0;
  if (mode > 4)mode = 0;
  if (mode <= 0)mode = 0;
}

void showLeds() {
  switch (mode)
  {
    // first digit
    case 0:
      digitalWrite(LED_MODE_1, 1);
      digitalWrite(LED_MODE_2, 0);
      digitalWrite(LED_MODE_3, 0);
      digitalWrite(LED_MODE_4, 0);
      digitalWrite(LED_MODE_5, 0);
      break;
    // second digit
    case 1:
      digitalWrite(LED_MODE_1, 0);
      digitalWrite(LED_MODE_2, 1);
      digitalWrite(LED_MODE_3, 0);
      digitalWrite(LED_MODE_4, 0);
      digitalWrite(LED_MODE_5, 0);
      break;
    // third digit
    case 2:
      digitalWrite(LED_MODE_1, 0);
      digitalWrite(LED_MODE_2, 0);
      digitalWrite(LED_MODE_3, 1);
      digitalWrite(LED_MODE_4, 0);
      digitalWrite(LED_MODE_5, 0);
      break;
    case 3:
      digitalWrite(LED_MODE_1, 0);
      digitalWrite(LED_MODE_2, 0);
      digitalWrite(LED_MODE_3, 0);
      digitalWrite(LED_MODE_4, 1);
      digitalWrite(LED_MODE_5, 0);
      break;
    case 4:
      digitalWrite(LED_MODE_1, 0);
      digitalWrite(LED_MODE_2, 0);
      digitalWrite(LED_MODE_3, 0);
      digitalWrite(LED_MODE_4, 0);
      digitalWrite(LED_MODE_5, 1);
      break;
  }
}
void A() {
  if (digitalRead(3) == LOW) {
    counter++;
  } else {
    counter--;
  }
}

void B() {
  if (digitalRead(2) == LOW) {
    counter--;
  } else {
    counter++;
  }
}
