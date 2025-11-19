//I consulted ChatGPT when writing this code
#pragma once
#include <vector>
#include "Tree.hpp"

template <typename T>
void fringeHelper(const Tree<T>& t, std::vector<T>& result) {
    if (t.isEmpty()) return;

    if (t.left().isEmpty() && t.right().isEmpty()) {
        result.push_back(t.root());
        return;
    }
    fringeHelper(t.left(), result);
    fringeHelper(t.right(), result);
}

template <typename T>
std::vector<T> fringe(const Tree<T>& t) {
    std::vector<T> result;
    fringeHelper(t, result);
    return result;
}

template <typename T>
bool hasSameFringe(const Tree<T>& a, const Tree<T>& b) {
    return fringe(a) == fringe(b);
}