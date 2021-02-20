//
// Created by paul on 19/02/2021.
//

#include <iostream>
#include <exception/fatal_exception.hpp>
#include <tools/debug_print.hpp>
#include <tools/logging.hpp>
#include <tools/time_tools.hpp>
#include <manager.hpp>
#include "service/scheduler/day_night_task.hpp"


DayNightTask::DayNightTask(time_t day, time_t night) : day(day), night(night) {
    recompute_date(0);
}

bool DayNightTask::time_is_up(time_t handled_date) {
    if(handled_date == day) {
        Logging::get().write("Switch to day.");
        Manager::get().get_color_input()->set_day_mode();
    } else if(handled_date == night) {
        Logging::get().write("Switch to night.");
        Manager::get().get_color_input()->set_night_mode();
    } else {
        throw FatalException("Incoherent handled date in day/night schedule");
    }
    return true; // Reschedule
}

void DayNightTask::reschedule(time_t &new_date, time_t &handled_date) {
    recompute_date(handled_date);

    if(day < night) {
        new_date = day;
        Logging::get().write("Day scheduled for " + TimeTools::time2str(new_date));
    } else {
        new_date = night;
        Logging::get().write("Night scheduled for " + TimeTools::time2str(new_date));
    }
}

void DayNightTask::recompute_date(time_t now) {
    while(now >= night) {
        night += 24 * 3600;
    }

    while(now >= day) {
        day += 24 * 3600;
    }
}


