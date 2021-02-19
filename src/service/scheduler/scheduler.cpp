//
// Created by paul on 19/02/2021.
//

#include "service/scheduler/scheduler.hpp"

Scheduler::Scheduler() : mutex(), tasks() {

}

void Scheduler::run() {
    while(!tasks.empty() && keepAlive) {
        mutex.lock();
        time_t wake_up_date = tasks.begin()->first;
        TaskScheduled* task = tasks.begin()->second;
        tasks.erase(wake_up_date);
        mutex.unlock();

        AsyncService::wait_until(wake_up_date);

        if(task->time_is_up(wake_up_date)) {
            // Reschedule
            time_t new_date;
            task->reschedule(new_date);

            mutex.lock();
            tasks[new_date] = task;
            mutex.unlock();
        }
    }
}

void Scheduler::append(TaskScheduled *task) {
    time_t date;
    task->reschedule(date);

    mutex.lock();
    tasks[date] = task;
    mutex.unlock();
}

