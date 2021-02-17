//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_CLOCK_SERVICE_HPP
#define HORLOGE_CLOCK_SERVICE_HPP


#include "service/timing_service.hpp"
#include "tools/safearray.hpp"

class ClockService : public TimingService {
private:


public:
    ClockService(DialMixer& mixer);

    void run() override;
};


#endif //HORLOGE_CLOCK_SERVICE_HPP
