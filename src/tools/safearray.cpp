//
// Created by paul on 17/02/2021.
//

#include "tools/safearray.hpp"

template<class T, int size>
SafeArray<T, size>::SafeArray() {

}

template<class T, int size>
void SafeArray<T, size>::end_get() {
    mutex.unlock();
}

template<class T, int size>
T* SafeArray<T, size>::start_get() {
    mutex.lock();
    return array;
}
