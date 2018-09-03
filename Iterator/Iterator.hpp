#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

template <class T>
class Iterator {
protected:
    T* container;
public:
    Iterator(const T& theContainer);
    ~Iterator();


};

template <class T>
Iterator<T>::Iterator(const T& theContainer) {
    container = theContainer;
    std::cout << "fine" << '\n';
}

template <class T>
Iterator<T>::~Iterator() {}



#endif // ITERATOR_HPP
