#include <IRremote.h>

/* ***
Project: Arduino Universal IR Control
Author:  Max Huzmiev
email:   max@huzm.ru
*** */

unsigned char irPin = 4;
IRrecv irrecv(irPin);
decode_results results;

void setup() {
  irrecv.enableIRIn();  // Start the receiver
  Serial.begin(9600);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);  
}
