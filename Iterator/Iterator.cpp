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
    std::cout << "chain contains " << *chain << '\n';
    iter = chain->begin();
    std::cout << "iter points to " << *(iter++) << '\n';
    std::cout << "chain contains " << *chain << '\n';
    return 0;
}