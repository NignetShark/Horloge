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
public:
    void display(LedMatrix &matrix) override;
};


#endif //HORLOGE_TERMINAL_DISPLAY_HPP
