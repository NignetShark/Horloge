//
// Created by paul on 17/02/2021.
//

#include "tools/ledcolor.hpp"

void led_color::LERP(color_t *target, const color_t *from, const color_t *to, float t, uint8_t end, uint8_t start) {
    for(uint8_t i = start; i < end; i++) {
        color_t c_target;
        color_t c_from = from[i];
        color_t c_to = to[i];

        c_target.white = 0;
        c_target.red = (uint8_t)((float)(c_to.red - c_from.red) * t + (float)c_from.red);
        c_target.green = (uint8_t)((float)(c_to.green - c_from.green) * t + (float)c_from.green);
        c_target.blue = (uint8_t)((float)(c_to.blue - c_from.blue) * t + (float)c_from.blue);

        target[i] = c_target;
    }
}
