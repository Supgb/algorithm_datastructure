#ifndef __BIN_SORT_H
#define __BIN_SORT_H

#include "extendedChain.hpp"

template <class T>
extendedChain<T> bin_sort(extendedChain<T>& chain, int range);

template <class T>
extendedChain<T> bin_sort_fast(extendedChain<T>& chain, int range);

#endif // __BIN_SORT_H
