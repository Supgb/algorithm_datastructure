#include "HashTable.hpp"
#include <sstream>

int main(int argc, char const *argv[]) {
    HashTable<int, std::string> hashtable;
    std::string str = "hello";
    std::pair<const int, std::string> pair2insert(1, str);
    hashtable.insert(pair2insert);
    std::pair<const int, std::string> pair2insert_1(2, "good");
    hashtable.insert(pair2insert_1);
    std::cout << hashtable << std::endl;
    std::cout << "[search] The position of key 1 is " << hashtable.search(1) << std::endl;
    std::cout << "[find] The element of key 2 is " << hashtable.find(2)->second << std::endl;
    return 0;
}
