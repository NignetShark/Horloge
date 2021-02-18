//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_DIAL_MIXER_INTERFACE_HPP
#define HORLOGE_DIAL_MIXER_INTERFACE_HPP

#include "tools/ledcolor.hpp"
#include "tools/settings.hpp"
#include "tools/pingpongarray.hpp"

class DialMixerInterface {
public:
    virtual color_t* get_color_array() = 0;
    virtual uint8_t * get_digit_array() = 0;
    virtual color_t* paint_color() = 0;
    virtual uint8_t* paint_digits() = 0;
};


#endif //HORLOGE_DIAL_MIXER_INTERFACE_HPP
