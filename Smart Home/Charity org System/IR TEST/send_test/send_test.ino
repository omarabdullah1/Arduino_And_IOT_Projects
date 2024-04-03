// IR Transmitter ...
#include <IRremote.h>
#define IR_SEND_PIN     13
#define DELAY_AFTER_SEND 2000


IRsend irsend;

void setup()
{
IrSender.begin(13, ENABLE_LED_FEEDBACK);
}

void loop() {


  IrSender.sendNEC(0x40, 0x12, 0);
  delay(500);
  
	}
