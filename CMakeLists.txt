cmake_minimum_required(VERSION 3.17)
project(Horloge)

set(CMAKE_CXX_STANDARD 14)

add_executable(Horloge
        src/main.cpp
        src/tools/ledmatrix.cpp
        src/tools/ledcolor.cpp
        src/tools/debugprint.cpp
        src/display/display.cpp
        src/display/nixie_display.cpp
        src/display/terminal_display.cpp
        src/service/coloration_service.cpp
        src/service/coloration/dial_coloration.cpp
        src/service/timing_service.cpp
        src/tools/selector.cpp
        src/service/service.cpp
        src/service/timing/clock_service.cpp
        src/tools/timetools.cpp
        src/dial_mixer.cpp
        src/tools/safearray.cpp)

target_include_directories(Horloge PRIVATE include lib/ws281x/include)
target_link_libraries(Horloge pthread)