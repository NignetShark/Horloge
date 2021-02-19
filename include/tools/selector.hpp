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
    size_t index, saved_index;

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
     * Call next_state mode
     */
    void next_state();

    /**
     * Set mode
     */
     void set_mode(unsigned int mode);

    /**
     * Call previous_state mode
     */
    void previous_state();

    /**
     * Save the current index
     */
    void save_state();

    /**
     * Load the saved index
     */
    void load_state();

    /**
     * Called to apply a change
     */
    virtual void mode_changed() = 0;

    unsigned int get_current_mode();


};


#endif //HORLOGE_SELECTOR_HPP
