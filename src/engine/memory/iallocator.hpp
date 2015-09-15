// iallocator.h
// Header for allocator base type

#ifndef _IALLOCATOR_H_
#define _IALLOCATOR_H_

namespace StevensDev {
namespace sgdm {

template<class T>
class IAllocator {
private:
public:
    virtual T* get(int count) = 0;
    virtual void release(T* elem, int count) = 0;
};

} // End namespace sgdm
} // End namespace StevensDev
#endif
