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
bool pin_set_mode(digital_pin pin, pin_mode mode) {
  uint8_t bi;
  if (static_cast<uint8_t>(pin) >= 8) {
    bi = static_cast<uint8_t>(pin) - 8;
    DDRB |= (mode << bi);
    return true;
  } else {
    bi = static_cast<uint8_t>(pin);
    DDRC |= (mode << bi);
    return true;
  }
  return false;
}
/*
// <<<<<<<<<<====================>>>>>>>>>>(pin_set_state()) this function set
the pin state (voltage) that mean (high/low). void pin_set_state(digital_pin
pin, pin_state state)
{
  port_bank port;
  port_from_pin(port, pin);
  if(state == HIGH)
    *port.PORTx |= (HIGH << port.bit);
    //PORTB |= (HIGH << pin);
  else
    //PORTB &= ~(HIGH << pin);
    *port.PORTx &= ~(HIGH << port.bit);
}

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
