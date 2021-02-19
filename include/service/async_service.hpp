//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_ASYNC_SERVICE_HPP
#define HORLOGE_ASYNC_SERVICE_HPP
#include <thread>
#include "service.hpp"

/**
 * Abstract class of any asynchronous service
 */
class AsyncService : public Service {
private:
    std::thread service_thread;

    /**
     * Body of the thread
     */
    virtual void run() = 0;

protected:
    /**
     * true = service running
     */
    bool keepAlive = false;

public:
    void _start() override;
    void _stop() override;

    /**
     * Is the service running ?
     * @return true if running.
     */
    bool is_alive() const;

    /**
     * Wait for a specific delay in ms
     * @param delay in milliseconds
     */
    static void wait_ms(unsigned int delay);
};


#endif //HORLOGE_ASYNC_SERVICE_HPP
