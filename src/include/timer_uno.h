//
// File: timer_uno.h
//
// this file contain the function for time
// delay method, and watch dog timer for
// the update of the ATmega328p system.
//

#ifndef _TIMER_UNO_H_
#define _TIMER_UNO_H_

#include <stdint.h>

/**
 *
 * @brief: define the 8-bit: timer/counter0 control (A/B), counter register,
 * output compare (A/B), interrupt mask register, and interrupt flag register.
 *
 **/
#define TCCR0A *((volatile uint8_t*)0x44)  // define of Timer/Counter0 Control Register (A).
#define TCCR0B *((volatile uint8_t*)0x45)  // define of Timer/Counter0 Control Register (B)
#define TCNT0 *((volatile uint8_t*)0x46)   // define of Timer/Counter0 Register.
#define OCR0A *((volatile uint8_t*)0x47)   // define of Output Compare0 Register (A)
#define OCR0B *((volatile uint8_t*)0x48)   // define of Output Compare0 Register (B)
#define TIMSK0 *((volatile uint8_t*)0x6E)  // define of Timer/Counter0 Interrupt Mask Register
#define TIFR0 *((volatile uint8_t*)0x35)   // define of Timer/Counter0 0 Interrupt Flag Register

/**
 *
 * @brief: define the 16-bit: timer counter control (A/B), counter register,
 * output compare (A/B), interrupt mask register, and interrupt flag register.
 *
 **/
#define TCCR1A *((volatile uint8_t*)0x80)  // define of Timer/Counter1 Control Register (A).
#define TCCR1B *((volatile uint8_t*)0x81)  // define of Timer/Counter1 Control Register (B).
#define TCCR1C *((volatile uint8_t*)0x82)  // define of Timer/Counter1 Control Register (C).
#define TCNT1H *((volatile uint8_t*)0x85)  // define of Timer/Counter1 Register.
#define TCNT1L *((volatile uint8_t*)0x84)  // define of Timer/Counter1 Register.
#define OCR1AH *((volatile uint8_t*)0x89)  // define of Output Compare1 Register (A) High.
#define OCR1AL *((volatile uint8_t*)0x88)  // define of Output Compare1 Register (A) LoW.
#define OCR1BH *((volatile uint8_t*)0x8B)  // define of Output Compare1 Register (B) High.
#define OCR1BL *((volatile uint8_t*)0x8A)  // define of Output Compare1 Register (B) Low.
#define ICR1H *((volatile uint8_t*)0x87)   // define of Input Capture Register 1 High.
#define ICR1L *((volatile uint8_t*)0x86)   // define of Input Capture Register 1 Low.
#define TIMSK1 *((volatile uint8_t*)0x6F)  // define of Timer/Counter1 Interrupt Mask Register.
#define TIFR1 *((volatile uint8_t*)0x36)   // Timer/Counter1 Interrupt Flag Register.

/**
 *
 * @brief: define the 8-bit: timer/counter2 control (A/B), counter register,
 * output compare (A/B), interrupt mask register, and interrupt flag register.
 *
 **/
#define TCCR2A *((volatile uint8_t*)0xB0)  // define of Timer/Counter0 Control Register (A).
#define TCCR2B *((volatile uint8_t*)0xB1)  // define of Timer/Counter0 Control Register (B)
#define TCNT2 *((volatile uint8_t*)0xB2)   // define of Timer/Counter0 Register.
#define OCR2A *((volatile uint8_t*)0xB3)   // define of Output Compare0 Register (A)
#define OCR2B *((volatile uint8_t*)0xB4)   // define of Output Compare0 Register (B)
#define TIMSK2 *((volatile uint8_t*)0x70)  // define of Timer/Counter0 Interrupt Mask Register
#define TIFR2 *((volatile uint8_t*)0x37)   // define of Timer/Counter0 0 Interrupt Flag Register

/**
 *
 * @brief: define the global interrupt register SREG for the ATmega328p
 * and config the 7th bit which (I).
 *
 **/
#define SREG *((volatile uint8_t*)0x3F)  // define the global interrupt register (I) is the 7th bit.

//<<<<<<<<<<<<<<<<<<<<<<<<=============================================>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

/**
 *
 * @brief: this abstract class timer definition that
 * will overridden by timer0, timer1, and timer2 class
 *
 **/
class Timer {
 public:
  Timer();
  virtual ~Timer() = default;

  virtual void count_setup() = 0;
  virtual void count() = 0;

  virtual void ctc_setup() = 0;
  virtual void delay(unsigned int) = 0;

  // virtual void pwm_setup() = 0;
  // virtual void pwm() = 0;

  virtual bool is_active() = 0;
  // virtual void irq_run() = 0;

  bool get_active() const;

 protected:
  int counter{};

 private:
  bool active{false};
};
void timer_ctc_setup();

void delay(unsigned int);

#endif  // _TIMER_UNO_H_
