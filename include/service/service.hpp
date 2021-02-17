//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_SERVICE_HPP
#define HORLOGE_SERVICE_HPP
#include <thread>

class Service {
private:
    std::thread service_thread;

    virtual void run() = 0;

protected:
    bool keepAlive = false;

public:
    void start();
    void stop();

    static void wait_ms(unsigned int delay);
};


#endif //HORLOGE_SERVICE_HPP
