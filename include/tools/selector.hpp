//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_SELECTOR_HPP
#define HORLOGE_SELECTOR_HPP

#include <vector>

class Selector {
private:
    size_t index;
    size_t size;

public:
    Selector(size_t size, size_t default_index);

    void next();
    void previous();
    void current();

    virtual void beforeChanging() = 0;
    virtual void mode(size_t index) = 0;
};


#endif //HORLOGE_SELECTOR_HPP
