//
// File: gpio_init.cpp
//
// this file contain the implementation of the,
// class GPIO, and all it's methods.
//

#include "gpio_init.h"

#include "gpio_uno.h"
#include "pin_map.h"
#include "utils_uno.h"

GPIO::GPIO(digital_pin pin, pin_mode mode) : pin{pin}, mode{mode}, state{LOW} {
  if (pin >= 8) {
    DDRx = MRF(DDRB);
    PORTx = MRF(PORTB);
    PINx = MRF(PINB);
    bit = static_cast<uint8_t>(pin) - 8;
  } else {
    DDRx = MRF(DDRD);
    PORTx = MRF(PORTD);
    PINx = MRF(PIND);
    bit = static_cast<uint8_t>(pin);
  }
}
/*
GPIO::~GPIO() {
  // code here
}
*/
digital_pin GPIO::get_pin() const { return pin; }

pin_mode GPIO::get_mode() const { return mode; }

pin_state GPIO::get_state() const { return state; }

uint8_t GPIO::get_bit() const { return bit; }

uint8_t GPIO::get_ddrx() const { return *DDRx; }

uint8_t GPIO::get_portx() const { return *PORTx; }
