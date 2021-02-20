//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_DEBUG_PRINT_HPP
#define HORLOGE_DEBUG_PRINT_HPP


#include <string>
#include "tools/led_color.hpp"
#include "led_matrix.hpp"

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
    static void print(const std::string &m, ColorTerm c, std::ostream &output);
    static void print(const std::string &m, color_t c, std::ostream &output);
    static void print(LedMatrix &m, std::ostream &output);

private:
};


#endif //HORLOGE_DEBUG_PRINT_HPP
