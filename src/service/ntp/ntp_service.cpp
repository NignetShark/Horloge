//
// Created by paul on 18/02/2021.
//

#include <manager.hpp>
#include <service/animation/fade.hpp>
#include "service/ntp/ntp_service.hpp"

NTPService::NTPService(AnimationService &anim_service) : anim_service(anim_service) {
}

void NTPService::run() {
    LedMatrix m404(true);
    m404.set(4, 3, led_color::RED);
    m404.set(0, 4, led_color::RED);
    m404.set(4, 5, led_color::RED);

    animation::Fade::get().setup(&m404);
    anim_service.setup(animation::Fade::get(), 0.02, 50);
    anim_service.sync_run();
}


