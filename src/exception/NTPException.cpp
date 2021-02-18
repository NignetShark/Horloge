//
// Created by paul on 18/02/2021.
//

#include "exception/NTPException.hpp"

NTPException::NTPException(std::string what) : std::logic_error(what) {

}