//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_NIXIE_DISPLAY_HPP
#define HORLOGE_NIXIE_DISPLAY_HPP

#include "display.hpp"

/**
 * Nixie display based on ws2811 LEDs.
 */
class NixieDisplay : public Display {
private:
    ws2811_t clock;

public:
    NixieDisplay();

    void display(LedMatrix &matrix) override;

};


#endif //HORLOGE_NIXIE_DISPLAY_HPP
