#include "LinkedStack.hpp"

template <class T>
void testOnStack(LinkedStack<T>& Stack, int* elements, size_t size, char flag = 'p');   // Note: The param with a default value must be at the end of params list.

int main(int argc, char const *argv[]) {
    try {
        LinkedStack<int> stack;    
        chainNode<int> node2push(99);
        int elements[] = {21, 31, 41, 51, 61, 71};
        testOnStack(stack, elements, sizeof(elements)/sizeof(int));
        std::cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n" << std::endl;
        testOnStack(stack, elements, sizeof(elements)/sizeof(int), 'd');
        std::cout << "\nEND OF TEST......\n" << std::endl;
        std::cout << "Test pushNode and popNode" << std::endl;
        stack.pushNode(node2push);
        std::cout << "The stack contains " << stack << std::endl;
        chainNode<int> r_node = stack.popNode();
        std::cout << "The top of stack was " << r_node << std::endl;
        std::cout << "The stack contains " << stack << std::endl;
    } catch(char const *e) {
        std::cerr << e << std::endl;
    }
    return 0;
}

template <class T>
void testOnStack(LinkedStack<T>& Stack, int* elements, size_t size, char flag) {
    if(flag == 'p') {
        std::cout << "\n-----Start Test-----\n" << std::endl;
        std::cout << "\n-----Test before any pushing-----\n" << std::endl;
        std::cout << "[Test method size]: " << Stack.size() << std::endl;
        std::cout << "[Test method empty]: " << "Is Stack empty? ans = "
                << (Stack.empty()?"Yes!":"No!") << std::endl;

        // Push elements
        std::cout << "Test status during pushing" << std::endl;
        for(size_t i = 0; i < size; ++i) {
            Stack.push(elements[i]);
            std::cout << "\n-----Test after push " << elements[i] << "-----\n" << std::endl;
            std::cout << "[Test method empty]: " << "Is Stack empty? ans = "
                    << (Stack.empty()?"Yes!":"No!") << std::endl;
            std::cout << "[Test method size]: " << Stack.size() << std::endl;
            std::cout << "[Test operator<< override]: " << "Stack contains:"
                    << Stack << std::endl;
            std::cout << "[Test method top]: " << "The top of Stack is " << Stack.top() << std::endl;
        }
    } else if(flag = 'd') {
        std::cout << "\n*****Test status during popping*****\n" << std::endl;
        for(size_t i = 0; i < size; ++i) {
            std::cout << "\n-----Test after popping " << Stack.top() << "-----\n" << std::endl;
            Stack.pop();
            std::cout << "[Test method empty]: " << "Is Stack empty? ans = "
                    << (Stack.empty()?"Yes!":"No!") << std::endl;
            std::cout << "[Test method size]: " << Stack.size() << std::endl;
            std::cout << "[Test operator<< override]: " << "Stack contains:"
                    << Stack << std::endl;
            // std::cout << "[Test method top]: " << "The top of Stack is " << Stack.top() << std::endl;
        }
    } else {
        std::cout << "Wrong option!" << std::endl;
    }
}
