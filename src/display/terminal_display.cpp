//
// Created by paul on 17/02/2021.
//


#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <exception/fatal_exception.hpp>
#include <sstream>
#include <cstring>
#include "display/terminal_display.hpp"
#include "tools/debug_print.hpp"

void TerminalDisplay::display(LedMatrix &matrix) {
    mutex.lock();
    *output << "\033[2J\033[1;1H"; // Reset screen
    DebugPrint::print(matrix, *output);
    mutex.unlock();
}

TerminalDisplay::TerminalDisplay() : terminal_pt(-1), xterm_fd(-1), output(nullptr), file_buf(nullptr) {
    terminal_pt = posix_openpt(O_RDWR);
    if (terminal_pt == -1) throw FatalException("Could not open pseudo terminal");
    char* pt_name = ptsname(terminal_pt);
    if (!pt_name) throw FatalException("Could not get pseudo terminal device name");
    if (grantpt(terminal_pt) == -1) throw FatalException("Could not get pseudo terminal device name");
    if (unlockpt(terminal_pt) == -1) throw FatalException("Could not get pseudo terminal device name");

    DebugPrint::print("TTY used : " + std::string(pt_name) + "\n", ColorTerm::BLUE, std::cout);

    std::string command = "gnome-terminal -e \"ttylog -d " + std::string(pt_name) + "\"";
    system(command.c_str());

    file_buf = new __gnu_cxx::stdio_filebuf<char>(terminal_pt, std::ios::out); // 1
    output = new std::ostream(file_buf);
}

TerminalDisplay::~TerminalDisplay() {
    if(terminal_pt >= 0) close(terminal_pt);
    if(xterm_fd >= 0) close(xterm_fd);

    delete file_buf;
    delete output;
}
