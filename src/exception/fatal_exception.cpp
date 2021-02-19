//
// Created by paul on 18/02/2021.
//

#include "exception/fatal_exception.hpp"

FatalException::FatalException(std::string what) : std::logic_error(what) {

}

