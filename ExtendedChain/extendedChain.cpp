#include "extendedChain.hpp"

int main(int argc, char const *argv[])
{
    extendedChain<int>* chain = new extendedChain<int>();
    // Chain<int>* chain1 = new Chain<int>(*chain);
    chain->insert(0, 11);
    chain->insert(0, 12);
    chain->insert(0, 102);
    chain->insert(0, 120);
    chain->insert(2, 13);
    extendedChain<int> chain1(*chain);
    try
    {
        chain->erase(1);
        std::cout << "chain contains " << *chain << std::endl;
        std::cout << "the size of chain is " << chain->size() << std::endl;
        std::cout << "chain1 contains " << chain1 << std::endl;
        chain1.clear();
        std::cout << "chain1 contains (after calling clear method) " << chain1 << std::endl;
        chain1.push_back(100);
        chain1.push_back(109);
        chain1.push_back(83);
        std::cout << "chain1 contains (after calling push_back method) " << chain1 << std::endl;
        chain1.reverse();
        std::cout << "chain  contains (after calling reverse method) " << *chain << std::endl;
        std::cout << "chain1 contains (after calling reverse method) " << chain1 << std::endl;
        extendedChain<int> chain2;
        chain2.meld(*chain, chain1); // The meld method will clear both of params.
        chain1.push_back(100);
        chain1.push_back(109);
        chain1.push_back(83);
        std::cout << "chain2 contains (after calling meld method) " << chain2 << std::endl;
        std::cout << chain1 << std::endl;
        chain2.merge(chain1);
        std::cout << "chain2 contains (after calling merge method) " << chain2 << std::endl;
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    
    delete chain;    
    return 0;
}

