//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_MANAGER_HPP
#define HORLOGE_MANAGER_HPP

#include <service/coloration/dial_coloration.hpp>
#include <service/timing/clock_service.hpp>
#include <service/dial_mixer.hpp>
#include <service/animation/wave.hpp>
#include "display/display.hpp"

class Manager {
private:
    static Manager* instance;

    Display& display;

    DialMixer* dial_mixer;
    DialColoration* dial_coloration;
    ClockService* clock_service;

    animation::Wave* anim_wave;

    Service* current_service = nullptr;

    Manager(Display& display);
    ~Manager();

public:
    static void create(Display& display);
    static Manager& get();

    Display& getDisplay();

    void start_clock();

    void stop();

    void start_animation();
};


#endif //HORLOGE_MANAGER_HPP
