//
// Created by paul on 19/02/2021.
//

#ifndef HORLOGE_DAY_NIGHT_TASK_HPP
#define HORLOGE_DAY_NIGHT_TASK_HPP

#include "task_scheduled.hpp"

class DayNightTask : public TaskScheduled {
    time_t day, night;

    void recompute_date();
public:
    DayNightTask(time_t day, time_t night);

    bool time_is_up(time_t handled_date) override;

    void reschedule(time_t &new_date) override;
};


#endif //HORLOGE_DAY_NIGHT_TASK_HPP
