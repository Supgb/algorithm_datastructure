#ifndef __STACK_H
#define __STACK_H

#include <iostream>

template <class T>
class Stack {
public:    
    virtual ~Stack();
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
    virtual T& top() const = 0; // Return the top element of stack.
    virtual void pop() = 0; // Delete the top element of stack.
    virtual void push(const T& element) = 0; // Push the new element to the top of stack.
};

template <class T>
Stack<T>::~Stack() {

}

#endif // __STACK_H
