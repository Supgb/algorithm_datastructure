
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
};

#endif // __EXTENDEDCHAIN_H
