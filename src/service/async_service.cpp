//
// Created by paul on 17/02/2021.
//

#include <exception/fatal_exception.hpp>
#include "service/async_service.hpp"

void AsyncService::_start() {
    if(keep_alive) throw FatalException("Service already running.");
    keep_alive = true;
    service_thread = std::move(std::thread(&AsyncService::run, this));
}

void AsyncService::_start_sync() {
    if(keep_alive) throw FatalException("Service already running.");
    keep_alive = true;
    run();
    keep_alive = false;
}


void AsyncService::_stop() {
    if(keep_alive) {
        keep_alive = false;
        service_thread.join();
    }
}

void AsyncService::wait_ms(unsigned int delay) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

bool AsyncService::is_alive() const {
    return keep_alive;
}

void AsyncService::wait_until(time_t date) {
    std::this_thread::sleep_until(std::chrono::system_clock::from_time_t(date));
}

