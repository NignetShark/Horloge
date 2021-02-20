//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_ANIMATOR_HPP
#define HORLOGE_ANIMATOR_HPP

#include "tools/led_matrix.hpp"

/**
 * Abstract class of any animation
 */
class Animator {

protected:
    /**
     * Progression (incremented for each frame)
     */
    unsigned int index = 0;
public:
    Animator();

    /**
     * Set the first frame of the animation
     * @param keyframe
     * @return false if the first frame must be the display's state
     */
    virtual bool first_frame(LedMatrix* keyframe) = 0;

    /**
     * Return the next_state frame
     * @param keyframe new frame
     * @param previous last frame if necessary
     * @return false if the animation is terminated
     */
    virtual bool next_keyframe(LedMatrix* keyframe, LedMatrix* previous) = 0;

    /**
     * Reset index
     */
    void reset_index();

    /**
     * Increment index
     */
    void incr_index();
};


#endif //HORLOGE_ANIMATOR_HPP
