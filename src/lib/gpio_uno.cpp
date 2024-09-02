//
// File: gpio_uno.cpp
//
// this file contain the implementation of the header
// file gpio_uno.h define the set_mode & set_state
// functions for each pin.
//

#include "gpio_uno.h"

#include <stdint.h>

#include "pin_map.h"

// <<<<<<<<<<====================>>>>>>>>>>(pin_set_mode()) this function set
// the pin mode (direction) that mean (output/input).
bool pin_set_mode(volatile unsigned char* DD, pin_mode mode, uint8_t b) {
  *DD |= (mode << b);
  return true;
}

// <<<<<<<<<<====================>>>>>>>>>>(pin_set_state()) this function set
// the pin state (voltage) that mean (high/low).
bool pin_set_state(volatile unsigned char* PT, pin_state state, uint8_t b) {
  if (state == HIGH)
    *PT |= (HIGH << b);
  else
    *PT &= ~(HIGH << b);
  return true;
}
/*
// <<<<<<<<<<====================>>>>>>>>>>(pull_check()) this function check
the input pin state (high/low), and return true or false. bool
pull_check(digital_pin pin_number)
{
  port_bank port;
  port_from_pin(port, pin_number);
  //if(!(PINB&(1<<pin_number)))
  if(!(*port.PINx&(1 << port.bit)))
    return false;
  return true;
}

// <<<<<<<<<<====================>>>>>>>>>>(port_form_pin) this function select
the port (b,c,d) depend on pin number. void port_from_pin(port_bank& port,
digital_pin pin)
{
  if(static_cast<uint8_t>(pin) >= 8)
    {
      port.PORTx = &PORTB;
      port.DDRx = &DDRB;
      port.PINx = &PINB;
      port.bit = static_cast<uint8_t>(pin)-8;
    }
  else
    {
      port.PORTx = &PORTD;
      port.DDRx = &DDRD;
      port.PINx = &PIND;
      port.bit = static_cast<uint8_t>(pin);
    }
}
*/
