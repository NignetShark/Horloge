//
// Created by paul on 17/02/2021.
//

#include "display/display.hpp"

void Display::save_state(LedMatrix *matrix) {
    matrix->copy(&this->state);
}

void Display::load_state(LedMatrix *target) {
    state.copy(target);
}

Display::Display() : state(true) {

}
