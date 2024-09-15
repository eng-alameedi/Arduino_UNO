//
// File: timers.h
//
// this file contain the definition of timers classes
// timer0, timer1, and timer2 that inherit from the
// abstract class Timer.
//

#ifndef _TIMERS_H_
#define _TIMERS_H_

#define WGM00 (0)
#define WGM01 (1)
#define WGM02 (3)

#define CS00 (0)
#define CS01 (1)
#define CS02 (2)

#define TOIE0 (0)
#define OCIE0A (1)
#define OCIE0B (2)

#define TOV0 (0)
#define OCF0A (1)
#define OCF0B (2)

#include <stdint.h>

#include "timer_uno.h"

void cli();
void sei();
/*
extern "C" void __vector_16(void) __attribute__((signal));
void __vector_16(void) {
  // do what you want, when interrupt occur.
  }*/

class Timer0 : public Timer {
 public:
  Timer0();
  void count_setup() override;
  void count() override;

  void ctc_setup() override;
  void delay(unsigned int) override;

  bool is_active() override;
};

class Timer1 : public Timer {
  // code here
};

class Timer2 : public Timer {
  // code here
};

#endif  // _TIMERS_H_
