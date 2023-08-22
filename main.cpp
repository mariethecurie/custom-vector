#include <iostream>
#include "vector.h"

int main() {
    Vector v;
    v.push_back(10);
    v.push_back(20);
    v.insert(1, 15);
    std::cout << v[2] << std::endl;
    std::cout << "Size: " << v.size() << std::endl;
    std::cout << "Capacity: " << v.capacity() << std::endl;
    std::cout << "Is empty: " << v.empty() << std::endl;
    std::cout << v.back() << std::endl;
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << " ";
    }

    Vector v2;
    v2 = v;
    for (int i = 0; i < v2.size(); ++i) {
        std::cout << v2.at(i) << " ";
    }

    return 0;
}