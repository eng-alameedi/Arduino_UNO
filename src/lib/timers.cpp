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

void Timer0::ctc_setup() {
  cli();

  TCCR0A |= (HIGH << WGM01);
  TCCR0B = 0;
  TCNT0 = 0;

  TCCR0B |= (HIGH << CS00) | (HIGH << CS01);  // set the prescaler to 64 011
  TIMSK0 |= (HIGH << OCIE0A);                 // enable the OCR0A compare
  OCR0A = 249;                                // (250-1), set the compare register for 1ms per 1000hz of cpu clock

  sei();
}

void Timer0::delay(unsigned int ms) {
  while (ms != 0) {
    while (!(TIFR0 & (1 << TOV0))) {
    };
    TIFR0 |= (HIGH << TOV0);
    ms--;
  }
}

bool Timer0::is_active() {
  if (get_active()) return true;
  return false;
}
