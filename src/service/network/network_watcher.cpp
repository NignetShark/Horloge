//
// Created by paul on 24/02/2021.
//
#include <cstdlib>
#include <iostream>
#include <tools/logging.hpp>
#include "service/network/network_watcher.hpp"

NetworkWatcher::NetworkWatcher() {

}

bool NetworkWatcher::ping_test() {
    std::string cmd = "/bin/ping " + std::string(PING_TARGET) + " -c 2 -I " +  std::string(NETWORK_INTERFACE) + " > /dev/null";
    return system(cmd.c_str()) == 0;
}

void NetworkWatcher::run() {
    if(ping_test()) {
        Logging::get().write(std::string(PING_TARGET) + " is reachable.");
    } else {
        Logging::get().warning("Ping test failed.");
    }
}
