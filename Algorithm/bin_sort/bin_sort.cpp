#include "extendedChain.hpp"

template <class T>
extendedChain<T> bin_sort(extendedChain<T>& chain, int range);

int main(int argc, char const *argv[]) {
    extendedChain<int> chain;
    chain.push_back(4);
    chain.push_back(5);
    chain.push_back(3);
    chain.push_back(2);
    chain.push_back(1);
    chain.push_back(6);
    chain.push_back(3);
    chain.push_back(2);
    chain.push_back(4);
    chain.push_back(6);
    
    extendedChain<int> result = bin_sort(chain, 10);
    std::cout << "The result of bin sorting is " << result << std::endl;
    return 0;
}


// Non-decreasing order
template <class T>
extendedChain<T> bin_sort(extendedChain<T>& chain, int range) {
    extendedChain<T> r_chain;
    extendedChain<T>* bins = new extendedChain<T>[range];   // Bins are a set of chain    
    Iterator<extendedChain<int>> iter, iter_b;
    for(iter = chain.begin();iter != chain.end(); ++iter) {
        bins[*iter].push_back(*iter);
    }
    for(size_t i = 0; i < range; ++i) {
        for(iter_b = bins[i].begin(); iter_b != bins[i].end(); ++iter_b) {
            r_chain.push_back(*iter_b);
        }
    }
    return r_chain;
}
