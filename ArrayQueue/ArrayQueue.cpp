#include "ArrayQueue.hpp"
#include <sstream>

template <class T>
void inputstream(std::stringstream&, ArrayQueue<T>&);

template <class T>
void testOnQueue(ArrayQueue<T>&);

int main(int argc, char const *argv[]) {    
    std::stringstream s;
    ArrayQueue<int> queue;
    std::cout << "\n-----------------Test after initializing...\n" << std::endl;
    testOnQueue(queue);    
    inputstream(s, queue);
    std::cout << "\n-----------------Test after pushing..." << std::endl;
    testOnQueue(queue);
    // ArrayQueue<int> queue1(queue);    
    return 0;
}

/* 提醒用户输入队列成员 */
template <class T>
void inputstream(std::stringstream& stream, ArrayQueue<T>& Queue) {
    std::string input_str;
    T temp;
    size_t count = 0;
    std::cout << "Please enter an array to Queue: ";
    getline(std::cin, input_str);
    stream << input_str;    
    while(stream >> temp) {
        Queue.push(temp);
    }
}

/* 测试相关方法 */
template <class T>
void testOnQueue(ArrayQueue<T>& Queue) {
    try {
        std::cout << "[EMPTY] Is queue empty now? ANS = " << 
        (Queue.empty()?"Yes!":"No!") << std::endl;
        std::cout << "[SIZE] The size of queue is " << Queue.size() << std::endl;
        std::cout << "[FRONT] The front of queue is " << Queue.front() << std::endl;
        std::cout << "[BACK] The back of queue is " << Queue.back() << std::endl;    
        std::cout << "[<<] The queue contains " << Queue << std::endl;
        // Test after pop
        std::cout << "\n[POP]-------------------\n" << std::endl;
        size_t size = Queue.size();
        for(size_t i = 0; i < size; ++i) {            
            Queue.pop();
            std::cout << "[EMPTY] Is queue empty now? ANS = " << 
            (Queue.empty()?"Yes!":"No!") << std::endl;
            std::cout << "[SIZE] The size of queue is " << Queue.size() << std::endl;
            std::cout << "[FRONT] The front of queue is " << Queue.front() << std::endl;
            std::cout << "[BACK] The back of queue is " << Queue.back() << std::endl;    
            std::cout << "[<<] The queue contains " << Queue << std::endl;
            std::cout << std::endl;            
        }
    } catch (char const *e) {
        std::cerr << e << std::endl;
    }
}
