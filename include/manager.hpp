//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_MANAGER_HPP
#define HORLOGE_MANAGER_HPP

#include <service/coloration/dial_coloration.hpp>
#include <service/timing/clock_service.hpp>
#include <service/dial_mixer.hpp>
#include <service/animation_service.hpp>
#include <service/ntp/ntp_service.hpp>
#include <service/scheduler/scheduler.hpp>
#include <input/terminal_input.hpp>
#include "display/display.hpp"

/**
 * Manager of all the services
 * Singleton model.
 */
class Manager {
private:
    static Manager* instance;

    Display& display;
    AnimationService anim_service;
    NTPService ntp_service;

    DialMixer* dial_mixer;
    DialColoration* dial_coloration;
    ClockService* clock_service;

    Scheduler scheduler;
    TerminalInput terminal_input;

    /**
     * Current base service
     */
    Service* current_base_service = nullptr;

    Manager(Display& display);
    ~Manager();

public:
    /**
     * Create the manager
     * @param display use to show LedMatrix
     */
    static Manager * create(Display& display);

    /**
     * Return the current instance
     * @return current instance
     */
    static Manager& get();

    /**
     * Return display used to show LedMatrix
     * @return display
     */
    Display& get_display();

    /**
     * Return the scheduler
     * @return scheduler
     */
    Scheduler& get_scheduler();

    void start_clock();
    void start_animation();
    void start_ntp();
    void start_scheduler();
    void read_input();

    ColorInputInterface* get_color_input();

    /**
     * Stop the current base process
     */
    void stop();

};


#endif //HORLOGE_MANAGER_HPP
