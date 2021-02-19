//
// Created by paul on 19/02/2021.
//

#include <iostream>
#include <exception/fatal_exception.hpp>
#include "service/scheduler/day_night_task.hpp"


DayNightTask::DayNightTask(time_t day, time_t night) : day(day), night(night) {
    recompute_date();
}

bool DayNightTask::time_is_up(time_t handled_date) {
    if(handled_date == day) {
        std::cout << "Day !";
    } else if(handled_date == night) {
        std::cout << "Night !";
    } else {
        throw FatalException("Incoherent handled date in day/night schedule");
    }
    return true; // Reschedule
}

void DayNightTask::reschedule(time_t &new_date) {
    recompute_date();

    if(day < night) {
        new_date = day;
    } else {
        new_date = night;
    }
}

void DayNightTask::recompute_date() {
    time_t now = time(0);

    while(now > night) {
        night += 24 * 3600;
    }

    while(now > day) {
        day += 24 * 3600;
    }

    // Todo remove
    std::cout << ctime(&night) << std::endl;
    std::cout << ctime(&day) << std::endl;

}


