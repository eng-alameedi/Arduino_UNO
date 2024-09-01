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
 private:
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

 public:
  GPIO(digital_pin, pin_mode);  // GPIO class constructor.
  ~GPIO();                      // GPIO class destructor.

 protected:
  virtual void set_pinmode(volatile unsigned char*,
                           pin_mode) = 0;  // set the pin mode (out,in)
  virtual void set_pinstate(
      digital_pin,
      pin_state) = 0;  // set the pin state (low,high) of the output mode pin.
  virtual int digital_pinread(
      digital_pin) = 0;  // read the pin state (0,1) of the input mode pin.
};

#endif  // _GPIO_INIT_H_
