/* The abstract class of priority queue,
you should include this file before you implement
this interface. */

#ifndef __PRIORITYQUEUE_H
#define __PRIORITYQUEUE_H

template <class T>
class PriorityQueue {
    public:
        virtual ~PriorityQueue() {}
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        virtual const T& top() const = 0;
        virtual void pop() =0;
        virtual void push(const T& element) = 0;
};

#endif // __PRIORITYQUEUE_H

