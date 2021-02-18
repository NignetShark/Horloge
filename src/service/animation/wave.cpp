//
// Created by paul on 18/02/2021.
//

#include <cstdint>
#include "service/animation/wave.hpp"
#include "tools/settings.hpp"
#include "tools/ledmatrix.hpp"

namespace animation {

    Wave::Wave(color_t color, unsigned int delay) : AnimationService(delay, 0.01),
                                                                      color(color), sizes() {

    }

    void Wave::wave_set(LedMatrix &matrix, color_t color) {
        for (unsigned int dial = 0; dial < DIAL_COUNT; dial++) {
            for (unsigned int i = 0; i < sizes[dial]; i++) {
                matrix.set(i, dial, color);
            }
        }
    }

    void Wave::next_keyframe(LedMatrix *keyframe, LedMatrix *previous) {

    }
}