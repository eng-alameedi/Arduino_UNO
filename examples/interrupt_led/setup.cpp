//
// File: setup.cpp
//
// this file will contain the user example led-button toggle
// that test and implement the GPIO_REAL.
//

#include "Arduino_test.h"
#include "interrupt_uno.h"
#include "pin_map.h"
#include "utils_uno.h"

// GPIO_REAL* gp;

// GPIO_REAL gp(PIN13, OUTPUT);
PIN_INIT(PIN13, OUTPUT);
PIN_INIT(PIN11, OUTPUT);

ISR(INIT0) { PIN_STATE(PIN11, HIGH); }
void setup() { PIN_STATE(PIN11, LOW); }

void loop() {
  PIN_STATE(PIN13, HIGH);
  DELAY(1000);
  PIN_STATE(PIN13, LOW);
  DELAY(1000);
}
