//
// Created by paul on 17/02/2021.
//

#include <iostream>
#include "service/digits_service.hpp"


DigitsService::DigitsService(DialMixerInterface &mixer) : mixer(mixer) {
}

void DigitsService::reset() {
    uint8_t* target = mixer.paint_digits();
    for(uint8_t i = 0; i < DIAL_COUNT; i++) {
        target[i] = 0;
    }
}

void DigitsService::print_digits(uint8_t *digits) {
    for(int i = 0; i < DIAL_COUNT; i++) {
        if(i % 2 == 0 and i > 0) std::cout << ":";
        std::cout << std::to_string(digits[i]);
    }
    std::cout << std::endl;
}

