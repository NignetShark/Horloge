//
// Created by paul on 19/02/2021.
//

#ifndef HORLOGE_HARDWARE_FAILURE_HPP
#define HORLOGE_HARDWARE_FAILURE_HPP

#include <stdexcept>
#include <ws2811.h>

/**
 * Failure from hardware. Multiple attempts are allowed as well as warning failure.
 */
class HardwareFailure {
private:
    bool warning;
    unsigned int remaining;
    const std::string what;


public:
    /**
     * Setup a possible hardware failure
     * @param what message
     * @param warning is it important ?
     * @param repetition number of attempts before a fatal exception
     */
    HardwareFailure(std::string what, bool warning, unsigned int repetition);

    /**
     * Report a ws2811 failure
     * @param ret return value
     */
    void report(ws2811_return_t ret);
    ~HardwareFailure();
};


#endif //HORLOGE_HARDWARE_FAILURE_HPP
