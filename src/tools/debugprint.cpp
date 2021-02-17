//
// Created by paul on 17/02/2021.
//

#include <iostream>
#include "tools/debugprint.hpp"

void DebugPrint::print(std::string m, color_t c) {
    std::cout << "\x1b[38;2;" << std::to_string(c.red) << ";"
                              << std::to_string(c.green) << ";"
                              << std::to_string(c.blue) << "m";
    std::cout << m;
    std::cout << "\x1b[0m";
}

void DebugPrint::print(LedMatrix &m) {
    for(int digit = 0; digit < DIGITS_COUNT; digit++) {
        for(int dial = 0; dial < DIAL_COUNT; dial++) {
            DebugPrint::print(" " + std::to_string(digit) +  " ", m.get(digit, dial));
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}
