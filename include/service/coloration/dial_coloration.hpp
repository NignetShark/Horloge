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
    /*** GENERIC FUNCTIONS ***/

    void unicolor(color_t color);

public:
    DialColoration(DialMixer &mixer);

    void run() override;

    /*** CUSTOM FUNCTIONS ***/
    void mode(size_t index) override;


};


#endif //HORLOGE_DIAL_COLORATION_HPP
