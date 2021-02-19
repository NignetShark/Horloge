//
// Created by paul on 17/02/2021.
//

#include "tools/selector.hpp"

#include <utility>

Selector::Selector(size_t size, size_t default_index) : index(default_index), size(size), saved_index(default_index) {
}

void Selector::next_state() {
    set_mode((index == size - 1) ? 0 : (index + 1));
}

void Selector::previous_state() {
    set_mode(((index == 0) ? size : index) - 1);
}

void Selector::save_state() {
    this->saved_index = index;
}

void Selector::load_state() {
    set_mode(saved_index);
}

void Selector::set_mode(unsigned int mode) {
    index = mode;
    mode_changed();
}

unsigned int Selector::get_current_mode() {
    return index;
}


