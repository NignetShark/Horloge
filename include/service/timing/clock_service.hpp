//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_CLOCK_SERVICE_HPP
#define HORLOGE_CLOCK_SERVICE_HPP


#include "service/digits_service.hpp"
#include "tools/pingpongarray.hpp"

class ClockService : public DigitsService, AsyncService {
private:
    void waitUntilNextSec();
    bool array_equals(uint8_t* array1, uint8_t* array2, size_t size);
    void cascadeNumbersToTime(unsigned int delay_ms);
    void cascadeDigits(uint8_t *toDigits, unsigned int delay_ms);
public:
    ClockService(DialMixerInterface &mixer);

    void try_start() override;
    void try_stop() override;

    void run() override;


};


#endif //HORLOGE_CLOCK_SERVICE_HPP
