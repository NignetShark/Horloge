//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_LEDCOLOR_HPP
#define HORLOGE_LEDCOLOR_HPP

#include "ws2811.h"
#include <cstdint>

typedef union {
    struct {
        uint8_t blue;
        uint8_t green;
        uint8_t red;
        uint8_t white;
    };
    ws2811_led_t ws2811;
} color_t;

const color_t COLOR_BLACK {.ws2811 = 0};
const color_t COLOR_WHITE {.ws2811 = 0x00FFFFFF};

namespace led_color {

    void LERP(color_t target[], const color_t from[], const color_t to[], float t, uint8_t end, uint8_t start = 0);
}

#endif //HORLOGE_LEDCOLOR_HPP
