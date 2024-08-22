//
// File: timer_uno.h
//
// this file contain the function for time
// delay method, and watch dog timer for
// the update of the ATmega328p system.
//

#ifndef _TIMER_UNO_H_
#define _TIMER_UNO_H_

/**
 *
 * @brief: define the 8-bit: timer counter control (A/B), counter register,
 * output compare (A/B), interrupt mask register, and interrupt flag register.
 *
 **/
#define TCCR0A (0x44) // define of Timer/Counter0 Control Register (A).
#define TCCR0B (0x45) // define of Timer/Counter0 Control Register (B)
#define TCNT0  (0x46) // define of Timer/Counter0 Register.
#define OCR0A  (0x47) // define of Output Compare0 Register (A)
#define OCR0B  (0x48) // define of Output Compare0 Register (B)
#define TIMSK0 (0x6E) // define of Timer/Counter0 Interrupt Mask Register
#define TIFR0  (0x35) // define of Timer/Counter0 0 Interrupt Flag Register

/**
 *
 * @brief: define the 16-bit: timer counter control (A/B), counter register,
 * output compare (A/B), interrupt mask register, and interrupt flag register.
 *
 **/
#define TCCR1A (0x80) // define of Timer/Counter1 Control Register (A).
#define TCCR1B (0x81) // define of Timer/Counter1 Control Register (B).
#define TCCR1C (0x82) // define of Timer/Counter1 Control Register (C).
#define TCNT1H (0x85) // define of Timer/Counter1 Register.
#define TCNT1L (0x84) // define of Timer/Counter1 Register.
#define OCR1AH (0x89) // define of Output Compare1 Register (A) High.
#define OCR1AL (0x88) // define of Output Compare1 Register (A) LoW.
#define OCR1BH (0x8B) // define of Output Compare1 Register (B) High.
#define OCR1BL (0x8A) // define of Output Compare1 Register (B) Low.
#define ICR1H  (0x87) // define of Input Capture Register 1 High.
#define ICR1L  (0x86) // define of Input Capture Register 1 Low.
#define TIMSK1 (0x6F) // define of Timer/Counter1 Interrupt Mask Register.
#define TIFR1  (0x36) // Timer/Counter1 Interrupt Flag Register.


// code here

#endif       // _TIMER_UNO_H_
