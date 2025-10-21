#pragma once
#include <vector>
#include <stdexcept>
//Step 2 A Dictionary Class
//Now use your Pair class to construct a template class Dictionary<Key,Value> that stores its data in a tree of Pair<Key,Value> objects.
#include "Pair.h"
//at() : Access an element by key, with an error if the key isn’t in the dictionary.
//insert() : Insert a new value pair into the dictionary.
//erase() : Remove the key - value pair from the dictionary as indicated by the key.
//clear() : Remove all elements from the dictionary.
//Lookup operations
//keys() : Return a reference to a List<Key> of the keys in the dictionary.
//values() : Return a reference to a List<Value> of the values in the dictionary.
//Capacity and Size :
//	isEmpty() : return true if the Dictionary is empty, false otherwise.
//	size() : return the number of key - value pairs in the dictionary.

    //The following access and modification methods:
    //operator[]() : 
 
        //Access or insert an element by key
        //if the key doesn’t exist, then 
        //insert a new pair into the dictionary with that value.
template <typename Comparable>
class Dictionary 
{
private:
    struct Node 
    {
        Comparable key;
        std::vector<std::shared_ptr<Node>> forward;

        Node (int k, int level) : key(k), forward(level,nullptr) {}
    };
    int maxLevel;
    float probability;
    int level;
    std::shared_ptr<Node> head;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> distribution;

    int randomLevel();
public:
    Dictionary(int maxLvl = 16, float prob = 0.5):
        maxLevel(maxLvl), probability(prob), level(1), 
        head(std::make_shared<Node>(-1, maxLvl)), 
        gen(rd()), distribution(0.0,1.0) { }
    void insert(Comparable key)
    {
        std::vector<std::shared_ptr<Node>> update(maxLevel, nullptr);
        auto current = head;

        for (int i = level - 1; i >= 0; --i)
        {
            while (current->forward[i] && current->forward->key < key)
            {
                current = current->forward[i];
            }
        }
    }
    bool search(Comparable key) const;
    void erase(int key);
    void print() const;
};

