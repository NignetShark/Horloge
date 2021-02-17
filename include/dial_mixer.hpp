//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_DIAL_MIXER_HPP
#define HORLOGE_DIAL_MIXER_HPP

#include <tools/safearray.hpp>
#include <display/display.hpp>
#include "tools/ledmatrix.hpp"

class DialMixer {
private:
    SafeArray<color_t, DIAL_COUNT>* colors = nullptr;
    SafeArray<uint8_t, DIAL_COUNT>* digits = nullptr;
    LedMatrix matrix;

    Display& display;

public:
    DialMixer(Display& display);

    void set_colors_ptr(SafeArray<color_t, DIAL_COUNT>* ptr);
    void set_digits_ptr(SafeArray<uint8_t, DIAL_COUNT>* ptr);

    void colors_ready(color_t * colors);
    void digits_ready(uint8_t* digits);
};


#endif //HORLOGE_DIAL_MIXER_HPP
