
include(${CMAKE_SOURCE_DIR}/avr-gcc-toolchain.cmake)

set(file_name Usart_Interrupt)

# Create the executable
file(GLOB SOURCES
  main.cpp
  setup.cpp)

add_executable(${file_name}.elf ${SOURCES})

# Link the Arduino Library
target_link_libraries(${file_name}.elf ArduinoLib_AVR)

# Convert the ELF file to HEX format for Arduino
add_custom_command(TARGET ${file_name}.elf
  POST_BUILD
  COMMAND avr-objcopy -O ihex -R .eeprom ${file_name}.elf ${file_name}.hex
  COMMENT "Generating HEX file for Arduino"
)

# Upload command
add_custom_target(upload5
  COMMAND avrdude -c arduino -p m328p -P /dev/ttyUSB2 -U flash:w:${file_name}.hex:i
  DEPENDS ${file_name}.hex
  COMMENT "Uploading HEX file to Arduino Uno"
)
