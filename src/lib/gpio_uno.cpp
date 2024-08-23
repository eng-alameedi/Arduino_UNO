//
// File: gpio_uno.cpp
//
// this file contain the implementation of the header
// file gpio_uno.h define the set_mode & set_state
// functions for each pin.
//

#include "gpio_uno.h"
#include <cstdint>

void set_pin_mode(uint8_t pin, pin_mode mode)
{
  DDRB |= (mode << pin);
}

void set_pin_state(uint8_t pin, pin_state state)
{
  if(state == HIGH)
    PORTB |= (HIGH << pin);
  else
    PORTB &= ~(HIGH << pin);
}
