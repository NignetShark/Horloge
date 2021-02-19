//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_NTP_SERVICE_HPP
#define HORLOGE_NTP_SERVICE_HPP

#include "service/async_service.hpp"

#define HOST_NAME "fr.pool.ntp.org"
#define NTP_PORT 123

/**
 * NTP Service to get right time
 */
class NTPService : public AsyncService {
private:
    AnimationService& anim_service;

    void run() override;

    /**
     * Animation of 404 error
     * @param attempt (number of remaining attempts)
     */
    void err404(unsigned int attempt);

    /**
     * Animation of success
     */
    void success();

    /**
     * Animation for waiting
     * @param from duration in sec
     * @param color
     */
    void wait_chrono(uint8_t from, color_t color);

    /**
     * Get the time from a NTP server
     * @return
     */
    time_t getNTPTime();

public:
    NTPService(AnimationService& anim_service);


};


#endif //HORLOGE_NTP_SERVICE_HPP
