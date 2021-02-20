//
// Created by paul on 19/02/2021.
//

#include <iostream>
#include <tools/debug_print.hpp>
#include <utility>
#include <exception/fatal_exception.hpp>
#include "exception/hardware_failure.hpp"



HardwareFailure::HardwareFailure(std::string what, bool warning, unsigned int repetition) : what(std::move(what)), warning(warning), remaining(repetition) {
}

void HardwareFailure::report(ws2811_return_t ret) {
    if(warning) {
        DebugPrint::print(what + " (" + ws2811_get_return_t_str(ret) + ")", WARNING, std::cerr);
    } else {
        if(remaining == 0) {
            throw FatalException(what + " (" + ws2811_get_return_t_str(ret) + ")");
        } else {
            DebugPrint::print("[" + std::to_string(remaining) + "] " + what + " (" + ws2811_get_return_t_str(ret) + ")",
                              FAIL, std::cerr);
            std::cout << std::endl;
            remaining--;
        }
    }
}

HardwareFailure::~HardwareFailure() = default;
