//
// Created by paul on 17/02/2021.
//

#include <exception/hardware_failure.hpp>
#include <chrono>
#include <thread>
#include "display/nixie_display.hpp"
#include "tools/settings.hpp"
#include "exception/fatal_exception.hpp"

void NixieDisplay::display(LedMatrix &matrix) {
    clock.channel[0].leds = (ws2811_led_t*)matrix.getMatrix();

    ws2811_return_t ret = ws2811_render(&clock);

    if(ret != WS2811_SUCCESS){
        HardwareFailure failure("Nixie refresh failed", true, 0);
        failure.report(ret);
    }
}

NixieDisplay::NixieDisplay() : clock() {
    HardwareFailure failure("Nixie initialization failed", false, 10);

    clock = {
            0,
            nullptr,
            nullptr,
            TARGET_FREQ,
            14,
            {
                    {10, 0, LED_COUNT, STRIP_TYPE, nullptr, 255, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, nullptr, 255, 0, 0, 0, 0, 0}
            }

    };

    while (true) {
        ws2811_return_t ret = ws2811_init(&clock);
        if (ret != WS2811_SUCCESS) {
            failure.report(ret);
        } else {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

}
