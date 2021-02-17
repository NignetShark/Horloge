//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_TIMETOOLS_HPP
#define HORLOGE_TIMETOOLS_HPP

#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "settings.hpp"

class TimeTools {
private:
    static div_t number2digits(uint8_t number);

public:
    static void time2digits(uint8_t result[DIAL_COUNT], std::tm* tmps);
};


#endif //HORLOGE_TIMETOOLS_HPP
