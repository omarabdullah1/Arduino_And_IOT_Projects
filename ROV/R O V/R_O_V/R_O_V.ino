
int AA1 = 2;
int AA2 = 3;
int BB1 = 4;
int BB2 = 5;
int CC1 = 6;
int CC2 = 7;
int qq1 = 8;
int qq2 = 9;
int EE1 = 10;
int EE2 = 11;
int FF1 = 12;
int FF2 = 13;
int GG1 = A4;
int GG2 = A5;

int command;

void setup()
{
  Serial.begin(9600);

  pinMode(AA1, OUTPUT);
  pinMode(AA2, OUTPUT);

  pinMode(BB1, OUTPUT);
  pinMode(BB2, OUTPUT);

  pinMode(CC1, OUTPUT);
  pinMode(CC2, OUTPUT);

  pinMode(qq1, OUTPUT);
  pinMode(qq2, OUTPUT);

  pinMode(EE1, OUTPUT);
  pinMode(EE2, OUTPUT);

  pinMode(FF1, OUTPUT);
  pinMode(FF2, OUTPUT);

  pinMode(GG1, OUTPUT);
  pinMode(GG2, OUTPUT);

}

void loop()
{
  if (Serial.available())
  { char data = Serial.read(); // Reading Serial Data and saving in data variable
    Serial.print(data);
  }
  while (Serial.available() > 0)
  {
    command = Serial.read();
    Serial.println(command);
  }
  //////////////////////////////////////////////////////////////////////////////////////////

  if (command == 'U') // UP
  {
    Serial.println("UP");
    digitalWrite(AA1, HIGH);
    digitalWrite(BB1, HIGH);
    digitalWrite(AA2, LOW);
    digitalWrite(BB2, LOW);
  }
  //////////////////////////////////////////////////////////////////////////////////////////

  else if  ( command == 'D') // DOWN
  {
    Serial.println("DOWN");
    digitalWrite(AA1, LOW);
    digitalWrite(BB1, LOW);
    digitalWrite(AA2, HIGH);
    digitalWrite(BB2, HIGH);
  }
  //////////////////////////////////////////////////////////////////////////////////////////

  else if  ( command == 'F') // Forward
  {
    Serial.println("Forward");
    digitalWrite(CC1, HIGH);
    digitalWrite(qq1, HIGH);
    digitalWrite(EE1, HIGH);
    digitalWrite(FF1, HIGH);
    
    digitalWrite(CC2, LOW);
    digitalWrite(qq2, LOW);
    digitalWrite(EE2, LOW);
    digitalWrite(FF2, LOW);
  }
  //////////////////////////////////////////////////////////////////////////////////////////

  else if (command == 'B') // Backward
  {
    Serial.println("Reverse");
    digitalWrite(CC1, LOW);
    digitalWrite(qq1, LOW);
    digitalWrite(EE1, LOW);
    digitalWrite(FF1, LOW);
    
    digitalWrite(CC2, HIGH);
    digitalWrite(qq2, HIGH);
    digitalWrite(EE2, HIGH);
    digitalWrite(FF2, HIGH);
  }
  //////////////////////////////////////////////////////////////////////////////////////////

  else if (command == 'L') // Left
  {
    Serial.println("Left");
    digitalWrite(CC1, HIGH);
    digitalWrite(qq1, LOW);
    digitalWrite(EE1, HIGH);
    digitalWrite(FF1, LOW);
    
    digitalWrite(CC2, LOW);
    digitalWrite(qq2, HIGH);
    digitalWrite(EE2, LOW);
    digitalWrite(FF2, HIGH);
  }
  //////////////////////////////////////////////////////////////////////////////////////////

  else if (command == 'R') // Right
  {
    Serial.println("Right");
    digitalWrite(CC1, LOW);
    digitalWrite(qq1, HIGH);
    digitalWrite(EE1, LOW);
    digitalWrite(FF1, HIGH);
    
    digitalWrite(CC2, HIGH);
    digitalWrite(qq2, LOW);
    digitalWrite(EE2, HIGH);
    digitalWrite(FF2, LOW);
  }
  //////////////////////////////////////////////////////////////////////////////////////////

  else if (command == 'C') // C = Clamp Forward
  {
    Serial.println("Clamp Forward");
    digitalWrite(GG1, HIGH);
    digitalWrite(GG2, LOW);
  }
  //////////////////////////////////////////////////////////////////////////////////////////

  else if (command == 'c') // c = Clamp Backward
  {
    Serial.println("Clamp Backward");
    digitalWrite(GG1, LOW);
    digitalWrite(GG2, HIGH);
  }
  //////////////////////////////////////////////////////////////////////////////////////////

  else if (command == 'S') // Stop
  {
    Serial.println("Stop");
    digitalWrite(AA1, LOW);
    digitalWrite(AA2, LOW);
    digitalWrite(BB1, LOW);
    digitalWrite(BB2, LOW);
    digitalWrite(CC1, LOW);
    digitalWrite(CC2, LOW);
    digitalWrite(qq1, LOW);
    digitalWrite(qq2, LOW);
    digitalWrite(EE1, LOW);
    digitalWrite(EE2, LOW);
    digitalWrite(FF1, LOW);
    digitalWrite(FF2, LOW);
    digitalWrite(GG1, LOW);
    digitalWrite(GG2, LOW);
  }
}
