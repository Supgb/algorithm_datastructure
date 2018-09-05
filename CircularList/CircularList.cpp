#include "CircularList.hpp"

int main(int argc, char const *argv[]) {
    CircularList<int>* list = new CircularList<int>();
    std::cout << "Is the list empty?(before inserting op) " << (list->empty()?"Yes!":"No!") << std::endl;
    list->insert(0, 23);
    std::cout << "Is the list empty?(After inserting op) " << (list->empty()?"Yes!":"No!") << std::endl;
    std::cout << "The size of list is: " << list->size() << std::endl;
    std::cout << "The list contains: " << *list << std::endl;
    std::cout << "The index of 23 is " << list->indexOf(23) << std::endl;
    std::cout << "The position 0 stores: " << list->get(0) << std::endl;
    delete list;
    return 0;
}
