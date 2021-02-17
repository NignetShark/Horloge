//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_NIXIE_DISPLAY_HPP
#define HORLOGE_NIXIE_DISPLAY_HPP

#include "display.hpp"

class NixieDisplay : public Display {
private:

public:
    void display(LedMatrix &matrix) override;

};


#endif //HORLOGE_NIXIE_DISPLAY_HPP
