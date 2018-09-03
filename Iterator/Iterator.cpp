#include "Iterator.hpp"
#include "extendedChain.hpp"

int main(int argc, char const *argv[])
{
    Iterator<extendedChain<int>> iter;
    extendedChain<int>* chain = new extendedChain<int>();

    // Add element to chain
    chain->push_back(45);
    chain->push_back(54);
    chain->push_back(89);
    chain->push_back(100);

    // Test
    std::cout << "chain contains " << *chain << '\n';
    iter = chain->begin();
    std::cout << "iter points to " << *(iter++) << '\n';
    std::cout << "iter points to " << *iter << '\n';
    std::cout << "chain contains " << *chain << '\n';
    std::cout << "Test comparation operator: Is chain[1] "
                << chain->get(1) << " equals to the value of iter "
                << *(++iter) << " ?"
                << " answer: " << (*(++iter) == chain->get(1) ? "true":"false")
                << '\n';
    std::cout << "Using iterator iter to iterate chain: " << '\n';
    
    for(iter = chain->begin(); iter != chain->end(); ++iter) {
        std::cout << *iter << ' ';
    }
    std::cout << '\n';    
    return 0;
}