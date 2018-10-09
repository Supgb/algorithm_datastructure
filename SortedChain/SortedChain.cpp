#include "SortedChain.hpp"
#include <sstream>

int main(int argc, char const *argv[]) {
    std::cout << "Start" << std::endl;
    SortedChain<int, std::string> s_chain;
    std::pair<int, std::string> pair2insert_0(1, "hello");
    std::pair<int, std::string> pair2insert_1(2, "world");
    std::pair<int, std::string> pair2insert_2(3, "good");
    std::pair<int, std::string> pair2insert_3(4, "bye");
    s_chain.insert(pair2insert_1);
    std::cout << s_chain << std::endl;
    s_chain.insert(pair2insert_0);
    std::cout << s_chain << std::endl;
    // s_chain.erase(2);
    // std::cout << s_chain << std::endl;
    s_chain.erase(1);
    std::cout << s_chain << std::endl;
    s_chain.insert(pair2insert_2);
    std::cout << s_chain << std::endl;
    std::pair<int, std::string> *p = s_chain.find(3);
    if(p != nullptr) {
        std::cout << "(" << (*p).first << ", " << (*p).second << ")" << std::endl;   
    } else {
        std::cout << "Not Found!" << std::endl;
    }
    std::cout << "End!" << std::endl;
    return 0;
}


