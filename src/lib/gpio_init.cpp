//
// File: gpio_init.cpp
//
// this file contain the implementation of the,
// class GPIO, and all it's methods.
//

#include "gpio_init.h"

#include "gpio_uno.h"
#include "pin_map.h"

GPIO::GPIO(digital_pin pin, pin_mode mode) : pin{pin}, mode{mode}, state{LOW} {
  unsigned char a = 0;
  unsigned char b = 0;
  unsigned char c = 0;
  if (pin >= 8) {
    //*DDRx = DDRB;
    //*PORTx = PORTB;
    //*PINx = PINB;
    DDRx = &a;
    PORTx = &b;
    PINx = &c;
    bit = static_cast<uint8_t>(pin) - 8;
  } else {
    //*DDRx = DDRD;
    //*PORTx = PORTD;
    //*PINx = PIND;
    DDRx = &a;
    PORTx = &b;
    PINx = &c;
    bit = static_cast<uint8_t>(pin);
  }
}

GPIO::~GPIO() {
  // code here
}

digital_pin GPIO::get_pin() const { return pin; }

pin_mode GPIO::get_mode() const { return mode; }

pin_state GPIO::get_state() const { return state; }

volatile unsigned char* GPIO::get_ddrx() const { return DDRx; }

volatile unsigned char* GPIO::get_portx() const { return PORTx; }
