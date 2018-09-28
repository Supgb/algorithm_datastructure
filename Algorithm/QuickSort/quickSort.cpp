#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

void inputstream(std::vector<int>&);
int partition(std::vector<int>&, int, int);
void quickSort(std::vector<int>&, int, int);

int main(int argc, char const *argv[]) {
    std::vector<int> vect;
    inputstream(vect);

    // TODO: Quick sort
    quickSort(vect, 0, vect.size()-1);

    std::cout << "The final: " << std::endl;
    for(auto i : vect) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}

void inputstream(std::vector<int> &vect) {
    std::cout << "Please enter an array(integer): ";
    std::string str;
    int temp;
    getline(std::cin, str);
    std::stringstream s(str);
    while(s >> temp) {
        vect.push_back(temp);
    }
}

int partition(std::vector<int> &vect, int begin, int end) {
    int r = vect.at(end);
    int t = begin-1;
    
    for(int iter = begin; iter < end; iter++) {
        if(vect.at(iter) < r) {
            // Exchange *iter with vect[t].
            int temp = vect.at(++t);
            vect.at(t) = vect.at(iter);
            vect.at(iter) = temp;
        }        
    }
    int temp = vect.at(++t);
    vect.at(t) = r;
    vect.at(end) = temp;
    return t;
}

void quickSort(std::vector<int> &vect, int begin, int end) {
    if(begin < end) {
        int d = partition(vect, begin, end);
        quickSort(vect, begin, d-1);
        quickSort(vect, d+1, end);
    }
}
