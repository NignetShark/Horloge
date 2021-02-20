//
// Created by paul on 19/02/2021.
//

#ifndef HORLOGE_TASK_SCHEDULED_HPP
#define HORLOGE_TASK_SCHEDULED_HPP


#include <ctime>

class TaskScheduled {
public:
    /**
     * Function called when time is up
     * @param handled_date wake up time
     * @return true if need a reschedule.
     */
    virtual bool time_is_up(time_t handled_date) = 0;

    /**
     * Reschedule a task
     * @param new_date the date of the future wake up
     * @param handled_date the date of the last wake up
     */
    virtual void reschedule(time_t &new_date, time_t &handled_date) = 0;
private:
};


#endif //HORLOGE_TASK_SCHEDULED_HPP
