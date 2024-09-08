//
// File: gpio_mock.h
//
// this file contain the implementation of the gpio
// class for mocking purpose, and testing.
//

#ifndef _GPIO_MOCK_H_
#define _GPIO_MOCK_H_

#include <gmock/gmock.h>
#include <stdint.h>

#include "gmock/gmock.h"
#include "gpio_init.h"
#include "pin_map.h"

class GPIO_MOCK : public GPIO {
 public:
  GPIO_MOCK(digital_pin pin, pin_mode mode) : GPIO(pin, mode) {}
  virtual ~GPIO_MOCK() = default;
  MOCK_METHOD(void, set_pinmode, (), (override));
  MOCK_METHOD(void, set_pinstate, (pin_state), (override));
  MOCK_METHOD(bool, digital_pinread, (), (override));

  MOCK_METHOD(uint8_t, get_ddrx, (), (const));
};

#endif  // _GPIO_MOCK_H_
