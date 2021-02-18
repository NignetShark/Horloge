//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_WAVE_HPP
#define HORLOGE_WAVE_HPP

#include "animator.hpp"

namespace animation {

    class Wave : public Animator {
    private:

        uint8_t sizes[DIAL_COUNT];
        bool direction[DIAL_COUNT];
        color_t color;

        void wave_set(LedMatrix *matrix, color_t color);
        Wave();

    public:
        void setup(color_t color);

        bool next_keyframe(LedMatrix *keyframe, LedMatrix *previous) override;

        bool first_frame(LedMatrix *keyframe) override;

        static Wave& get();

    };
}

#endif //HORLOGE_WAVE_HPP
