//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_DISPLAY_HPP
#define HORLOGE_DISPLAY_HPP


#include <tools/ledmatrix.hpp>

class Display {
private:

public:
    virtual void display(LedMatrix& matrix) = 0;
};


#endif //HORLOGE_DISPLAY_HPP
