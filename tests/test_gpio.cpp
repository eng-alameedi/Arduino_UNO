#include <gtest/gtest.h>

#include "Arduino_Uno.h"
#include "gpio_real.h"
#include "pin_map.h"

// Test case for GPIO pin initialization
TEST(GPIOTest, Initialization) {
  GPIO_REAL gpio(PIN13, OUTPUT);
  ASSERT_EQ(gpio.get_pin(), PIN13);
  ASSERT_EQ(gpio.get_mode(), OUTPUT);
}

// Test case for setting and getting pin state
TEST(GPIOTest, SetGetState) {
  GPIO_REAL gpio(PIN12, OUTPUT);
  ASSERT_EQ(gpio.get_state(), LOW);
  gpio.set_pinstate(HIGH);
  ASSERT_EQ(gpio.get_state(), HIGH);
}
TEST(GPIOTest, VarTest) {
  ASSERT_EQ(static_cast<uint8_t>(PIN13), 13);
  ASSERT_EQ(static_cast<uint8_t>(OUTPUT), 1);
}

TEST(GPIOTest, PortTest) {
  GPIO_REAL gpio(PIN11, OUTPUT);
  ASSERT_EQ(static_cast<int>(*(gpio.get_ddrx())), 8);
  ASSERT_EQ(static_cast<int>(*(gpio.get_portx())), 0);
  gpio.set_pinstate(HIGH);
  ASSERT_EQ(static_cast<int>(*(gpio.get_portx())), 8);
}

TEST(GPIOTest, PinRead) {
  GPIO_REAL gpio(PIN5, INPUT);
  ASSERT_EQ(gpio.get_pin(), PIN5);
  ASSERT_EQ(gpio.get_mode(), INPUT);
  gpio.set_pinstate(HIGH);
  ASSERT_EQ(static_cast<int>(*(gpio.get_ddrx())), 0);
  ASSERT_EQ(static_cast<int>(*(gpio.get_portx())), 32);
  ASSERT_EQ(gpio.digital_pinread(), false);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
