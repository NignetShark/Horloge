//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_CLOCK_SERVICE_HPP
#define HORLOGE_CLOCK_SERVICE_HPP


#include "service/timing_service.hpp"
#include "tools/safearray.hpp"

class ClockService : public TimingService {
private:
    void waitUntilNextSec();
    bool array_equals(uint8_t* array1, uint8_t* array2, size_t size);

    void reset();

    void cascadeNumbersToTime(u_int16_t delay_ms);
    void cascadeDigits(uint8_t *toDigits, unsigned int delay_ms);
public:
    ClockService(DialMixer& mixer);

    void run() override;


};


#endif //HORLOGE_CLOCK_SERVICE_HPP
