//
// Created by paul on 17/02/2021.
//

#include "service/coloration/dial_coloration.hpp"

DialColoration::DialColoration(DialMixer &mixer) : ColorationService(mixer, NB_DIAL_MODE, NIGHT) {
}

void DialColoration::run() {
    unicolor(led_color::BLACK);
    mixer.set_colors_ptr(&pattern);
    this->current();
}

void DialColoration::unicolor(color_t color) {
    color_t* target = pattern.start_get();
    for(uint8_t i = 0; i < DIAL_COUNT; i++) {
        target[i] = color;
    }
    mixer.colors_ready(target);
    pattern.end_get();
}

void DialColoration::mode(size_t index) {
    if (!keepAlive) return;

    switch (index) {
        case NIGHT: {
            unicolor(led_color::WHITE);
            break;
        }
        case UNI:
            break;
        case RAINBOW:
            break;
        case RESTRICTED_RAINBOW:
            break;
        default:
            break;
    }
}
