//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_LEDCOLOR_HPP
#define HORLOGE_LEDCOLOR_HPP

#include "ws2811.h"
#include <cstdint>

/**
 * Abstraction of a ws2811 using an union to access to each component
 */
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

    const color_t NIGHT {.rgb = {0, 0, 255, 0}};
    const color_t BLACK {.ws2811 = 0};
    const color_t WHITE {.ws2811 = 0x00FFFFFF};
    const color_t RED   {.rgb = {0, 0, 255, 0}};
    const color_t YELLOW{.rgb = {0, 255, 255, 0}};
    const color_t GREEN {.rgb = {0, 255, 0, 0}};

    /**
     * Linear interpolation of an array of colors
     * @param target result array
     * @param from
     * @param to
     * @param t percentage (0 to 1) of interpolation
     * @param end index
     * @param start index
     */
    void LERP(color_t target[], const color_t from[], const color_t to[], float t, uint8_t end, uint8_t start = 0);

    /**
     * Convert a HSV to RGB
     * @param h
     * @param s
     * @param v
     * @return conversion result
     */
    color_t from_HSV(float h, float s, float v);
}

#endif //HORLOGE_LEDCOLOR_HPP
