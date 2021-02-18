//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_ANIMATION_SERVICE_HPP
#define HORLOGE_ANIMATION_SERVICE_HPP

#include <service/animation/animator.hpp>
#include "display/display.hpp"
#include "async_service.hpp"
#include "tools/ledmatrix.hpp"

class AnimationService : public AsyncService {
private:
    Animator* animator = nullptr;
    float increment;
    unsigned int delay;
    void run() override;

public:
    AnimationService();
    void setup(Animator &animator, float increment, unsigned int delay);

    void sync_run();
};


#endif //HORLOGE_ANIMATION_SERVICE_HPP
