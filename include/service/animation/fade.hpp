//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_FADE_HPP
#define HORLOGE_FADE_HPP

#include "animator.hpp"

namespace animation {
    class Fade : public Animator {
    private:
        LedMatrix* target;
        Fade();

    public:
        void setup(LedMatrix* target);

        bool first_frame(LedMatrix *keyframe) override;

        bool next_keyframe(LedMatrix *keyframe, LedMatrix *previous) override;

        static Fade& get();
    };
}



#endif //HORLOGE_FADE_HPP
