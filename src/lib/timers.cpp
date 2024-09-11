//
// File: timers.cpp
//
// this file contain the implementation of the timers
// classes for ATmega328p timer/counter.
//

#include "timers.h"

#include "pin_map.h"
#include "timer_uno.h"

void sei() {
  SREG |= (1 << 7);  // enable the global interrupts
}

void cli() {
  SREG &= ~(1 << 7);  // disable the global interrupts
}

Timer0::Timer0() : Timer() {}

void Timer0::count_setup() {
  __asm__ __volatile__("cli");  // disable the global interrupts during the timer configuration.
  TCCR0A = 0;
  TCCR0B = 0;

  TCCR0B |= (HIGH << CS02) | (HIGH << CS00);  // set the prescaler to 1024 101
  TCNT0 = 0;
  __asm__ __volatile__("sei");  // enable the global interrupts after completing the timer configuration.
}

void Timer0::count() {
  // code here
}
