//
// File: interrupt_uno.h
//
// This file contain the registers for handling interrupt,
// in the board ATmega328p (Arduino Uno).
//

#ifndef _INTERRUPT_UNO_H_
#define _INTERRUPT_UNO_H_

/**
 *
 * @brief: this block define the "moving interrupt between application and boot space"
 * MCU control register, controls the placement of the interrupt vector table
 *
 **/
#define MCUCR (0x55)
#define IVSEL (1)
#define IVCE (0)

/**
 *
 * @brief: this block define the "external interrupt control register A"
 * EICRA, control bits for interrupt sense control
 *
 **/
#define EICRA (0x69)
#define ISC11 (3)
#define ISC10 (2)
#define ISC01 (1)
#define ISC00 (0)

#endif  // _INTERRUPT_UNO_H_
