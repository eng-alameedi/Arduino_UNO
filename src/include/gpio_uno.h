//
// File: gpio_uno.h
//
// this file contain definition of the arduino uno,
// gpio ports type, mode, and state for all the pin.
//

#ifndef _GPIO_UNO_H_
#define _GPIO_UNO_H_

// #include <cstdint>                          // to call the (uint8_t) type.

#define PORTB     *((volatile unsigned char*)0x25)                    // gpio (B) group data register.
#define DDRB      *((volatile unsigned char*)0x24)                    // gpio (B) group data direction register.
#define PINB      *((volatile unsigned char*)0x23)                    // gpio (B) group input pins address.

#define PORTC     (0x28)                    // gpio (C) group data register.
#define DDRC      (0x27)                    // gpio (C) group data direction register.
#define PINC      (0x26)                    // gpio (C) group input pins address.

#define PORTD     (0x2B)                    // gpio (D) group data register.
#define DDRD      (0x2A)                    // gpio (D) group data direction register.
#define PIND      (0x29)                    // gpio (D) group input pins address.

enum pin_mode { INPUT = 0, OUTPUT = 1 };    // define a pin mode as (output) or (input).
enum pin_state { LOW = 0, HIGH = 1 };       // define a pin state voltage as (low) or (high).

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
void pin_set_mode(unsigned int, pin_mode);

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


#endif     // _GPIO_UNO_H_
