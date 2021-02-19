//
// Created by paul on 19/02/2021.
//

#ifndef HORLOGE_TASK_SCHEDULED_HPP
#define HORLOGE_TASK_SCHEDULED_HPP


#include <ctime>

class TaskScheduled {
public:
    virtual bool time_is_up(time_t handled_date) = 0;
    virtual void reschedule(time_t &new_date) = 0;
private:
};


#endif //HORLOGE_TASK_SCHEDULED_HPP
