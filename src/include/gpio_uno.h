//
// File: gpio_uno.h
//
// this file contain definition of the arduino uno,
// gpio ports type, mode, and state for all the pin.
//

#ifndef _GPIO_UNO_H_
#define _GPIO_UNO_H_

#include "pin_map.h"

#define PORTB *((volatile unsigned char*)0x25)  // gpio (B) group data register.
#define DDRB \
  *((volatile unsigned char*)0x24)  // gpio (B) group data direction register.
#define PINB \
  *((volatile unsigned char*)0x23)  // gpio (B) group input pins address.

#define PORTC *((volatile unsigned char*)0x28)  // gpio (C) group data register.
#define DDRC \
  *((volatile unsigned char*)0x27)  // gpio (C) group data direction register.
#define PINC \
  *((volatile unsigned char*)0x26)  // gpio (C) group input pins address.

#define PORTD *((volatile unsigned char*)0x2B)  // gpio (D) group data register.
#define DDRD \
  *((volatile unsigned char*)0x2A)  // gpio (D) group data direction register.
#define PIND \
  *((volatile unsigned char*)0x29)  // gpio (D) group input pins address.

/**
 *
 * @brief: this function set the pin mode (output) or (input) depend on pin
 *number.
 *
 * @param1: this function take (uint8_t) for pin number.
 *
 * @param2: this function take (pin_mode) for mode (output/input).
 *
 * @return: this function return nothing (void).
 *
 **/
bool pin_set_mode(volatile unsigned char*, pin_mode, uint8_t b);

/**
 *
 * @brief: this function set the pin state to (low) or (high) voltage.
 *
 * @param1: this function take (uint8_t) for pin number.
 *
 * @param2: this function take (pin_state) for set the pin (high/low)
 *
 * @return: this function return nothing (void)
 *
 **/
bool pin_set_state(volatile unsigned char*, pin_state, uint8_t);

/**
 *
 * @brief: this function check the pin input, after set the pin direction to
 *         input, and pull-up resistor to on.
 *
 * @param1: this function take a (unsigned int) pin number.
 *
 * @return: this function return (true) or (false) depend on input pin state.
 *
 **/
bool pull_check(digital_pin);
#endif  // _GPIO_UNO_H_
