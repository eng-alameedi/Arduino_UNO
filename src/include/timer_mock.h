//
// File: timer_mock.h
//
// this file contain the implementation of the timer
// class for mocking purpose, and testing.
//

#ifndef _TIMER_MOCK_H_
#define _TIMER_MOCK_H_

#include <gmock/gmock.h>

#include "gmock/gmock.h"
#include "timer_uno.h"

class TIMER_MOCK : public Timer {
 public:
  TIMER_MOCK() : Timer() {}
  virtual ~TIMER_MOCK() = default;

  MOCK_METHOD(void, count_setup, (), (override));
  MOCK_METHOD(void, count, (), (override));
  MOCK_METHOD(void, ctc_setup, (), (override));
  MOCK_METHOD(void, delay, (unsigned int), (override));
  MOCK_METHOD(bool, is_active, (), (override));
};

#endif  // _TIMER_MOCK_H_
