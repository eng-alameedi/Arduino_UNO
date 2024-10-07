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
PIN_INIT(PIN11, OUTPUT);
int counter{};
void setup() { PIN_STATE(PIN13, LOW); }

void loop() {
  PIN_STATE(PIN11, HIGH);
  DELAY(1000);
  PIN_STATE(PIN11, LOW);
  DELAY(1000);
  counter++;
  if (counter > 100) asm volatile("jmp 0");
}
