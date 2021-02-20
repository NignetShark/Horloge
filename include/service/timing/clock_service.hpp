//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_CLOCK_SERVICE_HPP
#define HORLOGE_CLOCK_SERVICE_HPP


#include "service/digits_service.hpp"
#include "tools/ping_pong_array.hpp"

/**
 * Service used to manage digits with the aim to show the time
 */
class ClockService : public DigitsService, AsyncService {
private:
    /**
     * Wait until the next_state sec
     */
    void wait_until_next_sec();

    /**
     * Compare two array
     * @param array1
     * @param array2
     * @param size
     * @return if they are equals
     */
    bool array_equals(uint8_t* array1, uint8_t* array2, size_t size);

    /**
     * Launching animation until the time is displayed
     * @param delay_ms between each frame
     */
    void cascadeNumbersToTime(unsigned int delay_ms);

    /**
     * Animation when 59sec is reached
     * @param delay_ms between each frame
     */
    void cascadeDigits(uint8_t *to_digits, unsigned int delay_ms);

    void run() override;
public:

    ClockService(DialMixerInterface &mixer);

    void try_start() override;
    void try_stop() override;
    bool is_alive() override;


};


#endif //HORLOGE_CLOCK_SERVICE_HPP
