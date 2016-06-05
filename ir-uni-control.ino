/* ***
Project: Arduino Universal IR Control
Author:  Max Huzmiev
email:   max@huzm.ru
*** */

#include <IRremote.h>
#include "ir-codes/TV--SAMSUNG-LE32C630K1W.h"
#include "ir-codes/DVBT2--HYUNDAI-H-DVB01T2.h"
#include "ir-codes/DVD--BBK-RC026-02R.h"

namespace TV = LE32C630K1W;
namespace DVB = H_DVB01T2;
namespace DVD = RC026_02R;

unsigned char irPin = 4;
IRrecv irrecv(irPin);
IRsend irsend;
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();  // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == TV::ARROW_RIGHT)   {
      Serial.write("TV Arrow Right\n");
      irsend.sendNEC(DVB::VOLUME_UP, 32);
    }
    if (results.value == TV::ARROW_LEFT)   {
      Serial.write("TV Arrow Left\n");
      irsend.sendNEC(DVB::VOLUME_DOWN, 32);
    }
    if (results.value == TV::ARROW_UP)   {
      Serial.write("TV Arrow Up\n");
      irsend.sendNEC(DVB::CHANNEL_UP, 32);
    }
    if (results.value == TV::ARROW_DOWN)   {
      Serial.write("TV Arrow Down\n");
      irsend.sendNEC(DVB::CHANNEL_DOWN, 32);
    }
    delay(40);
    irrecv.enableIRIn(); // Restart receiver
    irrecv.resume(); // Receive the next value
  }
  delay(50);  
}
