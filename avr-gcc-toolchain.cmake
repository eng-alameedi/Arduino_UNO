# Define the toolchain for AVR
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)

# Set the compiler and tools
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)

# Specify the path to the AVR toolchain, if not in PATH
# set(AVR_TOOLCHAIN_PATH /path/to/avr-toolchain)
# set(CMAKE_C_COMPILER ${AVR_TOOLCHAIN_PATH}/bin/avr-gcc)
# set(CMAKE_CXX_COMPILER ${AVR_TOOLCHAIN_PATH}/bin/avr-g++)

# Define the CMake flags for AVR
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -mmcu=atmega328p -DF_CPU=16000000UL")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17 -mmcu=atmega328p -DF_CPU=16000000UL")
