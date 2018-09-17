#ifndef __ARRAYQUEUE_H
#define __ARRAYQUEUE_H

#include "Queue.hpp"


template <class T>
class ArrayQueue : public Queue<T> {
    template <class Y>
    friend std::ostream& operator<<(std::ostream& out, const ArrayQueue<Y>& Queue);
    template <class X>
    friend void changeLengthQueue(ArrayQueue<X>&, size_t newLength);
private:
    int queueFront, queueBack, arrayLength;
    T *queue;
public:
    ArrayQueue(int initialLength = 1);
    ArrayQueue(const ArrayQueue<T>&);

    ~ArrayQueue();
    bool empty() const {return queueBack==queueFront;}
    size_t size() const {return (queueBack + arrayLength - queueFront) % arrayLength;}
    T& front() const {
        if(queueBack == queueFront) {
            throw "[front] EMPTY Queue!";
        }
        size_t frontIndex = (queueFront+1)%arrayLength;
        return queue[frontIndex];
    }
    T& back() const {
        if(queueBack == queueFront) {
            throw "[back] EMPTY Queue!";
        }        
        return queue[queueBack];
    }
    void pop();
    void push(const T&);
};

template <class T>
ArrayQueue<T>::ArrayQueue(int initialLength):
queueFront(0),
queueBack(0),
arrayLength(initialLength)
{
    if(initialLength < 0) {
        throw "[Initialize] Please assign a valid initial capacity.";
    }
    queue = new T[arrayLength];
}

template <class T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& Queue) {
    if(Queue.queueBack == Queue.queueFront) {
        queueFront = 0; queueBack = 0;
        arrayLength = 1;
        queue = new T[arrayLength];
    } else {
        queueFront = Queue.queueFront;
        queueBack = Queue.queueBack;
        arrayLength = Queue.arrayLength;
        queue = new T[arrayLength];
        for(size_t i = queueFront+1; i != queueFront; i=(++i)%arrayLength) {
            queue[i] = Queue.queue[i];
        }
    }
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
    delete [] queue;
}

template <class T>
void ArrayQueue<T>::pop() {
    if(queueBack == queueFront) {
        throw "[pop] EMPTY Queue!";
    }
    queueFront = (queueFront + 1)%arrayLength;
    queue[queueFront].~T();
}

template <class T>
void ArrayQueue<T>::push(const T& element) {
    if((queueBack+1)%arrayLength == queueFront) {
        changeLengthQueue(*this, 2*arrayLength);
    }
    queueBack = (queueBack+1)%arrayLength;
    queue[queueBack] = element;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const ArrayQueue<T>& Queue) {
    if(Queue.queueFront == Queue.queueBack) {
        out << "[<<] EMPTY Queue!";
        return out;
    }
    for(size_t i = Queue.queueFront+1; i!=(Queue.queueBack+1)%Queue.arrayLength; i=(++i)%Queue.arrayLength) {
        out << Queue.queue[i] << " ";
    }
    return out;
}

template <class T>
void changeLengthQueue(ArrayQueue<T>& Queue, size_t newLength) {
    if(newLength < 0) {
        throw "The length of array cannot be less than 0!";        
    }
    T *temp = new T[Queue.arrayLength*2];
    size_t start = (Queue.queueFront + 1)%Queue.arrayLength;
    if(start < 2) {
        // The case that the Queue is uncircular. Looks like the following:
        //front          back
        //  |             |
        // [ ] [e0] [e1] [e2]
        std::copy(Queue.queue, Queue.queue+Queue.arrayLength, temp);
    } else {
        // The case that the Queue is circular. Looks like the following:
        // back front
        //  |     |
        // [e2]  [ ] [e0] [e1]
        std::copy(Queue.queue+Queue.queueFront, Queue.queue+Queue.arrayLength, temp);
        std::copy(Queue.queue, Queue.queue+Queue.queueBack+1, temp+Queue.arrayLength-Queue.queueFront);
    }
    // After above operation, we will come into the following situation:
    //front               back
    //  |                  |
    // [ ] [e0] [e1] [e2] [e3] [] [] []

    delete [] Queue.queue;
    Queue.queue = temp;

    /* Assign new value to front, back and array length */
    size_t size = (Queue.queueBack - Queue.queueFront + Queue.arrayLength) % Queue.arrayLength;
    Queue.queueFront = 0; Queue.queueBack = size; Queue.arrayLength *= 2;
}


#endif // __ARRAYQUEUE_H
