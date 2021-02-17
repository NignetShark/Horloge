//
// Created by paul on 17/02/2021.
//

#include "service/coloration/dial_coloration.hpp"

DialColoration::DialColoration(DialMixer &mixer) : ColorationService(mixer, NB_DIAL_MODE, RAINBOW) {
}

void DialColoration::run() {
    unicolor(led_color::BLACK);
    mixer.set_colors_ptr(&pattern);
    this->current();
}

void DialColoration::unicolors(color_t* colors) {
    color_t* target = pattern.lock_get();
    for(uint8_t i = 0; i < DIAL_COUNT; i++) {
        target[i] = colors[i];
    }
    mixer.colors_ready(target);
    pattern.unlock();
}

void DialColoration::unicolor(color_t color) {
    color_t* target = pattern.lock_get();
    for(uint8_t i = 0; i < DIAL_COUNT; i++) {
        target[i] = color;
    }
    mixer.colors_ready(target);
    pattern.unlock();
}

void DialColoration::movingRainbow(float* hueOffsets, uint16_t delay_ms, float increment){
    color_t colors[DIAL_COUNT];
    while(keepAlive){
        for(uint8_t i = 0; i < DIAL_COUNT; i++){
            hueOffsets[i] += increment;
            if(hueOffsets[i] > 360) hueOffsets[i] -= 360;
            colors[i] = led_color::from_HSV(hueOffsets[i], 1, 1);
        }
        unicolors(colors);
        wait_ms(delay_ms);
    }
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
        {
            float hueOffsets[6] = {10, 20, 30, 40, 50, 60};
            movingRainbow(hueOffsets, 10);
            break;
        }
        case RESTRICTED_RAINBOW:
            break;
        default:
            break;
    }
}
