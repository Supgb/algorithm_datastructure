#ifndef __HASH_H
#define __HASH_H

#include <iostream>
#include <sstream>

template <class T>
class hash {
    public:
        size_t operator()(const T theKey) const {
            return static_cast<size_t>(theKey);
        }
};

template <>
class hash<std::string> {
    public:
        size_t operator()(const std::string theKey) const {
            size_t hashValue = 0;
            size_t len = static_cast<size_t>(theKey.length());
            for(size_t i = 0; i < len; ++i) {
                hashValue = 5 * hashValue + theKey.at(i);
            }
            return hashValue;
        }
};

#endif // __HASH_H
