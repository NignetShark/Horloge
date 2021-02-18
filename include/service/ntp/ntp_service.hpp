//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_NTP_SERVICE_HPP
#define HORLOGE_NTP_SERVICE_HPP

#include "service/async_service.hpp"

class NTPService : public AsyncService {
private:
    AnimationService& anim_service;
public:
    NTPService(AnimationService& anim_service);

private:
    void run() override;
};


#endif //HORLOGE_NTP_SERVICE_HPP
