//
// Created by paul on 21/02/2021.
//

#ifndef HORLOGE_TERMINAL_INPUT_HPP
#define HORLOGE_TERMINAL_INPUT_HPP

#include <unordered_map>
#include <string>
#include <vector>
#include "service/async_service.hpp"

typedef bool (*input_handler_t)(std::vector<std::string>& args);

class TerminalInput : public AsyncService {
private:
    std::unordered_map<std::string, input_handler_t> commands;
    std::vector<std::string> split(const std::string& str, const std::string& delim);
    void run() override;
    void command_error();
    void read_stdin();

public:
    TerminalInput();
    void append(input_handler_t function, const std::string& command);
};




#endif //HORLOGE_TERMINAL_INPUT_HPP
