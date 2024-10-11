#include "serial_uno.h"

void usart_init() {
  _MEM_8(UBBR0H) = (uint8_t)(UBRR >> 8);  // set the ubrr upper bits
  _MEM_8(UBBR0L) = (uint8_t)(UBRR);       // set the ubrr lower bits

  _MEM_8(UCSR0B) = (1 << RXEN0) | (1 << TXEN0);    // enable receive, and send data
  _MEM_8(UCSR0C) = (1 << UCSZ01) | (1 << UCSZ00);  // set the frame bits to 8 011
}

void usart_format(const char* message) {
  while (*message) {
    usart_transmit(*message++);
  }
}

void usart_transmit(char letter) {
  while (!(_MEM_8(UCSR0A) & (1 << UDRE0)))  // check the register bit UDRE0 is it ready for next data
    ;
  _MEM_8(UDR0) = letter;
}
