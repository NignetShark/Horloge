//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_ASYNC_SERVICE_HPP
#define HORLOGE_ASYNC_SERVICE_HPP
#include <thread>
#include "service.hpp"

class AsyncService : public Service {
private:
    std::thread service_thread;

    virtual void run() = 0;

protected:
    bool keepAlive = false;

public:
    void start() override;
    void stop() override;

    static void wait_ms(unsigned int delay);
};


#endif //HORLOGE_ASYNC_SERVICE_HPP
