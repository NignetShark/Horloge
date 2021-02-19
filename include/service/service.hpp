//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_SERVICE_HPP
#define HORLOGE_SERVICE_HPP

#include <set>

/**
 * Abstract class of any service
 */
class Service {
private:
    /**
     * Set of all running service
     */
    static std::set<Service*> running;

    /**
     * Request start
     */
    virtual void _start() = 0;

    /**
     * Request stop
     */
    virtual void _stop() = 0;

    virtual void _start_sync() = 0;

public:
    /**
     * Stop all running services
     */
    static void stop_all();

    /**
     * Start a service
     */
    void start();

    /**
     * Start and wait for termination
     */
    void start_sync();

    /**
     * Stop a service
     */
    void stop();
};


#endif //HORLOGE_SERVICE_HPP
