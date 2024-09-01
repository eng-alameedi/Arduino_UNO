# CMakeLists.txt file for the tests directory
cmake_minimum_required(VERSION 3.10..3.20)
project(Arduino_UNO_Library
        VERSION 1.0.0
        LANGUAGES CXX
       )

# Add source files
set(GLOB ${CMAKE_SOURCE_DIR}/src/main.cpp ${CMAKE_SOURCE_DIR}/src/lib*.cpp SOURCES)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src/include)

# Add the library
add_library(ArduinoLib ${SOURCES})

# Add Google Test
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

# Add unit tests
add_executable(runTests tests/test_gpio.cpp)
target_link_libraries(runTests gtest gtest_main ArduinoLib)

