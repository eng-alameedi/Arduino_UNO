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
enable_testing()

# Find the installed GoogleTest package
find_package(GTest REQUIRED)

# Add the test executable
add_executable(runTests test_gpio.cpp)

# Link the test executable against GTest and your library
target_link_libraries(runTests GTest::GTest GTest::Main ArduinoLib)
