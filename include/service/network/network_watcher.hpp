//
// Created by paul on 24/02/2021.
//

#ifndef HORLOGE_NETWORK_WATCHER_HPP
#define HORLOGE_NETWORK_WATCHER_HPP

#include <string>
#include "service/async_service.hpp"

#define NETWORK_INTERFACE "wlan0"
#define PING_TARGET "192.168.1.1"

class NetworkWatcher : public AsyncService {
private:
    static bool ping_test();

    void run() override;

public:
    NetworkWatcher();

};


#endif //HORLOGE_NETWORK_WATCHER_HPP
