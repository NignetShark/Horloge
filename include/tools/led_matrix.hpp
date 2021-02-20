//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_LED_MATRIX_HPP
#define HORLOGE_LED_MATRIX_HPP

#include <cstdint>
#include "tools/led_color.hpp"
#include "tools/settings.hpp"


/**
 * Class used to store the matrix color data and provide helpers to manipulate them.
*/
class LedMatrix {

private:
    /**
     * Matrix color data.
     */
    color_t matrix[LED_COUNT];

public:

    explicit LedMatrix(bool clear = true);
    ~LedMatrix() = default;

    /**
     * Clear all the matrix data
     */
    void clear();

    /**
     * Set all the matrix data
     * @param color
     */
    void all(color_t color);

    /**
     * Set a specific point
     * @param digit
     * @param dial
     * @param color
     */
    void set(uint8_t digit, uint8_t dial, color_t color);

    /**
     * Set all the digits of a dial.
     * @param dial
     * @param color
     */
    void dial(uint8_t dial, color_t color);

    /**
     * Set the color of each digit
     * @param digits
     * @param colors
     */
    void digits(const uint8_t digits[DIAL_COUNT], const color_t colors[DIAL_COUNT]);

    /**
     * Get the color of a specific point
     * @param digit
     * @param dial
     * @return
     */
    color_t get(uint8_t digit, uint8_t dial) const;

    /**
     * Copy this LedMatrix to dest.
     * @param dest
     */
    void copy(LedMatrix* dest);

    /**
     * Linear interpolation between this and final
     * @param result
     * @param final
     * @param t (percentage between 0 and 1)
     */
    void matrixLERP(LedMatrix& result, LedMatrix& final, float t);

    /**
     * Return the matrix color_t
     * @return matrix color_t
     */
    const color_t *getMatrix() const;
};

#endif //HORLOGE_LED_MATRIX_HPP


