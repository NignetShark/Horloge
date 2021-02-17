#include <iostream>
#include <display/terminal_display.hpp>
#include <dial_mixer.hpp>
#include <service/coloration/dial_coloration.hpp>
#include <service/timing/clock_service.hpp>
#include "tools/ledmatrix.hpp"
#include "tools/ledcolor.hpp"
#include "tools/debugprint.hpp"


int main() {
    TerminalDisplay display;
    DialMixer mixer(display);
    DialColoration dial_coloration(mixer);
    ClockService clock(mixer);

    dial_coloration.start();
    clock.start();

    dial_coloration.stop();
    clock.stop();

    return 0;
}


