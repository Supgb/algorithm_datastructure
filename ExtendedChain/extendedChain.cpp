#include "extendedChain.hpp"

int main(int argc, char const *argv[])
{
    extendedChain<int>* chain = new extendedChain<int>();
    // Chain<int>* chain1 = new Chain<int>(*chain);
    chain->insert(0, 11);
    chain->insert(0, 12);
    chain->insert(2, 13);
    extendedChain<int> chain1(*chain);
    try
    {
        chain->erase(1);
        std::cout << "chain contains " << *chain << std::endl;
        std::cout << "the size of chain is " << chain->size() << std::endl;
        std::cout << "chain1 contains " << chain1 << std::endl;
        
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    
    delete chain;    
    return 0;
}

