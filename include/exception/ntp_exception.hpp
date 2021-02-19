//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_NTP_EXCEPTION_HPP
#define HORLOGE_NTP_EXCEPTION_HPP

#include <stdexcept>

/**
 * Exception during NTP service (can be a network error)
 */
class NTPException : public std::logic_error {
public:
    NTPException(std::string what);

    ~NTPException() override = default;
};

#endif //HORLOGE_NTP_EXCEPTION_HPP
