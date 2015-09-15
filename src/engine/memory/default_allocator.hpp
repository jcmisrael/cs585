// default_allocator.hpp
// Default implementation of an Allocator
#ifndef _DEFAULT_ALLOCATOR_H_
#define _DEFAULT_ALLOCATOR_H_

#include "iallocator.hpp"

namespace StevensDev {
namespace sgdm {

template<class T>
class DefaultAllocator: public IAllocator<T> {
private:
public:
    T* get(int count){
        T* tPtr = new T[count];
        return tPtr;
    }

    void release(T* elem, int count){
        delete[] elem;
    }
};

} // End namespace sgdm
} // End namespace StevensDev

#endif
