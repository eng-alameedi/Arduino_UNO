//
// File: setup.cpp
//
// this file will contain the user example led-button toggle
// that test and implement the GPIO_REAL.
//

#include "Arduino_test.h"
#include "utils_uno.h"

void setup_int0_interrupt(void);
void setup_wdt(void);
void delay(void);

PIN_INIT(PIN13, OUTPUT);
PIN_INIT(PIN8, OUTPUT);
PIN_INIT(PIN2, INPUT);

ISR(INIT0) {
  PIN_STATE(PIN8, HIGH);
  PIN_STATE(PIN13, LOW);
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
  setup_wdt();
}

void setup_int0_interrupt(void) {
  EICRA |= _BV(ISC01);
  EICRA &= ~(_BV(ISC00));
  EIMSK |= _BV(INT0);
}

void setup_wdt(void) {
  WDTCSR |= (1 << WDCE) | (1 << WDE);
  WDTCSR = (1 << WDE) | (1 << WDP2) | (1 << WDP1);
}

void delay(void) {
  for (uint16_t i{}; i <= 1000; i++)
    for (uint16_t j{}; j <= 1000; j++);
}
