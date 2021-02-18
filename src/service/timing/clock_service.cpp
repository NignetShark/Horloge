//
// Created by paul on 17/02/2021.
//

#include <iostream>
#include <exception/FatalException.hpp>
#include "sys/time.h"
#include "service/timing/clock_service.hpp"
#include "tools/timetools.hpp"


ClockService::ClockService(DialMixerInterface &mixer) : TimingService(mixer) {

}

void ClockService::run() {
    uint8_t* target = this->digits.unsafe_get();

    // Launch animation
    reset();
    cascadeNumbersToTime(50);

    while (keepAlive) {

        time_t now = time(0);
        tm* local_tm = localtime(&now);


        TimeTools::time2digits(target, local_tm);
        mixer.paint();

        // Go back to 0 animation.
        if(target[5] == 9){
            time_t plus1 = time(0) + 1;
            tm* tm_after = localtime(&plus1);
            wait_ms(200);

            uint8_t result[DIAL_COUNT];
            TimeTools::time2digits(result, tm_after);
            cascadeDigits(result, 50);
        }

        waitUntilNextSec();
    }
}

void ClockService::cascadeDigits(uint8_t* toDigits, unsigned int delay_ms) {
    uint8_t* target = this->digits.unsafe_get();
    wait_ms(delay_ms);

    while(!array_equals(target, toDigits, DIAL_COUNT) and keepAlive){

        digits.lock();
        for(uint8_t i = 0; i < DIAL_COUNT; i++){
            if(target[i] < toDigits[i]){
                target[i]++;
            }
            else if (target[i] > toDigits[i])
            {
                target[i]--;
            }
        }
        digits.unlock();

        mixer.paint();
        wait_ms(delay_ms);
    }
}

void ClockService::cascadeNumbersToTime(u_int16_t delay_ms) {
    uint8_t* target = digits.lock_get();

    time_t now = time(0);
    tm* local_tm = localtime(&now);

    uint8_t targetNum[3], currentNum[3];
    TimeTools::time2numbers(currentNum, local_tm);
    TimeTools::digits2numbers(targetNum, target);
    digits.unlock();

    wait_ms(delay_ms);

    while(!array_equals(targetNum, currentNum, 3) and keepAlive){

        for(uint8_t i = 0; i < 3; i++){
            if(targetNum[i] < currentNum[i]){
                targetNum[i]++;
            }
            else if (targetNum[i] > currentNum[i])
            {
                targetNum[i]--;
            }
        }

        now = time(0);
        local_tm = localtime(&now);
        TimeTools::time2numbers(currentNum, local_tm);

        digits.lock();
        TimeTools::numbers2digits(target, targetNum);
        digits.unlock();

        mixer.paint();

        wait_ms(delay_ms);
    }

}

void ClockService::waitUntilNextSec() {
    struct timeval now;
    gettimeofday(&now, NULL);
    wait_ms(1000 - now.tv_usec / 1000);
}

bool ClockService::array_equals(uint8_t* array1, uint8_t* array2, size_t size) {
    for(int i = 0; i < size; i++) {
        if(array1[i] != array2[i]) return false;
    }
    return true;
}

void ClockService::reset() {
    uint8_t* target = this->digits.lock_get();
    for(uint8_t i = 0; i < DIAL_COUNT; i++) {
        target[i] = 0;
    }
    digits.unlock();
    mixer.paint();
}
