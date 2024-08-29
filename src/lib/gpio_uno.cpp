//
// File: gpio_uno.cpp
//
// this file contain the implementation of the header
// file gpio_uno.h define the set_mode & set_state
// functions for each pin.
//

#include "gpio_uno.h"
#include "pin_map.h"

#include <stdint.h>

// <<<<<<<<<<====================>>>>>>>>>>(pin_set_mode()) this function set the pin mode (direction) that mean (output/input).
void pin_set_mode(digital_pin pin, pin_mode mode)
{
  port_bank port;
  port_from_pin(port, pin);
  *port.DDRx |= (mode << port.bit);
  // DDRB |= (mode << static_cast<uint8_t>(pin));
}

// <<<<<<<<<<====================>>>>>>>>>>(pin_set_state()) this function set the pin state (voltage) that mean (high/low).
void pin_set_state(unsigned int pin, pin_state state)
{
  if(state == HIGH)
    PORTB |= (HIGH << pin);
  else
    PORTB &= ~(HIGH << pin);
}

// <<<<<<<<<<====================>>>>>>>>>>(pull_check()) this function check the input pin state (high/low), and return true or false.
bool pull_check(const unsigned int& pin_number)
{
  if(!(PINB&(1<<pin_number)))
    return false;
  return true;
}

// <<<<<<<<<<====================>>>>>>>>>>(port_form_pin) this function select the port (b,c,d) depend on pin number.
void port_from_pin(port_bank& port, digital_pin pin)
{
  if(static_cast<uint8_t>(pin) >= 8)
    {
      port.PORTx = &PORTB;
      *port.DDRx = DDRB;
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
