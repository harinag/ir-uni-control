/* ***
Project: Arduino Universal IR Control
Author:  Max Huzmiev
email:   max@huzm.ru
*** */

#include <IRremote.h>
#include "ir-codes/TV--SAMSUNG-LE32C630K1W.h"
#include "ir-codes/DVBT2--HYUNDAI-H-DVB01T2.h"

namespace TV = LE32C630K1W;
namespace DVB = H_DVB01T2;

unsigned char irPin = 4;
IRrecv irrecv(irPin);
decode_results results;

void setup() {
  irrecv.enableIRIn();  // Start the receiver
  Serial.begin(9600);
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == TV::VOLUME_UP)   Serial.write("Volume up (TV)\n");
    if (results.value == TV::VOLUME_DOWN)   Serial.write("Volume down (TV)\n");
    if (results.value == TV::CHANNEL_UP)   Serial.write("Channel up (TV)\n");
    if (results.value == TV::CHANNEL_DOWN)   Serial.write("Channel down (TV)\n");
    if (results.value == TV::OK)   Serial.write("OK (TV)\n");
    if (results.value == DVB::VOLUME_UP)   Serial.write("Volume up (Pristavka)\n");
    if (results.value == DVB::VOLUME_DOWN)   Serial.write("Volume down (Pristavka)\n");
    if (results.value == DVB::CHANNEL_UP)   Serial.write("Channel up (Pristavka)\n");
    if (results.value == DVB::CHANNEL_DOWN)   Serial.write("Channel down (Pristavka)\n");
    if (results.value == DVB::OK)   Serial.write("OK (Pristavka)\n");
    irrecv.resume(); // Receive the next value
  }
  delay(100);  
}
