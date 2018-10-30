#include "HashChains.hpp"

int main(int argc, char const *argv[]) {
    HashChains<int, std::string> chain;
    std::pair<int, std::string> pair2insert_0(1, "hello");
    std::pair<int, std::string> pair2insert_1(2, "world");
    std::pair<int, std::string> pair2insert_2(3, "good");
    chain.insert(pair2insert_0);
    chain.insert(pair2insert_1);
    chain.insert(pair2insert_2);
    std::cout << chain << std::endl;
    chain.erase(2);
    std::cout << chain << std::endl;
    
    return 0;
}
