//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_DIAL_MIXER_HPP
#define HORLOGE_DIAL_MIXER_HPP

#include "service.hpp"
#include "service/coloration/dial_coloration.hpp"
#include "service/timing/clock_service.hpp"

#include <tools/safearray.hpp>
#include <display/display.hpp>
#include "tools/ledmatrix.hpp"
#include "dial_mixer_interface.hpp"



class DialMixer : public Service, public DialMixerInterface {
private:
    SafeArray<color_t, DIAL_COUNT>* colors = nullptr;
    SafeArray<uint8_t, DIAL_COUNT>* digits = nullptr;

    DialColoration* coloration;
    TimingService* timing;

    LedMatrix matrix;
    Display& display;

public:
    DialMixer();

    void setup(DialColoration *coloration, TimingService *timing);

    void start() override;
    void stop() override;


    void paint() override;


};


#endif //HORLOGE_DIAL_MIXER_HPP
