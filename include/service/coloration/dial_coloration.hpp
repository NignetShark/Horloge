//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_DIAL_COLORATION_HPP
#define HORLOGE_DIAL_COLORATION_HPP


#include <tools/ledcolor.hpp>
#include "tools/pingpongarray.hpp"
#include "service/coloration_service.hpp"

typedef enum {
    NIGHT,
    UNI,
    RAINBOW,
    RESTRICTED_RAINBOW,
    NB_DIAL_MODE
} dial_color_mode_t;

/**
 * Service used by a dial mixer to get the dial coloration
 */
class DialColoration : public ColorationService {
private:
    DialMixerInterface& mixer;

    /*** GENERIC FUNCTIONS ***/
    void unicolor(color_t color);
    void unicolors(color_t *colors);
    void movingRainbow(float *hueOffsets, uint16_t delay_ms, float increment = 1);

public:
    DialColoration(DialMixerInterface& mixer);

    /**
     * Reset the color array
     */
    void reset();

    void run() override;


private:
    unsigned int get_night_mode() override;

};


#endif //HORLOGE_DIAL_COLORATION_HPP
