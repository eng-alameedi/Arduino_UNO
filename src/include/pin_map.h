//
// File: pin_map.h
//
// this file contain the gpio pin number
// maps for direct use.
//

#ifndef _PIN_MAP_H_
#define _PIN_MAP_H_

#include <stdint.h>

/**
 *
 * @brief: this enumeration contains the digital GPIO pins maps form (8 - 13).
 *         its create a pin maps for digital pin (B) with (8bit) integer type.
 *
 **/
enum Digital_Pin_B: uint8_t {
  PIN13 = 5,
  PIN12 = 4,
  PIN11 = 3,
  PIN10 = 2,
  PIN9 = 1,
  PIN8 = 0
};

#endif     // _PIN_MAP_H_
