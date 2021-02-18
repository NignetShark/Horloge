//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_DIGITS_SERVICE_HPP
#define HORLOGE_DIGITS_SERVICE_HPP


#include <cstdint>
#include <service/async_service.hpp>
#include <mutex>
#include <service/dial_mixer_interface.hpp>
#include "tools/settings.hpp"
#include "tools/pingpongarray.hpp"

class DigitsService : public AsyncService {
protected:
    DialMixerInterface& mixer;


public:
    DigitsService(DialMixerInterface &mixer);

    void reset();
};


#endif //HORLOGE_DIGITS_SERVICE_HPP
