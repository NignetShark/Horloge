//
// Created by paul on 21/02/2021.
//

#include "input/terminal_input.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <tools/logging.hpp>
#include <exception/fatal_exception.hpp>

TerminalInput::TerminalInput() {

}

void TerminalInput::read_stdin() {
    for(std::string line; getline(std::cin, line);){
        std::vector<std::string> splited = split(line, " ");
        auto iter = commands.find(splited[0]);
        if(iter == commands.end()) {
            command_error();
        } else {
            if(!iter->second(splited)) command_error();
        }
    }
}

std::vector<std::string> TerminalInput::split(const std::string& str, const std::string& delim) {
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

void TerminalInput::command_error() {
    Logging::get().write("Command failed");
}

void TerminalInput::run() {
    read_stdin();
}

void TerminalInput::append(input_handler_t function, const std::string& command) {
    if(keepAlive) throw FatalException("Cannot add a command while running");
    commands[command] = function;
}


