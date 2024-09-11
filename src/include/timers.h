//
// File: timers.h
//
// this file contain the definition of timers classes
// timer0, timer1, and timer2 that inherit from the
// abstract class Timer.
//

#ifndef _TIMERS_H_
#define _TIMERS_H_

#include <stdint.h>

#include "timer_uno.h"

class Timer0 : public Timer {
 public:
  Timer0();
  void count_setup() override;
  void count() override;
};

class Timer1 : public Timer {
  // code here
};

class Timer2 : public Timer {
  // code here
};

#endif  // _TIMERS_H_
