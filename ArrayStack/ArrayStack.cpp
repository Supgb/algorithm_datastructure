#include "ArrayStack.hpp"

template <class T>
void testOnStack(ArrayStack<T>&, char);

int main(int argc, char const *argv[]) {
    ArrayStack<int> Stack;
    testOnStack(Stack, 'p');
    std::cout << "\n\n[Test copy constructor] :\n" << std::endl;
    ArrayStack<int> Stack2(Stack);    
    testOnStack(Stack2, 'd');
    // Test the split method
    Stack.pop();    // The origin data number is even, pop one out to test performance for odd case.
    ArrayStack<int> d_stack1, d_stack2;
    Stack.split(d_stack1, d_stack2);
    std::cout << "d_stack1 contains: " << d_stack1 << std::endl;
    std::cout << "d_stack2 contains: " << d_stack2 << std::endl;
    return 0;
}

template <class T>
void testOnStack(ArrayStack<T>& Stack, char flag) {
    int elements[] = {21, 31, 41, 51, 61, 71};
    if(flag == 'p') {
        std::cout << "\n-----Start Test-----\n" << std::endl;
        std::cout << "\n-----Test before any pushing-----\n" << std::endl;
        std::cout << "[Test method size]: " << Stack.size() << std::endl;
        std::cout << "[Test method empty]: " << "Is Stack empty? ans = "
                << (Stack.empty()?"Yes!":"No!") << std::endl;

        // Push elements
        std::cout << "Test status during pushing" << std::endl;
        for(size_t i = 0; i < sizeof(elements)/sizeof(int); ++i) {
            Stack.push(elements[i]);
            std::cout << "\n-----Test after push " << elements[i] << "-----\n" << std::endl;
            std::cout << "[Test method empty]: " << "Is Stack empty? ans = "
                    << (Stack.empty()?"Yes!":"No!") << std::endl;
            std::cout << "[Test method size]: " << Stack.size() << std::endl;
            std::cout << "[Test operator<< override]: " << "Stack contains:"
                    << Stack << std::endl;
            std::cout << "[Test method top]: " << "The top of Stack is " << Stack.top() << std::endl;
        }
    } else if(flag == 'd') {
        std::cout << "\n*****Test status during popping*****\n" << std::endl;
        for(size_t i = 0; i < sizeof(elements)/sizeof(int); ++i) {
            std::cout << "\n-----Test after popping " << Stack.top() << "-----\n" << std::endl;
            Stack.pop();
            std::cout << "[Test method empty]: " << "Is Stack empty? ans = "
                    << (Stack.empty()?"Yes!":"No!") << std::endl;
            std::cout << "[Test method size]: " << Stack.size() << std::endl;
            std::cout << "[Test operator<< override]: " << "Stack contains:"
                    << Stack << std::endl;
            std::cout << "[Test method top]: " << "The top of Stack is " << Stack.top() << std::endl;
        }
    } else {
        std::cout << "Wrong option!" << std::endl;
    }
}
