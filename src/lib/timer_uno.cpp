#include "timer_uno.h"

void timer_ctc_setup() 
{
  TCCR0A |= (1 << 1);            // bit 1 for WGM01 to setup CTC timer.
  TCCR0B |= (1 << 1) | (1 << 0); // use 1 for CS01 bit, and use 0 for CS00 bit
                                 // all to set the prescaler to 64
  TIMSK0 |= (1 << 1); // use 1 for OCIE0A to enable timer0 to compare interrupt.
}
