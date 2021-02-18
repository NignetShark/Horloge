//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_ANIMATOR_HPP
#define HORLOGE_ANIMATOR_HPP

#include "tools/ledmatrix.hpp"

class Animator {

protected:
    unsigned int index = 0;
public:
    Animator();

    virtual bool first_frame(LedMatrix* keyframe) = 0;
    virtual bool next_keyframe(LedMatrix* keyframe, LedMatrix* previous) = 0;

    void reset_index();
    void incr_index();
};


#endif //HORLOGE_ANIMATOR_HPP
