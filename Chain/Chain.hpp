
#if !defined(__CHAIN_H)
#define __CHAIN_H

#include <iostream>
#include "LinearList.hpp"

template <typename T>
struct chainNode {
    template <class Y>
    friend std::ostream& operator<<(std::ostream& out,
                                    const chainNode<Y>& node);
    // 数据成员
    T element;
    // 链域
    chainNode<T> *next;
    chainNode(const T& element) {
        this->element = element;
    }
    chainNode(const T& element, chainNode<T> *next) {
        this->element = element;
        this->next = next;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& out, const chainNode<T>& node) {
    out << node.element;
    return out;
}

template <typename T>
class Chain : public LinearList<T> {
    template <typename Y>
    friend std::ostream& operator<<(std::ostream&, const Chain<Y>&);
    protected:
        void checkIndex(int) const;
        
        chainNode<T>* firstNode;
        int listSize;
    
    public:
        Chain();
        Chain(Chain<T>&);

        virtual ~Chain();
        virtual bool empty() const {return firstNode == nullptr;}
        virtual int size() const {return listSize;}
        virtual T& get(int) const;
        virtual int indexOf(const T&) const;
        virtual void erase(int);
        virtual void insert(int, const T&);
        virtual void output(std::ostream&) const;
};

template <typename T>
Chain<T>::Chain() {
    firstNode = nullptr;
    listSize = 0;
}

template <typename T>
Chain<T>::Chain(Chain<T>& chain) {
    listSize = chain.listSize;
    chainNode<T>* t = chain.firstNode;
    if (t == nullptr) {
        firstNode = nullptr;
        return;
    }
    
    firstNode = new chainNode<T>(t->element);
    chainNode<T>* s = firstNode;
    while(t->next != nullptr) {
        t = t->next;
        s->next = new chainNode<T>(t->element);
        s = s->next;
    }
}

template <typename T>
Chain<T>::~Chain() {
    chainNode<T>* t;
    while(firstNode != nullptr) {
        std::cout << "Destroying " << firstNode->element << std::endl;
        t = firstNode->next;        
        delete firstNode;
        firstNode = t;        
    }
}

template <typename T>
T& Chain<T>::get(int theIndex) const {
    checkIndex(theIndex);
    chainNode<T>* t = firstNode;
    
    for(size_t i = 0; i < theIndex; i++)
    {
        t = t->next;
    }

    return t->element;
}

template <typename T>
int Chain<T>::indexOf(const T& value) const {
    int theIndex;
    chainNode<T>* t = firstNode;
    
    for(size_t i = 0; i < listSize; i++)
    {
        if (t->element == value) {
            return i;
        }
        t = t->next;   
    }
    return -1;
}

template <typename T>
void Chain<T>::erase(int theIndex) {
    checkIndex(theIndex);
    chainNode<T>* deleteNode;
    if (theIndex == 0) {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else {
        chainNode<T>* p = firstNode;
        for(size_t i = 0; i < theIndex-1; i++)
        {
            p = p->next;
        }
        deleteNode = p->next;
        p->next = deleteNode->next;
    }
    delete deleteNode;
    listSize--;        
}

template <typename T>
void Chain<T>::insert(int theIndex, const T& value) {
    
    if (theIndex < 0 || theIndex > listSize) {
        throw "out of range when inserting";
    }
    
    if (theIndex == 0) {        
        firstNode = new chainNode<T>(value, firstNode);
    } else {
        chainNode<T>* t = firstNode;
        for(size_t i = 0; i < theIndex-1; i++)
        {
            t = t->next;
        }
        t->next = new chainNode<T>(value, t->next);        
    }
    listSize++;
}

template <typename T>
void Chain<T>::output(std::ostream& out) const {
    chainNode<T>* t = firstNode;
    for(size_t i = 0; i < listSize; i++)
    {        
        out << t->element << " ";
        t = t->next;
    }    
}

template <typename T>
void Chain<T>::checkIndex(int theIndex) const {
    
    if (theIndex < 0 || theIndex >= listSize) {
        throw "out of range!";
    }
    
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& chain) {
    chain.output(out);
    return out;
}

#endif // __CHAIN_H
