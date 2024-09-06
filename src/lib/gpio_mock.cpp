#include "gpio_mock.h"

#include <gpio_mock.h>

#include "pin_map.h"

GPIO_MOCK::GPIO_MOCK(digital_pin pin, pin_mode mode) : GPIO(pin, mode) {}

GPIO_MOCK::~GPIO_MOCK() {}
