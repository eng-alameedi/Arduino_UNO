//
// File: setup.cpp
//
// this file will contain the user example led-button toggle
// that test and implement the GPIO_REAL.
//

#include "Arduino_test.h"

volatile uint8_t* int0_var;
volatile uint8_t* int0_var2;

void int0_run(void);

PIN_INIT(PIN13, OUTPUT);
PIN_INIT(PIN8, OUTPUT);
PIN_INIT(PIN2, INPUT);

// ISR(INIT0) { PIN_STATE(PIN11, HIGH); }

extern "C" void __vector_1(void) __attribute__((signal, used));
void __vector_1(void) { PIN_STATE(PIN8, HIGH); }

void setup() {
  PIN_STATE(PIN8, LOW);
  PIN_STATE(PIN2, HIGH);
  int0_var = _SFR(EICRA);
  *int0_var |= _BV(ISC01);
  *int0_var &= ~(_BV(ISC00));

  int0_var2 = _SFR(EIMSK);
  *int0_var |= _BV(INT0);
}

void loop() {
  PIN_STATE(PIN13, HIGH);
  DELAY(1000);
  PIN_STATE(PIN13, LOW);
  DELAY(1000);
}
