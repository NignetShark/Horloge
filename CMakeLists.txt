cmake_minimum_required(VERSION 3.17)
project(Horloge)

set(CMAKE_CXX_STANDARD 14)

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
        src/tools/ping_pong_array.cpp include/service/animation/wave.hpp src/service/animation/wave.cpp src/service/animation_service.cpp include/service/animation_service.hpp src/manager.cpp include/manager.hpp src/exception/fatal_exception.cpp include/exception/fatal_exception.hpp src/service/service.cpp include/service/service.hpp src/service/dial_mixer_interface.cpp include/service/dial_mixer_interface.hpp src/service/animation/animator.cpp include/service/animation/animator.hpp src/service/ntp/ntp_service.cpp include/service/ntp/ntp_service.hpp src/service/animation/fade.cpp include/service/animation/fade.hpp src/exception/ntp_exception.cpp include/exception/ntp_exception.hpp src/exception/hardware_failure.cpp include/exception/hardware_failure.hpp src/input/color_input_interface.cpp include/input/color_input_interface.hpp src/service/scheduler/scheduler.cpp include/service/scheduler/scheduler.hpp src/service/scheduler/task_scheduled.cpp include/service/scheduler/task_scheduled.hpp src/service/scheduler/day_night_task.cpp include/service/scheduler/day_night_task.hpp)

target_include_directories(Horloge PRIVATE
        include
        lib/ws281x/include)

target_link_libraries(Horloge
        pthread
        ws2811
        )

target_link_directories(Horloge PRIVATE lib/ws281x)