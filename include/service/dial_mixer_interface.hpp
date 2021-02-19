//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_DIAL_MIXER_INTERFACE_HPP
#define HORLOGE_DIAL_MIXER_INTERFACE_HPP

#include "tools/ledcolor.hpp"
#include "tools/settings.hpp"
#include "tools/pingpongarray.hpp"

/**
 * Interface used by process that use DialMixer
 */
class DialMixerInterface {
public:

    /**
     * Get the pointer of the color array
     * WARNING: Only the coloration thread can call this function
     * @return color array
     */
    virtual color_t* get_color_array() = 0;

    /**
     * Get the pointer of the digit array
     * WARNING: Only the digits thread can call this function
     * @return digits array
     */
    virtual uint8_t * get_digit_array() = 0;

    /**
     * Request painting and return the new array
     * WARNING: Only the coloration thread can call this function
     * WARNING: the last pointer must not be used.
     * @return color array
     */
    virtual color_t* paint_color() = 0;

    /**
     * Request painting and return the new array
     * WARNING: Only the digits thread can call this function
     * WARNING: the last pointer must not be used.
     * @return digits array
     */
    virtual uint8_t* paint_digits() = 0;
};


#endif //HORLOGE_DIAL_MIXER_INTERFACE_HPP
