// default_allocator.cpp
// Default implementation of IAllocator
#include "default_allocator.hpp"

namespace StevensDev {
namespace sgdm {

template<class T>
T* DefaultAllocator<T>::get(int count){
    T* tPtr = new T[count];
    return tPtr;
}

template<class T>
void DefaultAllocator<T>::release(T *elem, int count){
    delete[] elem;
}

} // End namespace sgdm
} // End namespace StevensDev
