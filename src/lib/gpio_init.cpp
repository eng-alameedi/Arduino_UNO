//
// File: gpio_init.cpp
//
// this file contain the implementation of the,
// class GPIO, and all it's methods.
//

#include "gpio_init.h"

#include "gpio_uno.h"
#include "pin_map.h"

GPIO::GPIO(digital_pin pin, pin_mode mode) : pin{pin}, mode{mode} {
  pin_set_mode(pin, mode);
}

/*GPIO::~GPIO()
{
  // code here
}
*/
