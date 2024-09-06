#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Arduino_Uno.h"

using ::testing::AtLeast;

TEST(GPIOTest, ClassInit) {
  GPIO_MOCK g(PIN13, OUTPUT);
  EXPECT_CALL(g, set_pinmode()).Times(AtLeast(1));
  g.set_pinmode();
}

/*
// Test case for GPIO pin initialization
TEST(GPIOTest, Initialization) {
  GPIO_REAL gpio(PIN13, OUTPUT);
  ASSERT_EQ(gpio.get_pin(), PIN13);
  ASSERT_EQ(gpio.get_mode(), OUTPUT);
  ASSERT_EQ(gpio.get_bit(), 5);
}

// Test case for setting and getting pin state
TEST(GPIOTest, PinState) {
  GPIO_REAL gpio(PIN12, OUTPUT);
  ASSERT_EQ(gpio.get_state(), LOW);
  gpio.set_pinstate(HIGH);
  ASSERT_EQ(gpio.get_state(), HIGH);
  ASSERT_EQ(gpio.get_bit(), 4);
}
TEST(GPIOTest, PinMap) {
  ASSERT_EQ(static_cast<uint8_t>(PIN13), 13);
  ASSERT_EQ(static_cast<uint8_t>(OUTPUT), 1);
  ASSERT_EQ(static_cast<uint8_t>(INPUT), 0);
  ASSERT_EQ(static_cast<uint8_t>(LOW), 0);
  ASSERT_EQ(static_cast<uint8_t>(HIGH), 1);
}

TEST(GPIOTest, Pin11Test) {
  GPIO_REAL gpio(PIN11, OUTPUT);
  ASSERT_EQ(gpio.get_bit(), 3);
  ASSERT_EQ(static_cast<int>((gpio.get_ddrx())), 8);
  ASSERT_EQ(static_cast<int>((gpio.get_portx())), 0);
  gpio.set_pinstate(HIGH);
  ASSERT_EQ(static_cast<int>((gpio.get_portx())), 8);
}

TEST(GPIOTest, PinRead) {
  GPIO_REAL gpio(PIN5, INPUT);
  ASSERT_EQ(gpio.get_bit(), 5);
  ASSERT_EQ(gpio.get_pin(), PIN5);
  ASSERT_EQ(gpio.get_mode(), INPUT);
  gpio.set_pinstate(HIGH);
  ASSERT_EQ(static_cast<int>((gpio.get_ddrx())), 0);
  ASSERT_EQ(static_cast<int>((gpio.get_portx())), 32);
  ASSERT_EQ(gpio.digital_pinread(), false);
}
*/

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
