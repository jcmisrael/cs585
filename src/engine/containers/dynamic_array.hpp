// dynamic_array.hpp
// Definition and implementation for a dynamic array
#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

#include <stdexcept>
#include "counting_allocator.hpp"

namespace StevensDev {
namespace sgdc {

template<class T>
class DynamicArray {
  private:
    const static unsigned int DEFAULT_ARRAY_SIZE;
    unsigned int frontIndex;
    unsigned int backIndex;
    unsigned int capacity;
    unsigned int size;
    StevensDev::sgdm::IAllocator<T>*  arrayAllocator;
    T* array;

    void resize(){
        unsigned int newCapacity = capacity * 2; // Stupid implementation
        T* newArray = NULL;
        newArray = arrayAllocator.get(newCapacity);
        copyArray(array, newArray, size);
        arrayAllocator.release(array, capacity);
        capacity = newCapacity;
        array = newArray;
        newArray = NULL;
    }

    void copyArray(T* initArray, T* newArray){
        unsigned int i;
        for(i = 0; i < size; ++i)
            newArray[i] = initArray[(frontIndex + i) % capacity];
    }

    void shift(unsigned int shiftIndex, unsigned int numShifts){
        unsigned int i;
        for(i = 0; ((shiftIndex + i) % capacity) != backIndex; ++i)
            array[shiftIndex + i] = array[shiftIndex + i + 1];
        backIndex = (backIndex - 1) % capacity;
    }
  public:
    DynamicArray(StevensDev::sgdm::IAllocator<T>* alloc){
        assert(alloc != NULL);

        arrayAllocator = alloc;
        array = arrayAllocator.get(DynamicArray<T>::DEFAULT_ARRAY_SIZE);
        frontIndex = 0;
        backIndex = 0;
        capacity = DynamicArray<T>::DEFAULT_ARRAY_SIZE;
        size = 0;
    }

    ~DynamicArray(){
        arrayAllocator.release(array, capacity);
        array = NULL;
    }

    void               push(const T& element){
        if(size == capacity)
            resize();
        backIndex = (backIndex + 1) % capacity;
        array[backIndex] = element;
        ++size;
    }

    void               pushFront(T element){
        if(size == capacity)
            resize();
        frontIndex = (frontIndex - 1) % capacity;
        array[frontIndex] = element;
        ++size;
    }

    T                  pop(){
        T element;
        element = array[backIndex];
        backIndex = (backIndex - 1) % capacity;
        --size;
        return element;
    }

    T                  popFront(){
        T element;
        element = array[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        --size;
        return element;
    }

    const unsigned int getLength(){
        return size;
    }

    const T            at(unsigned int index){
        if(index > size || index < 0)
            throw std::out_of_range("Index value out of range");
        return array[(frontIndex + index) % capacity];
    }

    T operator [](int index) const {
        return array[(frontIndex + index) % capacity];
    }
    const T& operator [](int index){
        return array[(frontIndex + index) % capacity];
    }
};

} // End namespace sgdc
} // End namespace StevensDev

#endif
