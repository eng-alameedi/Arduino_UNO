//
// File: setup.cpp
//
// this file will contain the user example led-button toggle
// that test and implement the GPIO_REAL.
//

#include "Arduino_test.h"

void setup_int0_interrupt(void);

PIN_INIT(PIN13, OUTPUT);
PIN_INIT(PIN8, OUTPUT);
PIN_INIT(PIN2, INPUT);

ISR(INIT0) {
  PIN_STATE(PIN8, HIGH);
  PIN_STATE(PIN13, LOW);
  for (uint16_t i{}; i <= 10000; i++)
    for (uint16_t j{}; j <= 1000; j++);
}

void setup() {
  PIN_STATE(PIN8, LOW);
  PIN_STATE(PIN2, HIGH);
  setup_int0_interrupt();
}

void loop() {
  PIN_STATE(PIN13, HIGH);
  DELAY(1000);
  PIN_STATE(PIN13, LOW);
  DELAY(1000);
}

void setup_int0_interrupt(void) {
  EICRA |= _BV(ISC01);
  EICRA &= ~(_BV(ISC00));
  EIMSK |= _BV(INT0);
}
