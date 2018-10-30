#ifndef __SORTEDCHAIN_H
#define __SORTEDCHAIN_H

#include "Dictionary.hpp"
#include "PairNode.hpp"
#include "Hash.hpp"

template <class K, class E>
class SortedChain : public Dictionary<K, E> {
    template <class _K, class _E>
    friend std::ostream& operator<<(std::ostream&, const SortedChain<_K, _E>&);
private:
    PairNode<K, E> *firstNode;    
    size_t p_size;    

public:
    SortedChain();
    SortedChain(const SortedChain<K, E>&);

    ~SortedChain();
    bool empty() const {return p_size == 0;}
    int size() const {return p_size;}
    std::pair<K, E>* find(const K&) const;
    void erase(const K&);
    void insert(const std::pair<const K, E>&);
};

template <class K, class E>
SortedChain<K, E>::SortedChain():
firstNode(nullptr),
p_size(0)
{

}

template <class K, class E>
SortedChain<K, E>::SortedChain(const SortedChain<K, E>& sortedChain) {    
    std::cout << "[Constructor working]" << std::endl;
    if(!sortedChain.p_size) {
        firstNode = nullptr;
        p_size = 0;
    } else {        
        p_size = sortedChain.p_size;        
        PairNode<K, E> *s = sortedChain.firstNode;
        firstNode = new PairNode<K, E>(s->element, nullptr);
        s = s->next;
        PairNode<K, E> *t = firstNode;
        for(size_t i = 0; i < p_size; ++i) {
            t->next = new PairNode<K, E>(s->element);
            t = t->next; s = s->next;
        }
    }

}

template <class K, class E>
SortedChain<K, E>::~SortedChain() {    
    PairNode<K, E> *t = firstNode;
    for(size_t i = 0; i < p_size; ++i) {
        t = t->next;
        delete firstNode;
        firstNode = t;
        std::cout << "Destructor working..." << std::endl;
    }
}

/* 
Input: the key to find
output: the pointer points to the pair to find if it exist, or nullptr.
 */
template <class K, class E>
std::pair<K, E>* SortedChain<K, E>::find(const K& key) const {
    PairNode<K, E> *t = firstNode;
    while(t != nullptr) {
        if(t->element.first == key) {
            return &(t->element);
        }
        t = t->next;
    }
    return nullptr;
}

/* 
Input: The pair to insert
Output: void
Functionality: replace the pair which key already exists in the chain,
               or create a new node.
 */
template<class K, class E>
void SortedChain<K, E>::insert(const std::pair<const K, E>& thePair) {
    PairNode<K, E> *t = firstNode;
    PairNode<K, E> *p;
    if(firstNode == nullptr) {
        firstNode = new PairNode<K, E>(thePair, nullptr);        
    }
    if(t != nullptr) {
        if(t->element.first > thePair.first) {
            p = t;
            t = new PairNode<K, E>(thePair, p);
            firstNode = t;
        } else if(t->element.first == thePair.first) {
            t->element.second = thePair.second;
        } else {
            t->next = new PairNode<K, E>(thePair, nullptr);
        }        
    }
    ++p_size;
}

/* 
Input: The key to erase.
Output: void.
 */
template<class K, class E>
void SortedChain<K, E>::erase(const K& theKey) {
    PairNode<K, E> *t = firstNode;
    PairNode<K, E> *p;
    if(firstNode->element.first == theKey) {
        p = firstNode;
        firstNode = firstNode->next;
        delete p;
        t = nullptr;
        --p_size;
    }
    while(t != nullptr) {
        if(t->element.first == theKey) {
            p->next = t->next;
            delete t;
            --p_size;
            break;
        }
        p = t;
        t = t->next;
    }    
}

template <class K, class E>
std::ostream& operator<<(std::ostream& out, const SortedChain<K, E>& sortedChain) {
    PairNode<K, E> *t = sortedChain.firstNode;
    for(size_t i = 0; i < sortedChain.p_size; ++i, t=t->next) {
        out << "(" << t->element.first << ", "
        << t->element.second << ") ";
    }
    return out;
}


#endif // __SORTEDCHAIN_H
