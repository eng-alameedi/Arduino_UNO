//
// File: gpio_real.cpp
//
// this file contain the implementation of the,
// gpio real class that will upload to the board,
// of Adduino uno.
//

#include "gpio_real.h"

#include "gpio_init.h"
#include "pin_map.h"

GPIO_REAL::GPIO_REAL(digital_pin p, pin_mode m) : GPIO(p, m) { set_pinmode(); }

GPIO_REAL::~GPIO_REAL() {
  // code here
}

void GPIO_REAL::set_pinmode() {
  // if (!(pin_set_mode(DDRx, mode, bit))) error_count += 1;
  *DDRx |= (mode << bit);
}

void GPIO_REAL::set_pinstate(pin_state st) {
  // if (!(pin_set_state(PORTx, st, bit))) error_count += 1;
  if (st == HIGH) {
    *PORTx |= (HIGH << bit);
    state = st;
  } else if (st == LOW) {
    *PORTx &= (HIGH << bit);
    state = st;
  } else {
    error_count += 1;
  }
}

bool GPIO_REAL::digital_pinread() {
  if (!(*PINx & (HIGH << bit))) return false;
  return true;
}
