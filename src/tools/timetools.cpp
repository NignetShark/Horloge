//
// Created by paul on 17/02/2021.
//

#include "tools/timetools.hpp"

void TimeTools::time2digits(uint8_t *result, tm *tmps) {
    div_t value = number2digits(tmps->tm_hour);
    result[0] = value.quot;
    result[1] = value.rem;
    value = number2digits(tmps->tm_min);
    result[2] = value.quot;
    result[3] = value.rem;
    value = number2digits(tmps->tm_sec);
    result[4] = value.quot;
    result[5] = value.rem;
}

void TimeTools::time2numbers(uint8_t *result, tm *tmps) {
    result[0] = tmps->tm_hour;
    result[1] = tmps->tm_min;
    result[2] = tmps->tm_sec;
}

void TimeTools::numbers2digits(uint8_t *result, uint8_t *numbers) {
    div_t value = number2digits(numbers[0]);
    result[0] = value.quot;
    result[1] = value.rem;
    value = number2digits(numbers[1]);
    result[2] = value.quot;
    result[3] = value.rem;
    value = number2digits(numbers[2]);
    result[4] = value.quot;
    result[5] = value.rem;
}

void TimeTools::digits2numbers(uint8_t *result, uint8_t *digits) {
    result[0] = digits[0] * 10 + digits[1];
    result[1] = digits[2] * 10 + digits[3];
    result[2] = digits[4] * 10 + digits[5];
}

__inline__ div_t TimeTools::number2digits(uint8_t number) {
    return div(number, 10);
}




