//ChatGPT helped me complete this code
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <utility>
#include "avltree.h"
#include "Tree.hpp"
//Write a function that, given an integer as an argument,
//will return a reference to a Tree containing that many randomly generated integers.
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
//Write a function that, given an argument that is a reference to a Tree, does an in - order traversal 
// of that tree and inserts the data into an AVL tree, which you will return back to the caller as a reference.
template<typename Func>
void inorderTraversal(const Tree<int>& t, Func f) 
{
    t.inorder(f);  
}
AVLTree<int> buildAVLFromTree(const Tree<int>& t) 
{
    AVLTree<int> avl;
    inorderTraversal(t, [&](int v) { avl.insert(v); });
    return avl;
}
//Now write a function that takes references to that tree and that AVL tree and picks 100 numbers at random, 
// and computes how long a search for each of those numbers take in those trees.
// Return a reference to a std::pair that reports the average for the regular BST and the AVL tree
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
//Now using that function from the previous step, write a driver program that will report the average search times 
// for searching thru a BST and AVL tree with 100, 500, 1000, 2500, 5000, and 10000 elements.
int main() {
    std::vector<int> sizes = { 100, 500, 1000};

    std::cout << "Size\tBST (us)\tAVL (us)\n";
    std::cout << "----------------------------------\n";

    for (int n : sizes) {
        std::cout << "Creating BST with " << n << " elements..." << std::flush;
        auto result = makeRandomTree(n);
        Tree<int>& bst = result.first;

        std::cout << " done.\nBuilding AVL tree..." << std::flush;
        AVLTree<int> avl = buildAVLFromTree(bst);
        std::cout << " done.\nMeasuring search times..." << std::flush;

        auto averages = measureSearchTimes(bst, avl, 100);
        double bstAvg = averages.first;
        double avlAvg = averages.second;

        std::cout << " done.\n";

        std::cout << n << "\t" << bstAvg << "\t\t" << avlAvg << "\n";
    }

    return 0;
}