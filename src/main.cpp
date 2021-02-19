#include <iostream>
#include <display/terminal_display.hpp>
#include <service/dial_mixer.hpp>
#include <service/coloration/dial_coloration.hpp>
#include <service/timing/clock_service.hpp>
#include <manager.hpp>
#include <display/nixie_display.hpp>
#include "tools/ledmatrix.hpp"
#include "tools/ledcolor.hpp"
#include "tools/debugprint.hpp"


int main() {
    //NixieDisplay display;
    TerminalDisplay display;

    Manager::create(display);

    Manager::get().start_ntp();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    Manager::get().start_animation();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    Manager::get().start_clock();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}


