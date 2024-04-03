void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);

}

void loop() {
  int sensorVal = analogRead(A2);
  float voltage = (sensorVal * 5.0) / 1024.0;
  float pressure_pascal = (3.0 * ((float)voltage - 0.47)) * 1000000.0;
  float pressure_bar = constrain(pressure_pascal / 10e5,0,5);

  double x = mapp(analogRead(A1), 0, 1024, 0.0, 5.0);

  Serial.print(pressure_bar);
  Serial.print("\t");
  Serial.println(x);
//analogWrite(5,map(an alogRead(A1),0,1023,0,255));
  if (pressure_bar >= x+0.04) {
    digitalWrite(5, 0);
  } else if (pressure_bar < x-0.04) {
    digitalWrite(5, 1);
  }
}

double mapp(double x, double in_min, double in_max, double out_min, double out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
