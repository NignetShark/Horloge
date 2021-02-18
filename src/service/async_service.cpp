//
// Created by paul on 17/02/2021.
//

#include <exception/FatalException.hpp>
#include "service/async_service.hpp"

void AsyncService::_start() {
    if(keepAlive) throw FatalException("Service already running.");
    keepAlive = true;
    service_thread = std::move(std::thread(&AsyncService::run, this));
}

void AsyncService::_stop() {
    if(keepAlive) {
        keepAlive = false;
        service_thread.join();
    }
}

void AsyncService::wait_ms(unsigned int delay) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));

}
