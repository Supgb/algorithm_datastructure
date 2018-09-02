
#if !defined(__EXTENDEDLIST)
#define __EXTENDEDLIST

#include "LinearList.hpp"

template <typename T>
class extendedChain;

template <typename T>
class extendedLinearList : public LinearList<T> {
    public:
        virtual ~extendedLinearList() { }
        virtual void clear() = 0;
        virtual void push_back(const T&) = 0;
        virtual void reverse() = 0;
        virtual extendedLinearList<T>& meld(
            extendedChain<T>&,
            extendedChain<T>&
        ) = 0;
};

#endif // __EXTENDEDLIST
