//lberry@my.athens.edu
//Midterm Exam: Programming Question 1
//Sources: cppreference.com, chatgpt.com

#include <iostream>
#include "Q1.h"   // include your template header

using namespace std;

void printData(int x) {
    cout << "[" << x << "]";
}

int main() {
    cout << "=== Test 1: Basic push and print ===\n";
    List<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    list1.push_front(5);
    list1.printTheList();  // Expect: 5 10 20
    cout << "\nFront: " << list1.front() << " Back: " << list1.back() << "\n\n";

    cout << "=== Test 2: Lazy deletion with pop_front/pop_back ===\n";
    list1.pop_front();  // 5 lazily deleted
    list1.pop_back();   // 20 lazily deleted
    list1.printTheList(); // Expect: 10
    cout << "\nFront: " << list1.front() << " Back: " << list1.back() << "\n\n";

    cout << "=== Test 3: Force cleanup by deleting all ===\n";
    list1.pop_back();   // deletes 10
    cout << "List empty? " << (list1.empty() ? "Yes" : "No") << "\n\n";

    cout << "=== Test 4: Copy constructor ===\n";
    list1.push_back(100);
    list1.push_back(200);
    List<int> list2 = list1;  // copy
    cout << "List1: "; list1.printTheList();
    cout << "List2 (copy): "; list2.printTheList();
    cout << "\n";

    cout << "=== Test 5: Copy assignment ===\n";
    List<int> list3;
    list3.push_back(999);
    list3 = list1;
    cout << "List1: "; list1.printTheList();
    cout << "List3 (assigned): "; list3.printTheList();
    cout << "\n";

    cout << "=== Test 6: Move constructor ===\n";
    List<int> list4 = std::move(list1);
    cout << "List4 (moved from list1): "; list4.printTheList();
    cout << "List1 (after move): "; list1.printTheList();
    cout << "\n";

    cout << "=== Test 7: Move assignment ===\n";
    List<int> list5;
    list5.push_back(1);
    list5.push_back(2);
    list5 = std::move(list2);
    cout << "List5 (after move assignment from list2): "; list5.printTheList();
    cout << "List2 (after being moved): "; list2.printTheList();
    cout << "\n";

    cout << "=== Test 8: Traverse with callback ===\n";
    cout << "List5 elements: ";
    list5.traverse(printData);
    cout << "\n";

    cout << "=== End of tests ===\n";
    return 0;
}
