//
// Created by paul on 18/02/2021.
//

#include "exception/ntp_exception.hpp"

NTPException::NTPException(std::string what) : std::logic_error(what) {

}