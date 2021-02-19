//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_DIAL_MIXER_HPP
#define HORLOGE_DIAL_MIXER_HPP

#include "service.hpp"
#include "service/coloration/dial_coloration.hpp"
#include "service/timing/clock_service.hpp"

#include <tools/pingpongarray.hpp>
#include <display/display.hpp>
#include "tools/ledmatrix.hpp"
#include "dial_mixer_interface.hpp"



class DialMixer : public Service, public DialMixerInterface, public ColorInputInterface {
private:
    PingPongArray<color_t, DIAL_COUNT> colors;
    PingPongArray<uint8_t, DIAL_COUNT> digits;

    DialColoration* coloration_service;
    DigitsService* digit_service;

    LedMatrix matrix;
    Display& display;

public:
    DialMixer();

    void setup(DialColoration *coloration, DigitsService *timing);

    void _start() override;
    void _stop() override;

private:
    void _start_sync() override;

public:


    color_t* paint_color() override;
    uint8_t* paint_digits() override;

    color_t *get_color_array() override;

    uint8_t * get_digit_array() override;

private:
    void set_night_mode() override;

    void set_day_mode() override;

    void next_color_mode() override;

    void previous_color_mode() override;


};


#endif //HORLOGE_DIAL_MIXER_HPP
