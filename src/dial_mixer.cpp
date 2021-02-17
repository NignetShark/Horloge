//
// Created by paul on 17/02/2021.
//

#include "dial_mixer.hpp"

DialMixer::DialMixer(Display &display) : display(display) {

}

void DialMixer::digits_ready(uint8_t *digits) {
    if(colors == nullptr) return;

    matrix.all(led_color::BLACK);

    matrix.digits(digits, colors->lock_get());
    colors->unlock();

    display.display(matrix);
}

void DialMixer::colors_ready(color_t *colors) {
    if(digits == nullptr) return;

    matrix.all(led_color::BLACK);

    matrix.digits(digits->lock_get(), colors);
    digits->unlock();

    display.display(matrix);
}

void DialMixer::set_colors_ptr(SafeArray<color_t, DIAL_COUNT> *ptr) {
    colors = ptr;

}

void DialMixer::set_digits_ptr(SafeArray<uint8_t, DIAL_COUNT> *ptr) {
    digits = ptr;
}
