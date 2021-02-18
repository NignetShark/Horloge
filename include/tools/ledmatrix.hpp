//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_LEDMATRIX_HPP
#define HORLOGE_LEDMATRIX_HPP

#include <cstdint>
#include "tools/ledcolor.hpp"
#include "tools/settings.hpp"


/**
Classe stockant les données d'affichage et les fonctions editions
*/
class LedMatrix {

private:
    color_t matrix[LED_COUNT]{};

public:

    explicit LedMatrix(bool clear = true);
    ~LedMatrix() = default;

    void clear();
    void all(color_t color);

    void set(uint8_t digit, uint8_t dial, color_t color);
    void dial(uint8_t dial, color_t color);
    void digits(const uint8_t digits[DIAL_COUNT], const color_t colors[DIAL_COUNT]);
    color_t get(uint8_t digit, uint8_t dial) const;

    void copy(LedMatrix* dest);

    void matrixLERP(LedMatrix& result, LedMatrix& final, float t);
};

#endif //HORLOGE_LEDMATRIX_HPP


