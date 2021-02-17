//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_LEDMATRIX_HPP
#define HORLOGE_LEDMATRIX_HPP

#include <cstdint>
#include "tools/ledcolor.hpp"

#define DIAL_COUNT              6                          // 6 dials
#define DIGITS_COUNT            10                         // 10 digits (from 0 to 9)
#define LED_COUNT               (DIAL_COUNT * DIGITS_COUNT)


/**
Classe stockant les données d'affichage et les fonctions editions
*/
class LedMatrix {

private:
    color_t matrix[LED_COUNT]{};

public:

    explicit LedMatrix(bool clear = true);
    ~LedMatrix() = default;

    void all(color_t color);
    void set(uint8_t digit, uint8_t dial, color_t color);
    void dial(uint8_t dial, color_t color);
    void digits(const uint8_t digits[DIAL_COUNT], const color_t colors[DIAL_COUNT]);
    void matrixLERP(LedMatrix& result, LedMatrix& final, float t);
    color_t get(uint8_t digit, uint8_t dial) const;
};

#endif //HORLOGE_LEDMATRIX_HPP


