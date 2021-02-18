//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_WAVE_HPP
#define HORLOGE_WAVE_HPP

#include <service/animation_service.hpp>

namespace animation {

    class Wave : public AnimationService {
    private:
        uint8_t sizes[DIAL_COUNT];
        color_t color;

        void wave_set(LedMatrix &matrix, color_t color);

    public:
        Wave(color_t color, unsigned int delay);

        void next_keyframe(LedMatrix *keyframe, LedMatrix *previous) override;

    };
}

#endif //HORLOGE_WAVE_HPP
