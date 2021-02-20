//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_TIME_TOOLS_HPP
#define HORLOGE_TIME_TOOLS_HPP

#include <ctime>
#include <cstdint>
#include <cstdlib>
#include <string>
#include "settings.hpp"

class TimeTools {
private:
    /**
     * Convert a 2 digits number to 2 digits
     * @param number
     * @return
     */
    static div_t number2digits(uint8_t number);

public:
    /**
     * Convert a time to an array of 6 digits
     * @param result
     * @param time time
     */
    static void time2digits(uint8_t result[DIAL_COUNT], time_t time);

    /**
     * Convert a time to an array of 3 numbers
     * @param result
     * @param time time
     */
    static void time2numbers(uint8_t *result, time_t time);

    /**
     * Convert an array of 3 numbers to an array of 6 digits
     * @param result
     * @param numbers
     */
    static void numbers2digits(uint8_t *result, uint8_t* numbers);

    /**
     * Convert an array of 6 digits to an array of 3 numbers
     * @param result
     * @param numbers
     */
    static void digits2numbers(uint8_t *result, uint8_t *digits);

    static std::string time2str(time_t time);
};


#endif //HORLOGE_TIME_TOOLS_HPP
