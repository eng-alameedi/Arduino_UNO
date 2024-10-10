//
// File: serial_uno.h
//
// this file contain the basic definition of USART
// communication for the ATmega328p microcontroller
// with registers and memory address.
//

#ifndef _SERIAL_UNO_H_
#define _SERIAL_UNO_H_

#include <stdint.h>

#define F_CPU 16000000UL
#define BAUD 9600
#define UBRR ((F_CPU / (16UL * BAUD)) - 1)

#define UDR0 (0xC6)

#define UBBR0H (0xC5)

#define UBBR0L (0xC4)

#define UCSR0A (0xC0)
#define RXC0 (7)
#define TXC0 (6)
#define UDRE0 (5)
#define FE0 (4)
#define DOR0 (3)
#define UPE0 (2)
#define U2X0 (1)
#define MPCM0 (0)

#define UCSR0B (0xC1)
#define RXCIE0 (7)
#define TXCIE0 (6)
#define UDRIE0 (5)
#define RXEN0 (4)
#define TXEN0 (3)
#define UCSZ02 (2)
#define RXB80 (1)
#define TXB80 (0)

#define UCSR0C (0xC2)
#define UMSEL01 (7)
#define UMSEL00 (6)
#define UPM01 (5)
#define UPM00 (4)
#define USBS0 (3)
#define UCSZ01 (2)
#define UCSZ00 (1)
#define UCPOL0 (0)

void usart_init(void);
void usart_transmit(char);
char usart_receive();

#define _MEM_8(reg_add) (*(volatile uint8_t*)reg_add)

#endif  // _SERIAL_UNO_H_
