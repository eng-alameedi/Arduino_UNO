//
// File: gpio_mock.h
//
// this file contain the implementation of the gpio
// class for mocking purpose, and testing.
//

#ifndef _GPIO_MOCK_H_
#define _GPIO_MOCK_H_

#include <gmock/gmock.h>

#include "gpio_init.h"
#include "pin_map.h"

class GPIO_MOCK : public GPIO {
 public:
  GPIO_MOCK() = default;
  // ~GPIO_MOCK();
  MOCK_METHOD(void, set_pinmode, (), (override));
  MOCK_METHOD(void, set_pinstate, (pin_state), (override));
  MOCK_METHOD(bool, digital_pinread, (), (override));
};

#endif  // _GPIO_MOCK_H_
