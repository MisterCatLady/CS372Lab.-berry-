//You have a Tree class. Write a function that, given an integer as an argument, 
//will return a reference to a Tree containing that many randomly generated integers.
//Grab the AVL tree class from Your Glorious Instructor’s GitHub repo and add it into your repository.
//Write a function that, given an argument that is a reference to a Tree, does an in - order traversal 
// of that tree and inserts the data into an AVL tree, which you will return back to the caller as a reference.
//Now write a function that takes references to that tree and that AVL tree and picks 100 numbers at random, 
// and computes how long a search for each of those numbers take in those trees.Use the chrono library to do the 
// timing(go back and look at the solution to the Towers of Annoy… I mean Towers of Hanoi… assignment).
// Return a reference to a std::pair that reports the average for the regular BST and the AVL tree
//Now using that function from the previous step, write a driver program that will report the average search times 
// for searching thru a BST and AVL tree with 100, 500, 1000, 2500, 5000, and 10000 elements.
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <utility>
#include "avltree.h"
#include "C:\Users\Lindsey\Desktop\CS318\CS372Lab.-berry-\startercode\include\Tree.hpp"
//Create Tree<int> filled with random integers
std::pair<Tree<int>, std::vector<int>> makeRandomTree(int n, int minVal = 0, int maxVal = 1000000) 
{
    Tree<int> t;
    std::vector<int> values;
    values.reserve(n);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(minVal, maxVal);

    for (int i = 0; i < n; ++i) {
        int v = dist(gen);
        t = t.insert(v);
        values.push_back(v);
    }
    return { t, values };
}
//build avltree from inorder traversal of Tree<int>
template<typename Func>
void inorderTraversal(const Tree<int>& t, Func f) 
{
    t.inorder(f);  
}

AVLTree<int> buildAVLFromTree(const Tree<int>& t) {
    AVLTree<int> avl;
    inorderTraversal(t, [&](int v) { avl.insert(v); });
    return avl;
}
//measure random search time for 100 random numbers
std::pair<double, double> measureSearchTimes(const Tree<int>& bst, const AVLTree<int>& avl, int trials = 100) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 2000000);

    using clock = std::chrono::steady_clock;
    long long totalBSTns = 0;
    long long totalAVLns = 0;

    for (int i = 0; i < trials; ++i) {
        int key = dist(gen);

        auto startBST = clock::now();
        volatile bool foundBST = bst.member(key);
        auto endBST = clock::now();
        totalBSTns += std::chrono::duration_cast<std::chrono::nanoseconds>(endBST - startBST).count();

        auto startAVL = clock::now();
        volatile bool foundAVL = avl.contains(key);
        auto endAVL = clock::now();
        totalAVLns += std::chrono::duration_cast<std::chrono::nanoseconds>(endAVL - startAVL).count();

        (void)foundBST;
        (void)foundAVL;
    }

    double avgBSTus = (totalBSTns / 1000.0) / trials;
    double avgAVLus = (totalAVLns / 1000.0) / trials;
    return { avgBSTus, avgAVLus };
}
int main() {
    auto [bst, values] = makeRandomTree(1000);   // Step 1
    AVLTree<int> avl = buildAVLFromTree(bst);    // Step 2
    auto [bstAvg, avlAvg] = measureSearchTimes(bst, avl, 100); // Step 3

    std::cout << "BST avg: " << bstAvg << " us, "
        << "AVL avg: " << avlAvg << " us\n";
}