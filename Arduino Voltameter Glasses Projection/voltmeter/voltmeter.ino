int analogInput = 0;
float Vout = 0.00;
float Vin = 0.00;
float R1 = 95000.00; // resistance of R1 (100K) 3000+1500
float R2 = 9400.00; // resistance of R2 (10K) 
int val = 0;
void setup(){
   pinMode(analogInput, INPUT); //assigning the input port
   Serial.begin(9600); //BaudRate
//   Serial.print("HELLO OMAR");
}
void loop(){
   
   val = analogRead(analogInput);//reads the analog input
   Vout = (val * 5.00) / 1024.00; // formula for calculating voltage out i.e. V+, here 5.00
   Vin = Vout / (R2/(R1+R2)); // formula for calculating voltage in i.e. GND
   if (Vin<0.09)//condition 
   {
     Vin=0.00;//statement to quash undesired reading !
  } 
//     Serial.print("HELLO OMAR");

Serial.println(Vin);
delay(1500);
}
