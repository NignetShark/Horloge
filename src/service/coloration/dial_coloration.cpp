//
// Created by paul on 17/02/2021.
//

#include <exception/fatal_exception.hpp>
#include "service/coloration/dial_coloration.hpp"

DialColoration::DialColoration(DialMixerInterface& mixer) : ColorationService(NB_DIAL_MODE, RESTRICTED_RAINBOW), mixer(mixer) {
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
            moving_rainbow(hueOffsets, 10);
            break;
        }
        case RESTRICTED_RAINBOW:
        {
            float hueOffsets[6] = {180, 190, 200, 200, 190, 180};
            moving_restricted_rainbow(hueOffsets, 80, 50, 1);
            break;
        }
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

void DialColoration::moving_rainbow(float* hue_offsets, uint16_t delay_ms, float increment){
    color_t colors[DIAL_COUNT];
    while(keep_alive){
        for(uint8_t i = 0; i < DIAL_COUNT; i++){
            hue_offsets[i] += increment;
            if(hue_offsets[i] > 360) hue_offsets[i] -= 360;
            colors[i] = led_color::from_HSV(hue_offsets[i], 1, 1);
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

void DialColoration::moving_restricted_rainbow(float *hue_offsets, float hue_max_increment, uint16_t delay_ms,
                                               float increment) {
    color_t colors[6];
    bool direction = true;
    uint8_t sum_increment = 0;

    while(keep_alive){

        if(direction){
            if(sum_increment >= hue_max_increment) {
                sum_increment = hue_max_increment - increment;
                direction = false;
            } else {
                sum_increment += increment;
            }
        } else {
            if(sum_increment <= 0) {
                sum_increment = 0;
                direction = true;
            } else {
                sum_increment -= increment;
            }
        }

        for(uint8_t i = 0; i < 6; i++){
            if(direction){
                hue_offsets[i] += increment;
                if(hue_offsets[i] > 360) hue_offsets[i] -= 360;
            } else {
                hue_offsets[i] -= increment;
                if(hue_offsets[i] < 0) hue_offsets[i] += 360;
            }
            colors[i] = led_color::from_HSV(hue_offsets[i], 1, 1);
        }

        unicolors(colors);
        wait_ms(delay_ms);
    }
}




