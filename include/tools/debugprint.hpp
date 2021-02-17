//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_DEBUGPRINT_HPP
#define HORLOGE_DEBUGPRINT_HPP


#include <string>
#include "tools/ledcolor.hpp"
#include "ledmatrix.hpp"

class DebugPrint {
private:
public:
    static void print(std::string m, color_t c);
    static void print(LedMatrix& m);
private:
};


#endif //HORLOGE_DEBUGPRINT_HPP
