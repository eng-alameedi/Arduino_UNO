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
 * @brief: this enumeration contains the digital GPIO pins maps form (0 - 13).
 *         its create a pin maps for digital pin (B, and D) to each bit in (8bit) integer type port.
 *
 **/
enum digital_pin: uint8_t {
  PIN13 = 5,
  PIN12 = 4,
  PIN11 = 3,
  PIN10 = 2,
  PIN9 = 1,
  PIN8 = 0,
  PIN7 = 7,
  PIN6 = 6,
  PIN5 = 5,
  PIN4 = 4,
  PIN3 = 3,
  PIN2 = 2,
  PIN1 =1,
  PIN0 = 0
};

/**
 *
 * @brief: define a struct type for hold the port bank like (DDRx, PORTx, PINx)
 *
 *
 *
 *
 **/
struct port_bank {
  volatile uint8_t* DDRx;
  volatile uint8_t* PORTx;
  volatile uint8_t* PINx;
  uint8_t bit;
}
#endif     // _PIN_MAP_H_
