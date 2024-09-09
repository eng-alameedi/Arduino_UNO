# CMakeLists.txt for the examples directory
cmake_minimum_required(VERSION 3.10..3.20)
project(Arduino_UNO_Library
        VERSION 1.0.0
        LANGUAGES CXX
       )

set(file_name LED)
set(files led_button_toggle/main.cpp led_button_toggle/setup.cpp)

include_directories(/home/alameedi/Github/Arduino_UNO/src/include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${file_name} ${files})
