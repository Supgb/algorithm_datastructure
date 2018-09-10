#include "DoublyLinkedList.hpp"

int main(int argc, char const *argv[]) {
    try {
        DoublyLinkedList<int> list;
        std::cout << "\n-----[Start test on DoublyLinkedList]-----\n" << std::endl;
        std::cout << "[Test method empty] Is the list empty?(before inserting) " << "ans: "
        << (list.empty()?"Yes!":"No!") << std::endl;
        std::cout << "[Test method size] The size of list is " << list.size() << std::endl;
        std::cout << "\n-----[Test method insert]-----\n\n" << std::endl;
        list.insert(0, 12);        
        list.insert(1, 41);
        std::cout << "[Test method size] The size of list is " << list.size() << std::endl;
        std::cout << "[Test method indexOf] The 12 element is at pos <" << list.indexOf(12) << ">" << std::endl;
        std::cout << "[Test method indexOf] The 41 element is at pos <" << list.indexOf(41) << ">" << std::endl;
        std::cout << "[Test method indexOf] The 0 element is at pos <" << list.indexOf(0) << ">" << std::endl;
        std::cout << "[Test method get] The element at pos '0' is " << list.get(0) << std::endl;
        std::cout << "[Test method get] The element at pos '1' is " << list.get(1) << std::endl;
        std::cout << "[Test method empty] Is the list empty?(after inserting) " << "ans: "
        << (list.empty()?"Yes!":"No!") << std::endl;
        std::cout << "[Test operator<< override] The list contains " << list << std::endl;
        std::cout << "\n-----[Test method erase]-----\n\n" << std::endl;
        list.erase(0);
        std::cout << "[Test method size] The size of list is " << list.size() << std::endl;
        std::cout << "[Test method indexOf] The 12 element is at pos <" << list.indexOf(12) << ">" << std::endl;
        std::cout << "[Test method indexOf] The 41 element is at pos <" << list.indexOf(41) << ">" << std::endl;
        std::cout << "[Test method indexOf] The 0 element is at pos <" << list.indexOf(0) << ">" << std::endl;
        std::cout << "[Test method get] The element at pos '0' is " << list.get(0) << std::endl;
        // std::cout << "[Test method get] The element at pos '1' is " << list.get(1) << std::endl;
        std::cout << "[Test method empty] Is the list empty?(after inserting) " << "ans: "
        << (list.empty()?"Yes!":"No!") << std::endl;
        std::cout << "[Test operator<< override] The list contains " << list << std::endl;
        std::cout << "\n-----[Test method erase]-----\n\n" << std::endl;
        list.erase(0);
        std::cout << "[Test method size] The size of list is " << list.size() << std::endl;
        std::cout << "[Test method indexOf] The 12 element is at pos <" << list.indexOf(12) << ">" << std::endl;
        std::cout << "[Test method indexOf] The 41 element is at pos <" << list.indexOf(41) << ">" << std::endl;
        std::cout << "[Test method indexOf] The 0 element is at pos <" << list.indexOf(0) << ">" << std::endl;
        // std::cout << "[Test method get] The element at pos '0' is " << list.get(0) << std::endl;
        // std::cout << "[Test method get] The element at pos '1' is " << list.get(1) << std::endl;
        std::cout << "[Test method empty] Is the list empty?(after inserting) " << "ans: "
        << (list.empty()?"Yes!":"No!") << std::endl;
        std::cout << "[Test operator<< override] The list contains " << list << std::endl;
    } catch (char const * e) {
        std::cout << e << std::endl;
    }
    return 0;
}
