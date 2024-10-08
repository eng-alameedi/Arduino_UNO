//
// File: setup.cpp
//
// this file will contain the user example led-button toggle
// that test and implement the GPIO_REAL.
//

#include "Arduino_test.h"
/*
#define ssei() __asm__ __volatile__("sei")
#define ccli() __asm__ __volatile__("cli" ::: "memory")
void int0_run(void);

PIN_INIT(PIN13, OUTPUT);
PIN_INIT(PIN11, OUTPUT);
PIN_INIT(PIN2, INPUT);

// ISR(INIT0) { PIN_STATE(PIN11, HIGH); }

extern "C" void __vector_1(void) __attribute__((signal, __INTR_ATTRS));
void __vector_1(void) { PIN_STATE(PIN11, HIGH); }

void setup() {
  PIN_STATE(PIN11, LOW);
  PIN_STATE(PIN2, HIGH);
  // ccli();
  int0_run();
  ssei();
}

void loop() {
  PIN_STATE(PIN13, HIGH);
  DELAY(1000);
  PIN_STATE(PIN13, LOW);
  DELAY(1000);
}

void int0_run() {
  volatile uint8_t* int0_var{nullptr};
  int0_var = _SFR(EICRA);
  *int0_var |= (1 << ISC01);
  *int0_var &= ~(1 << ISC00);

  volatile uint8_t* int0_var2{nullptr};
  int0_var2 = _SFR(EIMSK);
  *int0_var |= (1 << INT0);
  for (uint16_t i{}; i <= 50000; i++);
}
*/
