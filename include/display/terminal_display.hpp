//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_TERMINAL_DISPLAY_HPP
#define HORLOGE_TERMINAL_DISPLAY_HPP

#include <mutex>
#include "display.hpp"

class TerminalDisplay : public Display {
private:
    std::mutex mutex;
    LedMatrix* last;
public:
    void display(LedMatrix &matrix) override;

    void get(LedMatrix *target) override;
};


#endif //HORLOGE_TERMINAL_DISPLAY_HPP
