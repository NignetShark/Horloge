//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_NTP_SERVICE_HPP
#define HORLOGE_NTP_SERVICE_HPP

#include "service/async_service.hpp"

#define HOST_NAME "fr.pool.ntp.org"
#define NTP_PORT 123

class NTPService : public AsyncService {
private:
    AnimationService& anim_service;
public:
    NTPService(AnimationService& anim_service);

private:
    void run() override;

    void err404(unsigned int attempt);

    void success();

    void chrono(uint8_t from, color_t color);

    time_t getNTPTime();
};


#endif //HORLOGE_NTP_SERVICE_HPP
