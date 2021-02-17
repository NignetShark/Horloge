//
// Created by paul on 17/02/2021.
//

#include "tools/selector.hpp"

#include <utility>

Selector::Selector(size_t size, size_t default_index) : index(default_index), size(size) {
}

void Selector::next() {
    index++;
    if(index >= size) index = 0;
    beforeChanging();
    mode(index);
}

void Selector::previous() {
    index = ((index == 0) ? size : index) - 1;
    beforeChanging();
    mode(index);
}

void Selector::current() {
    mode(index);
}


