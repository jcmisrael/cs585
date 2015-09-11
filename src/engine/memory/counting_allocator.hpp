// counting_allocator.hpp
// Definition of counting allocator
#ifndef _COUNTING_ALLOCATOR_H_
#define _COUNTING_ALLOCATOR_H_

#include "iallocator.hpp"

namespace StevensDev {
namespace sgdm {

template<class T>
class CountingAllocator: public IAllocator<T> {
  private:
    int        numAllocations;
    int        numReleases;
    static int totalNumAllocations;
    static int totalNumReleases;
  public:
    T*         get(int count);
    void       release(T* elem, int count);
    const int  getAllocationCount();
    const int  getReleaseCount();
    const int  getOutstandingCount();
    static int getTotalAllocationCount();
    static int getTotalReleaseCount();
    static int getTotalOutstandingCount();
};

} // End namespace sgdm
} // End namespace StevensDev

#endif
