#include <iostream>
#include "Dictionary.h"
//Chat gpt helped write these tests
int main() {
    Dictionary<std::string, int> dict;
    //test insert()
    dict.insert("Alice", 88);
    dict.insert("Bob", 95);
    dict.insert("Charlie", 72);

    std::cout << "Bob's score: " << dict.at("Bob") << "\n";

    //Test operator[]
    dict["Diana"]; 
    dict.insert("Eve", 99);
    //Testing lookup operators
    std::cout << "\nKeys: ";
    for (const auto& key : dict.keys())
        std::cout << key << " ";
    std::cout << "\nValues: ";
    for (const auto& val : dict.values())
        std::cout << val << " ";
    //Testing size()
    std::cout << "\n\nSize: " << dict.size();
    std::cout << "\nEmpty? " << std::boolalpha << dict.isEmpty() << "\n";
    //Testing clear()
    dict.clear();
    std::cout << "\nAfter clearing, size = " << dict.size() << "\n";

    dict.insert("Alice", 90);
    dict.insert("Bob", 85);
    dict.insert("Charlie", 95);

    std::cout << "Before erase:\n";
    for (auto k : dict.keys()) std::cout << k << " ";
    std::cout << "\n";

    dict.erase("Bob");

    std::cout << "After erase:\n";
    for (auto k : dict.keys()) std::cout << k << " ";
    std::cout << "\n";
    return 0;
}