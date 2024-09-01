#include <gtest/gtest.h>

#include "gpio.h"

// Test case for GPIO pin initialization
TEST(GPIOTest, Initialization) {
  GPIO gpio(PIN13, OUTPUT);
  ASSERT_EQ(gpio.get_pin(), PIN13);
  ASSERT_EQ(gpio.get_mode(), OUTPUT);
}

// Test case for setting and getting pin state
TEST(GPIOTest, SetGetState) {
  GPIO gpio(PIN13, OUTPUT);
  gpio.set_state(HIGH);
  ASSERT_EQ(gpio.get_state(), HIGH);
  gpio.set_state(LOW);
  ASSERT_EQ(gpio.get_state(), LOW);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
