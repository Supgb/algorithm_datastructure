#ifndef ITERATOR_HPP
#define ITERATOR_HPP 

#include <iostream>

template <class T>
class Iterator {
protected:
    T* container;
    typename T::element_type element;
    typename T::value_type* position;

public:
    Iterator() {container = nullptr; element = 0; position = nullptr;}
    Iterator(const T& theContainer);
    Iterator(typename T::value_type* thePosition);
    ~Iterator();

    typename T::element_type operator*() const;
    typename T::element_type* operator->() const;
    Iterator<T>& operator++(); // 前加
    Iterator<T> operator++(int); // 后加 注意由于需要使用到临时变量，不可放回其应用，而应交由复制构造函数
    bool operator==(const Iterator<T>& right) const;
    bool operator!=(const Iterator<T>& right) const;

protected:
    void checkValid() const; // 监视越界
};

template <class T>
Iterator<T>::Iterator(const T& theContainer) {
    container = &theContainer;
    position = container->begin();
    element = position->element;
}

template <class T>
Iterator<T>::Iterator(typename T::value_type* thePosition) {
    position = thePosition;
    try
    {
        checkValid();
        element = position->element;   
    }
    catch (const char* e)
    {
        element = 0;
    }
}

template <class T>
Iterator<T>::~Iterator() {}

template <class T>
typename T::element_type Iterator<T>::operator*() const {
    checkValid();
    return element;
}

template <class T>
typename T::element_type* Iterator<T>::operator->() const {
    checkValid();
    return &element;
}

template <class T>
Iterator<T>& Iterator<T>::operator++() {
    position = position->next;
    try
    {
        checkValid();    
        element = position->element;
    }
    catch (const char*)
    {
        element = 0;
    }
    return *this;
}

template <class T>
Iterator<T> Iterator<T>::operator++(int) {
    Iterator<T> t;
    t = *this;
    position = position->next;
    try
    {
        checkValid();    
        element = position->element;
    }
    catch (const char*)
    {
        element = 0;
    }
    return t;
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T>& right) const {
    return position == right.position;
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T>& right) const {
    return position != right.position;
}

template <class T>
void Iterator<T>::checkValid() const {
    if (position == nullptr)
    {
        throw "Out of range!!";
    }
}


#endif // ITERATOR_HPP
