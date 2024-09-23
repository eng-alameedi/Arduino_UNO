//
// File: gpio_init.h
//
// this file contain the main gpio class definition
// that initiate the gpio (DDRx,PORTx,PINx) depend
// on pin number, also contain pure virtual method
// that can overridden by other classes like the
// class GPIO_REAL, and GPIO_MOCK class.
//

#ifndef _GPIO_INIT_H_
#define _GPIO_INIT_H_

#include <stdint.h>

#include "pin_map.h"

class GPIO {
 protected:
  volatile uint8_t* DDRx{nullptr};  // Pointer that point to DDR (B,C,D)

  volatile uint8_t* PORTx{nullptr};  // Pointer that point to PORT (B,C,D)

  volatile uint8_t* PINx{nullptr};  // Pointer that point to PIN (B,C,D)

  virtual void set_pinstate(pin_state) = 0;  // Set pin state (high/low)

  virtual void set_pinmode() = 0;  // set the pin mode (out,in)

  virtual bool digital_pinread() = 0;  // read the pin state (0,1).

  uint8_t bit{};  // the correct bit of the selected pin

  digital_pin pin;  // enum define the pin number map.

  pin_mode mode{INPUT};  // enum pin mode (OUT,IN).

  pin_state state{LOW};  // enum pin state (HIGH,LOW).

  int error_count{};  // error count when function not work properly.

 public:
  GPIO(digital_pin, pin_mode);  // GPIO class constructor.
  // virtual ~GPIO() = 0;          // GPIO class destructor.
  ~GPIO();

  digital_pin get_pin() const;  // method return digital pin

  pin_mode get_mode() const;  // method return mode (out/in)

  pin_state get_state() const;  // method return state (high/low)

  uint8_t get_bit() const;  // method return bit number

  uint8_t get_ddrx() const;  // method return the value of DDR

  uint8_t get_portx() const;  // method return the value of PORT

  uint8_t get_pinx() const;  // method return the value of PIN
};

#endif  // _GPIO_INIT_H_
