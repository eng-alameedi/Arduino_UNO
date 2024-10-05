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
typedef struct {
  uint8_t B0 : 1;
  uint8_t B1 : 1;
  uint8_t B2 : 1;
  uint8_t B3 : 1;
  uint8_t B4 : 1;
  uint8_t B5 : 1;
  uint8_t B6 : 1;
  uint8_t B7 : 1;
} port_B;

/**
 * @brief: this block of definition for the block (C) of ATmega328p register.
 *
 * @PORTB: this is the port (c) register which set the bit to high or low.
 *
 * @DDRB: this is the ddr (c) register which set the bit to input or output.
 *
 * @PINB: this the pin (c) register which read the input digital signal to pin.
 **/

#define PORTC (0x28)
#define DDRC (0x27)
#define PINC (0x26)
typedef struct {
  uint8_t C0 : 1;
  uint8_t C1 : 1;
  uint8_t C2 : 1;
  uint8_t C3 : 1;
  uint8_t C4 : 1;
  uint8_t C5 : 1;
  uint8_t C6 : 1;
  uint8_t C7 : 1;
} port_C;

/**
 * @brief: this block of definition for the block (B) of ATmega328p register.
 *
 * @PORTB: this is the port (d) register which set the bit to high or low.
 *
 * @DDRB: this is the ddr (d) register which set the bit to input or output.
 *
 * @PINB: this the pin (d) register which read the input digital signal to pin.
 **/

#define PORTD (0x2B)
#define DDRD (0x2A)
#define PIND (0x29)
typedef struct {
  uint8_t D0 : 1;
  uint8_t D1 : 1;
  uint8_t D2 : 1;
  uint8_t D3 : 1;
  uint8_t D4 : 1;
  uint8_t D5 : 1;
  uint8_t D6 : 1;
  uint8_t D7 : 1;
} port_D;

#endif  // _GPIO_UNO_H_
