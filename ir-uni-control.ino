/* ***
Project: Arduino Universal IR Control
Author:  Max Huzmiev
email:   max@huzm.ru
*** */

#include <IRremote.h>
#include "ir-codes/TV--SAMSUNG-LE32C630K1W.h"

unsigned char irPin = 4;
IRrecv irrecv(irPin);
decode_results results;

void setup() {
  irrecv.enableIRIn();  // Start the receiver
  Serial.begin(9600);
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == VOLUME_UP)   Serial.write("Volume up\n");
    if (results.value == VOLUME_DOWN)   Serial.write("Volume down\n");
    if (results.value == CHANNEL_UP)   Serial.write("Channel up\n");
    if (results.value == CHANNEL_DOWN)   Serial.write("Channel down\n");
    if (results.value == OK)   Serial.write("OK\n");
    irrecv.resume(); // Receive the next value
  }
  delay(100);  
}
