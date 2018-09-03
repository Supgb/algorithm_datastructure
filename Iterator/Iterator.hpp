#ifndef ITERATOR_HPP
#define ITERATOR_HPP 

#include <iostream>

template <class T>
class Iterator {
protected:
    T* container;
    typename T::value_type* position;
public:
    Iterator(const T& theContainer);
    Iterator(typename T::value_type* thePosition = 0);
    ~Iterator();

    typename T::value_type& operator*() const;
    typename T::value_type* operator->() const;
    Iterator<T>& operator++(); // 前加
    Iterator<T> operator++(int); // 后加
    Iterator<T>& operator--(); // 前减
    Iterator<T> operator--(int); // 后减 注意由于需要使用到临时变量，不可放回其应用，而应交由复制构造函数
    bool operator==(const Iterator<T>& right) const;
    bool operator!=(const Iterator<T>& right) const;
};

template <class T>
Iterator<T>::Iterator(const T& theContainer) {
    container = &theContainer;
    position = container->begin();
}

template <class T>
Iterator<T>::Iterator(typename T::value_type* thePosition) {
    position = thePosition;
}

template <class T>
Iterator<T>::~Iterator() {}

template <class T>
typename T::value_type&
Iterator<T>::operator*() const {
    return *position;
}

template <class T>
typename T::value_type*
Iterator<T>::operator->() const {
    return &*position;
}

template <class T>
Iterator<T>& Iterator<T>::operator++() {
    position = position->next;
    return *this;
}

template <class T>
Iterator<T> Iterator<T>::operator++(int) {
    Iterator<T> t;
    t = *this;
    position = position->next;
    return t;
}

template <class T>
Iterator<T>& Iterator<T>::operator--() {
    position = position->next;
    return *this;
}

template <class T>
Iterator<T> Iterator<T>::operator--(int) {
    Iterator<T> t;
    t = *this;
    position = position->next;
    return t;
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T>& right) const {
    return *this == *right;
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T>& right) const {
    return *this != *right;
}


#endif // ITERATOR_HPP
