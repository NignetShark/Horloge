cmake_minimum_required(VERSION 3.17)
project(Horloge)

set(CMAKE_CXX_STANDARD 14)

add_executable(Horloge src/main.cpp src/tools/ledmatrix.cpp include/tools/ledmatrix.hpp src/tools/ledcolor.cpp include/tools/ledcolor.hpp src/tools/debugprint.cpp include/tools/debugprint.hpp)
target_include_directories(Horloge PRIVATE include lib/ws281x/include)