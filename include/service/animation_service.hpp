//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_ANIMATION_SERVICE_HPP
#define HORLOGE_ANIMATION_SERVICE_HPP

#include "display/display.hpp"
#include "async_service.hpp"
#include "tools/ledmatrix.hpp"

class AnimationService : public AsyncService {
private:
protected:
    unsigned int index = 0;
    float increment;
    unsigned int delay;

public:
    AnimationService(unsigned int delay, float increment);

    void run() override;

    virtual void next_keyframe(LedMatrix* keyframe, LedMatrix* previous) = 0;
};


#endif //HORLOGE_ANIMATION_SERVICE_HPP
