#include "extendedChain.hpp"
#include "bin_sort.hpp"

template <class T>
void radix_sort(extendedChain<T>& chain, int radix, int range);

int main(int argc, char const *argv[]) {
    extendedChain<int> chain;
    chain.push_back(45);
    chain.push_back(51);
    chain.push_back(38);
    chain.push_back(27);
    chain.push_back(19);
    chain.push_back(67);
    chain.push_back(33);
    chain.push_back(24);
    chain.push_back(47);
    chain.push_back(69);
    radix_sort(chain, 10, 100);
    std::cout << "The result of radix sorting is " << chain << std::endl;
    return 0;
}

template <class T>
void radix_sort(extendedChain<T>& chain, int radix, int range) {
    // Analyze how much bin sort operation required.
    size_t cnt;
    for(cnt = 0; range != 0; ++cnt, range /= radix) {;}
    
    // Split the element on the specific radix    
    extendedChain<T> r_chain;
    Iterator<extendedChain<int>> iter, iter_b;
    int base = 1;
    for(size_t i = 0; i < cnt; ++i) {
        extendedChain<T>* bins = new extendedChain<T>[radix];
        for(iter = chain.begin(); iter != chain.end(); ++iter) {
            bins[(*iter/base)%radix].push_back(*iter);
        }
        for(size_t i = 0; i < radix; ++i) {
            r_chain.merge(bins[i]);
        }
        chain.clear();
        for(iter = r_chain.begin(); iter != r_chain.end(); ++iter) {
            chain.push_back(*iter);
        }        
        r_chain.clear();
        base *= radix;
    }

}
