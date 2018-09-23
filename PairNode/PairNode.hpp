#ifndef __PAIRNODE_H
#define __PAIRNODE_H

#include <iostream>

template <class K, class E>
struct PairNode {
    std::pair<K, E> element;
    PairNode<K, E> *next;
    PairNode(const std::pair<K, E> element) {
        this->element = element;
    }

    PairNode(const std::pair<K, E> element, PairNode<K, E> *next) {
        this->element = element;
        this->next = next;
    }
};

#endif // __PAIRNODE_H
