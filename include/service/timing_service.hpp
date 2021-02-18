//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_TIMING_SERVICE_HPP
#define HORLOGE_TIMING_SERVICE_HPP


#include <cstdint>
#include <service/async_service.hpp>
#include <mutex>
#include <service/dial_mixer_interface.hpp>
#include "tools/settings.hpp"
#include "tools/safearray.hpp"

class TimingService : public AsyncService {
protected:
    SafeArray<uint8_t, DIAL_COUNT> digits;
    DialMixerInterface& mixer;

public:
    TimingService(DialMixerInterface &mixer);
    SafeArray<uint8_t, DIAL_COUNT> *getDigits();
};


#endif //HORLOGE_TIMING_SERVICE_HPP
