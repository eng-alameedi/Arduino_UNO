cmake_minimum_required(VERSION 3.10..3.20)
project(Arduino_UNO_Library
  VERSION 1.0.0
  LANGUAGES CXX
)

# Set the executable filename
#set(file_name Arduino)

# Specify the Arduino core directory (adjust path accordingly)
#set(ARDUINO_CORE_PATH /home/alameedi/Github/Arduino_UNO)

# Include the Arduino core library
#include_directories(${ARDUINO_CORE_PATH})

# Add include directory for the library headers
include_directories(${CMAKE_SOURCE_DIR}/src/include)

# Set the source files
file(GLOB SOURCES src/main.cpp src/lib/*.cpp)
#file(GLOB Lib_Source src/lib/*.cpp)

# Set options for the compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# Add debug flag
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Add the libra[<35;67;29Mry (create only once here)
add_library(ArduinoLib STATIC ${SOURCES})

# Create the executable file
#add_executable(${file_name} ${SOURCES})

# Link the executable against the ArduinoLib
#target_link_libraries(${file_name} ArduinoLib)

#if(DEFINED CMAKE_TOOLCHAIN_FILE AND CMAKE_TOOLCHAIN_FILE MATCHES "avr-gcc-toolchain.cmake")
#  add_library(ArduinoLib_AVR STATIC ${Lib_Source})
#else()
#  add_library(ArduinoLib STATIC ${Lib_Source})
#endif()

# Add examples
add_subdirectory(examples)

# Add tests
add_subdirectory(tests)
