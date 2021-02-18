//
// Created by paul on 18/02/2021.
//

#include <exception/FatalException.hpp>
#include "manager.hpp"

Manager* Manager::instance;

Manager::Manager(Display &display) : display(display) {
    instance = this;
    dial_mixer = new DialMixer();
    dial_coloration = new DialColoration(*dial_mixer);
    clock_service = new ClockService(*dial_mixer);
}

void Manager::create(Display &display) {
    if(instance != nullptr) throw FatalException("The manager was already initialized");
    new Manager(display);
}

Manager &Manager::get() {
    if(instance == nullptr) throw FatalException("The manager was not initialized");
    return *instance;
}

Display &Manager::getDisplay() {
    return display;
}

void Manager::stop() {
    if(current_service) {
        current_service->stop();
    }
}

void Manager::start_clock() {
    stop();
    dial_mixer->setup(dial_coloration, clock_service);
    dial_mixer->start();
}


