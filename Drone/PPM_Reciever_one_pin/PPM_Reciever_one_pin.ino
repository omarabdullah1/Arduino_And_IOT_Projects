/* 4 cnannels rf receiver (PPM output) */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
////////////////////// CONFIGURATION del PPM//////////////////////////
#define channel_number 4 //we will have 4 channels
#define sigPin 2 //The PPM output will be pin D2
#define PPM_FrLen 27000 //frames per seccond of the PPM (1ms = 1000µs)
#define PPM_PulseLen 400 //pulse width config
//////////////////////////////////////////////////////////////////

int ppm[channel_number];

const uint64_t pipeIn = 0xE8E8F0F0E1LL;
//EThis part of code should be the same as the transmitter

RF24 radio(9, 10); //pin 8 is CSN!

//Up to 32 channels
struct MyData {
byte throttle; //we degine each byte of the analog input
byte yaw;
byte pitch;
byte roll;
};

MyData data;

void resetData()
{
//We give the start value of each byte

data.throttle = 0;
data.yaw = 127;
data.pitch = 127;
data.roll = 127;

setPPMValuesFromData();//we call this function that will map the values

}

void setPPMValuesFromData()
{
ppm[0] = map(data.throttle, 0, 255, 1000, 2000);
ppm[1] = map(data.yaw, 0, 255, 1000, 2000);
ppm[2] = map(data.pitch, 0, 255, 1000, 2000);
ppm[3] = map(data.roll, 0, 255, 1000, 2000);
//This is an example used in a drone project. My drone use microseconds
//signals with a range between 1000 and 2000. That is why
//I've maped my values in this way. You should change the values as you desire
//afor your application.
}

/**************************************************/

void setupPPM() {
pinMode(sigPin, OUTPUT);
digitalWrite(sigPin, 0); //We put the signal pin of the PPM in his "normal" state (off)

cli();
TCCR1A = 0; // We set to 0 the TCCR1 register
TCCR1B = 0;

OCR1A = 100;
TCCR1B |= (1 << WGM12); // We start CTC mode
TCCR1B |= (1 << CS11); // 8 prescale: 0,5 microseconds at 16mhz
TIMSK1 |= (1 << OCIE1A); // Interrupt enable
sei();
}

void setup()
{
resetData();
setupPPM();

radio.begin();
radio.setAutoAck(false);
radio.setDataRate(RF24_250KBPS);

radio.openReadingPipe(1,pipeIn);
radio.startListening();

}

/**************************************************/

unsigned long lastRecvTime = 0;

void recvData()
{
while ( radio.available() ) {
radio.read(&data, sizeof(MyData));
lastRecvTime = millis();
}
}

/**************************************************/

void loop()
{
recvData();

unsigned long now = millis();
if ( now - lastRecvTime > 1000 ) {
// Ha perdido la señal?
resetData();
}

setPPMValuesFromData();
}

/**************************************************/

#error Make sure that your clockMultiplier is the correct one (below). Delete this line after that
#define clockMultiplier 1 //set this to 2 if you're using a 16MHz arduino, leave it to 1 for a 8MHz arduino

ISR(TIMER1_COMPA_vect){
static boolean state = true;

TCNT1 = 0;

if ( state ) {
//end pulse
PORTD = PORTD & ~B00000100; // turn off D2
OCR1A = PPM_PulseLen * clockMultiplier;
state = false;
}
else {
//start pulse
static byte cur_chan_numb;
static unsigned int calc_rest;

PORTD = PORTD | B00000100; // turn on D2
state = true;

if(cur_chan_numb >= channel_number) {
cur_chan_numb = 0;
calc_rest += PPM_PulseLen;
OCR1A = (PPM_FrLen - calc_rest) * clockMultiplier;
calc_rest = 0;
}
else {
OCR1A = (ppm[cur_chan_numb] - PPM_PulseLen) * clockMultiplier;
calc_rest += ppm[cur_chan_numb];
cur_chan_numb++;
}
}
}




PWM receiver code!

/* 4 channels receiver example (PWM output) */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const uint64_t pipeIn = 0xE8E8F0F0E1LL; //Remember that this code is the same as in the transmitter

RF24 radio(9, 8); //Remember, here we changed the CSN pin from 10 to 8

//We could use up to 32 channels
struct MyData {
byte throttle; //We define each byte of data input, in this case just 4 channels
byte yaw;
byte pitch;
byte roll;
};

MyData data;

void resetData()
{
//We define the inicial value of each data input
//3 potenciometers will be in the middle position so 127 is the middle from 254
data.throttle = 0;
data.yaw = 127;
data.pitch = 127;
data.roll = 127;

}

/**************************************************/

void setup()
{
//We define the H bridge output pins
pinMode(10,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
pinMode(3,OUTPUT);

resetData();
radio.begin();
radio.setAutoAck(false);
radio.setDataRate(RF24_250KBPS);

radio.openReadingPipe(1,pipeIn);
//we start the radio comunication
radio.startListening();

}

/**************************************************/

unsigned long lastRecvTime = 0;

void recvData()
{
while ( radio.available() ) {
radio.read(&data, sizeof(MyData));
lastRecvTime = millis(); //here we receive the data
Serial.println("Hello");
}
}

/**************************************************/

void loop()
{
recvData();
unsigned long now = millis();
//Here we check if we've lost signal and if we did we reset the values unsigned long now = millis();
if ( now - lastRecvTime > 1000 ) {
// Signal lost?
resetData();
}

//we make an analogWrite using the received values

analogWrite(10,data.throttle);
analogWrite(6, data.yaw);
analogWrite(5,data.pitch);
analogWrite(3, data.roll);
}

/**************************************************/
