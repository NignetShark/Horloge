//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_NTPEXCEPTION_HPP
#define HORLOGE_NTPEXCEPTION_HPP

#include <stdexcept>

class NTPException : public std::logic_error {
public:
    NTPException(std::string what);

    ~NTPException() override = default;
};

#endif //HORLOGE_NTPEXCEPTION_HPP
