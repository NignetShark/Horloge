//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_PINGPONGARRAY_HPP
#define HORLOGE_PINGPONGARRAY_HPP

#include <mutex>
#include "ledcolor.hpp"
#include "settings.hpp"

template<class T, int size>
class PingPongArray {
private:
    T array1[size];
    T array2[size];

    T* front;
    T* back;
    std::mutex mutex;

public:
    PingPongArray();

    void lock();
    void unlock();

    T* getFront();
    T* getBack();

    void unsafe_swap();

};

template class PingPongArray<color_t, DIAL_COUNT>;
template class PingPongArray<uint8_t, DIAL_COUNT>;


#endif //HORLOGE_PINGPONGARRAY_HPP
