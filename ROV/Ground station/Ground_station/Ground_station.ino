
int U = 2; //UP
int D = 3; //DOWN
int F = 4; //FORWARD
int B = 5; //BACKWARD
int L = 6; //LEFT
int R = 7; //RIGHT
int CF = 8; //Clamp Forward
int CB = 9; //ClampBACKWARD


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(U, INPUT);
  pinMode(D, INPUT);
  pinMode(F, INPUT);
  pinMode(B, INPUT);
  pinMode(R, INPUT);
  pinMode(L, INPUT);
  pinMode(CF, INPUT);
  pinMode(CB, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
    if  (digitalRead(U) == LOW||digitalRead(D) == LOW||digitalRead(F) == LOW||digitalRead(B) == LOW||digitalRead(R) == LOW||digitalRead(L) == LOW||digitalRead(CF) == LOW||digitalRead(CB) == LOW) // STOP
  {
    //Serial.print("S");
    Serial.println("S");
  }
  //////////////////////////////////////////////////////////////////////////////////////////

  if  (digitalRead(U) == HIGH) // UP
  {
    //Serial.print("U");
    Serial.println("U");
  }
  //////////////////////////////////////////////////////////////////////////////////////////

  if  (digitalRead(D) == HIGH) // DOWN
  {
    //Serial.print("D");
    Serial.println("D");
  }
  //////////////////////////////////////////////////////////////////////////////////////////
  if  (digitalRead(F) == HIGH) // FORWARD
  {
    //Serial.print("F");
    Serial.println("F");
  }
  //////////////////////////////////////////////////////////////////////////////////////////
  if  (digitalRead(B) == HIGH) // BACKWARD
  {
    //Serial.print("B");
    Serial.println("B");
  }
  //////////////////////////////////////////////////////////////////////////////////////////
  if  (digitalRead(R) == HIGH) // RIGHT
  {
    //Serial.print("R");
    Serial.println("R");
  }
  //////////////////////////////////////////////////////////////////////////////////////////
  if  (digitalRead(L) == HIGH) // LEFT
  {
    //Serial.print("L");
    Serial.println("L");
  }
  //////////////////////////////////////////////////////////////////////////////////////////
  if  (digitalRead(CF) == HIGH) // Clamp Forward
  {
    //Serial.print("C");
    Serial.println("C");
  }
  //////////////////////////////////////////////////////////////////////////////////////////
  if  (digitalRead(CB) == HIGH) // Clamp BACKWARD
  {
    //Serial.print("c");
    Serial.println("c");
  }
  
  //////////////////////////////////////////////////////////////////////////////////////////

  
}
