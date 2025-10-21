#pragma once
#include <vector>
#include <stdexcept>
//Step 2 A Dictionary Class
//Now use your Pair class to construct a template class Dictionary<Key,Value> that stores its data in a tree of Pair<Key,Value> objects.
#include "Pair.h"
#include "C:\Users\Lindsey\Desktop\CS318\CS372Lab.-berry-\startercode\include\Tree.hpp"
//clear() : Remove all elements from the dictionary.
//Lookup operations
//keys() : Return a reference to a List<Key> of the keys in the dictionary.
//values() : Return a reference to a List<Value> of the values in the dictionary.
//Capacity and Size :
//	isEmpty() : return true if the Dictionary is empty, false otherwise.
//	size() : return the number of key - value pairs in the dictionary.
template <typename Key, typename Value>
//Tree of Pairs
class Dictionary 
{
private:
    struct Node 
    {
        Pair<Key, Value> data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(const Key& k, const Value& v) : data{ k, v } {}
    };
    std::unique_ptr<Node> root;
    size_t count = 0;


    void insertNode(std::unique_ptr<Node>& node, const Key& key, const Value& value) 
    {
        if (!node) 
        {
            node = std::make_unique<Node>(key, value);
            ++count;
            return;
        }
        if (key < node->data.pairKey)
            insertNode(node->left, key, value);
        else if (key > node->data.pairKey)
            insertNode(node->right, key, value);
        else
            node->data.second = value; // replace existing
    }

    std::unique_ptr<Node> eraseNode(std::unique_ptr<Node> node, const Key& key) 
    {
        if (!node) return nullptr;

        if (key < node->data.pairKey)
            node->left = eraseNode(std::move(node->left), key);
        else if (key > node->data.pairKey)
            node->right = eraseNode(std::move(node->right), key);
        else {
            // Node to delete found
            if (!node->left)
                return std::move(node->right);
            else if (!node->right)
                return std::move(node->left);

            // Node with two children: find inorder successor
            Node* successor = node->right.get();
            while (successor->left)
                successor = successor->left.get();

            node->data = successor->data;
            node->right = eraseNode(std::move(node->right), successor->data.pairKey);
        }
        return node;
    }
public:
    //Rule of 5
    Dictionary() : root(nullptr), count(0) {}
    ~Dictionary() { clear(); }

    Dictionary(const Dictionary& other) : root(nullptr), count(0) 
    {
        for (const auto& k : other.keys())
            insert(k, other.at(k));
    }

    Dictionary(Dictionary&& other) noexcept
        : root(other.root), count(other.count) {
        other.root = nullptr;
        other.count = 0;
    }

    Dictionary& operator=(const Dictionary& other) {
        if (this != &other) {
            clear();
            for (const auto& k : other.keys())
                insert(k, other.at(k));
        }
        return *this;
    }

    Dictionary& operator=(Dictionary&& other) noexcept {
        if (this != &other) {
            clear();
            root = other.root;
            count = other.count;
            other.root = nullptr;
            other.count = 0;
        }
        return *this;
    }
    //The following access and modification methods:
//operator[]() : 
    Value& operator[](const Key& key) 
    {
        //Access or insert an element by key
        Node* found = findNode(root.get(), key);
        if (found) { return found->data.pairVal; }
        //if the key doesn’t exist, then 
        //insert a new pair into the dictionary with that value.
        insert(key, Value{});
        return findNode(root.get(), key)->data.pairVal;
    }
    //insert() : Insert a new value pair into the dictionary.
    void insert(const Key& key, const Value& value) 
    {
        insertNode(root, key, value);
    }
    //at() : Access an element by key, with an error if the key isn’t in the dictionary.
    Value& at(const Key& key) 
    {
        Node* found = findNode(root.get(), key);
        if (!found)
            throw std::out_of_range("Key not found in dictionary");
        return found->data.pairVal;
    }
    //erase() : Remove the key - value pair from the dictionary as indicated by the key.
    void erase(const Key& key) 
    {
        root = eraseNode(std::move(root), key);
        --count;
    }
    bool search(Comparable key) const;
  
    void print() const;
};

