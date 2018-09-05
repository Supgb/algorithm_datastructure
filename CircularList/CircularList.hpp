#ifndef __CIRCULARLIST_H
#define __CIRCULARLIST_H

#include <iostream>

#include "extendedChain.hpp"

template <class T>
class CircularList : public LinearList {
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

template <class T>
CircularList<T>::CircularList() {
    
}
template <class T>
CircularList<T>::~CircularList() {

}

#endif // __CIRCULARLIST_H

