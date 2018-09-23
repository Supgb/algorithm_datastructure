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
hash(),
dSize(0)
{
    if(divisor < 0) {
        throw "[Init] DIVISOR cannot be less than 0!";
    }   
    this->divisor = divisor;
    table = new std::pair<const K, E> *[divisor];
    for(size_t i = 0; i < divisor; ++i) {
        table[i] = nullptr;
    }
}

template <class K, class E>
HashTable<K, E>::HashTable(const HashTable<K, E>& hashtable) {
    this->divisor = hashtable.divisor;
    this->dSize = hashtable.dSize;
    this->table = new std::pair<const K, E> *[this->divisor];
    for(size_t i = 0; i < this->divisor; ++i) {
        table[i] = nullptr;
    }

    std::pair<const K, E> pair2cp;
    for(size_t i = 0; i < this->divisor; ++i) {
        if(hashtable.table[i] != nullptr) {
            this->table[i] = 
            new std::pair<const K, E>(*(hashtable.table[i]));
        }        
    }
}

template <class K, class E>
HashTable<K, E>::~HashTable(){
    delete
}

/* Search the table by key word.
    If success, return its position,
    or return the position that can insert new element
    if the table is spare. */
template <class K, class E>
size_t HashTable<K, E>::search(const K& theKey) const {
    size_t homeBucket = hash(theKey)%divisor;
    size_t i;
    if(table[homeBucket] == nullptr || table[homeBucket]->first == theKey) {
        return homeBucket;
    }
    for(i = homeBucket+1; table[i] != nullptr && i != homeBucket; ++i) {
        if(i > divisor) { // Make the table be circluar.
            i = 0;
        }
        if(table[i]->first == theKey) {
            return i;   // Return its pos.
        }
    }
    return i;   // Return the pos to insert, or the homeBucket.
}

/* Return pointer points to the found pair,
    or return nullptr */
template <class K, class E>
std::pair<K, E> *HashTable<K, E>::find(const K& theKey) const {
    size_t position = search(theKey);
    if(table[position] != nullptr && table[position]->first == theKey) {
        return table[position];
    }
    return nullptr;
}

/* Insert the pair to the table if it spare,
    or throw an exception. */
template <class K, class E>
void HashTable<K, E>::insert(const std::pair<K, E>& thePair) {
    size_t position = search(thePair.first);
    if(table[position] == nullptr) {    // free to insert.
        table[position] = new std::pair<const K, E> (thePair);
        ++dSize;
    } else {    // Necessary to do capacity check and duplicate check.
        if(table[position]->first == thePair.first) {
            // Duplicate.
            table[position]->second = thePair.second;
        } else {
            // Overflow.
            throw "[Insert] OVERFLOW!";
        }
    }
}

#endif // __HASHTABLE_H
