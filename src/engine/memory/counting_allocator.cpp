// counting_allocator.cpp
// Implementation of counting allocator
#include "counting_allocator.hpp"

namespace StevensDev {
namespace sgdm {

template<class T>
int CountingAllocator<T>::totalNumAllocations = 0;
template<class T>
int CountingAllocator<T>::totalNumReleases = 0;

template<class T>
T* CountingAllocator<T>::get(int count){
    T* elem = new T[count];
    numAllocations += count;
    totalNumAllocations += count;
    return elem;
}

template<class T>
void CountingAllocator<T>::release(T *elem, int count){
    delete[] elem;
    numReleases += count;
    totalNumReleases += count;
}

template<class T>
const int CountingAllocator<T>::getAllocationCount(){
    return numAllocations;
}

template<class T>
const int CountingAllocator<T>::getReleaseCount(){
    return numReleases;
}

template<class T>
const int CountingAllocator<T>::getOutstandingCount(){
    return numAllocations - numReleases;
}


template<class T>
int CountingAllocator<T>::getTotalAllocationCount(){
    return totalNumAllocations;
}

template<class T>
int CountingAllocator<T>::getTotalReleaseCount(){
    return totalNumReleases;
}

template<class T>
int CountingAllocator<T>::getTotalOutstandingCount(){
    return totalNumAllocations - totalNumReleases;
}

} // End namespace sgdm
} // End namespace StevensDev
