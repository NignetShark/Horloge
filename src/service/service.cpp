//
// Created by paul on 18/02/2021.
//

#include "service/service.hpp"

std::set<Service*> Service::running;

void Service::stop_all() {
    for(Service* service : running) {
        service->_stop();
    }
    running.clear();
}

void Service::start() {
    running.insert(this);
    this->_start();
}

void Service::stop() {
    this->_stop();
    running.erase(this);
}

void Service::start_sync() {
    running.insert(this);
    this->_start_sync();
    running.erase(this);
}
