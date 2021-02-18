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

class DigitsService {
protected:
    DialMixerInterface& mixer;


public:
    DigitsService(DialMixerInterface &mixer);

private:

public:
    void reset();

    /**
     * If not already started, try to start.
     */
    virtual void try_start() = 0;

    /**
     * A service is not necessarily stopped by the digit service. But it will not be able to print.
     */
    virtual void try_stop() = 0;
};


#endif //HORLOGE_DIGITS_SERVICE_HPP
