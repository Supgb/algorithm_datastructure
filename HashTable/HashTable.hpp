#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include "Hash.hpp"
#include "PairNode.hpp"

template <class K, class E>
class HashTable {
    template <class A, class B>
    friend std::ostream& operator<<(std::ostream&, const HashTable<A, B>& hashtable);
private:
    std::pair<const K, E> **table; // Hash table pointer.
    hash<K> HASH;   // Hashing function for encoding the key.
    size_t dSize;   // The number of pairs in the table.
    size_t divisor; // equals to the number of the slot in the table.
                    // f(k) = k%divisor;
public:
    HashTable(int divisor = 10);
    HashTable(const HashTable<K, E>&);
    ~HashTable();
    size_t search(const K& theKey) const;
    std::pair<const K, E> *find(const K& theKey) const;
    void insert(const std::pair<K, E>& thePair);
};

template <class K, class E>
HashTable<K, E>::HashTable(int divisor):
HASH(),
dSize(0)
{
    if(divisor <= 0) {
        throw "[Init] DIVISOR must be greater than 0!";
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
    for(size_t i = 0; i < divisor; ++i) {
        delete table[i];
    }
    delete [] table;
}

/* Search the table by key word.
    If success, return its position,
    or return the position that can insert new element
    if the table is spare. */
template <class K, class E>
size_t HashTable<K, E>::search(const K& theKey) const {
    size_t homeBucket = HASH(theKey)%divisor;
    size_t i;
    if(table[homeBucket] == nullptr || table[homeBucket]->first == theKey) {
        return homeBucket;
    }
    for(i = homeBucket+1; table[i] != nullptr && i != homeBucket; i=(++i)%divisor) {
        if(table[i]->first == theKey) {
            return i;   // Return its pos.
        }
    }
    return i;   // Return the pos to insert, or the homeBucket.
}

/* Return pointer points to the found pair,
    or return nullptr */
template <class K, class E>
std::pair<const K, E> *HashTable<K, E>::find(const K& theKey) const {
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

template <class K, class E>
std::ostream& operator<<(std::ostream& out, const HashTable<K, E>& hashtable) {
    for(size_t i = 0, count = 0; i < hashtable.divisor; ++i) {
        if(hashtable.table[i] != nullptr) {
            ++count;
            out << "(" << hashtable.table[i]->first << ", "
             << hashtable.table[i]->second << ")" << " ";
        }
        if(count == hashtable.dSize) {
            break;
        }
    }
    return out;
}


#endif // __HASHTABLE_H
