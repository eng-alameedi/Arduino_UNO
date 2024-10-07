//
// File: interrupt_uno.h
//
// This file contain the registers for handling interrupt,
// in the board ATmega328p (Arduino Uno).
//

#ifndef _INTERRUPT_UNO_H_
#define _INTERRUPT_UNO_H_

#include "utils_uno.h"

/**
 *
 * @brief: this block define the "moving interrupt between application and boot space"
 * MCU control register, controls the placement of the interrupt vector table
 *
 **/
#define MCUCR (0x35)
#define BODS (6)
#define BODSE (5)
#define PUD (4)
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

/**
 *
 * @brief: this block define the "external interrupt mask register"
 * EIMSK, control bits for interrupt INT1, and INT0
 *
 **/
#define EIMSK (0x1D)
#define INT1 (1)
#define INT0 (0)

/**
 *
 * @brief: this block define the "external interrupt flag register"
 * EIFR, control bits for interrupt INTF1, and INTF0
 *
 **/
#define EIFR (0x1C)
#define INTF1 (1)
#define INTF0 (0)

/**
 *
 * @brief: this block define the "pin change interrupt control register"
 * PCICR, control bits for pin change interrupt control
 *
 **/
#define PCICR (0x68)
#define PCIE2 (2)
#define PCIE1 (1)
#define PCIE0 (0)

/**
 *
 * @brief: this block define the "pin change flag register"
 * PCICR, control bits for interrupt flag when pin change
 *
 **/
#define PCIFR (0x1B)
#define PCIF2 (2)
#define PCIF1 (1)
#define PCIF0 (0)

/**
 *
 * @brief: this block define the "pin change mask register 2"
 * PCMSK2, control bits for pin change mask
 *
 **/
#define PCMSK2 (0x6D)
#define PCINT23 (7)
#define PCINT22 (6)
#define PCINT21 (5)
#define PCINT20 (4)
#define PCINT19 (3)
#define PCINT18 (2)
#define PCINT17 (1)
#define PCINT16 (0)

/**
 *
 * @brief: this block define the "pin change mask register 1"
 * PCMSK1, control bits for interrupt pin change mask.
 *
 **/
#define PCMSK1 (0x6C)
#define PCINT14 (6)
#define PCINT13 (5)
#define PCINT12 (4)
#define PCINT11 (3)
#define PCINT10 (2)
#define PCINT9 (1)
#define PCINT8 (0)

/**
 *
 * @brief: this block define the "pin change mask register 0"
 * PCMSK0, control bits for interrupt pin change mask.
 *
 **/
#define PCMSK0 (0x6B)
#define PCINT7 (7)
#define PCINT6 (6)
#define PCINT5 (5)
#define PCINT4 (4)
#define PCINT3 (3)
#define PCINT2 (2)
#define PCINT1 (1)
#define PCINT0 (0)

/**
 *
 * @brief: define the mostly used interrupt routine in ATmega328p
 *
 **/
#define RESET (_VECTOR(0))
#define INIT0 (_VECTOR(1))

#endif  // _INTERRUPT_UNO_H_
