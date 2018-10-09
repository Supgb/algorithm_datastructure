#ifndef __HASHCHAINS_H
#define __HASHCHAINS_H

#include "iostream"
#include "Hash.hpp"
#include "SortedChain.hpp"

template <class K, class E>
class HashChains {

private:
    SortedChain<K, E> **table;
    hash<K> HASH;
    int divisor;
    int dSize;

public:
    HashChains(int theDivisor = 10);
    HashChains(const HashChains<K, E>&);
    ~HashChains();
    size_t search(const K& theKey) const;
    std::pair<const K, E> *find(const K& theKey) const;
    void insert(const std::pair<K, E>& thePair);
    void erase(const K& theKey);
};

template <class K, class E>
HashChains<K, E>::HashChains(int theDivisor):
HASH(),
divisor(theDivisor),
dSize(0)
{
    if(divisor < 0) {
        throw "[init] DIVISOR must be greater than 0!";
    }
    table = new SortedChain<K, E> *[divisor];
    for(size_t i = 0; i < divisor; ++i) {
        table[i] = nullptr;
    }
}

template <class K, class E>
HashChains<K, E>::HashChains(const HashChains<K, E>& hash_chain) {

}

template <class K, class E>
HashChains<K, E>::~HashChains() {

}

template <class K, class E>
size_t HashChains<K, E>::search(const K& theKey) const {

}

template <class K, class E>
std::pair<const K, E> *HashChains<K, E>::find(const K& theKey) const {

}

template <class K, class E>
void HashChains<K, E>::insert(const std::pair<K, E>& thePair) {

}

template <class K, class E>
void HashChains<K, E>::erase(const K& theKey) {
    
}

#endif // __HASHCHAINS_H
