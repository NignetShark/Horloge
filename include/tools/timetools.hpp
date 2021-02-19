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
     * @param tmps time
     */
    static void time2digits(uint8_t result[DIAL_COUNT], std::tm* tmps);

    /**
     * Convert a time to an array of 3 numbers
     * @param result
     * @param tmps time
     */
    static void time2numbers(uint8_t *result, tm *tmps);

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
};


#endif //HORLOGE_TIMETOOLS_HPP
