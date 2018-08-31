
#if !defined(_LINEARLIST_H)
#define _LINEARLIST_H

#include <iostream>

template <typename T>
class LinearList {
    
    public:
        virtual ~LinearList() = 0; // pure virtual destructor
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        // virtual int capacity() const = 0;
        virtual T& get(int theIndex) const = 0;
        virtual int indexOf(const T& theElement) const = 0;
        virtual void erase(int theIndex) = 0;
        virtual void insert(int theIndex, const T& theElement) = 0;
        virtual void output(std::ostream& out) const = 0;
};

template <typename T>
LinearList<T>::~LinearList() { }

#endif // _LINEARLIST_H
