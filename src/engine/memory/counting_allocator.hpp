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
    CountingAllocator(){
        numAllocations = 0;
        numReleases = 0;
    }

    T*         get(int count){
        T* elem = new T[count];
        numAllocations += count;
        totalNumAllocations += count;
        return elem;
    }

    void       release(T* elem, int count){
        delete[] elem;
        numReleases += count;
        totalNumReleases += count;
    }

    const int  getAllocationCount(){
        return numAllocations;
    }

    const int  getReleaseCount(){
        return numReleases;
    }

    const int  getOutstandingCount(){
        return numAllocations - numReleases;
    }

    static int getTotalAllocationCount(){
        return totalNumAllocations;
    }

    static int getTotalReleaseCount(){
        return totalNumReleases;
    }

    static int getTotalOutstandingCount(){
        return totalNumAllocations - totalNumReleases;
    }
};

template<class T>
int CountingAllocator<T>::totalNumAllocations = 0;
template<class T>
int CountingAllocator<T>::totalNumReleases = 0;

} // End namespace sgdm
} // End namespace StevensDev

#endif
