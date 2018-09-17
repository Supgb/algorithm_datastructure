#include "ArrayQueue.hpp"

int main(int argc, char const *argv[]) {
    ArrayQueue<int> queue;
    std::cout << "Queue's size is " << queue.size() << std::endl;
    queue.push(10);
    queue.push(12);
    queue.push(13);
    queue.push(14);
    std::cout << "Queue's size is " << queue.size() << std::endl;
    std::cout << queue << std::endl;
    // ArrayQueue<int> queue1(queue);
    std::cout << "END!" << std::endl;
    return 0;
}
