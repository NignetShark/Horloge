//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_PING_PONG_ARRAY_HPP
#define HORLOGE_PING_PONG_ARRAY_HPP

#include <mutex>
#include "led_color.hpp"
#include "settings.hpp"

/**
 * Array using the ping pong technic for a model 1 producer / 1 consumer
 * @tparam T array type
 * @tparam size array size
 */
template<class T, int size>
class PingPongArray {
private:
    T array1[size];
    T array2[size];

    /**
     * Pointer to the front array
     */
    T* front;

    /**
     * Pointer to the back array
     */
    T* back;

    /**
     * Mutex used to protect swap
     */
    std::mutex mutex;

public:
    PingPongArray();

    void lock();
    void unlock();

    T* getFront();
    T* getBack();

    /**
     * Swap front and back.
     * WARNING: Not protected by the mutex.
     */
    void unsafe_swap();

};

template class PingPongArray<color_t, DIAL_COUNT>;
template class PingPongArray<uint8_t, DIAL_COUNT>;


#endif //HORLOGE_PING_PONG_ARRAY_HPP
