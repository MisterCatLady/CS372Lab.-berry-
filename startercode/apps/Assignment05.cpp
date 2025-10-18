#include <iostream>
#include <cassert>
#include <functional>
#include <list>
#include "Tree.hpp" 


std::list<int> resultList;


void addToResult(int thing) { resultList.push_back(thing); }

template <typename Iterable>
void printAny(Iterable aContainer)
{
	for (auto aThing : aContainer)
	{
		std::cout << aThing << " ";
	}
	std::cout << std::endl;
}
template <typename T>
std::list<T> collectLevelOrder(const Tree<T>& t)
{
    std::list<T> result;
    levelTraversal(t, [&](T val) { result.push_back(val); });
    return result;
}
int main() {
    // ------------------------
    // 1. Test default constructor
    // ------------------------
    Tree<int> t1;
    assert(t1.isEmpty());
    assert(t1.size() == 0);

    // ------------------------
    // 2. Test initializer_list constructor
    // ------------------------
    Tree<int> t2 = { 5, 3, 7, 2, 4, 6, 8 };
    assert(!t2.isEmpty());
    assert(t2.size() == 7);

    // ------------------------
    // 3. Test insert() and member()
    // ------------------------
    Tree<int> t3;
    t3 = t3.insert(10);
    t3 = t3.insert(5);
    t3 = t3.insert(15);
    assert(t3.size() == 3);
    assert(t3.member(10));
    assert(t3.member(5));
    assert(t3.member(15));
    assert(!t3.member(100));

    // ------------------------
    // 4. Test root(), left(), right()
    // ------------------------
    assert(t3.root() == 10);
    assert(t3.left().root() == 5);
    assert(t3.right().root() == 15);

    // ------------------------
    // 5. Test find()
    // ------------------------
    Tree<int> subtree;
    assert(t3.find(5, subtree));
    assert(subtree.root() == 5);
    assert(!t3.find(100, subtree));
    assert(subtree.isEmpty());

    // ------------------------
    // 6. Test preorder traversal
    // ------------------------
    std::cout << "Preorder: ";
    t3.preorder([](int x) { std::cout << x << " "; });
    std::cout << "\n"; // Expected: 10 5 15

    // ------------------------
    // 7. Test inorder traversal
    // ------------------------
    std::cout << "Inorder: ";
    t3.inorder([](int x) { std::cout << x << " "; });
    std::cout << "\n"; // Expected: 5 10 15

    // ------------------------
    // 8. Test postorder traversal
    // ------------------------
    std::cout << "Postorder: ";
    t3.postorder([](int x) { std::cout << x << " "; });
    std::cout << "\n"; // Expected: 5 15 10

    // ------------------------
    // 9. Test level-order traversal (stand-alone function)
    // ------------------------
    std::cout << "Level-order traversal: ";
    levelTraversal(t2, [](int x) { std::cout << x << " "; });
    std::cout << "\n"; // Expected: 5 3 7 2 4 6 8

    // ------------------------
    // 10. Test treeHeight()
    // ------------------------
    int h = treeHeight(t2);
    std::cout << "Tree height: " << h << "\n"; // Expected: 3
    assert(h == 3);

    // ------------------------
    // 11. Test visitLevel()
    // ------------------------
    std::cout << "Nodes at level 0: ";
    visitLevel(t2, 0, [](int x) { std::cout << x << " "; });
    std::cout << "\n"; // Expected: 5

    std::cout << "Nodes at level 1: ";
    visitLevel(t2, 1, [](int x) { std::cout << x << " "; });
    std::cout << "\n"; // Expected: 3 7

    std::cout << "Nodes at level 2: ";
    visitLevel(t2, 2, [](int x) { std::cout << x << " "; });
    std::cout << "\n"; // Expected: 2 4 6 8

    // ------------------------
    // 12. Test copy/move constructors
    // ------------------------
    Tree<int> t4 = t2;       // copy constructor
    Tree<int> t5;
    t5 = t2;                  // copy assignment
    Tree<int> t6 = std::move(t5); // move constructor
    Tree<int> t7;
    t7 = std::move(t4);       // move assignment
    assert(t6.root() == t2.root());
    assert(t7.root() == t2.root());

    // ------------------------
    // 13. Test generic treeTraversal
    // ------------------------
    std::cout << "Generic treeTraversal (inorder style): ";
    t2.treeTraversal<int>([](int x) { std::cout << x << " "; });
    std::cout << "\n"; // Expected: 2 3 4 5 6 7 8

    std::cout << "All tests passed!\n";

    return 0;
}