//
// Created by paul on 17/02/2021.
//

#include "tools/led_color.hpp"

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


color_t led_color::from_HSV(float h, float s, float v) {
    float      hh, p, q, t, ff;
    long        i;
    color_t    out;

    if(s <= 0.0) {       // < is bogus, just shuts up warnings
        out.rgb.red = v;
        out.rgb.green = v;
        out.rgb.blue = v;
        return out;
    }
    hh = h;
    if(hh >= 360.0) hh = 0.0;
    hh /= 60.0;
    i = (long)hh;
    ff = hh - i;
    p = v * (1.0 - s);
    q = v * (1.0 - (s * ff));
    t = v * (1.0 - (s * (1.0 - ff)));

    switch(i) {
        case 0:
            out.rgb.red = v*255;
            out.rgb.green = t*255;
            out.rgb.blue = p*255;
            break;
        case 1:
            out.rgb.red = q*255;
            out.rgb.green = v*255;
            out.rgb.blue = p*255;
            break;
        case 2:
            out.rgb.red = p*255;
            out.rgb.green = v*255;
            out.rgb.blue = t*255;
            break;

        case 3:
            out.rgb.red = p*255;
            out.rgb.green = q*255;
            out.rgb.blue = v*255;
            break;
        case 4:
            out.rgb.red = t*255;
            out.rgb.green = p*255;
            out.rgb.blue = v*255;
            break;
        case 5:
        default:
            out.rgb.red = v*255;
            out.rgb.green = p*255;
            out.rgb.blue = q*255;
            break;
    }

    return out;
}