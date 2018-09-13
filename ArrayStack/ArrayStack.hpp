#ifndef __ARRAYSTACK_H
#define __ARRAYSTACK_H

#include <iostream>
#include "Stack.hpp"

// Change the 1-D array's capacity.
template <class T>
void changeLength1D(T *&array, size_t arrayLength, size_t newLength) {
    if(newLength < 0) {
        throw "The length of array cannot be less than 0!";
    }
    T *temp = new T[newLength];
    size_t length = newLength>arrayLength?arrayLength:newLength;
    std::copy(array, array + length, temp);
    delete [] array;
    array = temp;
}

template <class T>
class ArrayStack : public Stack<T> {
    template <class Y>    
    friend std::ostream& operator<<(std::ostream& out, const ArrayStack<Y>& Stack);
private:
    int stackTop;   // The index of array which points to the top of the stack.
    size_t arrayLength;
    T *stack;

public:
    ArrayStack(size_t initialCap = 0);
    ArrayStack(const ArrayStack<T>&);
    
    ~ArrayStack();
    bool empty() const {return stackTop == -1;}
    size_t size() const {return stackTop+1;}
    T& top() const {return stack[stackTop];}
    void pop();
    void push(const T& element);

    // Custom functions
    void split(ArrayStack<T>&, ArrayStack<T>&) const; // Split the current stack to two stacks.
    ArrayStack<T> merge(const ArrayStack<T>&) const;    // merge two stacks, and make sure that the second stack is above the first one.

};

template <class T>
ArrayStack<T>::ArrayStack(size_t initialCap) :
stackTop(-1),
arrayLength(initialCap) {
    stack = new T[arrayLength];
}

template <class T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& Stack) {
    if(!Stack.arrayLength) {
        arrayLength = 0;
        stackTop = -1;
    } else {
        arrayLength = Stack.arrayLength;
        stackTop = Stack.stackTop;
        stack = new T[arrayLength];
        for(size_t i = 0; i <= Stack.stackTop; ++i) {
            stack[i] = Stack.stack[i];
        }
    }
}

template <class T>
ArrayStack<T>::~ArrayStack() {
    delete [] stack;
}

template <class T>
void ArrayStack<T>::pop() {
    stack[stackTop--].~T();
}

template <class T>
void ArrayStack<T>::push(const T& element) {
    if(stackTop == arrayLength-1) {
        // The stack is full, expand the array capacity.
        if(!arrayLength) {
            changeLength1D(stack, arrayLength, 1);
            arrayLength = 1;
        } else {
            changeLength1D(stack, arrayLength, 2*arrayLength);
            arrayLength *= 2;
        }        
    }
    stack[++stackTop] = element;    
}

template <class T>
void ArrayStack<T>::split(ArrayStack<T>& Stack1, ArrayStack<T>& Stack2) const {
    size_t __size = this->stackTop + 1;
    for(size_t i = 0; i < __size/2; ++i) {
        Stack1.push(this->stack[i]);        
    }
    for(size_t i = __size/2; i < __size; ++i) {
        Stack2.push(this->stack[i]);
    }
}

template <class T>
ArrayStack<T> ArrayStack<T>::merge(const ArrayStack<T>& Stack) const {
    ArrayStack<T> r_stack(*this);
    for(size_t i = 0; i <= Stack.stackTop; ++i) {
        r_stack.push(Stack.stack[i]);
    }
    return r_stack;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const ArrayStack<T>& Stack) {
    for(size_t i = 0; i < Stack.stackTop+1; ++i) {
        out << Stack.stack[i] << " ";
    }
    return out;
}

#endif // __ARRAYSTACK_H
