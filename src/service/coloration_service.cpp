//
// Created by paul on 17/02/2021.
//

#include "service/coloration_service.hpp"

ColorationService::ColorationService(size_t nb_modes, size_t default_mode) : Selector(nb_modes, default_mode) {

}

void ColorationService::mode_changed() {
    if(keepAlive) stop();
    start();
}

void ColorationService::next_color_mode() {
    this->next_state();
}

void ColorationService::previous_color_mode() {
    this->previous_state();
}

void ColorationService::set_day_mode() {
    load_state();
}

void ColorationService::set_night_mode() {
    save_state();
    set_mode(get_night_mode());
}



