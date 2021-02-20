//
// Created by paul on 20/02/2021.
//

#ifndef HORLOGE_LOGGING_HPP
#define HORLOGE_LOGGING_HPP


#include <string>
#include "tools/debug_print.hpp"
class Logging {
private:
    std::ostream& output;

    Logging();
public:
    void info(const std::string &mes);
    void warning(const std::string &mes);
    void error(const std::string &mes);
    void write(const std::string &mes, ColorTerm color);
    void write(const std::string &mes);

    static Logging & get();
};


#endif //HORLOGE_LOGGING_HPP
