#ifndef __QUEUE_H
#define __QUEUE_H

#include <iostream>

template <class T>
class Queue {
private:
    
public:    
    virtual ~Queue();
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
    virtual T& front() const = 0;
    virtual T& back() const = 0;
    virtual void pop() = 0;
    virtual void push(const T&) = 0;
};

template <class T>
Queue<T>::~Queue() {

}

#endif // __QUEUE_H
