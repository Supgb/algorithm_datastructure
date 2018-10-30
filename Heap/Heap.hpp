/* Implementation of priority queue using heap struct */

#ifndef __HEAP_H
#define __HEAP_H

#include "PriorityQueue.hpp"
#include "ArrayStack.hpp"
#include <iostream>

/* Exception class for Heap OP */
class HeapException {
    private:
        std::string err_msg;

    public:
        HeapException(std::string err_msg = ""):
        err_msg(err_msg){}

        ~HeapException() {}

        void print_error() {
            std::cout << "[Fatal] " << err_msg << std::endl;
        }
};

template <class T>
class Heap : public PriorityQueue<T> {

    private:
        T *heap;             // Heap entries
        int arrayLength;     // Heap capacity
        int heapSize;
        bool (*comp) (const T& arg_0, const T& arg_1); // For acheiving max or min Heap.

    public:
        typedef bool (*FUNC_T) (const T& arg_0, const T& arg_1);

        /* Constructor Params list explanation
        arrayLength: self-explanatory
        diff_func:   tells whether constructs a MAX priority HEAP
                     or a MIN one.(corresponding to greater and less function.)
                     By default, it'll provided a greater function.   
        eg. if you pass the following one:
        [] (const T &arg_0, const T &arg_1)->bool{return arg_0>arg_1?1:0}
        it will constructs a MAX priority Heap.                          */
        Heap(int arrayLength = 5, FUNC_T diff_func = nullptr);
        Heap(const Heap<T>&);

        /* VIRTUAL functions from superclass */
        ~Heap() {
            delete [] heap;
        }
        
        bool empty() const {
            return heapSize == 0;
        }

        int size() const {
            return heapSize;
        }

        /* Get the greatest value(or priority) of the heap */
        const T& top() const {
            if(!empty()) {
                return heap[1]; // Return the root of heap, since it contains the greatest value(or priority).
            }
            throw HeapException("EMPTY Heap!");
        }

        /* Delete the greatest priority entry */
        void pop();

        /* Append an element */
        void push(const T& element);

        private:
            /* Rearrange the array to keep the priority right. */
            void push_rearranger(int index);
};

template <class T>
Heap<T>::Heap(int arrayLength, FUNC_T diff_func):
arrayLength(arrayLength),
heapSize(0),
comp(diff_func)
{
    // Allocate memory for heap entries.
    heap = new T[this->arrayLength];
    // Verify diff_func, or provide a default function (To make a MAX Priority Heap)
    if(comp == nullptr) {
        comp = [](const T &arg_0, const T &arg_1) -> bool {
            return arg_0>arg_1?1:0;
        };
    }
    
}

template <class T>
Heap<T>::Heap(const Heap& theHeap) {
    arrayLength = theHeap.arrayLength;
    heap = new T[arrayLength];
    for(size_t i = 0; i < theHeap.heapSize; i++)
    {
        heap[i] = theHeap.heap[i];
    }
}

template <class T>
void Heap<T>::pop() {

}

template <class T>
void Heap<T>::push(const T& element) {
    // Check whether the capacity is avaliable for pushing operation.
    // Make sure it is twice greater than the capacity needed.
    if(heapSize == arrayLength-1) {
        changeLength1D(heap, arrayLength, 2*arrayLength);
        arrayLength *= 2;
    }
    heap[++heapSize] = element;

    // RE-arrange Heap
    push_rearranger(heapSize);
}

template <class T>
void Heap<T>::push_rearranger(int index) {
    if(index == 1) {
        return;
    }
    // Control swap operation
    if((*comp)(heap[index], heap[index/2])) {
        // Swap the node with its parent node.
        heap[index] ^= heap[index/2];
        heap[index/2] ^= heap[index];
        heap[index] ^= heap[index/2];
    }
    push_rearranger(index/2);
    return;
}

#endif // __HEAP_H
