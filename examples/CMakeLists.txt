cmake_minimum_required(VERSION 3.10..3.14)
project(Arduino_UNO_Library
        VERSION 1.0.0
        LANGUAGES CXX
       )

# Include the AVR toolchain
include(${CMAKE_CURRENT_SOURCE_DIR}/avr-gcc-toolchain.cmake)

# Include directories for Arduino core files
include_directories(${CMAKE_SOURCE_DIR}/src/include)

# Source files
file(GLOB SOURCES
    #led_button_toggle/main.cpp
    #led_button_toggle/*.cpp
    ${CMAKE_SOURCE_DIR}/src/lib/*.cpp
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions -fno-rtti")

add_library(ArduinoLib_AVR STATIC ${SOURCES})

# Create the executable
#add_executable(${PROJECT_NAME}.elf ${SOURCES})

# Link the Arduino Library
#target_link_libraries(${PROJECT_NAME}.elf ArduinoLib_AVR)

# Convert the ELF file to HEX format for Arduino
#add_custom_command(TARGET ${PROJECT_NAME}.elf
#    POST_BUILD
#    COMMAND avr-objcopy -O ihex -R .eeprom ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
#    COMMENT "Generating HEX file for Arduino"
#)

# Upload command
#add_custom_target(upload
#    COMMAND avrdude -c arduino -p m328p -P /dev/ttyUSB0 -U flash:w:${PROJECT_NAME}.hex:i
#    DEPENDS ${PROJECT_NAME}.hex
#    COMMENT "Uploading HEX file to Arduino Uno"
#)

# add the test sub-directory
add_subdirectory(led_button_toggle)
add_subdirectory(led_toggle)
add_subdirectory(interrupt_led)
