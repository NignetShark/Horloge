//
// Created by paul on 20/02/2021.
//

#include <iostream>
#include <tools/time_tools.hpp>
#include "tools/logging.hpp"

Logging::Logging() : output(std::cout) {

}

void Logging::write(const std::string &mes, ColorTerm color) {
    std::string buf = "[" + TimeTools::time2str(time(0)) + "] " + mes;
    DebugPrint::print(buf, color, output);
    output << std::endl;
}

void Logging::warning(const std::string &mes) {
    write(mes, WARNING);
}

void Logging::error(const std::string &mes) {
    write(mes, FAIL);
}

void Logging::info(const std::string &mes) {
    write(mes, BLUE);
}

void Logging::write(const std::string &mes) {
    write(mes, NO_COLOR);
}

Logging & Logging::get() {
    static Logging log;
    return log;
}


