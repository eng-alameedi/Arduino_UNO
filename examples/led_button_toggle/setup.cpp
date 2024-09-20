//
// File: setup.cpp
//
// this file will contain the user example led-button toggle
// that test and implement the GPIO_REAL.
//

#include "Arduino_Uno.h"

GPIO_REAL* gp;

void setup() {
  // code here
  PIN_INIT(PIN13, OUTPUT);
  PIN_INIT(PIN10, INPUT);
}
void loop() {
  // code here
  PIN_STATE(PIN10, HIGH);
  PIN_STATE(PIN13, LOW);
}
