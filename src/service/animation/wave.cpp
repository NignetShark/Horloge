//
// Created by paul on 18/02/2021.
//

#include <cstdint>
#include "service/animation/wave.hpp"
#include "tools/settings.hpp"
#include "tools/ledmatrix.hpp"

namespace animation {

    Wave::Wave(color_t color, unsigned int delay) : AnimationService(delay, 0.1),
                                                                      color(color), sizes() {

    }

    void Wave::wave_set(LedMatrix *matrix, color_t color) {
        matrix->all(led_color::BLACK);
        for (unsigned int dial = 0; dial < DIAL_COUNT; dial++) {
            for (unsigned int i = 0; i < sizes[dial]; i++) {
                matrix->set(i, dial, color);
            }
        }
    }

    void Wave::next_keyframe(LedMatrix *keyframe, LedMatrix *previous) {
        for(unsigned int dial = 0; dial < DIAL_COUNT; dial++) {
            if(direction[dial]) {
                sizes[dial]++;
                if(sizes[dial] == 9) direction[dial] = false;
            } else {
                sizes[dial]--;
                if(sizes[dial] == 0) direction[dial] = true;
            }
        }
        wave_set(keyframe, color);
    }

    void Wave::first_frame(LedMatrix *keyframe) {
        for(unsigned int dial = 0; dial < DIAL_COUNT; dial++) {
            sizes[dial] = dial;
            direction[dial] = true;
        }
        wave_set(keyframe, color);
        //keyframe->all(color);
    }
}