cmake_minimum_required(VERSION 3.17)
project(ws2811 VERSION 1.0.0 DESCRIPTION "Library for WS2811 leds")

add_library(ws2811 SHARED
        src/mailbox.c
        src/ws2811.c
        src/pwm.c
        src/pcm.c
        src/dma.c
        src/rpihw.c
        )

target_include_directories(ws2811 PRIVATE include)

install(TARGETS ws2811
        LIBRARY DESTINATION ./)