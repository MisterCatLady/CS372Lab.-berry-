//lberry4@my.athens.edu
//Assignment03.cpp
// chatgpt helped me write these tests
#include <iostream>
#include "Bag.h"
int main()
{
        std::cout << "Creating bag of integers...\n";
    Bag<int> bag;

    bag.insert(10);
    bag.insert(20);
    bag.insert(10);
    bag.insert(40);

    std::cout << "Bag contents: ";
    bag.printBag();

    std::cout << "Bag size: " << bag.size() << std::endl;
    std::cout << "Count of 10: " << bag.count(10) << std::endl;

    std::cout << "\nPopping one item: " << bag.pop() << std::endl;
    std::cout << "Bag now contains: ";
    bag.printBag();

    std::cout << "\nTesting copy constructor...\n";
    Bag<int> bagCopy = bag;
    bagCopy.printBag();

    std::cout << "Testing move constructor...\n";
    Bag<int> bagMoved = std::move(bag);
    std::cout << "Moved bag contents: ";
    bagMoved.printBag();

    return 0;
}
