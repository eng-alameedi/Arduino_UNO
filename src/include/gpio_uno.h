//
// File: gpio_uno.h
//
// this file contain definition of the arduino uno,
// gpio ports type, mode, and state for all the pin.
//

#ifndef _GPIO_UNO_H_
#define _GPIO_UNO_H_

#include "pin_map.h"
#include <stdint.h>                                                   // to call the (uint8_t) type.

#define PORTB     *((volatile unsigned char*)0x25)                    // gpio (B) group data register.
#define DDRB      *((volatile unsigned char*)0x24)                    // gpio (B) group data direction register.
#define PINB      *((volatile unsigned char*)0x23)                    // gpio (B) group input pins address.

#define PORTC     *((volatile unsigned char*)0x28)                    // gpio (C) group data register.
#define DDRC      *((volatile unsigned char*)0x27)                    // gpio (C) group data direction register.
#define PINC      *((volatile unsigned char*)0x26)                    // gpio (C) group input pins address.

#define PORTD     *((volatile unsigned char*)0x2B)                    // gpio (D) group data register.
#define DDRD      *((volatile unsigned char*)0x2A)                    // gpio (D) group data direction register.
#define PIND      *((volatile unsigned char*)0x29)                    // gpio (D) group input pins address.

enum pin_mode { INPUT = 0, OUTPUT = 1 };                              // define a pin mode as (output) or (input).
enum pin_state { LOW = 0, HIGH = 1 };                                 // define a pin state voltage as (low) or (high).

/**
 *
 * @brief: this function set the pin mode (output) or (input) depend on pin number.
 *
 * @param1: this function take (uint8_t) for pin number.
 *
 * @param2: this function take (pin_mode) for mode (output/input).
 *
 * @return: this function return nothing (void).
 *
 **/
void pin_set_mode(digital_pin, pin_mode);

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
void pin_set_state(unsigned int, pin_state);

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
bool pull_check(const unsigned int &);

/**
 *
 * @brief: this function select the right gpio bank (b,c,d) depend on the
 *         digital pin number.
 *
 * @param1: this function take (volatile unsigned char*) for the port selection (DDR,PORT,PIN)
 *
 * @param2: this function take (unsigned 8bint int type) for the port number
 *
 * @param3: this function take (enum Reg_type) for select different situation of the register
 *
 * @return: this function return nothing (void)
 *
 **/
void port_from_pin(port_bank&, digital_pin);
#endif     // _GPIO_UNO_H_
