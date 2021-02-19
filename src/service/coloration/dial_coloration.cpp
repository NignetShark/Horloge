//
// Created by paul on 17/02/2021.
//

#include <exception/fatal_exception.hpp>
#include "service/coloration/dial_coloration.hpp"

DialColoration::DialColoration(DialMixerInterface& mixer) : ColorationService(NB_DIAL_MODE, RAINBOW), mixer(mixer) {
    reset(); // Important to prevent uninitialized values
}

void DialColoration::run() {
    mixer.paint_color();

    switch (this->get_current_mode()) {
        case NIGHT: {
            unicolor(led_color::NIGHT);
            break;
        }
        case UNI:
            unicolor(led_color::WHITE);
            break;
        case RAINBOW:
        {
            float hueOffsets[6] = {10, 20, 30, 40, 50, 60};
            movingRainbow(hueOffsets, 100);
            break;
        }
        case RESTRICTED_RAINBOW:
            break;
        default:
            break;
    }
}

void DialColoration::unicolors(color_t* colors) {
    color_t* target = mixer.get_color_array();
    for(uint8_t i = 0; i < DIAL_COUNT; i++) {
        target[i] = colors[i];
    }
    mixer.paint_color();
}

void DialColoration::unicolor(color_t color) {
    color_t* target = mixer.get_color_array();
    for(uint8_t i = 0; i < DIAL_COUNT; i++) {
        target[i] = color;
    }
    mixer.paint_color();
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

void DialColoration::reset() {
    color_t* target = mixer.get_color_array();
    for(unsigned int i = 0; i < DIAL_COUNT; i++) {
        target[i] = led_color::BLACK;
    }
}

unsigned int DialColoration::get_night_mode() {
    return NIGHT;
}


