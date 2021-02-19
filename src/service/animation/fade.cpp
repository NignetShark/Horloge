//
// Created by paul on 18/02/2021.
//

#include <exception/fatal_exception.hpp>
#include "service/animation/fade.hpp"

bool animation::Fade::first_frame(LedMatrix *keyframe) {
    if(target == nullptr) throw FatalException("Target not define for fade animation.");
    return false;
}

bool animation::Fade::next_keyframe(LedMatrix *keyframe, LedMatrix *previous) {
   if(index == 0) {
        target->copy(keyframe);
       return true;
   } else {
       return false;
   }
}

void animation::Fade::setup(LedMatrix *target) {
    this->target = target;
}

animation::Fade &animation::Fade::get() {
    static Fade instance;
    return instance;
}

animation::Fade::Fade() {

}

