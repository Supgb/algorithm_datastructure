#include <sstream>

#include "LinkedStack.hpp"

/* 
    Input: string to handle parentheses matching.
    output: The string between two matched parentheses.
 */
bool parentheses_match(std::string&);

int main(int argc, char const *argv[]) {
    std::cout << "Please enter a statement including parentheses: ";
    std::string input;
    getline(std::cin, input);
    bool r = parentheses_match(input);
    std::cout << r << std::endl;
    return 0;
}

bool parentheses_match(std::string& str) {
    LinkedStack<char> left_stack, right_stack, sstack;
    for(auto s : str) {
        if(s == '(') {
            left_stack.push(s);
        } else if(s == ')') {
            try {
                if(left_stack.top() == '(') {
                    left_stack.pop();
                }
            } catch (const char* e) {
                std::cout << e << std::endl;
                std::cout << "The statement is invalid" << std::endl;
                return false;
            }
        }
    }
    return true;    
}
