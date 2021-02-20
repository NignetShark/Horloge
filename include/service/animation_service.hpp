//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_ANIMATION_SERVICE_HPP
#define HORLOGE_ANIMATION_SERVICE_HPP

#include <service/animation/animator.hpp>
#include "display/display.hpp"
#include "async_service.hpp"
#include "tools/led_matrix.hpp"

/**
 * Service use to show an animation
 */
class AnimationService : public AsyncService {
private:
    /**
     * Animation object set in setup()
     */
    Animator* animator = nullptr;

    /**
     * Increment for LERP interpolation
     */
    float increment;

    /**
     * Delay for LERP interpolation
     */
    unsigned int delay;

    void run() override;

public:
    AnimationService();

    /**
     * Setup the service
     * @param animator specify the animation
     * @param increment used for LERP
     * @param delay used for LERP
     */
    void setup(Animator &animator, float increment, unsigned int delay);

};


#endif //HORLOGE_ANIMATION_SERVICE_HPP
