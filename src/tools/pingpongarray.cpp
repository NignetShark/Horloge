//
// Created by paul on 17/02/2021.
//

#include <cstring>
#include "tools/pingpongarray.hpp"

template<class T, int size>
PingPongArray<T, size>::PingPongArray() {
    front = array1;
    back = array2;

    memset(array1, 0, sizeof(array1));
    memset(array2, 0, sizeof(array2));
}

template<class T, int size>
void PingPongArray<T, size>::unlock() {
    mutex.unlock();
}

template<class T, int size>
void PingPongArray<T, size>::lock() {
    mutex.lock();
}

template<class T, int size>
void PingPongArray<T, size>::unsafe_swap() {
    T* temp = front;
    front = back;
    back = temp;
}

template<class T, int size>
T *PingPongArray<T, size>::getFront() {
    return front;
}

template<class T, int size>
T *PingPongArray<T, size>::getBack() {
    return back;
}


