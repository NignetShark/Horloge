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
    } rgb;
    ws2811_led_t ws2811;
} color_t;



namespace led_color {

    const color_t NIGHT {.rgb = {0, 0, 1, 0}};
    const color_t BLACK {.ws2811 = 0};
    const color_t WHITE {.ws2811 = 0x00FFFFFF};

    void LERP(color_t target[], const color_t from[], const color_t to[], float t, uint8_t end, uint8_t start = 0);
}

#endif //HORLOGE_LEDCOLOR_HPP
