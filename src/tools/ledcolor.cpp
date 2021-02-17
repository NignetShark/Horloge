//
// Created by paul on 17/02/2021.
//

#include "tools/ledcolor.hpp"

void led_color::LERP(color_t *target, const color_t *from, const color_t *to, float t, uint8_t end, uint8_t start) {
    for(uint8_t i = start; i < end; i++) {
        color_t c_target;
        color_t c_from = from[i];
        color_t c_to = to[i];

        c_target.rgb.white = 0;
        c_target.rgb.red = (uint8_t)((float)(c_to.rgb.red - c_from.rgb.red) * t + (float)c_from.rgb.red);
        c_target.rgb.green = (uint8_t)((float)(c_to.rgb.green - c_from.rgb.green) * t + (float)c_from.rgb.green);
        c_target.rgb.blue = (uint8_t)((float)(c_to.rgb.blue - c_from.rgb.blue) * t + (float)c_from.rgb.blue);

        target[i] = c_target;
    }
}
