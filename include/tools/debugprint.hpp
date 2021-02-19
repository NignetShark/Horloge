//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_DEBUGPRINT_HPP
#define HORLOGE_DEBUGPRINT_HPP


#include <string>
#include "tools/ledcolor.hpp"
#include "ledmatrix.hpp"

typedef enum {
    BLUE = 34,
    CYAN = 36,
    OK = 32,
    WARNING = 33,
    FAIL = 31
} ColorTerm;

/**
 * Print to a terminal using TRUE COLORS
 */
class DebugPrint {
private:
public:
    static void print(const std::string& m, ColorTerm c);
    static void print(const std::string& m, color_t c);
    static void print(LedMatrix& m);

private:
};


#endif //HORLOGE_DEBUGPRINT_HPP
