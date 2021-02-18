//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_SERVICE_HPP
#define HORLOGE_SERVICE_HPP

#include <set>

class Service {
private:
    static std::set<Service*> running;
    virtual void _start() = 0;
    virtual void _stop() = 0;

public:
    static void stop_all();

    void start();
    void stop();
};


#endif //HORLOGE_SERVICE_HPP
