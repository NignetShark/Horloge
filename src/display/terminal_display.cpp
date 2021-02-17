//
// Created by paul on 17/02/2021.
//

#include <cstdlib>
#include <iostream>
#include "display/terminal_display.hpp"
#include "tools/debugprint.hpp"

void TerminalDisplay::display(LedMatrix &matrix) {
    mutex.lock();
    std::system("clear");
    DebugPrint::print(matrix);
    mutex.unlock();
}
