//
// File: gpio_real.cpp
//
// this file contain the implementation of the,
// gpio real class that will upload to the board,
// of Adduino uno.
//

#include "gpio_real.h"

// #include <csignal>
// #include <cstdlib>
// #include <iostream>

#include "gpio_init.h"
#include "pin_map.h"

GPIO_REAL::GPIO_REAL(digital_pin p, pin_mode m) : GPIO(p, m) {
  // std::signal(SIGSEGV, SignalHandler);
  set_pinmode();
}

GPIO_REAL::~GPIO_REAL() noexcept {
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
  } else {
    *PORTx &= ~(HIGH << bit);
    state = st;
  }
}

bool GPIO_REAL::digital_pinread() {
  if (!(*PINx & (HIGH << bit))) return false;
  return true;
}
/*
void GPIO_REAL::SignalHandler(int signal) {
  if (signal == SIGSEGV) {
    std::cerr << "Error: Segmentation Fault Detected..." << std::endl;
    std::exit(signal);

    }*/
