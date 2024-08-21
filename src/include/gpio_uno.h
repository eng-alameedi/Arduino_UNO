//
// File: gpio_uno.h
//
// this file contain definition of the arduino uno,
// gpio ports type, mode, and state for all the pin.
//

#ifndef _GPIO_UNO_H_
#define _GPIO_UNO_H_

#define PORTB     (0x25)                    // gpio (B) group data register.
#define DDRB      (0x24)                    // gpio (B) group data direction register.
#define PINB      (0x23)                    // gpio (B) group input pins address.

#define PORTC     (0x28)                    // gpio (C) group data register.
#define DDRC      (0x27)                    // gpio (C) group data direction register.
#define PINC      (0x26)                    // gpio (C) group input pins address.

#define PORTD     (0x2B)                    // gpio (D) group data register.
#define DDRD      (0x2A)                    // gpio (D) group data direction register.
#define PIND      (0x29)                    // gpio (D) group input pins address.

// code here

#endif     // _GPIO_UNO_H_
