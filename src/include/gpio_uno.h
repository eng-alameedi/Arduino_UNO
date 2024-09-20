//
// File: gpio_uno.h
//
// this file contain definition of the arduino uno,
// gpio ports type, mode, and state for all the pin.
// group B,C,D for digital pin from (0 - 13), and
// analog pin from (1 - 6).
//

#ifndef _GPIO_UNO_H_
#define _GPIO_UNO_H_

#include <stdint.h>

/**
 * @brief: this block of definition for the block (B) of ATmega328p register.
 *
 * @PORTB: this is the port (b) register which set the bit to high or low.
 *
 * @DDRB: this is the ddr (b) register which set the bit to input or output.
 *
 * @PINB: this the pin (b) register which read the input digital signal to pin.
 **/
#define PORTB (0x25)
#define DDRB (0x24)
#define PINB (0x23)

/**
 * @brief: this block of definition for the block (C) of ATmega328p register.
 *
 * @PORTB: this is the port (c) register which set the bit to high or low.
 *
 * @DDRB: this is the ddr (c) register which set the bit to input or output.
 *
 * @PINB: this the pin (c) register which read the input digital signal to pin.
 **/
#define PORTC *((volatile uint8_t*)0x28)
#define DDRC *((volatile uint8_t*)0x27)
#define PINC *((volatile uint8_t*)0x26)

/**
 * @brief: this block of definition for the block (B) of ATmega328p register.
 *
 * @PORTB: this is the port (d) register which set the bit to high or low.
 *
 * @DDRB: this is the ddr (d) register which set the bit to input or output.
 *
 * @PINB: this the pin (d) register which read the input digital signal to pin.
 **/
#define PORTD *((volatile uint8_t*)0x2B)
#define DDRD *((volatile uint8_t*)0x2A)
#define PIND *((volatile uint8_t*)0x29)

#endif  // _GPIO_UNO_H_
