//
// File: setup.cpp
//
// this file will contain the user example led-button toggle
// that test and implement the GPIO_REAL.
//

#include "Arduino_Uno.h"
#include "gpio_real.h"
#include "pin_map.h"

// GPIO_REAL* gp;

// GPIO_REAL gp(PIN13, OUTPUT);

inline void setup() {
  gp = new GPIO_REAL(PIN13, OUTPUT);
  GPIO_REAL gp2(PIN12, INPUT);
  // code here
  // PIN_INIT(PIN13, OUTPUT);
  // PIN_INIT(PIN10, INPUT);
}
inline void loop() {
  // code here
  // PIN_STATE(PIN10, HIGH);
  // PIN_STATE(PIN13, LOW);
}
