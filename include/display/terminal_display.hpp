//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_TERMINAL_DISPLAY_HPP
#define HORLOGE_TERMINAL_DISPLAY_HPP

#include <mutex>
#include <fstream>
#include <ext/stdio_filebuf.h>
#include "display.hpp"

/**
 * Display on a gnome-terminal using TRUE COLORS
 * WARNING: ttylog must be installed.
 */
class TerminalDisplay : public Display {
private:
    __gnu_cxx::stdio_filebuf<char>* file_buf;
    std::ostream* output;
    int terminal_pt, xterm_fd;
    std::mutex mutex;

public:
    TerminalDisplay();
    ~TerminalDisplay();

    void display(LedMatrix &matrix) override;
};


#endif //HORLOGE_TERMINAL_DISPLAY_HPP
