//
// File: gpio_real.cpp
//
// this file contain the implementation of the,
// gpio real class that will upload to the board,
// of Adduino uno.
//

#include "gpio_real.h"

#include "gpio_init.h"
#include "gpio_uno.h"
#include "pin_map.h"

GPIO_REAL::GPIO_REAL(digital_pin p, pin_mode m) : GPIO(p, m) {
  set_pinmode(p, m);
}

GPIO_REAL::~GPIO_REAL() {
  // code here
}

void GPIO_REAL::set_pinmode(digital_pin p, pin_mode m) {
  bool condition{false};
  condition = pin_set_mode(p, m);
}

void GPIO_REAL::set_pinstate(digital_pin p, pin_state s) {
  // code here
}

int GPIO_REAL::digital_pinread(digital_pin p) {
  // code here
  return 0;
}
