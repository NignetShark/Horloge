//
// Created by paul on 17/02/2021.
//

#include "service/async_service.hpp"

void AsyncService::start() {
    keepAlive = true;
    service_thread = std::thread(&AsyncService::run, this);
}

void AsyncService::stop() {
    if(keepAlive) {
        keepAlive = false;
        service_thread.join();
    }
}

void AsyncService::wait_ms(unsigned int delay) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));

}
