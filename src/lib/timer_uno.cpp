//
// File: timer_uno.cpp
//
// this file contain the constructor of the class Timer
// just the timer to active if used.
//

#include "timer_uno.h"

Timer::Timer() : active(false) {}

bool Timer::get_active() const { return active; }
