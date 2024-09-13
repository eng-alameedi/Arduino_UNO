#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Arduino_Uno.h"
#include "gmock/gmock.h"
#include "gpio_init.h"
#include "gpio_mock.h"
#include "gpio_real.h"
#include "gpio_uno.h"
#include "pin_map.h"
#include "timer_mock.h"
#include "timer_uno.h"

using ::testing::AtLeast;
using ::testing::Return;

TEST(GPIOMock, SetModeCall) {
  GPIO_MOCK g(PIN13, OUTPUT);
  EXPECT_CALL(g, set_pinmode()).Times(AtLeast(1));
  g.set_pinmode();
}

TEST(GPIOMock, SetStateCall) {
  GPIO_MOCK g(PIN13, INPUT);
  EXPECT_CALL(g, set_pinstate(HIGH)).Times(AtLeast(1));
  g.set_pinstate(HIGH);
}

TEST(GPIOMock, DigitalPinRead) {
  GPIO_MOCK g(PIN13, INPUT);
  EXPECT_CALL(g, digital_pinread()).Times(AtLeast(1));
  g.digital_pinread();
}

TEST(GPIOMock, GpioCall5) {
  GPIO_MOCK gp(PIN5, INPUT);
  ON_CALL(gp, digital_pinread()).WillByDefault(testing::Return(false));
  EXPECT_EQ(gp.get_bit(), 5);
}

TEST(GPIOMock, GpioCall13) {
  GPIO_MOCK gp(PIN13, OUTPUT);
  EXPECT_EQ(gp.get_bit(), 5);
  EXPECT_EQ(gp.get_mode(), OUTPUT);
  EXPECT_EQ(gp.get_state(), LOW);
}

TEST(GPIOMock, GpioNull) {
  GPIO_MOCK gp(PIN10, INPUT);
  // ON_CALL(gp, get_ddrx()).WillByDefault(Return(DDRB));
}

TEST(GPIOTest, DigitalPinTest) {
  EXPECT_EQ(PIN13, 13);
  EXPECT_EQ(PIN5, 5);
  EXPECT_EQ(PIN0, 0);
}

TEST(GPIOTest, PinMode) {
  EXPECT_EQ(OUTPUT, 1);
  EXPECT_EQ(INPUT, 0);
}

TEST(GPIOTest, PinState) {
  EXPECT_EQ(HIGH, 1);
  EXPECT_EQ(LOW, 0);
}

TEST(TIMERMock, CountTest) {
  TIMER_MOCK t1;
  EXPECT_CALL(t1, count_setup());
}

TEST(TIMERMock, DelayTest) {
  // code here
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
