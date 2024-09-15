//
// File: timer_uno.cpp
//
// this file contain the constructor of the class Timer
// just the timer to active if used.
//

#include "timer_uno.h"

Timer::Timer() : active(false), run(false) {}

bool Timer::get_active() const { return active; }

bool Timer::get_run() const { return run; }

void Timer::set_active(bool setted) { active = setted; }

void Timer::set_run(bool exec) { run = exec; }
