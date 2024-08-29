//
// File: pin_map.h
//
// this file contain the gpio pin number
// maps for direct use.
//

#ifndef _PIN_MAP_H_
#define _PIN_MAP_H_

#include <stdint.h>

enum pin_mode : uint8_t {
  INPUT = 0,
  OUTPUT = 1
};                                                      // define a pin mode as (output) or (input).
enum pin_state : uint8_t {
  LOW = 0,
  HIGH = 1
};                                                      // define a pin state voltage as (low) or (high).

/**
 *
 * @brief: this enumeration contains the digital GPIO pins maps form (0 - 13).
 *         its create a pin maps for digital pin (B, and D) to each bit in (8bit) integer type port.
 *
 **/
enum digital_pin: uint8_t {
  PIN13 = 13,
  PIN12 = 12,
  PIN11 = 11,
  PIN10 = 10,
  PIN9 = 9,
  PIN8 = 8,
  PIN7 = 7,
  PIN6 = 6,
  PIN5 = 5,
  PIN4 = 4,
  PIN3 = 3,
  PIN2 = 2,
  PIN1 = 1,
  PIN0 = 0
};
#endif     // _PIN_MAP_H_
