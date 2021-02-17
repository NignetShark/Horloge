//
// Created by paul on 17/02/2021.
//

#include "service/service.hpp"

void Service::start() {
    keepAlive = true;
    service_thread = std::thread(&Service::run, this);
}

void Service::stop() {
    if(keepAlive) {
        keepAlive = false;
        service_thread.join();
    }
}

void Service::wait_ms(unsigned int delay) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));

}
