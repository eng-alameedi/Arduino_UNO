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
#include "pin_map.h"

class GPIO_REAL : public GPIO {
 public:
  GPIO_REAL(digital_pin, pin_mode);
  // ~GPIO_REAL();

  void set_pinstate(pin_state) override;
  bool digital_pinread() override;

 protected:
  void set_pinmode() override;
  // void set_pinstate(pin_state) override;
  // bool digital_pinread() override;
};

#endif  // _GPIO_REAL_H_
