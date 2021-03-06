#include <iostream>
#include <display/terminal_display.hpp>
#include <service/timing/clock_service.hpp>
#include <manager.hpp>
#include <display/nixie_display.hpp>
#include <service/scheduler/day_night_task.hpp>
#include <service/network/network_watcher.hpp>


int main() {
    /* Select a display */
    NixieDisplay display;
    //TerminalDisplay display;

    Manager* manager = Manager::create(display); // Create the manager

    time_t now = time(0), day, night;
    tm* time = localtime(&now);
    time->tm_hour = 22;
    time->tm_min = 0;
    time->tm_sec = 0;
    night = mktime(time);
    time->tm_hour = 8;
    time->tm_min = 0;
    time->tm_sec = 0;
    day = mktime(time);

    DayNightTask day_night_task(day, night);
    manager->get_scheduler().append(&day_night_task);
    manager->start_scheduler();


    NetworkWatcher networkWatcher;
    networkWatcher.start();
    Manager::get().start_ntp();

    //Manager::get().start_animation();


    manager->start_clock();



    manager->read_input();
    //std::this_thread::sleep_for(std::chrono::seconds(25));

    return 0;
}


