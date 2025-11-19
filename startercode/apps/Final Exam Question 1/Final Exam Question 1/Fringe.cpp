//I consulted ChatGPT when writing this code

#include <iostream>
#include "Tree.hpp"
#include "Fringe.h"

int main() {
    // -------------------------------
    // Create example trees
    // -------------------------------
    Tree<int> tree1{ 10, 5, 15 };  // simple tree
    tree1 = tree1.insert(3).insert(7).insert(12).insert(18);

    Tree<int> tree2{ 10, 5, 15 };
    tree2 = tree2.insert(3).insert(7).insert(12).insert(18);

    Tree<int> tree3{ 10, 5, 15 };
    tree3 = tree3.insert(3).insert(6).insert(13).insert(20);

    // -------------------------------
    // Print the trees
    // -------------------------------
    std::cout << "Tree 1: " << tree1 << "\n";
    std::cout << "Tree 2: " << tree2 << "\n";
    std::cout << "Tree 3: " << tree3 << "\n\n";

    // -------------------------------
    // Compute and print fringes
    // -------------------------------
    auto fringe1 = fringe(tree1);
    auto fringe2 = fringe(tree2);
    auto fringe3 = fringe(tree3);

    auto printFringe = [](const std::vector<int>& f) {
        std::cout << "[ ";
        for (int v : f) std::cout << v << " ";
        std::cout << "]";
        };

    std::cout << "Fringe of Tree 1: "; printFringe(fringe1); std::cout << "\n";
    std::cout << "Fringe of Tree 2: "; printFringe(fringe2); std::cout << "\n";
    std::cout << "Fringe of Tree 3: "; printFringe(fringe3); std::cout << "\n\n";

    // -------------------------------
    // Compare fringes
    // -------------------------------
    std::cout << "Tree 1 and Tree 2 have same fringe? "
        << (hasSameFringe(tree1, tree2) ? "Yes" : "No") << "\n";

    std::cout << "Tree 1 and Tree 3 have same fringe? "
        << (hasSameFringe(tree1, tree3) ? "Yes" : "No") << "\n";

    return 0;
}