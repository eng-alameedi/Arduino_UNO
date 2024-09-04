//
// File: utils_uno.h
//
// this file contain some required utilities
// that help in simplify the use of this
// library.
//

#ifndef _UTILS_UNO_H_
#define _UTILS_UNO_H_

#define PIN_MODE(number, mode) \
  pin_set_mode(number,         \
               mode)  // define a macro to call the function set_pin_mode
#define PIN_STATE(number, state) \
  pin_set_state(number,          \
                state)  // define a macro to call the function set_pin_state
#define PIN_INIT(number, mode)  \
  GPIO_REAL gp_##number(number, \
                        mode)  // define a macro to initial the class GPIO

#endif  // _UTILS_UNO_H_
