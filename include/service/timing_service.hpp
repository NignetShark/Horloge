//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_TIMING_SERVICE_HPP
#define HORLOGE_TIMING_SERVICE_HPP


#include <cstdint>
#include <service/service.hpp>
#include <mutex>
#include <dial_mixer.hpp>
#include "tools/settings.hpp"
#include "tools/safearray.hpp"

class TimingService : public Service {
protected:
    SafeArray<uint8_t, DIAL_COUNT> digits;
    DialMixer& mixer;

public:
    TimingService(DialMixer& mixer);


};


#endif //HORLOGE_TIMING_SERVICE_HPP
