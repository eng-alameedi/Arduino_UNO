//
// File: utils_uno.h
//
// this file contain some required utilities
// that help in simplify the use of this
// library.
//

#ifndef _UTILS_UNO_H_
#define _UTILS_UNO_H_

#include <stdint.h>

#include "gpio_real.h"

// #define PIN_MODE(number, mode) pin_set_mode(number,mode)  // define a macro to call the function set_pin_mode
// #define PIN_STATE(number, state) pin_set_state(number,state)  // define a macro to call the function set_pin_state

// <<<<<<<<<<====================>>>>>>>>>> define a macro to initial the
// GPIO_REAL class.
// #define PIN_INIT(number, mode) GPIO_REAL gp_##number(number, mode)
#define PIN_INIT(number, mode) (gp = new GPIO_REAL(number, mode))

// <<<<<<<<<<====================>>>>>>>>>> define a macro to set pin state
// (high/low)
// #define PIN_STATE(number, mode) gp_##number.set_pinstate(mode)
#define PIN_STATE(number, state) gp->set_pinstate(state)

// <<<<<<<<<<====================>>>>>>>>>> define a macro to read a pin state
#define PIN_READ(number) gp_##number.digital_pinread()

// <<<<<<<<<<====================>>>>>>>>>> define a macro to set the Timer0 class and active the count() method.
#define COUNT()          \
  Timer0 t##__COUNTER__; \
  t##__COUNTER__.count();

// <<<<<<<<<<====================>>>>>>>>>> define a macro to set the Timer0 class and active the count() method.
#define DELAY(ms)        \
  Timer0 t##__COUNTER__; \
  t##__COUNTER__.delay(ms);
/*
#define _SFR(mem_addr) _MIMO(mem_addr)

#define _MIMO(mem_addr) (*(volatile uint8_t*)(mem_addr))
*/

#define MRF(reg_addr) ((volatile uint8_t*)(reg_addr))  // simple memory register function

extern GPIO_REAL* gp;
/**
 *
 * @brief: this function will setup the required pin parameter once such pin
 *direction
 *
 **/
void setup();

/**
 *
 * @brief: this function well continue looping, user will put the pin parameter.
 *
 **/
void loop();
#endif  // _UTILS_UNO_H_
