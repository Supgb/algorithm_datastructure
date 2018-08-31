#include "extendedChain.hpp"

int main(int argc, char const *argv[])
{
    extendedChain<int>* chain = new extendedChain<int>();
    // Chain<int>* chain1 = new Chain<int>(*chain);
    chain->insert(0, 11);
    chain->insert(0, 12);
    chain->insert(2, 13);
    extendedChain<int> chain1(*chain);
    try
    {
        chain->erase(1);
        std::cout << "chain contains " << *chain << std::endl;
        std::cout << "the size of chain is " << chain->size() << std::endl;
        std::cout << "chain1 contains " << chain1 << std::endl;
        
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    
    delete chain;    
    return 0;
}

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
        throw "out of range [extendedChain]";
    }
    if (theIndex == this->listSize-1) {
        /* 在链表尾部插入元素 */

    } else {

    }
    
    
}

template <typename T>
void extendedChain<T>::output(std::ostream& out) const {

}

template <typename T>
void extendedChain<T>::clear() {

}

template <typename T>
void extendedChain<T>::push_back(const T&) {

}
