/*
USE THIS CODE TO ERASE THE ELECTRICALLY ERASABLE PROGRAMMABLE READ-ONLY MEMORY
(EEPROM) OF YOUR ARDUINO BOARD.
*/
#include <EEPROM.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, LOW);

  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }

  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {}
