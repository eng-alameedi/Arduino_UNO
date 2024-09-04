//
// File: gpio_init.h
//
// this file contain the main gpio class,
// that initiate the gpio (DDRx,PORTx,PINx),
// depend on pin number.
//

#ifndef _GPIO_INIT_H_
#define _GPIO_INIT_H_

#include "pin_map.h"

class GPIO {
 protected:
  volatile unsigned char* DDRx;   // pointer that hold the address of DDR(B,C,D)
                                  // depend on pin number.
  volatile unsigned char* PORTx;  // pointer that hold the address of
                                  // PORT(B,C,D) depend on pin number.
  volatile unsigned char* PINx;   // pointer that hold the address of PIN(B,C,D)
                                  // depend on pin number.
  uint8_t bit;                    // the correct bit of the pin selected.
  digital_pin pin;                // enum define the pin number map.
  pin_mode mode;                  // enum pin mode (OUT,IN).
  pin_state state;                // enum pin state (HIGH,LOW).
  int error_count{};  // error count when function not work properly.

 public:
  GPIO(digital_pin, pin_mode);  // GPIO class constructor.
  ~GPIO();                      // GPIO class destructor.
  digital_pin get_pin() const;
  pin_mode get_mode() const;
  pin_state get_state() const;
  volatile unsigned char* get_ddrx() const;
  volatile unsigned char* get_portx() const;

 protected:
  virtual void set_pinmode() = 0;  // set the pin mode (out,in)

  virtual void set_pinstate(pin_state) = 0;  // set the pin state (low,high).

  virtual bool digital_pinread() = 0;  // read the pin state (0,1).
};

#endif  // _GPIO_INIT_H_
