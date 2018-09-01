
#if !defined(__EXTENDEDCHAIN_H)
#define __EXTENDEDCHAIN_H

#include <iostream>
#include "extendedLinearList.hpp"
#include "Chain.hpp"

template <typename T>
class extendedChain :  public extendedLinearList<T>,
                        public Chain<T> {
    protected:
        chainNode<T>* lastNode;

    public:
        extendedChain();
        extendedChain(const extendedChain<T>&);

        virtual ~extendedChain();

        virtual bool empty() const;
        virtual int size() const;
        virtual T& get(int) const;
        virtual int indexOf(const T&) const;
        virtual void erase(int);
        virtual void insert(int, const T&);
        virtual void output(std::ostream&) const;

        virtual void clear();
        virtual void push_back(const T&);
        virtual void reverse();
        virtual extendedChain<T>& meld(
            const extendedChain<T>&,
            const extendedChain<T>&
        );
};

template <typename T>
extendedChain<T>::extendedChain() :
Chain<T>::Chain()
{        
    lastNode = nullptr;
}

template <typename T>
extendedChain<T>::extendedChain(const extendedChain<T>& chain) {
    this->listSize = chain.listSize;
    chainNode<T>* t = chain.firstNode;
    if (t == nullptr) {
        this->firstNode = nullptr;
        return;
    }
    
    this->firstNode = new chainNode<T>(t->element);
    chainNode<T>* s = this->firstNode;
    while(t->next != nullptr) {
        t = t->next;
        s->next = new chainNode<T>(t->element);
        s = s->next;
        lastNode = s;
    }
}

template <typename T>
extendedChain<T>::~extendedChain() {
    lastNode = nullptr;
}

template <typename T>
bool extendedChain<T>::empty() const {
    return this->firstNode == nullptr;
}

template <typename T>
int extendedChain<T>::size() const {
    return this->listSize;
}

template <typename T>
T& extendedChain<T>::get(int theIndex) const {
    return Chain<T>::get(theIndex);
}

template <typename T>
int extendedChain<T>::indexOf(const T& theElement) const {
    return Chain<T>::indexOf(theElement);
}

template <typename T>
void extendedChain<T>::erase(int theIndex) {
    this->checkIndex(theIndex);
    chainNode<T>* deleteNode;
    if (theIndex == this->listSize-1) {
        /* 要删除的元素位于链表的最后一位 */
        deleteNode = lastNode;
        chainNode<T>* p = this->firstNode;
        for(size_t i = 0; i < theIndex-1; i++)
        {
            p = p->next;
        }
        lastNode = p;
        delete deleteNode;
        this->listSize--;
    } else {
        Chain<T>::erase(theIndex);
    }
}

template <typename T>
void extendedChain<T>::insert(int theIndex, const T& theElement) {
    
    if (theIndex < 0 || theIndex > this->listSize) {
        throw "out of range -- when insert element [extendedChain]";
    }
    if (theIndex == this->listSize && theIndex != 0) {
        /* 在链表尾部插入元素 */
        chainNode<T>* p = lastNode;
        lastNode = new chainNode<T>(theElement, lastNode->next);
        p->next = lastNode;
        this->listSize++;
    } else {
        Chain<T>::insert(theIndex, theElement);
    }
    if (lastNode == nullptr) {
        lastNode = this->firstNode;
    }
    
}

template <typename T>
void extendedChain<T>::output(std::ostream& out) const {
    Chain<T>::output(out);
}

template <typename T>
void extendedChain<T>::clear() {    
    chainNode<T>* t;
    while(this->firstNode != nullptr) {
        std::cout << "Clear " << this->firstNode->element << std::endl;
        t = this->firstNode->next;
        delete this->firstNode;
        this->firstNode = t;        
    }
    lastNode = nullptr;
    this->listSize = 0;
}

template <typename T>
void extendedChain<T>::push_back(const T& theElement) {
    insert(this->listSize, theElement);
}

/* 原地颠倒链表元素，即不使用额外的空间 */
template <typename T>
void extendedChain<T>::reverse() {
    // 新建指针用于遍历，并将末节点指针指向首节点
    chainNode<T>* p = this->firstNode->next;
    chainNode<T>* np;
    lastNode = this->firstNode;
    while(p != nullptr){
        np = p->next;
        p->next = this->firstNode;  // 使链表中两元素链域反向
        this->firstNode = p;
        p = np;
    }    
    // 避免形成环状链表
    lastNode->next = nullptr;
}

template <typename T>
extendedChain<T>& extendedChain<T>::meld(
            const extendedChain<T>& chain_a,
            const extendedChain<T>& chain_b
        ) {
    
}

#endif // __EXTENDEDCHAIN_H
