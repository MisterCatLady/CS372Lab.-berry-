#pragma once
#include "List.h"
#include <iostream>
//Using the code discussed in lecture as starting point, implement the List<> template class in your library. 
//Your class must support the public interface of the List ADT as defined in the lecture.  
//You will note that the version of the class included in the lectures did not take into account copy and move construction.   
//Implement a copy constructor,  copy assignment, move constructor, and move assignment in your class.

//Use your newly created list class to refactor your Bag class to use a list rather than a vector as the backing store for the Bag. 
//Note: do this with the Bag class from the lecture materials rather than the ReceiptBag class from a previous assignment. 
//Explain why this is required within your submission document. 
//Hint: it’s related to the nature of a “bag” vs. a “bag with receipts” and underlying data structure you use.
template <typename Thing>
class Bag 
{
private:
	List<Thing> bagContents;
	
	int bagSize;
public:
	Bag() = default; // default constructor
	Bag(const Bag<Thing>& rhs): bagContents(rhs.bagContents) {} // copy constructor
	Bag<Thing>& operator=(cosnt Bag<Thing>& rhs) //copy assign operator
	{
		if (this != &rhs) { bagContents = rhs.bagContents; }
		return *this;
	}
	Bag(Bag<Thing>&& rhs) noexcept : bagContents(std::move(rhs.bagContents) {} //move constructor
	Bag<T>& operator=(Bag<Thing>&& rhs) noexcept //move assignment operator
	{
		if (this != &rhs) {bagContents = std::move(rhs.bagContents);}
		return *this;
	}
	void insert(Thing aThing)
	{
		bagContents.push_back(aThing);
		bagSize++;
	}
	Thing& pop()
	{
		Thing aThing;
		if (bagContents.size() > 0)
		{
			aThing = bagContents[bagSize];
			bagSize--;
		}
		else
		{
			std::cerr << "Can't pop out of an empty bag" << std::endl;
		}
		return aThing;
	}
	int size() { return bagSize; }
	int count(Thing aThing)
	{
		int bagCount = 0;
		for (int i = 0; i < bagSize; i++) { bagCount++; }
		return bagCount;
	}

};

//We need a “circular list”, where such a thing differs from a regular 
// list in that attempts to traverse the list will return you back to the front of the list and continue. 
//This can be built by inheriting from your existing list class.

//You’ll need a starting point in the list (an additional parameter to the traverse) and then the traverse will stop when you get back to the starting point. 
//Your submission will need to document how you interpret the different requirements, document what you need to override + what needs to change (if anything) 
//in the base class in your design, and provide the new class and test code for your work.