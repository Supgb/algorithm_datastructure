#include "Iterator.hpp"
#include "extendedChain.hpp"

int main(int argc, char const *argv[])
{
    Iterator<extendedChain<int>> iter;
    extendedChain<int>* chain = new extendedChain<int>();

    // Add element to chain
    chain->push_back(45);
    std::cout << "chain contains " << *chain << '\n';
    return 0;
}