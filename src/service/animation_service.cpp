//
// Created by paul on 18/02/2021.
//

#include <manager.hpp>
#include "service/animation_service.hpp"

AnimationService::AnimationService(unsigned int delay, float increment)
        : AsyncService(), delay(delay), increment(increment) {

}

void AnimationService::run() {
    Display& display = Manager::get().getDisplay();

    LedMatrix key_frame_1;
    LedMatrix key_frame_2;
    LedMatrix result;

    LedMatrix *next_frame = &key_frame_1;
    LedMatrix *prev_frame = &key_frame_2;

    float t;

    while (keepAlive) {
        next_keyframe(next_frame, prev_frame);

        // Animation part
        t = 0;
        while (t <= 1) {
            prev_frame->matrixLERP(result, *next_frame, t);
            t += increment;

            display.display(result);
        }

        // Swap pointers.
        LedMatrix *temp = next_frame;
        next_frame = prev_frame;
        prev_frame = temp;
        index++;
    }

}
