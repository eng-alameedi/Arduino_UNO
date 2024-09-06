#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Arduino_Uno.h"
#include "gmock/gmock.h"
#include "gpio_mock.h"
#include "pin_map.h"

using ::testing::AtLeast;

TEST(GPIOTest, SetModeCall) {
  GPIO_MOCK g(PIN13, OUTPUT);
  EXPECT_CALL(g, set_pinmode()).Times(AtLeast(1));
  g.set_pinmode();
}

TEST(GPIOTest, SetStateCall) {
  GPIO_MOCK g(PIN13, INPUT);
  EXPECT_CALL(g, set_pinstate(HIGH)).Times(AtLeast(1));
  g.set_pinstate(HIGH);
}

TEST(GPIOTest, DigitalPinRead) {
  GPIO_MOCK g(PIN13, INPUT);
  EXPECT_CALL(g, digital_pinread()).Times(AtLeast(1));
  g.digital_pinread();
}

TEST(GPIOTest, DigitalPinTest) {
  EXPECT_EQ(PIN13, 13);
  EXPECT_EQ(PIN5, 5);
  EXPECT_EQ(PIN0, 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
