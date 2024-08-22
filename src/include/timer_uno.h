//
// File: timer_uno.h
//
// this file contain the function for time
// delay method, and watch dog timer for
// the update of the ATmega328p system.
//

#ifndef _TIMER_UNO_H_
#define _TIMER_UNO_H_

#define TCCR0A (0x44) // define of Timer/Counter Control Register (A).
#define TCCR0B (0x45) // define of Timer/Counter Control Register (B)
#define TCNT0  (0x46) // define of Timer/Counter Register.
#define OCR0A  (0x47) // define of Output Compare Register (A)
#define OCR0B  (0x48) // define of Output Compare Register (B)
#define TIMSK0 (0x6E) // define of Timer/Counter Interrupt Mask Register
#define TIFR0  (0x35) // define of Timer/Counter 0 Interrupt Flag Register

// code here

#endif       // _TIMER_UNO_H_
