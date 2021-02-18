//
// Created by paul on 18/02/2021.
//

#include <manager.hpp>
#include <exception/FatalException.hpp>
#include "service/animation_service.hpp"

AnimationService::AnimationService()
        : AsyncService(), animator() {

}

void AnimationService::setup(Animator &animator, float increment, unsigned int delay) {
    this->animator = &animator;
    this->increment = increment;
    this->delay = delay;
}

void AnimationService::run() {
    if(animator == nullptr) throw FatalException("Animation not defined");

    Display& display = Manager::get().getDisplay();

    LedMatrix key_frame_1;
    LedMatrix key_frame_2;
    LedMatrix result;

    LedMatrix *next_frame = &key_frame_1;
    LedMatrix *prev_frame = &key_frame_2;

    float t;

    animator->first_frame(prev_frame);

    while (keepAlive) {
        animator->next_keyframe(next_frame, prev_frame);

        // Animation part
        t = 0;
        while (t <= 1) {
            prev_frame->matrixLERP(result, *next_frame, t);
            t += increment;

            wait_ms(delay);
            display.display(result);
        }

        // Swap pointers.
        LedMatrix *temp = next_frame;
        next_frame = prev_frame;
        prev_frame = temp;
        animator->incr_index();
    }

    animator = nullptr;
}



