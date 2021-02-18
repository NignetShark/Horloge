//
// Created by paul on 18/02/2021.
//

#include <service/animation/wave.hpp>
#include <exception/FatalException.hpp>
#include "manager.hpp"

Manager* Manager::instance;

Manager::Manager(Display &display) : display(display), anim_service(), ntp_service(anim_service) {
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
        current_service = nullptr;
    }
}

void Manager::start_clock() {
    stop();
    dial_mixer->setup(dial_coloration, clock_service);
    dial_mixer->start();
    current_service = dial_mixer;
}

void Manager::start_animation() {
    stop();
    animation::Wave::get().setup(led_color::WHITE);
    anim_service.setup(animation::Wave::get(), 0.1, 50);
    anim_service.start();
    current_service = &anim_service;
}

void Manager::start_ntp() {
    stop();
    ntp_service.start();
    current_service = &ntp_service;
}


