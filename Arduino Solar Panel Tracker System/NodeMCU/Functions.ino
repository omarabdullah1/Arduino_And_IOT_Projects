void Init() {
  pinMode(S0, OUTPUT);                      /* Define digital signal pin as output to the Multiplexer pin SO */
  pinMode(S1, OUTPUT);                      /* Define digital signal pin as output to the Multiplexer pin S1 */
  pinMode(S2, OUTPUT);                      /* Define digital signal pin as output to the Multiplexer pin S2 */
  pinMode(S3, OUTPUT);                      /* Define digital signal pin as output to the Multiplexer pin S3 */
  pinMode(SIG, INPUT);                      /* Define analog signal pin as input or receiver from the Multiplexer pin SIG */

  dht.begin();
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  delay(700);
}

void getSensorData() {
  // Channel 0 (C0 pin - binary output 0,0,0,0)
  digitalWrite(S0, LOW); digitalWrite(S1, LOW); digitalWrite(S2, LOW); digitalWrite(S3, LOW);
  sensor0 = analogRead(SIG);

  // Channel 1 (C1 pin - binary output 1,0,0,0)
  digitalWrite(S0, HIGH); digitalWrite(S1, LOW); digitalWrite(S2, LOW); digitalWrite(S3, LOW);
  sensor1 = analogRead(SIG);

  // Channel 2 (C2 pin - binary output 0,1,0,0)
  digitalWrite(S0, LOW); digitalWrite(S1, HIGH); digitalWrite(S2, LOW); digitalWrite(S3, LOW);
  sensor2 = analogRead(SIG);

  // Channel 3 (C3 pin - binary output 1,1,0,0)
  digitalWrite(S0, HIGH); digitalWrite(S1, HIGH); digitalWrite(S2, LOW); digitalWrite(S3, LOW);
  sensor3 = analogRead(SIG);

  // Channel 4 (C4 pin - binary output 0,0,1,0)
  digitalWrite(S0, LOW); digitalWrite(S1, LOW); digitalWrite(S2, HIGH); digitalWrite(S3, LOW);
  sensor4 = analogRead(SIG);
  moistureSensor = sensor0;
  voltageSensor = sensor1;
}
