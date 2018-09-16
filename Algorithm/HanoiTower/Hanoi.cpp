#include <iostream>
#include "ArrayStack.hpp"

ArrayStack<int> x, y, z;

void getStatus();
void move(int n, ArrayStack<int>& x_tower, ArrayStack<int>& y_tower, ArrayStack<int>& z_tower);

int main(int argc, char const *argv[]) {    
    x.push(3);x.push(2);x.push(1);
    getStatus();
    move(x.size(), x, y, z);
    return 0;
}

void move(int n, ArrayStack<int>& x_tower, ArrayStack<int>& y_tower, ArrayStack<int>& z_tower) {
    if(n > 0) {
        move(n-1, x_tower, z_tower, y_tower);
        // Do something.
        int t = x_tower.top();
        x_tower.pop();
        y_tower.push(t);
        // Show the current status
        getStatus();
        move(n-1, z_tower, y_tower, x_tower);
    }
}

void getStatus() {
    std::cout << "The x tower contains " << x << std::endl;
    std::cout << "The y tower contains " << y << std::endl;
    std::cout << "The z tower contains " << z << std::endl;
    std::cout << std::endl;
}
