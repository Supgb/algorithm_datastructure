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
template <class Y>
friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<Y>& list);
private:
    chainNode_d<T> *firstNode;
    chainNode_d<T> *lastNode;
    size_t listSize;

    void checkIndex(int theIndex) const;

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
        std::cout << "[Destroying " << i << " ] element " << firstNode->element << std::endl;
        delete firstNode;        
        firstNode = t;
    }    
    firstNode = nullptr;
    lastNode = nullptr;
    listSize = 0;
}

template <class T>
T& DoublyLinkedList<T>::get(int theIndex) const {
    checkIndex(theIndex);
    chainNode_d<T> *t;
    if(theIndex > listSize/2) {
        t = lastNode;
        for(size_t i = listSize-1; i > theIndex; --i) {
            t = t->prev;            
        }
    } else {
        t = firstNode;
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
    checkIndex(theIndex);   // theIndex should be less than listSize and greater than zero.
    chainNode_d<T> *t;
    chainNode_d<T> *deleteNode;
    // More efficient.
    if(theIndex > listSize/2) {
        // Search the element in right-to-left dir.
        t = lastNode;
        for(size_t i = listSize; i > theIndex+1; --i) {
            t = t->prev;
        }
    } else {
        // Search the element in left-to-right dir.
        t = firstNode;
        for(size_t i = 0; i < theIndex; ++i) {
            t = t->next;
        }
    }
    // Three case : points to firstNode, lastNode or normal node.
    if(t == firstNode) {
        firstNode = t->next;
        listSize==1?(nullptr):(t->next->prev = t->prev);
        deleteNode = t;
    } else if(t == lastNode) {
        lastNode = t->prev;
        t->prev->next = t->next;
        deleteNode = t;
    } else {
        t->next->prev = t->prev;
        t->prev->next = t->next;
        deleteNode = t;
    }
    listSize--;
}

template <class T>
void DoublyLinkedList<T>::insert(int theIndex, const T& theElement) {    
    if(theIndex < 0 || theIndex > listSize) {
        throw "[Insert OP] Index out of range!";
    }
    chainNode_d<T> *t;
    if(!theIndex) {;} // When theIndex == 0, do nothing.
    else if(theIndex > listSize/2) {
        // Search the pos in right-to-left dir.
        t = lastNode;
        for(int i = listSize; i > theIndex; --i) {
            t = t->prev;
        }
    } else {
        // Search the pos in left-to-right dir.
        t = firstNode;
        for(size_t i = 0; i < listSize-1; ++i) {
            t = t->next;
        }
    }

    if(theIndex == 0) { // Insert the element at the head of list.
        firstNode = new chainNode_d<T>(theElement, nullptr, firstNode);
        if(listSize) {
            firstNode->next->prev = firstNode;
        } else {
            lastNode = firstNode;
        }
    } else {
        t->next = new chainNode_d<T>(theElement, t, t->next);
        if(t != lastNode) { 
            t->next->next->prev = t->next;
        } else {    // Insert the element at the end of list.
            lastNode = t->next;
        }
    }
    listSize++;
}

template <class T>
void DoublyLinkedList<T>::output(std::ostream& out) const {
    chainNode_d<T>* t = firstNode;
    while(t != nullptr) {
        out << t->element << " ";
        t = t->next;        
    }
}

template <class T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& list) {
    list.output(out);
    return out;
}

template <class T>
void DoublyLinkedList<T>::checkIndex(int theIndex) const {
    if(theIndex < 0 || theIndex >= listSize) {
        throw "Index out of range!";
    }
}

#endif // __DOUBLYLINKEDLIST_H
