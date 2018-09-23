#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include "Hash.hpp"
#include "PairNode.hpp"

template <class K, class E>
class HashTable {
private:
    std::pair<const K, E> **table; // Hash table pointer.
    hash<K> hash;   // Hashing function for encoding the key.
    size_t dSize;   // The number of pairs in the table.
    size_t divisor; // equals to the number of the slot in the table.
                    // f(k) = k%divisor;
public:
    HashTable(int divisor);
    HashTable(const HashTable<K, E>&);
    ~HashTable();
    size_t search(const K& theKey) const;
    std::pair<K, E> *find(const K& theKey) const;
    void insert(const std::pair<K, E>& thePair);
};

template <class K, class E>
HashTable<K, E>::HashTable(int divisor):
dSize(0)
{
    if(divisor < 0) {
        throw "[Init] DIVISOR cannot be less than 0!";
    }   
    divisor(divisor); 
    table = new std::pair<const K, E> *[divisor];
    for(size_t i = 0; i < divisor; ++i) {
        table[i] = nullptr;
    }
}

template <class K, class E>
HashTable<K, E>::HashTable(const HashTable<K, E>& hashtable) {

}

template <class K, class E>
HashTable<K, E>::~HashTable(){

}

template <class K, class E>
size_t HashTable<K, E>::search(const K& theKey) const {

}

template <class K, class E>
std::pair<K, E> *HashTable<K, E>::find(const K& theKey) const {

}

template <class K, class E>
void HashTable<K, E>::insert(const std::pair<K, E>& thePair) {
    
}

#endif // __HASHTABLE_H
