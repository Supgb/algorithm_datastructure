#ifndef __DICTIONARY_H
#define __DICTIONARY_H

#include <iostream>

template <class K, class E>
class Dictionary {
    public:
        virtual ~Dictionary() {}
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        virtual std::pair<K, E>* find(const K&) const = 0;
        virtual void erase(const K&) = 0;
        virtual void insert(const std::pair<const K, E>&) = 0;
};

#endif // __DICTIONARY_H
