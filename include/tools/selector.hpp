//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_SELECTOR_HPP
#define HORLOGE_SELECTOR_HPP

#include <vector>

/**
 * Class that provide a selection
 */
class Selector {
private:
    /**
     * Current mode
     */
    size_t index;

    /**
     * Number of modes
     */
    size_t size;

public:

    /**
     * Define a mode selector
     * @param size number of mode
     * @param default_index default mode
     */
    Selector(size_t size, size_t default_index);
    
    /**
     * Call next mode
     */
    void next();

    /**
     * Call previous mode
     */
    void previous();

    /**
     * Call the current mode
     */
    void current();

    /**
     * Called before any change
     */
    virtual void beforeChanging() = 0;

    /**
     * Called when a mode is selected
     * @param index
     */
    virtual void mode(size_t index) = 0;
};


#endif //HORLOGE_SELECTOR_HPP
