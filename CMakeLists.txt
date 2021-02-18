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
        src/service/async_service.cpp
        src/service/timing/clock_service.cpp
        src/tools/timetools.cpp
        src/service/dial_mixer.cpp
        src/tools/safearray.cpp include/service/animation/wave.hpp src/service/animation/wave.cpp src/service/animation_service.cpp include/service/animation_service.hpp src/manager.cpp include/manager.hpp src/exception/FatalException.cpp include/exception/FatalException.hpp src/service/service.cpp include/service/service.hpp src/service/dial_mixer_interface.cpp include/service/dial_mixer_interface.hpp)

target_include_directories(Horloge PRIVATE include lib/ws281x/include)
target_link_libraries(Horloge pthread)