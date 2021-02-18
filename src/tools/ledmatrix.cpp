//
// Created by paul on 17/02/2021.
//

#include <cstring>
#include <algorithm>
#include <iostream>
#include "tools/ledmatrix.hpp"

static uint8_t LOOKUP_INDEXES[DIGITS_COUNT][DIAL_COUNT];  // Look up table use to match the corresponding

/**
 * Setup the lookup table
 */
__attribute__((constructor)) // Important in order to setup before using it. (Works with gcc and clang)
void setup_lookup_indexes() {
    for(uint8_t digit = 0; digit < DIGITS_COUNT; digit++) {
        for(uint8_t dial = 0; dial < DIAL_COUNT; dial++) {
            uint8_t index = dial * 10;
            if(digit % 2 == 0){
                index += 5;
            }
            index += digit/2;
            LOOKUP_INDEXES[digit][dial] = index;
        }
    }
    std::cout << "OK" << std::endl;
}

LedMatrix::LedMatrix(bool clear) : matrix() {
    if(clear) all(led_color::BLACK); // Clear values in matrix.
}


void LedMatrix::all(const color_t color) {
    std::fill_n(this->matrix, LED_COUNT, color);
}

void LedMatrix::dial(const uint8_t dial, const color_t color) {
    for (uint8_t digit = 0; digit < DIGITS_COUNT; digit++)
    {
        matrix[LOOKUP_INDEXES[digit][dial]] = color;
    }
}

void LedMatrix::digits(const uint8_t digits[DIAL_COUNT], const color_t colors[DIAL_COUNT]) {
    for (uint8_t index = 0; index < DIAL_COUNT; index++)
    {
        matrix[LOOKUP_INDEXES[digits[index]][index]] = colors[index];
    }
}

void LedMatrix::set(const uint8_t digit, const uint8_t dial, const color_t color) {
    matrix[LOOKUP_INDEXES[digit][dial]] = color;
}

void LedMatrix::matrixLERP(LedMatrix &result, LedMatrix &final, float t) {
    led_color::LERP(result.matrix, this->matrix, final.matrix, t, 0, LED_COUNT);
}

color_t LedMatrix::get(uint8_t digit, uint8_t dial) const {
    return matrix[LOOKUP_INDEXES[digit][dial]];
}







