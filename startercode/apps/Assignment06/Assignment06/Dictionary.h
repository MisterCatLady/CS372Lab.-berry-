#pragma once
#include <list>
#include <stdexcept>
#include <functional>
//Step 2 A Dictionary Class
//Now use your Pair class to construct a template class Dictionary<Key,Value> that stores its data in a tree of Pair<Key,Value> objects.
#include "Pair.h"
//compiler doesn't like file name for some reason
//#include "C:/Users/Lindsey/Desktop/CS318/CS372Lab.-berry-/startercode/include/Tree.hpp"
#include "Tree.hpp"
//Chatgpt helped me write this code
template <typename Key, typename Value>
class Dictionary 
{
private:
    using PairType = Pair<Key, Value>;
    Tree<PairType> tree;

    static bool keyCompare(const PairType& a, const PairType& b)
    {
        return a.pairKey < b.pairKey;
    }
public:
    //Rule of 5
    Dictionary() = default;
    ~Dictionary() = default;
    Dictionary(const Dictionary&) = default;
    Dictionary(Dictionary&&) noexcept = default;
    Dictionary& operator=(const Dictionary&) = default;
    Dictionary& operator=(Dictionary&&) noexcept = default;

    //The following access and modification methods:
    //operator[]() : 
    Value& operator[](const Key& key) 
    {
        //Access or insert an element by key
        PairType searchPair{ key, Value{} };
        Tree<PairType> subtree;

        if (!tree.find(searchPair, subtree, keyCompare)) {
            // Insert new key with default value
            tree = tree.insert(searchPair, keyCompare);
        }

        // Now find again to retrieve the current value
        tree.find(searchPair, subtree, keyCompare);
        PairType p = subtree.root();
        return p.pairVal;
    }
    //insert() : Insert a new value pair into the dictionary.
    void insert(const Key& key, const Value& value) 
    {
        PairType newPair{ key, value };
        tree = tree.insert(newPair, keyCompare);
    }
    //at() : Access an element by key, with an error if the key isn’t in the dictionary.
    Value at(const Key& key) 
    {
        PairType searchPair{ key, Value{} };
        Tree<PairType> subtree;
        if (!tree.find(searchPair, subtree, keyCompare)) {
            throw std::out_of_range("Key not found in dictionary");
        }
        return subtree.root().pairVal;
    }
    //erase() : Remove the key - value pair from the dictionary as indicated by the key.
    void erase(const Key& key) 
    {
        std::list<PairType> remaining;

       
        tree.inorder([&](const PairType& p) {
            if (p.pairKey != key)
                remaining.push_back(p);
            });

        // Rebuild the tree from remaining elements
        Tree<PairType> newTree;
        for (const auto& p : remaining) {
            newTree = newTree.insert(p, keyCompare);
        }

        tree = newTree;  // Replace old tree with new one
    }
    //clear() : Remove all elements from the dictionary.
    void clear() 
    {
        tree = Tree<PairType>();
    }
//Lookup operations
//keys() : Return a reference to a List<Key> of the keys in the dictionary.
    std::list<Key> keys() const 
    {
        std::list<Key> klist;
        tree.inorder([&klist](const PairType& p) { klist.push_back(p.pairKey); });
        return klist;
    }
//values() : Return a reference to a List<Value> of the values in the dictionary.
    std::list<Value> values() const 
    {
        std::list<Value> vlist;
        tree.inorder([&vlist](const PairType& p) { vlist.push_back(p.pairVal); });
        return vlist;
    }
    //Capacity and Size :
    //	isEmpty() : return true if the Dictionary is empty, false otherwise.
    bool isEmpty() const { return tree.isEmpty(); }
    //	size() : return the number of key - value pairs in the dictionary.
    size_t size() const { return tree.size(); }
};

