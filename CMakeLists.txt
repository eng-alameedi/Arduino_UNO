cmake_minimum_required(VERSION 3.10..3.20)
project(Arduino_UNO_Library
  VERSION 1.0.0
  LANGUAGES CXX
)

# Specify the Arduino core directory (adjust path accordingly)
set(ARDUINO_CORE_PATH /home/alameedi/Github/Arduino_UNO)

# Include the Arduino core library
include_directories(${ARDUINO_CORE_PATH})

# Add include directory for the library headers
include_directories(${CMAKE_SOURCE_DIR}/src/include)

# Add source files
add_library(ArduinoLib STATIC
  src/GPIO.cpp
  src/Timer.cpp
  src/UART.cpp
  src/SPI.cpp
  src/I2C.cpp
)

# Add examples
add_subdirectory(examples)

# Add tests
add_subdirectory(tests)
