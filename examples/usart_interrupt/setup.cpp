//
// File: setup.cpp
//
// this file will contain the user example led-button toggle
// that test and implement the GPIO_REAL.
//

#include "Arduino_test.h"

char msg;
ISR(USART_RX) { msg = usart_receive(); }
void usart_rx_interrupt_setup(void);

PIN_INIT(PIN13, OUTPUT);
PIN_INIT(PIN8, OUTPUT);
PIN_INIT(PIN2, INPUT);

void setup() {
  PIN_STATE(PIN8, LOW);
  PIN_STATE(PIN2, HIGH);
  usart_rx_interrupt_setup();
  usart_init();
}

void loop() {
  PIN_STATE(PIN13, HIGH);
  DELAY(1000);
  PIN_STATE(PIN13, LOW);
  DELAY(1000);
  if (PIN_READ(PIN2)) {
    usart_transmit(msg);
    PIN_STATE(PIN8, HIGH);
    DELAY(1000);
  }
  PIN_STATE(PIN8, LOW);
}

void usart_rx_interrupt_setup(void) { _MEM_8(UCSR0B) |= _BV(RXCIE0); }
