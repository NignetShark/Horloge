//
// Created by paul on 17/02/2021.
//

#include <iostream>
#include <exception/fatal_exception.hpp>
#include "sys/time.h"
#include "service/timing/clock_service.hpp"
#include "tools/time_tools.hpp"


ClockService::ClockService(DialMixerInterface& mixer) : DigitsService(mixer) {
    reset(); // Important to prevent uninitialized values
}

void ClockService::run() {
    reset();

    // Launch animation
    cascadeNumbersToTime(50);

    uint8_t result[DIAL_COUNT];
    uint8_t* target = mixer.get_digit_array();

    while (keepAlive) {

        time_t now = time(0);
        TimeTools::time2digits(target, now);
        target = mixer.paint_digits();

        // Go back to 0 animation.
        if(target[5] == 9) {
            wait_ms(200);

            TimeTools::time2digits(result, now + 1);
            cascadeDigits(result, 50);

            target = mixer.get_digit_array();
        }

        wait_until_next_sec();
    }
}

void ClockService::cascadeDigits(uint8_t* to_digits, unsigned int delay_ms) {
    uint8_t* prev = mixer.get_prev_digit_array(); // Used to get the last value
    uint8_t* target = mixer.get_digit_array();

    while(!array_equals(target, to_digits, DIAL_COUNT) and keepAlive){

        for(uint8_t i = 0; i < DIAL_COUNT; i++){
            if(prev[i] < to_digits[i]){
                target[i] = prev[i] + 1;
            } else if (prev[i] > to_digits[i]) {
                target[i] = prev[i] - 1;
            } else {
                target[i] = prev[i];
            }
        }

        prev = target;
        target = mixer.paint_digits();
        wait_ms(delay_ms);
    }
}

void ClockService::cascadeNumbersToTime(unsigned int delay_ms) {
    uint8_t* target = mixer.get_digit_array();

    uint8_t targetNum[3], currentNum[3];
    TimeTools::time2numbers(currentNum, time(0));
    TimeTools::digits2numbers(targetNum, target);

    while(!array_equals(targetNum, currentNum, 3) and keepAlive){

        wait_ms(delay_ms);

        for(uint8_t i = 0; i < 3; i++){
            if(targetNum[i] < currentNum[i]){
                targetNum[i]++;
            }
            else if (targetNum[i] > currentNum[i])
            {
                targetNum[i]--;
            }
        }

        TimeTools::time2numbers(currentNum, time(0));
        TimeTools::numbers2digits(target, targetNum);

        target = mixer.paint_digits();
    }

}

void ClockService::wait_until_next_sec() {
    //struct timeval now;
    //gettimeofday(&now, NULL);
    //wait_ms(1000 - now.tv_usec / 1000); // Little extra to prevent rollback
    wait_until(time(0) + 1);
}

bool ClockService::array_equals(uint8_t* array1, uint8_t* array2, size_t size) {
    for(int i = 0; i < size; i++) {
        if(array1[i] != array2[i]) return false;
    }
    return true;
}

void ClockService::try_start() {
    this->start();
}

void ClockService::try_stop() {
    this->stop();
}

bool ClockService::is_alive() {
    return keepAlive;
}


