//
// Created by paul on 17/02/2021.
//

#include <manager.hpp>
#include <exception/FatalException.hpp>
#include "service/dial_mixer.hpp"


DialMixer::DialMixer() : display(Manager::get().getDisplay()) {
}

void DialMixer::setup(DialColoration *coloration, DigitsService *timing) {
    this->digit_service = timing;
    this->coloration = coloration;
}

void DialMixer::_start() {
    if(digit_service == nullptr || coloration == nullptr) throw FatalException("No setup for dual mixer");
    coloration->start();
    digit_service->start();
}

void DialMixer::_stop() {
    digit_service->stop();
    coloration->stop();
}

color_t* DialMixer::paint_color() {
    // WARNING: Only DialColoration thread can call this.
    // DialColoration is synchronous
    // DigitsService is asynchronous

    colors.lock();
    digits.lock();

    colors.unsafe_swap();


    matrix.clear();

    matrix.digits(digits.getBack(), colors.getBack());

    colors.unlock();
    digits.unlock();

    display.display(matrix);

    return colors.getFront();
}

uint8_t *DialMixer::paint_digits() {
    // WARNING: Only DigitsService thread can call this.
    // DigitsService is synchronous
    // DialColoration is asynchronous

    colors.lock();
    digits.lock();

    digits.unsafe_swap();


    matrix.clear();

    matrix.digits(digits.getBack(), colors.getBack());

    colors.unlock();
    digits.unlock();

    display.display(matrix);

    return digits.getFront();
}

color_t *DialMixer::get_color_array() {
    // WARNING: Only DialColoration thread can call this.
    return colors.getFront();
}

uint8_t * DialMixer::get_digit_array() {
    // WARNING: Only DigitsService thread can call this.
    return digits.getFront();
}








