//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_FATAL_EXCEPTION_HPP
#define HORLOGE_FATAL_EXCEPTION_HPP

#include <stdexcept>

/**
 * Used when an error is not recoverable.
 */
class FatalException : public std::logic_error {
public:
    FatalException(std::string what);

    ~FatalException() override = default;
};


#endif //HORLOGE_FATAL_EXCEPTION_HPP
