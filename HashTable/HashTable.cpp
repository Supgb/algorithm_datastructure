#include "HashTable.hpp"
#include <sstream>

int main(int argc, char const *argv[]) {
    HashTable<int, std::string> hashtable(3);
    std::pair<const int, std::string> pair2insert(1, "hello");
    std::pair<const int, std::string> pair2insert_1(2, "good");
    // std::pair<const int, std::string> pair2insert_2(3, "world");
    std::pair<const int, std::string> pair2insert_3(4, "bye");
    try {
        hashtable.insert(pair2insert);
        hashtable.insert(pair2insert_1);
        // hashtable.insert(pair2insert_2);
        hashtable.insert(pair2insert_3);
    } catch(const char *e) {
        std::cout << e << std::endl;
    }
    std::cout << hashtable << std::endl;
    std::cout << "[search] The position of key 1 is " << hashtable.search(1) << std::endl;
    std::cout << "[find] The element of key 3 is " << ((hashtable.find(3)!=nullptr)?hashtable.find(3)->second:"NOTFOUND!") << std::endl;
    return 0;
}
