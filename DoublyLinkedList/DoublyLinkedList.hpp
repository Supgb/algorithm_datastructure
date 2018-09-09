#ifndef __DOUBLYLINKEDLIST_H
#define __DOUBLYLINKEDLIST_H

#include "LinearList.hpp"

// Doubly chainNode structure
template <class T>
struct chainNode_d {
    T element;
    chainNode_d<T> *prev;
    chainNode_d<T> *next;

    chainNode_d(const T& element, chainNode_d<T> *prev = nullptr, chainNode_d<T> *next = nullptr) {
        this->element = element;
        this->prev = prev;
        this->next = next;
    }
};

template <class T>
class DoublyLinkedList : public LinearList<T>{
private:
    chainNode_d<T> *firstNode;
    chainNode_d<T> *lastNode;
    size_t listSize;

    checkIndex(int theIndex);

public:
    DoublyLinkedList();

    ~DoublyLinkedList();
    bool empty() const {return listSize == 0;}
    int size() const {return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(std::ostream& out) const;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList():
listSize(0), firstNode(nullptr), lastNode(firstNode)
{}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    chainNode_d<T>* t = firstNode;
    for(size_t i = 0; i < listSize; ++i) {
        t = t->next;
        delete t->prev;
    }
    delete t;
    firstNode = nullptr;
    lastNode = nullptr;
    listSize = 0;
}

template <class T>
T& DoublyLinkedList<T>::get(int theIndex) const {
    checkIndex(theIndex);
    chainNode_d *t;
    if(theIndex > listSize/2) {
        t = lastNode;
        for(size_t i = listSize-1; i > theIndex; --i) {
            t = t->prev;            
        }
    } else {
        for(size_t i = 0; i < theIndex; ++i) {
            t = t->next;
        }
    }
    return t->element;
}

template <class T>
int DoublyLinkedList<T>::indexOf(const T& theElement) const {
    chainNode_d<T> *t = firstNode;
    for(size_t i = 0; i < listSize; ++i) {
        if(t->element == theElement) {
            return i;
        }
        t = t->next;
    }
    return -1;
}

template <class T>
void DoublyLinkedList<T>::erase(int theIndex) {
    checkIndex(theIndex);
    chainNode_d<T> *deleteNode;
    // The element to erase is firstNode.
    if(theIndex == 0) {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else if(theIndex == listSize-1) {   // The element to erase is the last one.
        
    } else {    // The elements to erase is middle elements.
        chainNode_d<T> *t = firstNode;
        for(size_t i = 0; i < listSize-1; ++i) {
            t = t->next;
        }
        deleteNode = t->next;
        t->next = t->next->next;        
    }
}

template <class T>
void DoublyLinkedList<T>::insert(int theIndex, const T& theElement) {
    checkIndex(theIndex);    
    chainNode_d<T> *t = firstNode;    
    if(theIndex == listSize) {  // The case appends new element to the chain.
        for(size_t i = 0; i < theIndex - 1; ++i) { // t will point to one element before theIndex pos.
            t = t->next;
        }
        t->next = new chainNode_d<T>(theElement, t, t->next);
    } else {
        for(size_t i = 0; i < theIndex; ++i) { // t will point to the exact theIndex pos.
            t = t->next;
        }
        t = new chainNode_d<T>(theElement, t->prev, t); // Create a new node at theIndex pos, when theIndex==listSize, this operator(t->prev) is not allowed.
        t->next->prev = t; // When theIndex == listSize(means it'll add a new element at the tail of chain), this operator should be removed.
        theIndex==0?;:(t->prev->next = t); // When theIndex == 0, this operator should be removed.    
    }
}

#endif // __DOUBLYLINKEDLIST_H
