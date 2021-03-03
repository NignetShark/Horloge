cmake_minimum_required(VERSION 3.17)
project(Horloge)

set(CMAKE_CXX_STANDARD 14)

set(COMPILER_PATH /home/paul/.git/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin)

option(CROSS_COMPILE_BUILD "Use cross-compilation" ON)


if(CROSS_COMPILE_BUILD)
    SET(CMAKE_SYSTEM_NAME Linux)
    SET(CMAKE_C_COMPILER ${COMPILER_PATH}/arm-linux-gnueabihf-gcc)
    SET(CMAKE_CXX_COMPILER ${COMPILER_PATH}/arm-linux-gnueabihf-g++)
endif(CROSS_COMPILE_BUILD)

add_executable(Horloge
        src/main.cpp
        src/tools/led_matrix.cpp
        src/tools/led_color.cpp
        src/tools/debug_print.cpp
        src/display/display.cpp
        src/display/nixie_display.cpp
        src/display/terminal_display.cpp
        src/service/coloration_service.cpp
        src/service/coloration/dial_coloration.cpp
        src/service/digits_service.cpp
        src/tools/selector.cpp
        src/service/async_service.cpp
        src/service/timing/clock_service.cpp
        src/tools/time_tools.cpp
        src/service/dial_mixer.cpp
        src/tools/ping_pong_array.cpp
        src/service/animation/wave.cpp
        src/service/animation_service.cpp
        src/manager.cpp
        src/exception/fatal_exception.cpp
        src/service/service.cpp
        src/service/dial_mixer_interface.cpp
        src/service/animation/animator.cpp
        src/service/ntp/ntp_service.cpp
        src/service/animation/fade.cpp
        src/exception/ntp_exception.cpp
        src/exception/hardware_failure.cpp
        src/input/color_input_interface.cpp
        src/service/scheduler/scheduler.cpp
        src/service/scheduler/task_scheduled.cpp
        src/service/scheduler/day_night_task.cpp
        src/tools/logging.cpp src/input/terminal_input.cpp include/input/terminal_input.hpp src/service/network/network_watcher.cpp include/service/network/network_watcher.hpp)

target_include_directories(Horloge PRIVATE
        include
        lib/rpi_ws281x)

target_link_libraries(Horloge
        pthread
        ws2811
        )

if(CROSS_COMPILE_BUILD)
    target_link_directories(Horloge PRIVATE /usr/local/lib/cross-rpi)
else()
    target_link_directories(Horloge PRIVATE /usr/local/lib)
endif()


if(CROSS_COMPILE_BUILD)
    add_custom_command(TARGET Horloge POST_BUILD COMMAND scp $<TARGET_FILE:Horloge> pi@192.168.1.12:~/)
endif(CROSS_COMPILE_BUILD)