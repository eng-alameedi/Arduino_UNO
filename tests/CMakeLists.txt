# tests/CMakeLists.txt

# Fetch GoogleTest
#include(FetchContent)
#FetchContent_Declare(
#  googletest
#  GIT_REPOSITORY https://github.com/google/googletest.git
#  GIT_TAG        release-1.12.1  # You can change this to the desired version
#)
#FetchContent_MakeAvailable(googletest)

# Add unit tests
#enable_testing()

#add_executable(runTests test_gpio.cpp)

# Link the test executable against gtest, gtest_main, and ArduinoLib
#target_link_libraries(runTests gtest gtest_main ArduinoLib)

# Keep the FetchContent block to download GoogleTest

# Remove the FetchContent block
# Use the locally installed version of GoogleTest


# Add unit tests
#enable_testing()

# Find the installed GoogleTest package
#find_package(GTest REQUIRED)
#find_package(GMock REQUIRED)  # Find the installed GoogleMock package

# Add the test executable
#add_executable(runTests test_gpio.cpp)

# Link the test executable against GTest, GMock, and your library
#target_link_libraries(runTests GTest::GTest GTest::Main GMock::GMock GMock::Main ArduinoLib)

# Add a test to CTest
#add_test(NAME runTests COMMAND runTests)

cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Find Google Test
find_package(GTest REQUIRED)

# Specify the path to the Google Mock libraries
set(GMOCK_LIB_PATH "/usr/local/lib")

# Specify the path to the Google Mock headers
set(GMOCK_INCLUDE_PATH "/usr/local/include")

# Add the include directories
include_directories(${GMOCK_INCLUDE_PATH})

# Add the test executable
add_executable(runTests test_gpio.cpp)

# Link the test executable against GTest, GMock, and your library
target_link_libraries(runTests
  ${GMOCK_LIB_PATH}/libgmock.a
  ${GMOCK_LIB_PATH}/libgmock_main.a
  GTest::GTest
  GTest::Main
  ArduinoLib
)

# Add a test to CTest
add_test(NAME runTests COMMAND runTests)
