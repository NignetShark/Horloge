//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_FATALEXCEPTION_HPP
#define HORLOGE_FATALEXCEPTION_HPP

#include <stdexcept>

class FatalException : public std::logic_error {
public:
    FatalException(std::string what);

    ~FatalException() override = default;
};


#endif //HORLOGE_FATALEXCEPTION_HPP
