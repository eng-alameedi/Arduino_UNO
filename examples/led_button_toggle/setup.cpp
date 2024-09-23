//
// File: setup.cpp
//
// this file will contain the user example led-button toggle
// that test and implement the GPIO_REAL.
//

#include "Arduino_test.h"

// GPIO_REAL* gp;

// GPIO_REAL gp(PIN13, OUTPUT);
PIN_INIT(PIN13, OUTPUT);
PIN_INIT(PIN12, INPUT);

void setup() {
  // PIN_INIT(PIN13, OUTPUT);
  // PIN_INIT(PIN12, INPUT);

  PIN_STATE(PIN12, HIGH);
}

void loop() {
  if (PIN_READ(PIN12))
    PIN_STATE(PIN13, HIGH);
  else
    PIN_STATE(PIN13, LOW);
}
