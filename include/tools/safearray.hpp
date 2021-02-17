//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_SAFEARRAY_HPP
#define HORLOGE_SAFEARRAY_HPP

#include <mutex>
#include "ledcolor.hpp"
#include "settings.hpp"

template<class T, int size>
class SafeArray {
private:
    T array[size];
    std::mutex mutex;

public:
    SafeArray();

    T* lock_get();
    T *unsafe_get();

    void lock();
    void unlock();

};

template class SafeArray<color_t, DIAL_COUNT>;
template class SafeArray<uint8_t, DIAL_COUNT>;


#endif //HORLOGE_SAFEARRAY_HPP
