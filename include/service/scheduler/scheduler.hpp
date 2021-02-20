//
// Created by paul on 19/02/2021.
//

#ifndef HORLOGE_SCHEDULER_HPP
#define HORLOGE_SCHEDULER_HPP

#include <mutex>
#include <map>
#include <ctime>
#include <service/async_service.hpp>
#include "task_scheduled.hpp"

class Scheduler : public AsyncService {
private:
    /**
     * Map of all scheduled task.
     */
    std::map<time_t, TaskScheduled*> tasks;
    std::mutex mutex;

    void run() override;


public:
    Scheduler();

    /**
     * Add a task to the scheduler
     * @param task
     */
    void append(TaskScheduled *task);
};


#endif //HORLOGE_SCHEDULER_HPP
