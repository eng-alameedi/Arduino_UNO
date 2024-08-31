//
// File: gpio_real.h
//
// this file contain the class gpio_real that,
// inherited from gpio class so simulate the,
// real ATmega328p microchip
//

#ifndef _GPIO_REAL_H_
#define _GPIO_REAL_H_

#include "gpio_init.h"

class GPIO_REAL : protected GPIO {
 protected:
  void set_pinmode(digital_pin, pin_mode) override;
};

#endif  // _GPIO_REAL_H_
