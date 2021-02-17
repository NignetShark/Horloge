//
// Created by paul on 17/02/2021.
//

#include "service/coloration_service.hpp"

ColorationService::ColorationService(DialMixer& mixer, size_t nb_modes, size_t default_mode) : Selector(nb_modes, default_mode), mixer(mixer) {

}

void ColorationService::beforeChanging() {

}
