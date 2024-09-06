# CMakeLists.txt file for the tests directory
cmake_minimum_required(VERSION 3.10..3.20)
project(Arduino_UNO_Library
        VERSION 1.0.0
        LANGUAGES CXX
       )



# Add source files
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp ${CMAKE_SOURCE_DIR}/src/lib*.cpp)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src/include)

# Add the library
#add_library(ArduinoLib ${SOURCES})

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1  # You can change this to the desired version
)
FetchContent_MakeAvailable(googletest)

# Add unit tests
enable_testing()
add_executable(runTests test_gpio.cpp)
target_link_libraries(runTests gtest gtest_main gmock gmock_main ArduinoLib)
