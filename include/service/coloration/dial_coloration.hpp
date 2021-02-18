//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_DIAL_COLORATION_HPP
#define HORLOGE_DIAL_COLORATION_HPP


#include <tools/ledcolor.hpp>
#include "tools/safearray.hpp"
#include "service/coloration_service.hpp"

typedef enum {
    NIGHT,
    UNI,
    RAINBOW,
    RESTRICTED_RAINBOW,
    NB_DIAL_MODE
} dial_color_mode_t;

class DialColoration : public ColorationService {
private:
    SafeArray<color_t, DIAL_COUNT> pattern;
    DialMixerInterface& mixer;

    /*** GENERIC FUNCTIONS ***/
    void unicolor(color_t color);
    void unicolors(color_t *colors);
    void movingRainbow(float *hueOffsets, uint16_t delay_ms, float increment = 1);

public:
    DialColoration(DialMixerInterface& mixer);

    void reset();

    void run() override;

    void mode(size_t index) override;

    SafeArray<color_t, DIAL_COUNT> *getPattern();


};


#endif //HORLOGE_DIAL_COLORATION_HPP
