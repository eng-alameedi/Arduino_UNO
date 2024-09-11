//
// File: timers.cpp
//
// this file contain the implementation of the timers
// classes for ATmega328p timer/counter.
//

#include "timers.h"

#include "pin_map.h"
#include "timer_uno.h"

Timer0::Timer0() : Timer() {}

void Timer0::count_setup() {
  TCCR0A = 0;
  TCCR0B = 0;

  TCCR0B |= (HIGH <<)

      void
      Timer0::count() {
    // code here
  }
