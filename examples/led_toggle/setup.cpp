//
// File: setup.cpp
//
// this file will contain the user example led-button toggle
// that test and implement the GPIO_REAL.
//

#include "Arduino_test.h"

PIN_INIT(PIN13, OUTPUT);
Timer0 t1;
void setup() { t1.ctc_setup(); }

void loop() {
  PIN_STATE(PIN13, HIGH);
  t1.delay(1000);
  // DELAY(1000);
  PIN_STATE(PIN13, LOW);
  t1.delay(1000);
  // DELAY(1000);
}
