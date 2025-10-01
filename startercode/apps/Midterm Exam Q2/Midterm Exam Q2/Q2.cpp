//lberry4@my.asu.edu
//Midterm Exam Question 2 source file

#include "Q2.h"
#include <iostream>

int main() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "Front: " << v.front() << ", Back: " << v.back() << "\n";

    v.pop_back();
    std::cout << "After pop_back, size: " << v.size() << "\n";

    return 0;
}