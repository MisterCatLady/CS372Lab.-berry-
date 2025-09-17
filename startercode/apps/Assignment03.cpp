//lberry4@my.athens.edu
//Assignment03.cpp
// Incomplete. Lecture video is unpublished on Canvas. Forgive me if I misunderstood protocol. 
// I didn't think we were required to attend lectures synchronously. I will attend next week.

//Using the code discussed in lecture as starting point, implement the List<> template class in your library. 
//Your class must support the public interface of the List ADT as defined in the lecture.  
//You will note that the version of the class included in the lectures did not take into account copy and move construction.   
//Implement a copy constructor,  copy assignment, move constructor, and move assignment in your class.
template <typename T>
class List
{
private:
	class Node
	{
	public:
		T data;
		Node* prev;
		Node* next;
	};
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	List();
	List(T newData);
	List(List& rhs); // copy constructor
	~List();
	bool empty();
	void push_front(T data);
	void push_back(T data);
	T front();
	T back();
	void pop_back();
	void pop_front();
	void traverse(void(*doIt)(T data));
};
//Use your newly created list class to refactor your Bag class to use a list rather than a vector as the backing store for the Bag. 
//Note: do this with the Bag class from the lecture materials rather than the ReceiptBag class from a previous assignment. 
//Explain why this is required within your submission document. 
//Hint: it’s related to the nature of a “bag” vs. a “bag with receipts” and underlying data structure you use.
template <typename Thing>
class Bag
{
private:

public:
	Bag();
	Bag(Bag& obj);
	void insert(Thing aThing);
	Thing& pop();
	int size();
	int count();
};

//Now let’s see if we can take advantage of your learned superpowers from object-oriented programming! We need a “circular list”,
//where such a thing differs from a regular list in that attempts to traverse the list will return you back to the front of the list and continue. 
//This can be built by inheriting from your existing list class.

//You’ll need a starting point in the list (an additional parameter to the traverse) and then the traverse will stop when you get back to the starting point. 
//Your submission will need to document how you interpret the different requirements, document what you need to override + what needs to change (if anything) 
//in the base class in your design, and provide the new class and test code for your work.
