//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_DISPLAY_HPP
#define HORLOGE_DISPLAY_HPP


#include <tools/led_matrix.hpp>

/**
 * Display abstraction with the aim to show a LedMatrix
 */
class Display {
private:
    /**
     * Save the last state of a ending service.
     */
    LedMatrix state;

public:
    Display();

    /**
     * Show a LedMatrix.
     * @param matrix
     */
    virtual void display(LedMatrix& matrix) = 0;

    /**
     * Load state (copy).
     * @param target
     */
    void load_state(LedMatrix *target);

    /**
     * Set state (copy).
     * @param matrix
     */
    void save_state(LedMatrix* matrix);
};


#endif //HORLOGE_DISPLAY_HPP
