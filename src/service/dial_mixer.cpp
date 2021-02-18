//
// Created by paul on 17/02/2021.
//

#include <manager.hpp>
#include <exception/FatalException.hpp>
#include "service/dial_mixer.hpp"


DialMixer::DialMixer() : display(Manager::get().getDisplay()) {
}

void DialMixer::setup(DialColoration *coloration, TimingService *timing) {
    this->timing = timing;
    this->coloration = coloration;
    this->digits = timing->getDigits();
    this->colors = coloration->getPattern();
}

void DialMixer::start() {
    if(timing == nullptr || coloration == nullptr) throw FatalException("No setup for dual mixer");
    coloration->start();
    timing->start();
}

void DialMixer::stop() {
    timing->stop();
    coloration->stop();
}

void DialMixer::paint() {
    matrix.all(led_color::BLACK);

    uint8_t* v_digits = digits->lock_get();
    color_t* v_colors = colors->lock_get();

    matrix.digits(v_digits, v_colors);

    colors->unlock();
    digits->unlock();

    display.display(matrix);
}








