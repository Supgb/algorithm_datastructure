#ifndef __CIRCULARLIST_H
#define __CIRCULARLIST_H

#include <iostream>

#include "extendedChain.hpp"

template <class T>
class CircularList : public LinearList<T> {
private:
    chainNode<T>* headerNode;
    int listSize;
public:
    CircularList();
    CircularList(const CircularList<T>&);
    
    // virtual function implementation
    ~CircularList();
    bool empty() const {return headerNode->next == headerNode;}
    int size() const {return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(std::ostream& out) const;
};

/* 
    Create an empty list
 */
template <class T>
CircularList<T>::CircularList() {
    headerNode = new chainNode<T>(NULL);
    headerNode->next = headerNode;
}

template <class T>
CircularList<T>::CircularList(const CircularList<T>& c_list) {
    // Check whether the current list is empty or not.
    if(listSize != 0) {
        throw "ERROR! The current list is not EMPTY!";
    }
    chainNode<T>* p = c_list.headerNode->next;
    chainNode<T>* t = this->headerNode;
    for(size_t i = 0; i < c_list.listSize; ++i) {
        t->next = new chainNode<T>(p->element);
        t = t->next;
        p = p->next;
    }
    t->next = this->headerNode;
}

template <class T>
CircularList<T>::~CircularList() {
    chainNode<T> *p = headerNode, *t = headerNode;
    do {
        p = t->next;
        std::cout << "Destroyed element " << t->element << std::endl;
        delete t;        
        t = p;
    } while(headerNode != t);
}

template <class T>
T& CircularList<T>::get(int theIndex) const {
    chainNode<T>* p = headerNode;
    for(size_t i = 0; i < theIndex+1; ++i) {
        p = headerNode->next;
    }
    return p->element;
}

/* 
    Search the specific value in the list,
    if it exist, return its index,
    or return -1.
 */
template <class T>
int CircularList<T>::indexOf(const T& theElement) const {
    chainNode<T>* p = headerNode->next;
    for(size_t i = 0; p != headerNode; ++i, p=p->next) {
        if(p->element == theElement) {
            return i;
        }
    }
    return -1;
}

/* Using the headerNode can save code
    when dealing with firstNode.
 */
template <class T>
void CircularList<T>::erase(int theIndex) {
    chainNode<T> *p = headerNode, *deleteNode;
    for(int i = 0; i <= theIndex-1; ++i) {
        p = p->next;
    }
    deleteNode = p->next;
    p->next = p->next->next;
    delete deleteNode;
    listSize--;
}

template <class T>
void CircularList<T>::insert(int theIndex, const T& theElement) {
    chainNode<T>* p = headerNode;
    for(int i = 0; i <= theIndex-1; ++i) {
        p = p->next;
    }
    p->next = new chainNode<T>(theElement, p->next);
    listSize++;
}

template <class T>
void CircularList<T>::output(std::ostream& out) const {
    chainNode<T>* p = headerNode->next;
    for(;p != headerNode; p = p->next) {
        out << p->element << " ";
    }
}
template <class T>
std::ostream& operator<<(std::ostream& out, const CircularList<T>& c_list) {
    c_list.output(out);
    return out;
}

#endif // __CIRCULARLIST_H

