//
// Created by paul on 17/02/2021.
//

#include <manager.hpp>
#include <exception/fatal_exception.hpp>
#include "service/dial_mixer.hpp"


DialMixer::DialMixer() : display(Manager::get().getDisplay()), digit_service(nullptr), coloration_service(nullptr) {
}

void DialMixer::setup(DialColoration *coloration, DigitsService *timing) {
    if(this->digit_service != nullptr && this->coloration_service != nullptr) {
        if(coloration->is_alive() || digit_service->is_alive()) {
            throw FatalException("Cannot setup dial mixer while coloration or digits is running");
        }
    }
    this->digit_service = timing;
    this->coloration_service = coloration;
}

void DialMixer::_start() {
    if(digit_service == nullptr || coloration_service == nullptr) throw FatalException("No setup for dual mixer");
    coloration_service->start();
    digit_service->try_start();
}

void DialMixer::_start_sync() {
    throw FatalException("DialMixer cannot be run as a sync process");
}

void DialMixer::_stop() {
    digit_service->try_stop();
    coloration_service->stop();
    display.save_state(&matrix);
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







