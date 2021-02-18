//
// Created by paul on 17/02/2021.
//

#include "service/timing_service.hpp"


TimingService::TimingService(DialMixerInterface &mixer) : AsyncService(),  mixer(mixer) {
}


SafeArray<uint8_t, DIAL_COUNT> *TimingService::getDigits() {
    return &digits;
}
