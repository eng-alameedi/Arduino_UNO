include(${CMAKE_SOURCE_DIR}/avr-gcc-toolchain.cmake)

# Create the executable
file(GLOB SOURCES
  main.cpp
  setup.cpp)

add_executable(${PROJECT_NAME}.elf ${SOURCES})

# Link the Arduino Library
target_link_libraries(${PROJECT_NAME}.elf ArduinoLib_AVR)

# Convert the ELF file to HEX format for Arduino
add_custom_command(TARGET ${PROJECT_NAME}.elf
  POST_BUILD
  COMMAND avr-objcopy -O ihex -R .eeprom ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
  COMMENT "Generating HEX file for Arduino"
)

# Upload command
add_custom_target(upload
  COMMAND avrdude -c arduino -p m328p -P /dev/ttyUSB0 -U flash:w:${PROJECT_NAME}.hex:i
  DEPENDS ${PROJECT_NAME}.hex
  COMMENT "Uploading HEX file to Arduino Uno"
)
