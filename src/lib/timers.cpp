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
  // same as __asm__ __volatile__("sei");
}

void cli() {
  SREG &= ~(1 << 7);  // disable the global interrupts
  // same as __asm__ __volatile__("cli");
}

//<<<<<<<<<<<<<<<<<<<<<<<<<================================>>>>>>>>>>>>>>>>>>>>>>>>>>
Timer0::Timer0() : Timer() {}

void Timer0::count_setup() {
  cli();  // disable the global interrupts during the timer configuration.

  TCCR0A = 0;
  TCCR0B = 0;
  TCNT0 = 0;

  TCCR0B |= (HIGH << CS02) | (HIGH << CS00);  // set the prescaler to 1024 101
  TIMSK0 |= (HIGH << TOIE0);                  // enable timer overflow interrupt

  sei();  // enable the global interrupts after completing the timer configuration.
}

void Timer0::count() {
  bool loop_condition{true};
  while (loop_condition) {
    if (TIFR0 & (1 << TOV0)) {
      counter++;
      TIFR0 |= (HIGH << TOV0);
      loop_condition = false;
    }
  }
}
