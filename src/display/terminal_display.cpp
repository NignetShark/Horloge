//
// Created by paul on 17/02/2021.
//

#include <cstdlib>
#include <iostream>
#include "display/terminal_display.hpp"
#include "tools/debugprint.hpp"

void TerminalDisplay::display(LedMatrix &matrix) {
    mutex.lock();
    matrix.copy(&last);
    std::cout << "\033[2J\033[1;1H";
    DebugPrint::print(matrix);
    mutex.unlock();
}

void TerminalDisplay::get(LedMatrix *target) {
    last.copy(target);
}
