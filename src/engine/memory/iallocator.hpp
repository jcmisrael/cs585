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
    virtual T* get(int count);
    virtual void release(T* elem, int count);
};

} // End namespace sgdm
} // End namespace StevensDev
#endif
