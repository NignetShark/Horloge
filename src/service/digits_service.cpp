//
// Created by paul on 17/02/2021.
//

#include "service/digits_service.hpp"


DigitsService::DigitsService(DialMixerInterface &mixer) : AsyncService(), mixer(mixer) {
}

void DigitsService::reset() {
    uint8_t* target = mixer.paint_digits();
    for(uint8_t i = 0; i < DIAL_COUNT; i++) {
        target[i] = 0;
    }
}