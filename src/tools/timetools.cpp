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

__inline__ div_t TimeTools::number2digits(uint8_t number) {
    return div(number, 10);
}
