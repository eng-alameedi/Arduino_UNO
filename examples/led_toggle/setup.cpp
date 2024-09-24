//
// File: setup.cpp
//
// this file will contain the user example led-button toggle
// that test and implement the GPIO_REAL.
//

#include "Arduino_test.h"

PIN_INIT(PIN11, OUTPUT);

void setup() {
  // code here
}

void loop() {
  PIN_STATE(PIN11, HIGH);
  DELAY(1000);
  PIN_STATE(PIN11, LOW);
  DELAY(1000);
}
