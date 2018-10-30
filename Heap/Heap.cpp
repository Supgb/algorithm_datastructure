#include "Heap.hpp"

int main(int argc, char const *argv[]) {
    Heap<int> heap(20, [](const int& arg_0, const int& arg_1)->bool{
        return arg_0<arg_1?1:0;
    });
    heap.push(10);
    std::cout << heap.size() << std::endl;
    std::cout << heap.top() << std::endl;
    heap.push(21);
    std::cout << heap.size() << std::endl;
    std::cout << heap.top() << std::endl;
    heap.push(8);
    std::cout << heap.size() << std::endl;
    std::cout << heap.top() << std::endl;
    return 0;
}
