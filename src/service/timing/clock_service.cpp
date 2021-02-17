//
// Created by paul on 17/02/2021.
//

#include "service/timing/clock_service.hpp"
#include "tools/timetools.hpp"


ClockService::ClockService(DialMixer &mixer) : TimingService(mixer) {

}

void ClockService::run() {
    mixer.set_digits_ptr(&digits);


    for(int i = 0; i < 10; i++ ) {
    time_t now = time(0);
    tm* localtm = localtime(&now);

    uint8_t* target = this->digits.start_get();
    TimeTools::time2digits(target, localtm);
    mixer.digits_ready(target);
    digits.end_get();
    wait_ms(1000);
    }
}